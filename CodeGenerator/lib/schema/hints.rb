module Schema
module Hints
  PARTIAL_INDEXES = 'partial_indexes'
  MULTI_INDEXES = 'multi_indexes'

  def add_hints(hints)
    hints.each do |table_name, table_hints|
      if @tables[table_name]
        if table_hints[PARTIAL_INDEXES]
          table_hints[PARTIAL_INDEXES].each do |index_name, index_columns|
            columns = get_columns(index_columns)
            @tables[table_name].add_partial_index(index_name, columns)
          end
        end

        if table_hints[MULTI_INDEXES]
          table_hints[MULTI_INDEXES].each do |index_name, index_columns|
            columns = get_columns(index_columns)
            @tables[table_name].add_multi_index(index_name, columns)
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
