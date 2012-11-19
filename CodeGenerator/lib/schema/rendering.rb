require 'render/header_view_model'
require 'render/collection_header_view_model'
require 'render/source_view_model'
require 'render/makefile_view_model'
require 'render/template_renderer'

module Schema
module Rendering
  TEMPLATE_PATH = File.join(File.dirname(__FILE__), 'templates')
  TABLE_TEMPLATES = ['template.cpp.erb', 'template.h.erb'].map { |t| File.join(TEMPLATE_PATH, t) }
  MAKEFILE_NAME = 'generated.mk'
  HEADER_NAME = 'schema.h'

  def get_renderers
    renderers = {}
    tables.each do |table|
      TABLE_TEMPLATES.each do |template|
        view_model = get_view_model(template, table)
        if view_model
          file_name = view_model.file_name
          renderers[file_name] = get_template_renderer(template, view_model)
        end
      end
    end

    files = renderers.keys
    renderers[MAKEFILE_NAME] = get_makefile_renderer(files)
    renderers[HEADER_NAME] = get_header_renderer(files)

    return renderers
  end

  private
  def get_view_model(template, table)
    template.match(/\.cpp/) do
      return SourceViewModel.new(table)
    end
    template.match(/\.h/) do
      return HeaderViewModel.new(table)
    end
  end

  def get_makefile_renderer(files)
    cpp_files = files.select { |f| f.match(/\.cpp/) }
    view_model = MakefileViewModel.new('SCHEMA', cpp_files)
    view_model.get_renderer
  end

  def get_header_renderer(files)
    h_files = files.select { |f| f.match(/\.h/) }
    view_model = CollectionHeaderViewModel.new('SCHEMA', h_files)
    view_model.get_renderer
  end

  def get_template_renderer(path, view_model)
    template = File.new(path).read
    TemplateRenderer.new(template, view_model)
  end
end
end
