#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
	int value;
	struct Node *prev;
	struct Node *next;
} Node;

typedef struct
{
	Node *head;
	Node *tail;
} LinkedList;

LinkedList *create_list();
void clear_list(LinkedList *list);
void free_list(LinkedList *list);
int push_front(LinkedList *list, int value);
int push_back(LinkedList *list, int value);
int pop_front(LinkedList *list);
int pop_back(LinkedList *list);
int insert_before(LinkedList *list, Node *node, int value);
int insert_after(LinkedList *list, Node *node, int value);
int delete_node(LinkedList *list, Node *node);

#endif
