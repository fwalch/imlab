require 'spec_helper'

require 'schema/parser/schema_factory'

describe 'SchemaFactory' do
  it 'should add tables with a name' do
    factory = Schema::SchemaFactory.new
    factory.add_table('table_name').wont_be_nil
    factory.table_factories.wont_be_empty
  end

  it 'should not have any tables by default' do
    factory = Schema::SchemaFactory.new
    factory.table_factories.must_be_empty
  end

  it 'should create a schema' do
    factory = Schema::SchemaFactory.new
    factory.create_schema.wont_be_nil
  end
end
