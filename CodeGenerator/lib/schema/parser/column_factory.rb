require 'schema/column'

module Schema
class ColumnFactory
  attr_reader :column_name, :column_type

  def initialize(column_name)
    @column_name = column_name
  end

  def set_integer
    @column_type = :integer
  end

  def set_timestamp
    @column_type = :timestamp
  end

  def set_numeric(x,y)
    @column_type = :numeric
  end

  def set_char(length)
    @column_type = :text
  end

  def set_varchar(length)
    @column_type = :text
  end

  def create_column
    Column.new(column_name, column_type)
  end
end
end