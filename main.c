#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include <time.h>
#include "queue.h"

const int DIVISOR = 61;
typedef const node* (*search_function)(const node*, int*);


const node* breadth_first_search(const node* node, int* depth) {
  struct node* root = prefilled_root_node();
  queue* queue = init_queue(); 

  put(queue, root);
  
  while(has_items(queue)) {
    (*depth)++;
    struct node* item = remove_item(queue);

    if (item->value % DIVISOR == 0) {
      delete_queue(queue);
      return item;
    }

    if (item->left != NULL) put(queue, item->left);
    if (item->right != NULL) put(queue, item->right);
  }

  delete_queue(queue);
  return NULL;
}

const node* depth_first_search(const node* node, int* depth) {
  (*depth)++;

  if (node == NULL) return NULL;
 
  if (node->value % DIVISOR == 0) return node;

  const struct node* left = depth_first_search(node->left, depth);
  if (left != NULL) return left;

  const struct node* right = depth_first_search(node->right, depth); 
  return right;
}

int execute_iteration(search_function search){
  srand(time(0));
  int depth = 0;
  node* root = prefilled_root_node(); 
  const node* node = search(root, &depth);
 
  /*
  if (node == NULL) {
    printf("not found\n");
  } else {
    printf("found value: %d\n", node->value);
  }

  printf("Search count is %d\n", depth);
  */

  delete_node(root);
  
  return depth;
}

void test(const char* algo, search_function search) {
  const int runs = 10000;
  int results[runs];
  int sum;

  for (int i=0; i < runs;i++) {
    int result = execute_iteration(search);
    results[i] = result;
    sum += result;
  }

  printf("%s -> Average search count is %d\n", algo, sum/runs);

}

int main() {
  test("DFS", depth_first_search);
  test("BFS", breadth_first_search);

  return 0;
}
