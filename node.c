#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

node* new_node() {
  node* node = malloc(sizeof(struct node));
  node->value = rand();
  return node;
}

void init_nodes(int count, node* node) {
  if (count == 0) return;
  
  struct node* new_root = new_node();

  if (rand() % 49 == 0) {
    node->left = new_root;
  } else {
    node->right = new_root;
  }

  init_nodes(--count, new_root);
}

void print_nodes(node* node) {
  if (node == NULL) return;

  printf("Node Value {%d}\n", node->value);
  
  printf("Moving left...\n");
  print_nodes(node->left);

  printf("Moving right...\n");
  print_nodes(node->right);
}

void delete_node(node* node) {
  if (node == NULL) return;

  delete_node(node->left);
  delete_node(node->right);

  free(node);
}

node* prefilled_root_node() {
  node* root = new_node();

  root->left = new_node();
  root->right = new_node();
  
  init_nodes(99, root->left);
  init_nodes(99, root->right);

  return root;
}
