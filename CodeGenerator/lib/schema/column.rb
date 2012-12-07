module Schema
class Column
  attr_reader :name, :type

  def initialize(name, type)
    @name = name
    @type = type
  end
end
end

