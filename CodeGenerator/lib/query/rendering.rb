require 'erb'

module Query
module Rendering
  TEMPLATE_PATH = File.join(File.dirname(__FILE__), 'templates')
  @@variable_name_counter = 0

  def render_template(template_name)
    file_name = "_#{template_name}.cpp.erb"
    file_path = File.join(TEMPLATE_PATH, file_name)
    content = File.open(file_path).read
    erb = ERB.new(content)
    erb.result binding
  end

  def indent(content)
    content.split("\n").map { |line| "  #{line}" }.join("\n")
  end

  # Helper method to generate variable names
  def v(identifier)
    @variable_names = {} unless @variable_names
    unless @variable_names[identifier]
      @@variable_name_counter += 1
      @variable_names[identifier] = "v_#{@@variable_name_counter}"
    end
    @variable_names[identifier]
  end
end
end
