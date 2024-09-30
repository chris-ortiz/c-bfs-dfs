#ifndef NODE_H
#define NODE_H
#include<stdint.h>

typedef struct node node;

struct node {
  node* left;
  node* right;
  uint32_t value;
};

node* new_node();
void delete_node(node*);

void init_nodes(int count, node*);
node* prefilled_root_node();

void print_nodes(node*);

#endif
