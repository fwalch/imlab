module Query
module Expression
class HashJoin
  include Rendering

  def initialize(consumer, left_attributes, right_attributes)
    @consumer = consumer
    @left_attributes = left_attributes
    @right_attributes = right_attributes
    consumer.set_input(self)
  end

  def produce
    render_template('hash_join_produce')
  end

  def consume(input)
    if input == @left
      render_template('hash_join_left')
    elsif input == @right
      render_template('hash_join_right')
    else
      raise "Wrong input"
    end
  end

  def set_input(input)
    (@right = input) && return unless @right
    (@left = input) && return unless @left

    raise "Already have two inputs"
  end

  def tuple_types
    @left_attributes
      .map(&:cpp_type)
      .join(', ')
  end

  def tuple_variables(input_id)
    if input_id == :left
      @left_attributes
        .map(&:value)
        .join(', ')
    else
      @right_attributes
        .map(&:value)
        .join(', ')
    end
  end
end
end
end
