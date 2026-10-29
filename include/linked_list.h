#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_Node
{
	int value;
	struct list_Node *prev;
	struct list_Node *next;
} list_Node;

typedef struct
{
	list_Node *head;
	list_Node *tail;
} LinkedList;

LinkedList *list_create_list();
void list_clear_list(LinkedList *list);
void list_free_list(LinkedList *list);
int list_push_front(LinkedList *list, int value);
int list_push_back(LinkedList *list, int value);
int list_pop_front(LinkedList *list);
int list_pop_back(LinkedList *list);
int list_insert_before(LinkedList *list, list_Node *node, int value);
int list_insert_after(LinkedList *list, list_Node *node, int value);
int list_delete_node(LinkedList *list, list_Node *node);

#endif
