class Node
  include Enumerable
  attr_accessor :value, :left, :right
  
  def initialize(value)
    @value = value
  end
  
  def each
    @left.each { |n| yield n } if @left
    yield self
    @right.each { |n| yield n} if @right
  end

  def insert_node(new_value)
    if (@value > new_value)
      if !@left
        @left = Node.new(new_value)
        return @left
      end
      @left.insert_node(new_value)
    else
      if !@right
        @right = Node.new(new_value)
        return @right
      end
      @right.insert_node(new_value)
    end
  end
  
  def print_nodes
    self.each do |x|
      puts "node: #{x.value}"
      puts "left: #{x.left.value}" if x.left
      puts "right: #{x.right.value}" if x.right
      puts "---------"
    end
  end
  
  def count_nodes
    count = 0
    self.each { |x| count = count + 1 }
    return count
  end

end

def compare_trees(node, other)
  node.zip(other).each do |node, other|
    if node.value != other.value
      return false
    end
  end
  return true
end

rootA = Node.new(10)
rootA.insert_node(12)
rootA.insert_node(1)
rootA.insert_node(10)
rootA.insert_node(17)
rootA.insert_node(3)
count = 0
rootA.print_nodes
puts "There are #{rootA.count_nodes} nodes in Tree A"

rootB = Node.new(10)
rootB.insert_node(12)
rootB.insert_node(1)
rootB.insert_node(10)
rootB.insert_node(17)
rootB.insert_node(3)
puts "There are #{rootB.count_nodes} nodes in Tree B"

rootC = Node.new(10)
rootC.insert_node(3)
rootC.insert_node(1)
rootC.insert_node(0)
rootC.insert_node(1)
puts "There are #{rootC.count_nodes} nodes in Tree C"

puts "A = B: #{compare_trees(rootA,rootB)}"
puts "A = C: #{compare_trees(rootA,rootC)}"