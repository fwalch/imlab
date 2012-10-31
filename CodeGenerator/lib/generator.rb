require 'parser/parser'
require 'yaml'

module CodeGenerator
  class Generator
    def self.run(args)
      raise ArgumentError, "generate: [sql-schema-file] [hints-file] [output-dir]" if args.length != 3

      schema = File.new(args[0]).read
      hints = YAML.load_file(args[1])
      output_dir = args[2]
      generator = Generator.new(schema, hints, output_dir)
      generator.execute
    end

    def initialize(schema, hints, output_dir)
      @schema = schema
      @hints = hints
      @output_dir = output_dir
    end

    def execute
      # Parse SQL
      parser = Parser.new
      context = parser.parse(@schema)
      context.add_hints(@hints)

      context.get_renderers.each do |file_name, renderer|
        output = renderer.render
        file_path = File.join(@output_dir, file_name)
        File.write(file_path, output)
      end
    end
  end
end

