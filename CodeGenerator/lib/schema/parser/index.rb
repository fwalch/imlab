module Schema
class Index
  attr_reader :name, :column_names

  def initialize(name, column_names)
    @name = name
    @column_names = column_names.to_a
  end
end
end
