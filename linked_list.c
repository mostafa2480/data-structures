#include <stdlib.h>

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

int main()
{
	return 0;
}

LinkedList *create_list()
{
	LinkedList *linked_list = malloc(sizeof(LinkedList));
	if (linked_list == NULL) exit(1);

	linked_list->head = NULL;
	linked_list->tail = NULL;
	return linked_list;
}

void clear_list(LinkedList *linked_list)
{
	if (linked_list == NULL) return;

	if (linked_list->head == NULL) return;

	Node *temp;
	while (linked_list->head != NULL)
	{
		temp = linked_list->head;
		linked_list->head = linked_list->head->next;
		free(temp);
	}

	linked_list->tail = NULL;
}

void free_list(LinkedList *linked_list)
{
	clear_list(linked_list);
	free(linked_list);
}

int push_front(LinkedList *linked_list, int value)
{
	if (linked_list == NULL) return 0;

	if (linked_list->head == NULL)
	{
		linked_list->head = malloc(sizeof(Node));
		if (linked_list->head == NULL) exit(1);

		linked_list->tail = linked_list->head;
		linked_list->head->prev = NULL;
		linked_list->head->next = NULL;
	}
	else
	{
		linked_list->head->prev = malloc(sizeof(Node));
		if (linked_list->head->prev == NULL) exit(1);

		linked_list->head->prev->prev = NULL;
		linked_list->head->prev->next = linked_list->head;
		linked_list->head = linked_list->head->prev;
	}
	linked_list->head->value = value;

	return 1;
}

int push_back(LinkedList *linked_list, int value)
{
	if (linked_list == NULL) return 0;

	if (linked_list->tail == NULL)
	{
		linked_list->tail = malloc(sizeof(Node));
		if (linked_list->tail == NULL) exit(1);

		linked_list->head = linked_list->tail;
		linked_list->tail->prev = NULL;
		linked_list->tail->next = NULL;
	}
	else
	{
		linked_list->tail->next = malloc(sizeof(Node));
		if (linked_list->tail->next == NULL) exit(1);

		linked_list->tail->next->prev = linked_list->tail;
		linked_list->tail->next->next = NULL;
		linked_list->tail = linked_list->tail->next;
	}
	linked_list->tail->value = value;

	return 1;
}

int pop_front(LinkedList *linked_list)
{
	if (linked_list == NULL) return -1;

	if (linked_list->head == NULL) return 0;

	if (linked_list->head == linked_list->tail)
	{
		free(linked_list->head);
		linked_list->head = NULL;
		linked_list->tail = NULL;
		return 1;
	}

	linked_list->head = linked_list->head->next;
	free(linked_list->head->prev);
	linked_list->head->prev = NULL;
	return 1;
}

int pop_back(LinkedList *linked_list)
{
	if (linked_list == NULL) return -1;

	if (linked_list->tail == NULL) return 0;

	if (linked_list->tail == linked_list->head)
	{
		free(linked_list->tail);
		linked_list->head = NULL;
		linked_list->tail = NULL;
		return 1;
	}

	linked_list->tail = linked_list->tail->prev;
	free(linked_list->tail->next);
	linked_list->tail->next = NULL;
	return 1;
}

int insert_before(LinkedList *linked_list, Node *node, int value)
{
	if (linked_list == NULL) return 0;

	if (linked_list->head == NULL)
	{
		if (node != NULL) return 0;
		
		linked_list->head = malloc(sizeof(Node));
		if (linked_list->head == NULL) exit(1);

		linked_list->tail = linked_list->head;
		linked_list->head->prev = NULL;
		linked_list->head->next = NULL;
		linked_list->head->value = value;
		return 1;
	}

	if (node == NULL) return 0;

	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) exit(1);

	new_node->prev = node->prev;
	new_node->next = node;

	node->prev = new_node;
	if (new_node->prev != NULL) new_node->prev->next = new_node;
	else linked_list->head = new_node;

	new_node->value = value;

	return 1;
}

int insert_after(LinkedList *linked_list, Node *node, int value)
{
	if (linked_list == NULL) return 0;

	if (linked_list->head == NULL)
	{
		if (node != NULL) return 0;
		
		linked_list->head = malloc(sizeof(Node));
		if (linked_list->head == NULL) exit(1);

		linked_list->tail = linked_list->head;
		linked_list->head->prev = NULL;
		linked_list->head->next = NULL;
		linked_list->head->value = value;
		return 1;
	}

	if (node == NULL) return 0;

	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) exit(1);

	new_node->prev = node;
	new_node->next = node->next;

	node->next = new_node;
	if (new_node->next != NULL) new_node->next->prev = new_node;
	else linked_list->tail = new_node;

	new_node->value = value;

	return 1;
}

int delete_node(LinkedList *linked_list, Node *node)
{
	if (linked_list == NULL) return -1;

	if (node == NULL) return 0;

	if (node == linked_list->head)
	{
		if (node == linked_list->tail)
		{
			free(linked_list->head);
			linked_list->head = NULL;
			linked_list->tail = NULL;
			return 1;
		}

		linked_list->head = linked_list->head->next;
		free(linked_list->head->prev);
		linked_list->head->prev = NULL;
		return 1;
	}

	if (node == linked_list->tail)
	{
		linked_list->tail = linked_list->tail->prev;
		free(linked_list->tail->next);
		linked_list->tail->next = NULL;
		return 1;
	}

	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	return 1;
}
