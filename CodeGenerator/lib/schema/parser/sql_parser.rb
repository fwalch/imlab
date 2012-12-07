require 'schema/parser/SQLLexer'
require 'schema/parser/SQLParser'
require 'schema/parser/tree_visitor'
require 'schema/parser/schema_factory'

module Schema
class SqlParser
  def parse(schema_sql, factory_callback=nil)
    lexer = SQL::Lexer.new(schema_sql)
    parser = SQL::Parser.new(lexer)
    output = parser.statements()

    schema_factory = SchemaFactory.new
    visitor = TreeVisitor.new(schema_factory)
    visitor.visit(output.tree)

    factory_callback.call(schema_factory) if factory_callback

    schema_factory.create_schema
  end
end
end
