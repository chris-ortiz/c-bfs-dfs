#include "queue.h"
#include <stdint.h>
#include <stdlib.h>

const uint16_t MAX_SIZE = 1000;

struct queue* init_queue() {
  struct queue* queue = malloc(sizeof(struct queue));
  queue->max_size = MAX_SIZE;
  queue->items = malloc(MAX_SIZE * sizeof(void*));
  return queue;
}

int put(struct queue* queue, void* element) {
  if (queue->current_size == MAX_SIZE) {
    return -1;
  }
  queue->items[queue->current_size] = element;
  queue->current_size++;

  return 0;
}

void* remove_item(struct queue* queue) {
  if (queue->current_size == 0) return NULL;

  void* first = queue->items[0];

  for (int i=0; i < queue->current_size - 1; i++) {
    queue->items[i] = queue->items[i+1];
  }

  queue->items[queue->current_size - 1] = NULL;
  queue->current_size--;

  return first;
} 

void delete_queue(struct queue* queue) {
  free(queue->items);
  free(queue);
}

bool has_items(struct queue* queue) {
  return queue->current_size > 0;
}
