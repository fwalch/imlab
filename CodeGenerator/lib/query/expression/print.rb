module Query
module Expression
class Print
  def initialize(attributes, &block)
    @attributes = attributes
    @block = block
  end

  def produce
    @input.produce
  end

  def consume(input)
    raise "Wrong input" unless input == @input

    if @block
      @block.yield(@attributes)
    else
      out = @attributes
        .map { |a| a.value }
        .join(' << "|" << ')

      "std::cout << #{out} << std::endl;"
    end
  end

  def set_input(input)
    @input = input
  end
end
end
end
