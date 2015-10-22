function Node(value) {
  this.value = value;
}

Node.prototype = {
  walk_tree: function(func) {
    if (this.left) {
      this.left.walk_tree(func);
    }
    if (this.right) {
      this.right.walk_tree(func);
    }
    return func(this);
  },
  insert_node: function (new_value) {
    if (new_value < this.value) {
      if (this.left == undefined) {
        this.left = new Node(new_value);
        return this.left;
      } 
      if (this.left != undefined) {
        this.left.insert_node(new_value);
      }
    }
    else {
      if (this.right == undefined) {
        this.right = new Node(new_value);
        return this.right;
      }
      if (this.right != undefined) {
        this.right.insert_node(new_value);
      }
    }
    return this;
  },
  print_nodes: function(){
    this.walk_tree(function(node) {
      if (node.left) {
        console.log("%d->left:%d ", node.value, node.left.value);
      }
      if (node.right) {
        console.log("%d->right:%d ", node.value, node.right.value);
      }
      if (!node.left && !node.right) {
        console.log("%d->null", node.value);
      }
    });
  },
  count_nodes: function() {
    var count = 0
    this.walk_tree(function(node) {
      count = count+1;
    });
    return count;
  }
};

function compare_trees(node1, node2) {
  if (node1 && node2) {
    if (node1.value != node2.value) {
      return false;
    }
    leftside = compare_trees(node1.left, node2.left);
    rightside = compare_trees(node1.right, node2.right);
    return leftside && rightside;
  }
  return !node1 && !node2;
}

var root_a = new Node(5);
console.log("\nRoot value: %d", root_a.value);
root_a.insert_node(10);
root_a.insert_node(3);
root_a.insert_node(2);
root_a.insert_node(8);
var total = root_a.count_nodes();
console.assert(total == 5);

root_a.print_nodes();

var root_b = new Node(5);
console.log("\nRoot value: %d", root_b.value);
root_b.insert_node(10);
root_b.insert_node(3);
root_b.insert_node(2);
root_b.insert_node(8);
var total = root_b.count_nodes();
console.assert(total == 5);

root_b.print_nodes();

var root_c = new Node(1)
console.log("\nRoot value: %d", root_c.value);
root_c.insert_node(1);
root_c.insert_node(12);
root_c.insert_node(20);
root_c.insert_node(8);
root_c.insert_node(3);
var total = root_c.count_nodes();
console.assert(total == 6);

root_c.print_nodes();

var same = compare_trees(root_a, root_b);
var same2 = compare_trees(root_a, root_c);
var same3 = compare_trees(root_b, root_c);

console.assert(same == true);
console.assert(same2 == false);
console.assert(same3 == false);