#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define ELETYPE int

struct node {
  ELETYPE elem;
  struct node* next;
};

struct header {
  int size; /* how many nodes do we have */
  struct node* next;
};

struct node; /* node */
typedef struct node* pnode;
typedef struct node* position;

struct header; /* header */
typedef struct header* linkedlist;

linkedlist create_list();
void init_list(linkedlist list);
void make_list_empty(linkedlist list);
int is_empty(linkedlist list);
position find(linkedlist list, ELETYPE elem);
void list_add_elem(linkedlist list, position pos, ELETYPE elem);
void list_del_elem(linkedlist list, position pos);
void list_print_all(linkedlist list);

#endif
