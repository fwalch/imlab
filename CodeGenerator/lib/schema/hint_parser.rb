module Schema
class HintParser
  PARTIAL_INDEXES = 'partial_indexes'
  MULTI_INDEXES = 'multi_indexes'

  def initialize(schema)
    @tables = schema.table_factories
  end

  def add_hints(hints)
    return unless hints

    hints.each do |table_name, table_hints|
      if @tables[table_name]
        if table_hints[PARTIAL_INDEXES]
          table_hints[PARTIAL_INDEXES].each do |index_name, index_columns|
            columns = get_columns(index_columns)
            @tables[table_name].index_factories[index_name].set_partial_columns(columns)
          end
        end

        if table_hints[MULTI_INDEXES]
          table_hints[MULTI_INDEXES].each do |index_name, index_columns|
            columns = get_columns(index_columns)
            @tables[table_name].add_index(index_name, columns).set_multi
          end
        end
      end
    end
  end

  private
  def get_columns(index_columns)
    index_columns.split(',').map { |c| c.strip }
  end
end
end
