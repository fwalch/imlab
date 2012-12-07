require 'spec_helper'

require 'schema/schema'
require 'schema/presentation/schema_presenter'

describe 'SchemaPresenter' do
  it 'should present tables' do
    tables = [1, 2]
    schema = Schema::Schema.new(tables)

    presenter = Schema::SchemaPresenter.new(schema)
    presenter.tables.wont_be_empty
    presenter.tables.wont_equal tables
  end
end
