require 'schema/schema'
require 'schema/parser/table_factory'

module Schema
class SchemaFactory
  attr_reader :table_factories

  def initialize
    @table_factories = {}
  end

  def add_table(table_name)
    @table_factories[table_name] = TableFactory.new(table_name)
  end

  def add_index(index_name, table_name, column_names)
    @table_factories[table_name].add_index(index_name, column_names)
  end

  def create_schema
    Schema.new(table_factories.values.map(&:create_table))
  end
end
end
