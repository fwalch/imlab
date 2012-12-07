module Query
module Expression
class Attribute
  attr_reader :value, :cpp_type

  def initialize(name, type, conversion=nil)
    @value = name
    @cpp_type = type
    @conversion = conversion
  end

  def get_value(store, tid)
    v = "#{store}.#{value}[#{tid}]"
    @conversion ? "#{store}.#{@conversion.call(v)}" : v
  end
end
end
end
