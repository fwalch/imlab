require 'common/presentation/template_renderer'

class MakefileViewModel
  TEMPLATE_PATH = File.join(File.dirname(__FILE__), '..', 'templates', 'template.mk.erb')

  def initialize(source_files, namespace=nil)
    @namespace = namespace || ENV['NAMESPACE']
    @source_files = source_files
  end

  def source_files
    @source_files.join(' ')
  end

  def get_binding
    binding
  end

  def namespace
    @namespace.upcase
  end

  def namespace_directory
    @namespace.downcase
  end

  def get_renderer
    TemplateRenderer.new(File.open(TEMPLATE_PATH).read, self)
  end
end
