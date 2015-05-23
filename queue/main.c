#include <stdio.h>
#include "queue.h"

int main()
{
  int max_elements = 5;
  queue q = create_queue(max_elements);

  make_empty(q);
  enqueue(q, 1);
  enqueue(q, 1);
  enqueue(q, 1);
  dequeue(q);
  print_queue(q);
}

