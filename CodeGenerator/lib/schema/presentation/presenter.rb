require 'common/presentation/template_renderer'

module Schema
class Presenter
  TEMPLATE_PATH = File.join(File.dirname(__FILE__), '..', 'templates')

  def get_binding
    binding
  end

  def render_partial(template_name)
    path = File.join(TEMPLATE_PATH, "_#{template_name}.cpp.erb")
    render_template(path)
  end

  def render_template(template_path)
    template = File.new(template_path).read
    TemplateRenderer.new(template, self).render
  end
end
end
