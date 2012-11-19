gem 'minitest'

$: << File.join(File.dirname(__FILE__), '..', 'lib')
$: << File.join(File.dirname(__FILE__), '..', 'gen')

require 'minitest/spec'
require 'minitest/autorun'
