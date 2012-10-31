require 'view_model_common'

module CodeGenerator
class HeaderViewModel
  include ViewModel::Common

  def file_name
    "#{@table.name}.h"
  end

  def header_constant
    "_#{codify(file_name).upcase}_"
  end

  def includes
    (@table.columns.map { |c| c.header } + index_headers)
      .flatten
      .uniq
      .map { |h| "#include #{h}" }
      .join("\n")
  end

  def index_members
    @table.indexes.map { |i| get_index_members(i) }
      .flatten
      .join("\n")
  end

  def index_methods
    (@table.indexes.map { |i| get_index_methods(i, false) } + @table.partial_indexes.map { |i| get_index_methods(i, true) })
      .flatten
      .join("\n")
  end

  def column_members
    @table.columns
      .map { |c| "#{c.cpp_collection_type} #{c.name};"}
      .join("\n")
  end

  def column_types
    @table.columns
      .map { |c| c.cpp_type }
      .join(', ')
  end

  private
  def get_index_members(index)
    partial = @table.partial_indexes.select { |i| i.name == index.name }.any?
    key_types = index.column_names
      .map { |c| 'int32_t' }
      .join(', ')
    map_type = partial ? 'map' : 'unordered_map'
    [
      "typedef std::tuple<#{key_types}> #{index.name}KeyType;",
      "typedef std::#{map_type}<#{index.name}KeyType, uint64_t> #{index.name}IndexType;",
      "#{index.name}IndexType #{index.name}Index;"
    ]
  end

  def get_index_methods(index, partial)
    index_type = "#{index.name}IndexType"
    return_type = partial ? "std::pair<#{index_type}::iterator, #{index_type}::iterator>" : 'uint64_t'
    parameter_types = index.column_names
      .map { |c| 'int32_t' }
      .join(', ')
    "#{return_type} get(#{parameter_types});"
  end

  def index_headers
    headers = []
    headers << '<unordered_map>' if @table.indexes.any?
    headers << '<map>' if @table.partial_indexes.any?
    return headers
  end
end
end

