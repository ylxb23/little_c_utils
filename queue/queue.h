#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

struct queue_record;
typedef struct queue_record *queue;
#define ELETYPE int

int is_empty(queue q);
int is_full(queue q);
queue create_queue(int max_elements);
void dispose_queue(queue q);
void make_empty(queue q);
void enqueue(queue q, ELETYPE element);
ELETYPE front(queue q);
void dequeue(queue q);
ELETYPE front_and_dequeue(queue q);
void print_queue(queue q);

#endif
