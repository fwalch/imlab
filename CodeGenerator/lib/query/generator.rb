$: << File.dirname(__FILE__)

require 'query/presentation/query_view_model'
require 'common/presentation/makefile_view_model'
require 'common/presentation/template_renderer'
require 'query/rendering'

module Query
class Generator
  TEMPLATE_PATH = File.join(File.dirname(__FILE__), 'templates')
  BUILTIN = 'builtin'
  MAKEFILE_NAME = 'generated_queries.mk'

  def self.run(args)
    raise CodeGeneratorArgumentError, "<query-name> <output-dir>" if args.length != 2

    query_name = args[0].underscore
    output_dir = args[1]

    Generator.new(query_name, output_dir).run
  end

  def initialize(query_name, output_dir)
    @query_name = query_name
    @output_dir = output_dir
  end

  def run
    @query_name == BUILTIN ? get_all_builtin_queries : get_builtin_query
  end

  def get_all_builtin_queries
    require 'builtin'
    query_trees = Builtin.get_query_trees
    query_trees.each do |query_name, query_tree|
      render_tree query_name, query_tree
    end
    generate_makefile query_trees.map { |query_name, _| query_name }
  end

  private
  def get_builtin_query
    require "query/builtin/#{@query_name}"

    query_module = "Query::#{@query_name.camelize}".constantize
    query_tree = query_module.get_query_tree

    render_tree @query_name, query_tree
    generate_makefile @query_name
  end

  def render_tree(query_name, query_tree)
    #TODO
    view_model = QueryViewModel.new(query_name, query_tree)
    header_file = "#{query_name}.h"
    source_file = "#{query_name}.cpp"
    header = TemplateRenderer.new(get_header_template, view_model)
    source = TemplateRenderer.new(get_source_template, view_model)

    {header_file => header, source_file => source}.each do |file_name, renderer|
      write_file file_name, renderer
    end
  end

  def generate_makefile(source_files)
    source_files = [source_files] unless source_files.respond_to? :map
    source_files = source_files.map { |f| "#{f}.cpp" }
    mk_view_model = MakefileViewModel.new(source_files, @query_name.upcase)
    makefile_renderer = mk_view_model.get_renderer
    write_file MAKEFILE_NAME, makefile_renderer
  end

  def write_file(file_name, renderer)
    output = renderer.render
    file_path = File.join(@output_dir, file_name)
    File.write(file_path, output)
  end

  def get_header_template
    File.open(File.join(TEMPLATE_PATH, 'template.h.erb')).read
  end

  def get_source_template
    File.open(File.join(TEMPLATE_PATH, 'template.cpp.erb')).read
  end
end
end
