require 'parser/table'
require 'hints'
require 'rendering'

module CodeGenerator
class Context
  include Hints
  include Rendering

  def initialize
    @tables = {}
  end

  def add_table(name)
    raise "Already added table #{name}" if @tables[name]
    @tables[name] = Table.new(name)
  end

  def add_index(index_name, table_name, column_names)
    raise "Table #{name} does not exist (yet); cannot add index" unless @tables[table_name]
    # TODO: support non-pk indexes
    #@tables[table_name].add_index(index_name, column_names)
  end

  def tables
    @tables.values
  end
end
end

