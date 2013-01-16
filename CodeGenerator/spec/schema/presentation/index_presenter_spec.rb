require 'spec_helper'

require 'schema/presentation/index_presenter'

describe 'IndexPresenter' do
  it 'should pass through index attribute calls' do
    index = MiniTest::Mock.new
    index.expect(:name, 'index_name')

    presenter = Schema::IndexPresenter.new(index)

    presenter.name.must_equal 'index_name'
    index.verify
  end

  it 'should provide a factory method' do
    Schema::SomeIndexPresenter = Module.new
    index = Struct.new(:type).new(:some)
    presenter = Schema::IndexPresenter.create(index)
    presenter.kind_of?(Schema::SomeIndexPresenter).must_equal true
  end
end