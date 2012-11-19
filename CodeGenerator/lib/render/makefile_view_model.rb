require 'render/template_renderer'

class MakefileViewModel
  TEMPLATE_PATH = File.join(File.dirname(__FILE__), '..', 'templates', 'template.mk.erb')

  attr_reader :prefix

  def initialize(prefix, source_files)
    @prefix = prefix
    @source_files = source_files
  end

  def source_files
    @source_files.join(' ')
  end

  def get_binding
    binding
  end

  def get_renderer
    TemplateRenderer.new(File.open(TEMPLATE_PATH).read, self)
  end
end
