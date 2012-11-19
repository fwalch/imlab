module Query
module Expression
class CrossProduct
  def initialize(consumer)
    @consumer = consumer
    consumer.set_input(self)
  end

  def produce
    @left.produce
  end

  def consume(input)
    if input == @left
      @right.produce
    elsif input == @right
      @consumer.consume(self)
    else
      raise "Wrong input"
    end
  end

  def set_input(input)
    (@right = input) && return unless @right
    (@left = input) && return unless @left

    raise "Already have two inputs"
  end
end
end
end
