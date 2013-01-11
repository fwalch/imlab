class Formatter
  INDENT_COUNT = 2
  INDENT_CHAR = ' '

  attr_reader :renderer

  def initialize(renderer)
    @renderer = renderer
  end

  def render
    indent = 0
    renderer.render.split("\n").map do |line|
      indent -= 1 if line =~ /}\s*;?\s*$/

      indentation = ''
      (INDENT_COUNT*indent).times { indentation += INDENT_CHAR } unless line =~ /^\s*$/

      indent += 1 if line =~ /{\s*$/

      indentation + line.strip
    end.join("\n") + "\n" # Newline at end of file
  end
end
