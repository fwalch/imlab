require 'spec_helper'

require 'schema/presentation/column_presenter'

describe 'ColumnPresenter' do
  it 'should pass through column attribute calls' do
    column = MiniTest::Mock.new
    column.expect(:name, 'column_name')

    presenter = Schema::ColumnPresenter.new(column)

    presenter.name.must_equal 'column_name'
    column.verify
  end

  it 'should provide a factory method' do
    Schema::SomeColumnPresenter = Module.new
    column = Struct.new(:type).new(:some)
    presenter = Schema::ColumnPresenter.create(column)
    presenter.kind_of?(Schema::SomeColumnPresenter).must_equal true
  end
end
