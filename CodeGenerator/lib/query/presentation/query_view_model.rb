require 'rendering'

module Query
class QueryViewModel
  include Rendering

  def initialize(query_name, query_tree)
    @query_name = query_name
    @query_tree = query_tree
  end

  def header_file
    "#{@query_name}.h"
  end

  def method_name
    @query_name.camelize(:lower)
  end

  def header_constant
    @query_name.upcase
  end

  def query_body
    @query_tree.produce
  end

  def get_binding
    binding
  end

  def namespace
    ENV['NAMESPACE']
  end
end
end
