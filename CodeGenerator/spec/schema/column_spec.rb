require 'spec_helper'
require 'schema/column'

describe 'Column' do
  it 'should take a name, datatype and attributes to initialize' do
    column = Schema::Column.new('column_name', :datatype, :attrs)
    column.name.must_equal 'column_name'
    column.type.must_equal :datatype
    column.attributes.must_equal :attrs
  end

  it 'should have only read only attributes' do
    column = Schema::Column.new('column_name', :datatype, :attrs)
    column.wont_respond_to 'name='
    column.wont_respond_to 'type='
    column.wont_respond_to 'attributes='
  end
end

