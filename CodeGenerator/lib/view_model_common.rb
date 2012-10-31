module CodeGenerator
module ViewModel
  module Common
    def initialize(table)
      @table = table
    end

    def generation_time
      Time.now.utc.to_s
    end

    def get_binding
      binding
    end

    def column_count
      @table.columns.count
    end

    def class_name
      "#{titleize(@table.name)}Store"
    end

    private
    def titleize(str)
      str.split(/(\W)/).map(&:capitalize).join
    end

    def codify(str)
      str.gsub(/\./, '_')
    end
  end
end
end
