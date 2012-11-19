require 'parser/column'
require 'parser/index'

module Schema
class Table
  PRIMARY_KEY_INDEX_NAME = 'pk'

  attr_reader :name

  def initialize(name)
    @name = name
    @indexes = {}
    @columns = {}
    @partial_indexes = {}
    @multi_indexes = {}
  end

  def add_index(index_name, column_names)
    raise "Already added index #{index_name} on table #{name}" if @indexes[index_name] || @multi_indexes[index_name]
    @indexes[index_name] = Index.new(index_name, column_names)
  end

  def add_multi_index(index_name, column_names)
    raise "Already added index #{index_name} on table #{name}" if @indexes[index_name] || @multi_indexes[index_name]
    @multi_indexes[index_name] = Index.new(index_name, column_names)
  end

  def add_partial_index(index_name, column_names)
    raise "No index #{index_name} on table #{name}; cannot add partial index" unless @indexes[index_name]
    @partial_indexes[index_name] = Index.new(index_name, column_names)
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

  def multi_indexes
    @multi_indexes.values
  end

  def partial_indexes
    @partial_indexes.values
  end

  def columns
    @columns.values
  end

  def get_column(name)
    @columns[name]
  end

  def get_index(name)
    @indexes[name]
  end

  def get_multi_index(name)
    @multi_indexes[name]
  end

  def get_partial_index(name)
    @partial_indexes[name]
  end
end
end
