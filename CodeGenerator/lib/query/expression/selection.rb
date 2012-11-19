module Query
module Expression
class Selection
  include Rendering
  attr_reader :consumer, :condition

  def initialize(consumer, condition)
    @consumer = consumer
    @condition = condition
    consumer.set_input(self)
  end

  def consume(input)
    raise "Wrong input" unless input == @input
    render_template('selection')
  end

  def produce
    @input.produce
  end

  def set_input(input)
    @input = input
  end
end
end
end
