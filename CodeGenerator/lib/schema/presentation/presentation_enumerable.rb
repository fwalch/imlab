module Schema
class PresentationEnumerable
  def initialize(collection)
    @collection = collection
  end

  def comma(&block)
    @collection.flat_map(&block).join(', ')
  end

  def comma_with_index(&block)
    i = -1
    @collection.flat_map do |element|
      block.call(i += 1, element)
    end.join(', ')
  end

  def line(&block)
    lines = @collection.flat_map(&block).select { |e| e && !e.empty? }.join(";\n")
    lines + ';' if lines and !lines.empty?
  end

  def block(&block)
    @collection.flat_map(&block).join("\n\n")
  end

  def each(&block)
    @collection.each(&block)
  end

  def empty?
    @collection.empty?
  end

  def any?(&block)
    @collection.any?(&block)
  end

  def count
    @collection.count
  end

  def select(&block)
    PresentationEnumerable.new(@collection.select(&block))
  end
end
end
