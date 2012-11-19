module Query
module Expression
class Equal
  def initialize(left, right)
    @left = left
    @right = right
  end

  def produce
    if @left.cpp_type == 'char*' || @right.cpp_type == 'char*'
      "strcmp(#{@left.value}, #{@right.value}) == 0"
    else
      "#{@left.value} == #{@right.value}"
    end
  end
end
end
end
