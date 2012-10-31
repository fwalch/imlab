require 'spec_helper'

require 'code_generator/template_renderer'

describe 'TemplateRenderer' do
  it 'should render the template with given variables' do
    view_model = Class.new do
      def var
        "text"
      end

      def get_binding
        binding
      end
    end.new
    renderer = TemplateRenderer.new("<%= var %>;", view_model)
    renderer.render.must_equal "text;"
  end
end
