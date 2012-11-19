module Query
module Expression
class Constant
  attr_reader :value, :cpp_type

  def initialize(value, type)
    @value = value
    @cpp_type = type
  end
end
end
end
