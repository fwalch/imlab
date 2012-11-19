QUERIES = ['tax_query', 'lastname_order_sum_query']
QUERIES.each { |q| require "builtin/#{q}" }

module Query
module Builtin
  def self.get_query_trees
    Hash[QUERIES.map { |q| [q, "Query::#{q.camelize}".constantize.get_query_tree] }]
  end
end
end
