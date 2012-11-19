require 'render/template_renderer'

class CollectionHeaderViewModel
  TEMPLATE_PATH = File.join(File.dirname(__FILE__), '..', 'templates', 'collection.h.erb')

  attr_reader :header_constant

  def initialize(constant, header_files)
    @header_constant = constant
    @header_files = header_files
  end

  def includes
    @header_files
      .map { |h| "#include \"#{h}\"" }
      .join("\n")
  end

  def get_binding
    binding
  end

  def get_renderer
    TemplateRenderer.new(File.open(TEMPLATE_PATH).read, self)
  end
end
