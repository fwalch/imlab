require 'spec_helper'

require 'schema/parser/index_factory'

describe 'IndexFactory' do
  it 'should take a name and columns to initialize' do
    columns = ['a', 'b']
    factory = Schema::IndexFactory.new('index_name', columns)
    factory.index_name.must_equal 'index_name'
    factory.column_names.must_equal columns
  end

  it 'should only have read-only attributes' do
    factory = Schema::IndexFactory.new('index_name', ['a', 'b'])
    factory.wont_respond_to 'index_name='
    factory.wont_respond_to 'column_names='
    factory.wont_respond_to 'index_type='
  end

  it 'should allow multi-index type' do
    factory = Schema::IndexFactory.new('column_name', ['a', 'b'])
    factory.set_multi
    factory.create_index([]).wont_be_nil
  end

  it 'should allow partial index type' do
    factory = Schema::IndexFactory.new('column_name', ['a', 'b'])
    factory.set_partial
    factory.create_index([]).wont_be_nil
  end

  it 'should have a default index type' do
    factory = Schema::IndexFactory.new('column_name', ['a', 'b'])
    factory.create_index([]).wont_be_nil
  end
end
