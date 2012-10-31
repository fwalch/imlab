module CodeGenerator
module Hints
  PARTIAL_INDEXES = 'partial_indexes'

  def add_hints(hints)
    hints.each do |table_name, table_hints|
      if @tables[table_name] && table_hints[PARTIAL_INDEXES]
        table_hints[PARTIAL_INDEXES].each do |index_name, index_columns|
          columns = index_columns.split(',').map { |c| c.strip }
          @tables[table_name].add_partial_index(index_name, columns)
        end
      end
    end
  end
end
end
