#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MINQUEUESIZE (5)

struct queue_record {
  int capacity;
  int front;
  int rear;
  int size; /* elements now we have */
  ELETYPE *array;
};

/*
 * return non-zero if the queue is not empty
 */
int is_empty(queue q) 
{
  return q->size == 0;
}

/*
 * return non-zero if queue is full
 */
int is_full(queue q)
{
  return q->size == q->capacity;
}

/*
 * make the queue empty
 */
void make_empty(queue q)
{
  q->size = 0;
  q->front = 0;
  q->rear = 0;
}

/*
 * get next position in the queue
 */
static int succ(queue q, int value)
{
  if (++value == q->capacity)
    value = 0;

  return value;
}

/*
 * enqueue a element in the queue 
 */
void enqueue(queue q, ELETYPE element)
{
  if (is_full(q)) {
    fprintf(stderr, "enqueue: the queue is full\n");
    exit(-1);
  } else {
    q->size++;
    q->rear = succ(q, q->rear);
    q->array[q->rear] = element;
  }
}

/*
 * return a pointer to the queue_record
 */
queue create_queue(int max_elements)
{
  queue q = malloc(sizeof(struct queue_record));
  if (q == NULL) {
    fprintf(stderr, "allocate memory failed\n");
    exit(-1);
  }

  q->array = malloc(sizeof(ELETYPE) * max_elements);
  if (q->array == NULL) {
    fprintf(stderr, "allocate memory failed\n");
    exit(-1);
  }

  /* set capacity */
  q->capacity = max_elements;

  return q;
}

/*
 * dispose the queue, release all the memory it has
 */
void dispose_queue(queue q)
{
  if (q == NULL)
    return; /* if the queue is NULL, do nothing */

  free(q->array);
  free(q);
}

/*
 * dequeue, but we don't return that element
 */
void dequeue(queue q)
{
  if(is_empty(q)) {
    fprintf(stderr, "dequeue: the queue is empty\n");
    exit(-1);
  }

  q->front = succ(q, q->front);
}

/*
 * we get the value of the front, but we don't dequeue
 */
ELETYPE front(queue q)
{
  if (is_empty(q)) {
    fprintf(stderr, "front: the queue is empty\n");
    exit(-1);
  }

  return q->array[q->front];
}

/*
 * dequeue, and return that element
 */
ELETYPE front_and_dequeue(queue q)
{
  ELETYPE result = front(q);
  dequeue(q);

  return result;
}

/*
 * print all the elements in the queue.
 * write for debug
 */
void print_queue(queue q)
{
  printf("the queue is :\n");
  int my_rear = q->rear;
  int my_front = q->front;

  while (my_rear != my_front) {
    if (my_front + 1 > q->capacity)
      my_front = 0;
    printf("%d -> ", q->array[my_front++]);
  }

  printf("NULL\n");
}
