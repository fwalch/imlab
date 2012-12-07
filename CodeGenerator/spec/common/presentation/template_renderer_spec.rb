require 'spec_helper'

require 'common/presentation/template_renderer'

describe 'TemplateRenderer' do
  it 'should render the template with given variables' do
    view_model = Class.new do
      def var
        "Text"
      end

      def get_binding
        binding
      end
    end.new
    renderer = TemplateRenderer.new("a <%= var %>;", view_model)
    renderer.render.must_equal "a Text;"
  end
end
