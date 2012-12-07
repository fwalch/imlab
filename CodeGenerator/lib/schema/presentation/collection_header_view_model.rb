require 'common/presentation/template_renderer'

class CollectionHeaderViewModel
  TEMPLATE_PATH = File.join(File.dirname(__FILE__), '..', 'templates', 'collection.h.erb')

  def initialize(header_files)
    @header_files = header_files
  end

  def includes
    @header_files
      .map { |h| "#include \"#{h}\"" }
      .join("\n")
  end

  def namespace
    ENV['NAMESPACE'].upcase
  end

  def header_constant
    "_#{namespace}_SCHEMA_H_"
  end

  def get_binding
    binding
  end

  def get_renderer
    TemplateRenderer.new(File.open(TEMPLATE_PATH).read, self)
  end
end
