require 'schema/presentation/presenter'
require 'schema/presentation/column_presenter'
require 'schema/presentation/presentation_enumerable'

module Schema
module MultiIndexPresenter
  def collection_type
    'std::multimap'
  end

  def get_method_retval
    "std::pair<#{index_type_iterator}, #{index_type_iterator}>"
  end

  def get_method_body
    "std::make_pair(\n#{global_name}.lower_bound(#{local_key_tuple}),\n#{global_name}.upper_bound(#{local_key_tuple}))"
  end

  def assign_from(tid_variable, value_variable)
    "#{global_name}.insert(std::make_pair(#{global_key_tuple(tid_variable)}, #{value_variable}))"
  end
end

module PrimaryIndexPresenter
  def get_method_name
    'get'
  end
end

module PartialIndexPresenter
  def partial_columns
    @partial_columns ||= @index.partial_columns.map { |p| PresentationEnumerable.new(p.map { |c| ColumnPresenter.create(c, table) }) }
  end

  def collection_type
    'std::map'
  end

  def get_method
    [super] + partial_columns.map { |c| partial_get_method(c) }
  end

  def partial_get_method(partial_columns)
    "#{partial_get_method_signature(partial_columns, true)} {\n return std::make_pair(\n#{global_name}.lower_bound(#{local_key_tuple_p(partial_columns, '0')}),\n#{global_name}.upper_bound(#{local_key_tuple_p(partial_columns, 'INT_MAX')}));\n}"
  end

  def get_method_signature(with_class=nil)
    [super] + partial_columns.map { |c| partial_get_method_signature(c, with_class) }
  end

  def partial_get_method_signature(partial_columns, with_class=nil)
    "std::pair<#{index_type_iterator}, #{index_type_iterator}> #{with_class ? "#{table.class_name}::" : ''}#{get_method_name}(#{partial_columns.comma(&:local_definition)})"
  end

  def local_key_tuple_p(partial_columns, placeholder)
    placeholders = []
    (columns.count - partial_columns.count).times { placeholders << placeholder }
    placeholders = placeholders.join(', ')
    "std::make_tuple(#{partial_columns.comma(&:local_to_index_key_value)}, #{placeholders})"
  end
end

module ComparingIndexPresenter
  def global_definition
    [
      "typedef #{key_type} #{key_type_name}",
      "typedef #{key_comparison_type} #{key_comparison_type_name}",
      "const void* #{key_comparison_parameters_name}[#{columns.count}]",
      "#{key_comparison_type_name} #{key_comparison_name}",
      "typedef #{index_type} #{index_type_name}",
      "#{index_type_name} #{local_name}"
    ]
  end

  def constructor_assignments
    [
      "#{key_comparison_parameters_name}{#{key_comparison_parameters}}",
      "#{key_comparison_name}(#{key_comparison_parameters_name})",
      "#{local_name}(#{key_comparison_name})",
    ]
  end

  def index_type
    "#{collection_type}<#{key_type_name}, #{value_type}, #{key_comparison_type_name}>"
  end

  def key_comparison_parameters_name
    "#{name}ComparisonParameters"
  end

  def key_comparison_type
    "tuple_less<#{key_type_name}>"
  end

  def key_comparison_type_name
    "#{name}ComparisonType"
  end

  def key_comparison_name
    "#{name}Comparison"
  end

  def key_comparison_parameters
    columns.comma { |c| c.respond_to?(:comparer_parameter) ? c.comparer_parameter : 'NULL' }
  end
end

class IndexPresenter < Presenter
  attr_reader :table

  def initialize(index, table)
    @table = table
    @index = index
  end

  def name
    @index.name
  end

  def index_type_iterator
    "#{table.class_name}::#{index_type_name}::iterator"
  end

  def get_method_name
    "getBy#{name[0].upcase + name.from(1)}"
  end

  def get_method_retval
    value_type
  end

  def get_method_signature(with_class=nil)
    get_method_signature_local(with_class)
  end

  def get_method_signature_local(with_class=nil)
    "#{get_method_retval} #{with_class ? "#{table.class_name}::" : ''}#{get_method_name}(#{columns.comma(&:local_definition)})"
  end

  def get_method_body
    "#{global_name}[#{local_key_tuple}]"
  end

  def key_type
    "std::tuple<#{columns.comma { |c| c.respond_to?(:index_key_type) ? c.index_key_type : c.type }}>"
  end

  def key_type_name
    "#{name}KeyType"
  end

  def value_type
    'uint64_t'
  end

  def collection_type
    "std::unordered_map"
  end

  def index_type
    "#{collection_type}<#{key_type_name}, #{value_type}>"
  end

  def index_type_name
    "#{name}IndexType"
  end

  def local_name
    "#{name}Index"
  end

  def local_definition
    "#{value_type} #{name}"
  end

  def global_name
    "this->#{local_name}"
  end

  def global_definition
    [
      "typedef #{key_type} #{key_type_name}",
      "typedef #{index_type} #{index_type_name}",
      "#{index_type_name} #{local_name}"
    ]
  end

  def remove
    render_partial 'remove_from_index'
  end

  def get_method
    "#{get_method_signature_local(true)} {\nreturn #{get_method_body};\n}"
  end

  def assign_from_tid
    assign_from('tid', 'tid')
  end

  def assign_from(tid_variable, value_variable)
    "#{global_name}[#{global_key_tuple(tid_variable)}] = #{value_variable}"
  end

  def global_key_tuple(tid_variable)
    "std::make_tuple(#{columns.comma { |c| c.global_access(tid_variable) }})"
  end

  def local_key_tuple
    "std::make_tuple(#{columns.comma(&:local_to_index_key_value)})"
  end

  def needs_constructor?
    respond_to?(:constructor_assignments)
  end

  def columns
    @columns ||= PresentationEnumerable.new(@index.columns.map { |c| ColumnPresenter.create(c, table) })
  end

  # Factory method
  def self.create(index, table)
    presenter = self.new(index, table)
    if index.type
      index_module = "Schema::#{index.type.to_s.camelize}IndexPresenter".safe_constantize
      presenter.extend index_module if index_module
    end
    presenter.extend PartialIndexPresenter if index.partial_columns.any?
    presenter.extend ComparingIndexPresenter if presenter.columns.any? { |c| c.respond_to?(:comparer_parameter) }
    return presenter
  end
end
end
