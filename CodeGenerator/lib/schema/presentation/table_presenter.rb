require 'schema/presentation/column_presenter'
require 'schema/presentation/index_presenter'
require 'schema/presentation/presentation_enumerable'

module Schema
class TablePresenter < Presenter
  attr_reader :schema

  def initialize(table, schema)
    @schema = schema
    @table = table
  end

  def name
    @table.name
  end

  def source_file_name
    "#{name}.cpp"
  end

  def header_file_name
    "#{name}.h"
  end

  def header_constant
    "_#{schema.namespace.upcase}_#{name.upcase}_H_"
  end

  def class_name
    name.camelize
  end

  def columns
    @columns ||= PresentationEnumerable.new(@table.columns.map { |c| ColumnPresenter.create(c, self) })
  end

  def indexes
    @indexes ||= PresentationEnumerable.new(@table.indexes.map { |i| IndexPresenter.create(i, self) })
  end
end
end
