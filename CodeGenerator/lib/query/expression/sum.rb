module Query
module Expression
class Sum
  include Rendering
  attr_reader :consumer

  def initialize(consumer, summands, result)
    @consumer = consumer
    @summands = summands
    @result = result
    consumer.set_input(self)
  end

  def produce
    render_template 'sum'
  end

  def consume(input)
    sum = @summands
      .map(&:produce)
      .join(' + ')
    "#{@result.value} += #{sum};"
  end

  def set_input(input)
    @input = input
  end

  def result_variable
    "#{@result.cpp_type} #{@result.value}"
  end
end
end
end
