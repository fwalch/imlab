require 'schema/parser/sql_parser'
require 'schema/hint_parser'
require 'schema/presentation/presentation_context'
require 'yaml'

module Schema
module Generator
  def self.run(args)
    raise CodeGeneratorArgumentError, "<sql-schema-file> <hints-file> <output-dir>" if args.length != 3

    schema_sql = File.new(args[0]).read
    hints = YAML.load_file(args[1])
    output_dir = args[2]

    parser = SqlParser.new
    schema = parser.parse(schema_sql, -> schema_factory { HintParser.new(schema_factory).add_hints(hints) })

    context = PresentationContext.new(schema)

    context.get_renderers.each do |file_name, renderer|
      output = renderer.render
      file_path = File.join(output_dir, file_name)
      File.write(file_path, output)
    end
  end
end
end
