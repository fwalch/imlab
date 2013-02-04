require 'schema/presentation/presenter'

module Schema
module IntegerColumnPresenter
  def type
    'int32_t'
  end

  def from_string_variable(variable_name)
    "atoi(#{super}.c_str())"
  end
end

module TimestampColumnPresenter
  def type
    'uint64_t'
  end

  def from_string_variable(variable_name)
    "db_stod(#{super})"
  end
end

module NumericColumnPresenter
  def type
    'int64_t'
  end

  def from_string_variable(variable_name)
    "db_stol(#{super})"
  end
end

module TextColumnPresenter
  def type
    'const char*'
  end

  def index_key_type
    'str::string'
  end

  def collection_type
    "std::vector<str::string>"
  end

  def dictionary_name
    "#{name}_dict"
  end

  def global_dictionary_name
    "this->#{dictionary_name}"
  end

  def global_definition
    [
      super,
      "str::dictionary #{dictionary_name}"
    ]
  end

  def from_string_variable(variable_name)
    "#{super}.c_str()"
  end

  def local_to_index_key_value
    "#{global_dictionary_name}.get_string(#{super})"
  end

  def add_from(variable_name)
    [
      "auto #{variable_name}_str = #{global_dictionary_name}.make_string(#{variable_name})",
      "#{global_name}.push_back(#{variable_name}_str)"
    ]
  end

  def remove
    [
      "auto #{local_name}_sid = #{global_name}.back()",
      "#{global_dictionary_name}.remove(#{local_name}_sid)",
      super
    ]
  end
end

class ColumnPresenter < Presenter
  attr_reader :table

  def initialize(column, table)
    @table = table
    @column = column
  end

  def name
    @column.name
  end

  def local_definition
    "#{type} #{local_name}"
  end

  def local_name
    name
  end

  def collection_type
    "std::vector<#{type}>"
  end

  def global_definition
    "#{collection_type} #{name}"
  end

  def global_name
    "this->#{name}"
  end

  def from_string_variable(variable_name)
    variable_name
  end

  def local_to_index_key_value
    local_name
  end

  def add_from_local
    add_from(local_name)
  end

  def add_from(variable_name)
    "#{global_name}.push_back(#{variable_name})"
  end

  def remove
    "#{global_name}.pop_back()"
  end

  def global_access(tid_variable)
    "#{global_name}[#{tid_variable}]"
  end

  def move_global(target_tid_variable, source_tid_variable)
    assign_from(target_tid_variable, "#{global_access(source_tid_variable)}")
  end

  def assign_from(tid_variable, value_variable)
    "#{global_access(tid_variable)} = #{value_variable}"
  end

  # Factory method
  def self.create(column, table)
    presenter = self.new(column, table)
    if column.type
      column_module = "Schema::#{column.type.to_s.camelize}ColumnPresenter".constantize
      presenter.extend column_module if column_module
    end
    return presenter
  end
end
end
