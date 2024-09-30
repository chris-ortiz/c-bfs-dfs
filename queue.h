#ifndef QUEUE_H
#define QUEUE_H 

#include <stdbool.h>

typedef struct queue queue;
struct queue {
  void** items;
  int current_size;
  int max_size;
};

queue* init_queue();
void delete_queue(queue*);
int put(queue*, void*); 
void* remove_item(queue*); 
bool has_items(const queue*); 

#endif
