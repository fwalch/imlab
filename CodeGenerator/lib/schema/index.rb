module Schema
class Index
  attr_reader :name, :columns, :type, :partial_columns

  def initialize(name, type, columns, partial_columns=[])
    @name = name
    @columns = columns
    @partial_columns = partial_columns
    @type = type
  end
end
end
