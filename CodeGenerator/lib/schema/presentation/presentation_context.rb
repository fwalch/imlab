require 'schema/presentation/collection_header_view_model'
require 'schema/presentation/schema_presenter'
require 'common/presentation/makefile_view_model'
require 'common/presentation/template_renderer'
require 'common/presentation/formatter'

module Schema
class PresentationContext
  TEMPLATE_PATH = File.join(File.dirname(__FILE__), '..', 'templates')
  SOURCE_TEMPLATE = File.join(TEMPLATE_PATH, 'template.cpp.erb')
  HEADER_TEMPLATE = File.join(TEMPLATE_PATH, 'template.h.erb')
  MAKEFILE_NAME = 'generated.mk'
  HEADER_NAME = 'schema.h'

  attr_reader :schema

  def initialize(schema)
    @schema = SchemaPresenter.new(schema)
  end

  def get_renderers
    renderers = {}
    schema.tables.each do |table|
      renderers[table.source_file_name] = get_template_renderer(SOURCE_TEMPLATE, table)
      renderers[table.header_file_name] = get_template_renderer(HEADER_TEMPLATE, table)
    end

    files = renderers.keys
    renderers[MAKEFILE_NAME] = get_makefile_renderer(files)
    renderers[HEADER_NAME] = get_header_renderer(files)

    return renderers
  end

  private
  def get_makefile_renderer(files)
    cpp_files = files.select { |f| f.match(/\.cpp/) }
    view_model = MakefileViewModel.new(cpp_files)
    view_model.get_renderer
  end

  def get_header_renderer(files)
    h_files = files.select { |f| f.match(/\.h/) }
    view_model = CollectionHeaderViewModel.new(h_files)
    view_model.get_renderer
  end

  def get_template_renderer(path, view_model)
    template = File.new(path).read
    Formatter.new(TemplateRenderer.new(template, view_model))
  end
end
end
