require 'spec_helper'

require 'schema/parser/column_factory'

describe 'ColumnFactory' do
  it 'should take a name to initialize' do
    factory = Schema::ColumnFactory.new('column_name')
    factory.column_name.must_equal 'column_name'
  end

  it 'should only have read-only attributes' do
    factory = Schema::ColumnFactory.new('column_name')
    factory.wont_respond_to 'column_name='
  end

  it 'should allow column type integer' do
    factory = Schema::ColumnFactory.new('column_name')
    factory.set_integer
    factory.create_column.wont_be_nil
  end

  it 'should allow column type timestamp' do
    factory = Schema::ColumnFactory.new('column_name')
    factory.set_timestamp
    factory.create_column.wont_be_nil
  end

  it 'should allow column type char' do
    factory = Schema::ColumnFactory.new('column_name')
    factory.set_char(16)
    factory.create_column.wont_be_nil
  end

  it 'should allow column type char' do
    factory = Schema::ColumnFactory.new('column_name')
    factory.set_varchar(16)
    factory.create_column.wont_be_nil
  end

  it 'should allow column type numeric' do
    factory = Schema::ColumnFactory.new('column_name')
    factory.set_numeric(4,2)
    factory.create_column.wont_be_nil
  end
end
