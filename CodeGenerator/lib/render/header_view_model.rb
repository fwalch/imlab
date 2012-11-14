require 'render/view_model_common'

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
    (@table.indexes + @table.multi_indexes)
      .map { |i| get_index_members(i) }
      .flatten
      .join("\n    ")
  end

  def index_methods
    (@table.indexes.map { |i| get_index_methods(i, false) } + @table.partial_indexes.map { |i| get_index_methods(i, true) } + @table.multi_indexes.map { |i| get_index_methods(i, true) } )
      .flatten
      .join("\n    ")
  end

  def column_members
    @table.columns
      .map { |c| "#{c.cpp_collection_type} #{c.name};"}
      .join("\n    ")
  end

  def column_types
    @table.columns
      .map { |c| c.cpp_type }
      .join(', ')
  end

  private
  #TODO
  def get_index_members(index)
    range_index = @table.get_partial_index(index.name)
    multi_index = @table.get_multi_index(index.name)
    raise "Internal error" if range_index && multi_index
    key_types = index.column_names
      .map { |c| @table.get_column(c).cpp_type }
      .join(', ')
    map_type = range_index ? 'map' : (multi_index ? 'multimap' : 'unordered_map')
    [
      "typedef std::tuple<#{key_types}> #{index.name}KeyType;",
      "typedef std::#{map_type}<#{index.name}KeyType, uint64_t> #{index.name}IndexType;",
      "#{index.name}IndexType #{index.name}Index;"
    ]
  end

  def get_index_methods(index, range_index)
    parameter_types = index.column_names
      .map { |c| @table.get_column(c).cpp_type }
      .join(', ')
    "#{get_index_get_signature(index, parameter_types, range_index)};"
  end

  def index_headers
    headers = []
    headers << '<unordered_map>' if @table.indexes.any?
    headers << '<map>' if @table.partial_indexes.any? || @table.multi_indexes.any?
    return headers
  end
end
end

