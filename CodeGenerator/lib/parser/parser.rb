require 'SQLLexer'
require 'SQLParser'

require 'parser/tree_visitor'
require 'parser/context'

module CodeGenerator
class Parser
  def parse(schema)
    lexer = SQL::Lexer.new(schema)
    parser = SQL::Parser.new(lexer)
    output = parser.statements()

    context = Context.new
    visitor = TreeVisitor.new(context)
    visitor.visit(output.tree)

    return context
  end
end
end
