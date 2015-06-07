#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
  linkedlist list = create_list();
  init_list(list);
  list->next = malloc(sizeof(struct node));
  list->next->elem = 0;
  list->next->next = NULL;
  list_add_elem(list, list->next, 1);
  list_add_elem(list, list->next, 2);
  list_add_elem(list, list->next, 3);
  position result = find(list, 3);
  if (result != NULL)
    printf("find it: %d\n", result->elem);
  result = find(list, 5);
  if (result != NULL)
    printf("find it: %d\n", result->elem);

  list_print_all(list);
}
