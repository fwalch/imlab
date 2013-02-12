class Formatter
  INDENT_COUNT = 2
  INDENT_CHAR = ' '

  attr_reader :renderer

  def initialize(renderer)
    @renderer = renderer
  end

  def render
    indent = 0
    previous_line_empty = false
    renderer.render.split("\n").select do |line|
      current_line_empty = line =~ /^\s*$/
      if previous_line_empty and current_line_empty
        false
      else
        previous_line_empty = current_line_empty
        true
      end
    end.map do |line|
      indent -= 1 if line =~ /}\s*;?\s*$/

      indentation = ''
      (INDENT_COUNT*indent).times { indentation += INDENT_CHAR } unless line =~ /^\s*$/

      indent += 1 if line =~ /{\s*$/

      indentation + line.strip
    end.join("\n") + "\n" # Newline at end of file
  end
end
