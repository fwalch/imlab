require 'expression'

module Query
module LastnameOrderSumQuery
  def self.get_query_tree
    ## IUs
    # for customer selection
    c_last = Expression::Attribute.new('c_last', 'char*')
    c_last_const = Expression::Constant.new('"BARBARBAR"', 'std::string')

    # for customer <-> order join
    o_c_id = Expression::Attribute.new('o_c_id', 'int32_t')
    c_id = Expression::Attribute.new('c_id', 'int32_t')

    # for order <-> orderline join
    ol_w_id = Expression::Attribute.new('ol_w_id', 'int32_t')
    ol_d_id = Expression::Attribute.new('ol_d_id', 'int32_t')
    ol_o_id = Expression::Attribute.new('ol_o_id', 'int32_t')
    o_w_id = Expression::Attribute.new('o_w_id', 'int32_t')
    o_d_id = Expression::Attribute.new('o_d_id', 'int32_t')
    o_id = Expression::Attribute.new('o_id', 'int32_t')

    # for print
    ol_quantity = Expression::Attribute.new('ol_quantity', 'int64_t')
    ol_amount = Expression::Attribute.new('ol_amount', 'int64_t')

    ## QUERY TREE
    # SELECT SUM(ol_quantity * ol_amount)
    sum_iu = Expression::Attribute.new('sum', 'int64_t')
    select = Expression::Print.new([sum_iu])
    mul = Expression::Multiplication.new([ol_quantity, ol_amount])
    sum = Expression::Sum.new(select, [mul], sum_iu)

    # WHERE ol_w_id = o_w_id AND o_d_id = ol_d_id AND o_id = ol_o_id
    ol_o_join = Expression::HashJoin.new(sum, [o_w_id, o_d_id, o_id], [ol_w_id, ol_d_id, ol_o_id])

    # FROM orderline
    orderline = Expression::TableScan.new('orderLines', ol_o_join, [ol_w_id, ol_d_id, ol_o_id, ol_amount, ol_quantity])

    # WHERE o_c_id = c_id
    o_c_join = Expression::HashJoin.new(ol_o_join, [c_id], [o_c_id])

    # FROM order
    order = Expression::TableScan.new('orders', o_c_join, [o_c_id, o_w_id, o_d_id, o_id])

    # WHERE c_last = 'BARBARBAR'
    c_last_eql = Expression::Equal.new(c_last, c_last_const)
    customer_selection = Expression::Selection.new(o_c_join, c_last_eql)

    # FROM customer
    customer = Expression::TableScan.new('customers', customer_selection, [c_id, c_last])

    return select
  end
end
end
