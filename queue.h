#include <stdbool.h>

struct queue {
  void** items;
  int current_size;
  int max_size;
};

struct queue* init_queue();
void delete_queue(struct queue*);
int put(struct queue*, void*); 
void* remove_item(struct queue*); 
bool has_items(struct queue*); 
