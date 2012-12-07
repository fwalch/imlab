require 'spec_helper'
require 'schema/table'

describe 'Table' do
  it 'should take name, columns and indexes to initialize' do
    indexes = [1, 2, 3]
    columns = [1, 2, 3]
    table = Schema::Table.new('table_name', columns, indexes)
    table.name.must_equal 'table_name'
    table.columns.must_equal columns
    table.indexes.must_equal indexes
  end

  it 'should have only read only attributes' do
    table = Schema::Table.new('table_name', [], [])
    table.wont_respond_to 'name='
    table.wont_respond_to 'columns='
    table.wont_respond_to 'indexes='
  end
end

