require 'spec_helper'

require 'schema/parser/table_factory'

describe 'TableFactory' do
  it 'should take a name to initialize' do
    factory = Schema::TableFactory.new('table_name')
    factory.table_name.must_equal 'table_name'
  end

  it 'should not have default values' do
    factory = Schema::TableFactory.new('table_name')
    factory.column_factories.must_be_empty
    factory.index_factories.must_be_empty
  end

  it 'should add columns with a name' do
    factory = Schema::TableFactory.new('table_name')
    factory.add_column('column_name').wont_be_nil
    factory.column_factories.wont_be_empty
  end

  it 'should create a table' do
    factory = Schema::TableFactory.new('table_name')
    factory.create_table.must_be_instance_of Schema::Table
  end

  it 'should add indexes' do
    factory = Schema::TableFactory.new('table_name')
    columns = ['column1']
    factory.add_index('index_name', columns).wont_be_nil
    factory.index_factories.wont_be_empty
  end
end
