require 'erb'

class TemplateRenderer
  def initialize(template, view_model)
    @template = template
    @view_model = view_model
  end

  def render
    content = ERB.new @template
    content.result @view_model.get_binding
  end
end
