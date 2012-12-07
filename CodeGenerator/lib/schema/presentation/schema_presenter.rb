require 'schema/presentation/table_presenter'

module Schema
class SchemaPresenter < Presenter
  def initialize(schema)
    @schema = schema
  end

  def namespace
    ENV['NAMESPACE']
  end

  def tables
    @tables ||= @schema.tables.map { |t| TablePresenter.new(t, self) }
  end
end
end
