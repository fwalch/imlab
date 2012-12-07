require 'rubygems'
require 'bundler'

Bundler.require

class CodeGeneratorArgumentError < ArgumentError; end

class Generator
  def self.from_schema(args)
    require 'schema/generator'
    Schema::Generator.run(args)
  end

  def self.from_query(args)
    require 'query/generator'
    Query::Generator.run(args)
  end
end

