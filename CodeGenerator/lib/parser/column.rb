module CodeGenerator
class Column
  attr_reader :name, :cpp_collection_type, :cpp_type, :header

  def initialize(name)
    @name = name
    @c_str = false
    @header = []
  end

  def set_integer
    lock_or_raise()
    set_vector('int32_t')
    @header << '<cstdint>'
    @c_str = true
    @converter = 'atoi'
  end

  def set_timestamp
    lock_or_raise()
    set_vector('uint64_t')
    @header << '<cstdint>'
    @converter = 'db_stod'
  end

  def set_char(max_length)
    lock_or_raise()
    @cpp_type = 'std::string'
    # TODO: get path from generator invocation
    @header << '"../src/str_vector.h"'
    @cpp_collection_type = "str_vector<#{max_length}>"
  end

  def set_varchar(max_length)
    set_char(max_length)
  end

  def set_numeric(x, y)
    lock_or_raise()
    set_vector('int64_t')
    @header << '<cstdint>'
    @converter = 'db_stol'
  end

  def get_conversion(value)
    raise_if_not_locked()
    value += '.c_str()' if @c_str
    @converter ? "#{@converter}(#{value})" : value
  end

  def get_move(target, source)
    raise_if_not_locked()
    if @cpp_collection_type.match(/str_vector/)
      "this->#{name}.set(#{target}, this->#{name}[#{source}]);"
    else
      "this->#{name}[#{target}] = this->#{name}[#{source}];"
    end
  end

  private
  def set_vector(type)
    @cpp_type = type
    @header << "<vector>"
    @cpp_collection_type = "std::vector<#{type}>"
  end

  def lock_or_raise
    raise "Already set column type for #{name}" if @locked
    @locked = true
  end

  def raise_if_not_locked
    raise "Column type not set for #{name}" unless @locked
  end
end
end
