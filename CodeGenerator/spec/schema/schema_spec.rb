require 'spec_helper'
require 'schema/schema'

describe 'Schema' do
  it 'should take tables to initialize' do
    tables = [1, 2, 3]
    schema = Schema::Schema.new(tables)
    schema.tables.must_equal tables
  end

  it 'should have only read only attributes' do
    schema = Schema::Schema.new([])
    schema.wont_respond_to 'tables='
  end
end

