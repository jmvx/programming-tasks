#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// nodes of a tree have a value and two child nodes
typedef struct Node {
  struct Node* lefty;
  struct Node* righty;
  int value;
} Node;

// user can define pre or post order traversal
typedef enum TraversalOrder {
  PREORDER,
  POSTORDER
} TraversalOrder;

// function pointer node_func that takes in two arguments
// node* and void* (optional - can be NULL)
typedef void (*node_func)(Node* node, void* extra);

// allocate memory for node and assign values
Node* create_node(int v, Node* left, Node* right) {
  Node* n = malloc(sizeof(Node));
  // in case malloc fails
  if (!n) { 
    return NULL; 
  }
  // assign values and return the new node
  n->lefty = left;
  n->righty = right;
  n->value = v;
  return n;
}

// tree sort order: leftside < root < rightside
// if you reach a NULL left/right child node, create a new node
// otherwise, keep moving left/right
Node* insert_node(Node* current, int new_value) {
  Node** next = (new_value < current->value) ? &current->lefty : &current->righty;
  if (!*next) {
    *next = create_node(new_value, NULL, NULL);
    return *next;
  }
  insert_node(*next, new_value);
  return current;
}

// this is the MEGA function of walk_tree
// it takes in a root node, transversal order pref, a function pointer, and
// an optional extra pointer
void walk_tree(Node* current, TraversalOrder order, node_func f, void* extra) {
  if (!current) { 
    return; 
  } 
  // for printing the tree
  if (order == PREORDER) { 
    f(current, extra); 
  }
  if (current->lefty) {
    walk_tree(current->lefty, order, f, extra);
  } 
  if (current->righty) {
    walk_tree(current->righty, order, f, extra);
  }
  // for deleting (don't delete current until after i'm done with it)
  if (order == POSTORDER) { 
    f(current, extra); 
  }
  return;
}

bool compare_trees(Node* current, Node* other) {
  // check if both nodes are not null before comparing them
  if (current && other) {
    if (current->value != other->value) {
      return false;
    }
    // if either side of the tree has a not matching pair, return false
    bool leftside = compare_trees(current->lefty, other->lefty);
    bool rightside = compare_trees(current->righty, other->righty);
    return leftside && rightside;
  } 
  // if just one of the nodes is null, return false, otherwise, return true
  return !current && !other;
}

// function pointers point here (delete, print, count)!
void delete_node(Node* current, void* extra) {
  free(current);
}

void print_node(Node* current, void* extra) {
  printf("current node: %d\n", current->value);
  if (current->lefty) {
    printf("- left child: %d\n", current->lefty->value);
  } 
  if (current->righty) {
    printf("- right child: %d\n", current->righty->value);
  } 
}

void count_nodes(Node* current, void* extra) {
  int* count = (int*)extra;
  (*count)++;
}

// create three trees, count the nodes, print them out, compare, and delete
void test_trees() {
  Node* a = create_node(5, NULL, NULL);
  insert_node(a, 10);
  insert_node(a, 2);
  insert_node(a, 12);
  insert_node(a, 1);
  insert_node(a, 7);
  insert_node(a, 7);
  
  Node* b = create_node(5, NULL, NULL);
  insert_node(b, 10);
  insert_node(b, 2);
  insert_node(b, 12);
  insert_node(b, 1);
  insert_node(b, 7);
  insert_node(b, 7);
  
  Node* c = create_node(9, NULL, NULL);
  insert_node(c, 4);
  insert_node(c, 10);
  insert_node(c, 1);
  insert_node(c, 2);
  insert_node(c, 1);
  
  // print number of nodes in each tree
  int count = 0;
  walk_tree(a, PREORDER, count_nodes, &count);
  printf("Number of nodes in A: %d\n", count);
  count = 0;
  walk_tree(b, PREORDER, count_nodes, &count);
  printf("Number of nodes in B: %d\n", count);
  count = 0;
  walk_tree(c, PREORDER, count_nodes, &count);
  printf("Number of nodes in C: %d\n", count);
  
  // print the nodes in each tree
  printf("-----A-----\n");
  walk_tree(a, PREORDER, print_node, NULL);
  printf("-----B-----\n");
  walk_tree(b, PREORDER, print_node, NULL);
  printf("-----C-----\n");
  walk_tree(c, PREORDER, print_node, NULL);
  printf("------------\n");
  
  // compare the trees
  printf("A = B? %s\n", compare_trees(a, b) ? "YES" : "NO");
  printf("B = C? %s\n", compare_trees(b, c) ? "YES" : "NO");
  printf("A = C? %s\n", compare_trees(a, c) ? "YES" : "NO");
  
  // free the memories
  walk_tree(a, POSTORDER, delete_node, NULL);
  walk_tree(b, POSTORDER, delete_node, NULL);
  walk_tree(c, POSTORDER, delete_node, NULL);
}

int main () {
  
  test_trees();
  printf("Press Any Key to Continue\n");
  getchar();
  printf("Thanks!\n");
  
  return 0;
}