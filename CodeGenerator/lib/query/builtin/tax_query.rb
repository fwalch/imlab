require 'expression'

module Query
module TaxQuery
  def self.get_query_tree
    ## IUs
    # for print
    w_name = Expression::Attribute.new('w_name', 'char*')
    d_name = Expression::Attribute.new('d_name', 'char*')
    d_tax = Expression::Attribute.new('d_tax', 'int64_t')

    # for warehouse <-> district join
    w_id = Expression::Attribute.new('w_id', 'int32_t')
    d_w_id = Expression::Attribute.new('d_w_id', 'int32_t')

    # for warehouse selection
    w_id_const = Expression::Constant.new('1', 'int32_t')

    ## QUERY TREE
    # SELECT w_name, d_name, d_tax
    select = Expression::Print.new([w_name, d_name, d_tax])

    # WHERE w_id = d_w_id
    w_id_eql = Expression::Equal.new(w_id, d_w_id)
    d_w_join = Expression::CrossProduct.new(select)
    district_selection = Expression::Selection.new(d_w_join, w_id_eql)

    # FROM district
    district = Expression::TableScan.new('districts', district_selection, [d_name, d_tax, d_w_id])

    # WHERE w_id = 1
    w_id_eql = Expression::Equal.new(w_id, w_id_const)
    warehouse_selection = Expression::Selection.new(d_w_join, w_id_eql)

    # FROM warehouse
    warehouse = Expression::TableScan.new('warehouses', warehouse_selection, [w_name, w_id])

    return select
  end
end
end
