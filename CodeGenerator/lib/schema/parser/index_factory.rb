require 'schema/index'

module Schema
class IndexFactory
  attr_reader :index_name, :index_type, :column_names, :partial_column_names

  def initialize(index_name, column_names)
    @index_name = index_name
    @column_names = column_names
    @partial_column_names = []
  end

  def set_multi
    @index_type = :multi
  end

  def set_primary
    @index_type = :primary
  end

  def set_partial_columns(column_names)
    @partial_column_names << column_names
  end

  def create_index(all_columns)
    all_columns = Hash[all_columns.map { |c| [c.name, c] }]
    columns = column_names.map { |c| all_columns[c] }
    partial_columns = partial_column_names.map { |c| c.map { |n| all_columns[n] } }
    Index.new(index_name, index_type, columns, partial_columns)
  end
end
end
