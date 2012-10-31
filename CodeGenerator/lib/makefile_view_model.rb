module CodeGenerator
  class MakefileViewModel
    def initialize(source_files)
      @source_files = source_files
    end

    def source_files
      @source_files.join(' ')
    end

    def generation_time
      Time.now.utc.to_s
    end

    def get_binding
      binding
    end
  end
end
