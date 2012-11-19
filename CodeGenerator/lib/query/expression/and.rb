module Query
module Expression
class And
  def initialize(expressions)
    @expressions = expressions
  end

  def produce
    @expressions
      .map { |e| e.produce }
      .join(" && ")
  end
end
end
end
