module CodeGenerator
module ViewModel
  module Common
    def initialize(table)
      @table = table
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

    def get_index_get_signature(index, parameters, range_index, class_name=nil)
      index_type = class_name ? "#{class_name}::#{index.name}IndexType" : "#{index.name}IndexType"
      return_type = range_index ? "std::pair<#{index_type}::iterator, #{index_type}::iterator>" : 'uint64_t'
      method_name = index.name == Table::PRIMARY_KEY_INDEX_NAME ? 'get' : "getBy#{titleize(index.name)}"
      if class_name
       "#{return_type} #{class_name}::#{method_name}(#{parameters})"
      else
        "#{return_type} #{method_name}(#{parameters})"
      end
    end
  end
end
end
