module Schema
class Column
  attr_reader :name, :type, :attributes

  def initialize(name, type, attributes)
    @name = name
    @type = type
    @attributes = attributes
  end
end
end

