module Query
module Expression
class TableScan
  include Rendering

  attr_reader :consumer, :table_name

  def initialize(table_name, consumer, attributes)
    @table_name = table_name
    @consumer = consumer
    @attributes = attributes
    consumer.set_input(self)
  end

  def produce
    render_template('table_scan')
  end

  def tid
    "#{table_name}_tid"
  end

  def store
    "tpcc->#{table_name}"
  end

  def attributes
    @attributes
      .map { |a| "auto #{a.value} = #{a.get_value(store, tid)};" }
      .join("\n");
  end
end
end
end
