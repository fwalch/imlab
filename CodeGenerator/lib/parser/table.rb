require 'parser/column'
require 'parser/index'

module CodeGenerator
class Table
  PRIMARY_KEY_INDEX_NAME = 'pk'

  attr_reader :name, :partial_indexes

  def initialize(name)
    @name = name
    @indexes = {}
    @columns = {}
    @partial_indexes = []
  end

  def add_index(index_name, column_names)
    raise "Already added index #{index_name} on table #{name}" if @indexes[index_name]
    @indexes[index_name] = Index.new(index_name, column_names)
  end

  def add_partial_index(index_name, column_names)
    raise "No index #{index_name} on table #{name}; cannot add partial index" unless @indexes[index_name]
    @partial_indexes << Index.new(index_name, column_names)
  end

  def add_primary_key(column_names)
    add_index(PRIMARY_KEY_INDEX_NAME, column_names)
  end

  def add_column(column_name)
    raise "Already added column #{column_name} on table #{name}" if @columns[column_name]
    @columns[column_name] = Column.new(column_name)
  end

  def indexes
    @indexes.values
  end

  def columns
    @columns.values
  end
end
end
