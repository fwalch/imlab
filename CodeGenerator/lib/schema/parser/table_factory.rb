require 'schema/parser/column_factory'
require 'schema/parser/index_factory'
require 'schema/table'

module Schema
class TableFactory
  attr_reader :table_name, :column_factories, :index_factories

  def initialize(table_name)
    @table_name = table_name
    @column_factories = {}
    @index_factories = {}
  end

  def add_column(column_name)
    @column_factories[column_name] = ColumnFactory.new(column_name)
    return @column_factories[column_name]
  end

  def add_index(index_name, column_names)
    @index_factories[index_name] = IndexFactory.new(index_name, column_names)
    return @index_factories[index_name]
  end

  def create_table
    columns = column_factories.values.map(&:create_column)
    indexes = index_factories.values.map { |f| f.create_index(columns) }
    Table.new(table_name, columns, indexes)
  end
end
end
