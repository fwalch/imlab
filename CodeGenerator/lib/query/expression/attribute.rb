module Query
module Expression
class Attribute
  attr_reader :value, :cpp_type

  def initialize(name, type)
    @value = name
    @cpp_type = type
  end
end
end
end
