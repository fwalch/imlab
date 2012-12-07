require 'spec_helper'
require 'schema/index'

describe 'Index' do
  it 'should take a name, columns and a type to initialize' do
    columns = ['a', 'b']
    index = Schema::Index.new('index_name', columns, :indextype)
    index.name.must_equal 'index_name'
    index.columns.must_equal columns
    index.type.must_equal :indextype
  end

  it 'should have only read only attributes' do
    index = Schema::Index.new('index_name', ['a', 'b'], :indextype)
    index.wont_respond_to 'name='
    index.wont_respond_to 'columns='
    index.wont_respond_to 'type='
  end
end

