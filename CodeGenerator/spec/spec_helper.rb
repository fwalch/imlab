require 'active_support/core_ext' # TODO: should not be necessary due to Bundler?

$: << File.join(File.dirname(__FILE__), '..', 'lib')
$: << File.join(File.dirname(__FILE__), '..', 'gen')

require 'minitest/spec'
require 'minitest/autorun'
