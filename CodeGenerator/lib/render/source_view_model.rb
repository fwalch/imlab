require 'render/view_model_common'

module CodeGenerator
class SourceViewModel
  include ViewModel::Common

  def file_name
    "#{@table.name}.cpp"
  end

  def header_name
    "#{@table.name}.h"
  end

  def index_assignments
    (@table.indexes.map { |i| "#{i.name}Index[std::make_tuple(#{get_index_fields(i)})] = tid;" } + @table.multi_indexes.map { |i| "#{i.name}Index.insert(std::make_pair(std::make_tuple(#{get_index_fields(i)}), tid));" })
      .join("\n  ")
  end

  def index_removals
    (@table.indexes + @table.multi_indexes)
      .map { |i| get_index_removal(i) }
      .flatten
      .join("\n  ")
  end

  def column_conversions
    @table.columns.each_with_index
      .map { |c,i| c.get_conversion("elements[#{i}]") }
      .join(",\n    ")
  end

  def column_typed_variables
    @table.columns
      .map { |c| "#{c.cpp_type} #{c.name}" }
      .join(', ')
  end

  def column_variables
    @table.columns
      .map { |c| "#{c.name}" }
      .join(', ')
  end

  def column_assignments
    @table.columns
      .map { |c| c.name }
      .map { |c| "this->#{c}.push_back(#{c});" }
      .join("\n  ")
  end

  def column_moves(target, source)
    @table.columns
      .map { |c| c.get_move(target, source) }
      .join("\n    ")
  end

  def column_fields
    @table.columns
      .map { |c| "this->#{c.name}" }
      .map { |c| yield(c) }
      .join("\n  ")
  end

  def index_methods
    (@table.indexes.map { |i| get_index_methods(i, false) } + @table.partial_indexes.map { |i| get_index_methods(i, true) } + @table.multi_indexes.map { |i| get_index_methods(i, true) })
      .flatten
      .join("\n")
  end

  private
  def get_index_fields(index)
    index.column_names
      .map { |c| "this->#{c}[tid]" }
      .join(', ')
  end

  def get_index_removal(index)
    [
      "auto #{index.name}Key = std::make_tuple(#{get_index_fields(index)});",
      "auto #{index.name}It = #{index.name}Index.find(#{index.name}Key);",
      "#{index.name}Index.erase(#{index.name}It);"
    ]
  end

  def get_typed_column_variable(column_name)
    column = @table.columns.select { |c| c.name == column_name }[0]
    "#{column.cpp_type} #{column.name}"
  end

  #TODO
  def get_index_methods(index, range_index)
    parameter_typed_variables = index.column_names
      .map { |c| get_typed_column_variable(c) }
      .join(', ')
    signature = get_index_get_signature(index, parameter_typed_variables, range_index, class_name)
    if range_index
      index_column_diff = (@table.indexes + @table.multi_indexes).select { |i| i.name == index.name}[0].column_names.count - index.column_names.count
      empty_lower_columns = []
      empty_upper_columns = []
      index_column_diff.times do
        empty_lower_columns << '0'
        empty_upper_columns << 'INT_MAX'
      end
      index_variables_lower = (index.column_names + empty_lower_columns).join(', ')
      index_variables_upper = (index.column_names + empty_upper_columns).join(', ')
      impl = <<eos
return std::make_pair(
    #{index.name}Index.lower_bound(std::make_tuple(#{index_variables_lower})),
    #{index.name}Index.upper_bound(std::make_tuple(#{index_variables_upper})));
eos
    else
      index_variables = index.column_names.join(', ')
      impl = "return #{index.name}Index[std::make_tuple(#{index_variables})];"
    end

    return <<eos
#{signature} {
  #{impl.strip}
}
eos
  end
end
end
