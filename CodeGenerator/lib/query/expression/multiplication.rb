module Query
module Expression
class Multiplication
  def initialize(attributes)
    @attributes = attributes
  end

  def produce
    @attributes.map(&:value).join(' * ')
  end
end
end
end
