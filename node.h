#include<stdint.h>

struct node {
  struct node* left;
  struct node* right;
  uint32_t value;
};

struct node* new_node();
void delete_node(struct node*);

void init_nodes(int count, struct node*);
struct node* prefilled_root_node();

void print_nodes(struct node*);

