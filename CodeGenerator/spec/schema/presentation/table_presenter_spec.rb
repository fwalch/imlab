require 'spec_helper'

require 'schema/table'
require 'schema/column'
require 'schema/index'
require 'schema/presentation/table_presenter'

describe 'TablePresenter' do
  it 'should pass through table attribute calls' do
    table = MiniTest::Mock.new
    table.expect(:name, 'table_name')

    presenter = Schema::TablePresenter.new(table)

    presenter.name.must_equal 'table_name'
    table.verify
  end

  it 'should present columns' do
    columns = [Schema::Column.new('a', nil)]
    table = Schema::Table.new('table_name', columns, [])

    presenter = Schema::TablePresenter.new(table)
    presenter.columns.wont_be_empty
    presenter.columns.wont_equal columns
    presenter.columns.count.must_equal 1
  end

  it 'should present indexes' do
    indexes = [Schema::Index.new('a', ['a'], nil)]
    table = Schema::Table.new('table_name', [], indexes)

    presenter = Schema::TablePresenter.new(table)
    presenter.indexes.wont_be_empty
    presenter.indexes.wont_equal indexes
    presenter.indexes.count.must_equal 1
  end
end
