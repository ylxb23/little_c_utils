#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/*
 * create list without initialize it.
 */
linkedlist create_list()
{
  linkedlist list = malloc(sizeof(struct header));
  if (list == NULL) {
    fprintf(stderr, "create_list: allocate memory failed");
    return NULL;
  }

  return list;
}

/*
 * initialize the given linkedlist header.
 */
void init_list(linkedlist list)
{
  assert(list != NULL);
  list->size = 0;
  list->next = NULL;
}

/*
 * delete all nodes header holds, then set size to 0.
 */
void make_list_empty(linkedlist list)
{
  assert(list != NULL);
  pnode head = list->next;
  pnode tmp;

  while (head != NULL) {
    tmp = head->next;
    free(head);
    head = tmp;
  }

  list->size = 0;
}

/*
 * check if the give list is empty.
 */
int is_empty(linkedlist list)
{
  assert(list != NULL);
  return list->next == NULL;
}

/*
 * return the positon which node equals to elem.
 */
position find(linkedlist list, ELETYPE elem)
{
  assert(list != NULL);

  pnode tmp = list->next;
  while (tmp != NULL) {
    if (memcmp((char *)&tmp->elem, (char *)&elem, sizeof(elem)) == 0)
      return tmp;
    tmp = tmp->next;
  }

  return NULL;
}

/*
 * add elem into list after the given position.
 */
void list_add_elem(linkedlist list, position pos, ELETYPE elem)
{
  assert(list != NULL);
  assert(pos != NULL);

  pnode tmp = malloc(sizeof(struct node));
  tmp->elem = elem;
  tmp->next = pos->next;

  pos->next = tmp;

  list->size++;
}

/*
 * delete the node in the given position
 * but actually what we do is copy the data in next node and then delete it.
 * of course, the next node can't be the tail node.
 */
void list_del_elem(linkedlist list, position pos)
{
  assert(list != NULL);
  assert(pos != NULL);
  if (pos->next = NULL) {
    /* it's tail node. All right. */
    pnode tmp = list->next;
    assert(tmp != NULL);
    while (tmp->next != NULL && tmp->next != pos)
      tmp = tmp->next; /* loop until the next node is pos */
    /* now tmp is the last but one */
    free(tmp->next);
    tmp->next = NULL;
  } else {
    pos->elem = pos->next->elem;
    pos->next = pos->next->next;
    free(pos->next);
    list->size--;
  }
}

/*
 * print the entire list
 */
void list_print_all(linkedlist list)
{
  if (list == NULL) {
    printf("the given list is empty\n");
    return;
  }

  printf("the given list is:\n");
  /* easy for debug, assume ELETYPE is int */
  pnode tmp = list->next;
  while (tmp != NULL) {
    printf("%d -> ", tmp->elem);
    tmp = tmp->next;
  }
  printf("NULL\n");
}
