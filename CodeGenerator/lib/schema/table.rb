module Schema
class Table
  attr_reader :name, :columns, :indexes

  def initialize(name, columns, indexes)
    @name = name
    @columns = columns
    @indexes = indexes
  end
end
end
