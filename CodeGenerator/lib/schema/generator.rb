$: << File.dirname(__FILE__)

require 'parser/parser'
require 'yaml'

module Schema
module Generator
  def self.run(args)
    raise ArgumentError, "<sql-schema-file> <hints-file> <output-dir>" if args.length != 3

    schema = File.new(args[0]).read
    hints = YAML.load_file(args[1])
    output_dir = args[2]

    parser = Parser.new
    context = parser.parse(schema)
    context.add_hints(hints)

    context.get_renderers.each do |file_name, renderer|
      output = renderer.render
      file_path = File.join(output_dir, file_name)
      File.write(file_path, output)
    end
  end
end
end
