require 'antlr3'
require 'SQLParser'

module Schema
class TreeVisitor
  def initialize(context, adapter=nil)
    @context = context.extend EnhancedContext
    @adapter = adapter
    @adapter ||= ANTLR3::AST::CommonTreeAdaptor.new
  end

  def visit(tree)
    # get the token name from the token type and call
    # corresponding method if it exists
    # e.g. text 'create table' has token name 'CREATE_TABLE'
    # and thus calls method 'create_table'
    # If no method found, continue and visit the children
    method_name = SQL::TokenData[tree.type].downcase
    if respond_to?(method_name)
      send(method_name, tree)
    else
      visit_children(tree)
    end
  end

  def visit_children(tree)
    @adapter.child_count(tree).times do |index|
      child = @adapter.child_of(tree, index)
      if block_given?
        yield [child, index]
      else
        visit(child)
      end
    end
  end

  def create_table(tree)
    table_name = @adapter.child_of(tree, 0).text
    @context.add_table table_name

    visit_children(tree)
  end

  def create_index(tree)
    index_name, table_name = nil
    column_names = []

    visit_children(tree) do |child, index|
      case index
      when 0 then index_name = child.text
      when 1 then table_name = child.text
      else
        column_names << child.text
      end
    end

    @context.add_index(index_name, table_name, column_names)
  end

  def primary_key(tree)
    column_names = []

    visit_children(tree) do |child, index|
      column_names << child.text
    end

    @context.last_table.add_primary_key(column_names)
  end

  def id(tree)
    # We are only in a column if we have children, i.e.
    # ID is a root node
    if @adapter.child_count(tree) > 0
      column_name = tree.text
      @context.last_table.add_column column_name
      visit_children(tree)
    end
  end

  def integer(tree)
    @context.last_column.set_integer
  end

  def timestamp(tree)
    @context.last_column.set_timestamp
  end

  def char(tree)
    max_length = @adapter.child_of(tree, 0).text
    @context.last_column.set_char(max_length)
  end

  def varchar(tree)
    max_length = @adapter.child_of(tree, 0).text
    @context.last_column.set_varchar(max_length)
  end

  def numeric(tree)
    overall = @adapter.child_of(tree, 0).text
    after_comma = @adapter.child_of(tree, 1).text
    @context.last_column.set_numeric(overall, after_comma)
  end

  module EnhancedContext
    def last_table
      tables.last
    end

    def last_column
      last_table.columns.last
    end
  end
end
end
