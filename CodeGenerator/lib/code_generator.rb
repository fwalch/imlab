require 'rubygems'
require 'bundler'

Bundler.require

$: << File.join(File.dirname(__FILE__), '..', 'gen')
require 'generator'

