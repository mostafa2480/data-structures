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
	LinkedList *list = malloc(sizeof(LinkedList));
	if (list == NULL) exit(1);

	list->head = NULL;
	list->tail = NULL;
	return list;
}

void clear_list(LinkedList *list)
{
	if (list == NULL) return;

	if (list->head == NULL) return;

	Node *temp;
	while (list->head != NULL)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
	}

	list->tail = NULL;
}

void free_list(LinkedList *list)
{
	clear_list(list);
	free(list);
}

int push_front(LinkedList *list, int value)
{
	if (list == NULL) return 0;

	if (list->head == NULL)
	{
		list->head = malloc(sizeof(Node));
		if (list->head == NULL) exit(1);

		list->tail = list->head;
		list->head->prev = NULL;
		list->head->next = NULL;
	}
	else
	{
		list->head->prev = malloc(sizeof(Node));
		if (list->head->prev == NULL) exit(1);

		list->head->prev->prev = NULL;
		list->head->prev->next = list->head;
		list->head = list->head->prev;
	}
	list->head->value = value;

	return 1;
}

int push_back(LinkedList *list, int value)
{
	if (list == NULL) return 0;

	if (list->tail == NULL)
	{
		list->tail = malloc(sizeof(Node));
		if (list->tail == NULL) exit(1);

		list->head = list->tail;
		list->tail->prev = NULL;
		list->tail->next = NULL;
	}
	else
	{
		list->tail->next = malloc(sizeof(Node));
		if (list->tail->next == NULL) exit(1);

		list->tail->next->prev = list->tail;
		list->tail->next->next = NULL;
		list->tail = list->tail->next;
	}
	list->tail->value = value;

	return 1;
}

int pop_front(LinkedList *list)
{
	if (list == NULL) return -1;

	if (list->head == NULL) return 0;

	if (list->head == list->tail)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		return 1;
	}

	list->head = list->head->next;
	free(list->head->prev);
	list->head->prev = NULL;
	return 1;
}

int pop_back(LinkedList *list)
{
	if (list == NULL) return -1;

	if (list->tail == NULL) return 0;

	if (list->tail == list->head)
	{
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;
		return 1;
	}

	list->tail = list->tail->prev;
	free(list->tail->next);
	list->tail->next = NULL;
	return 1;
}

int insert_before(LinkedList *list, Node *node, int value)
{
	if (list == NULL) return 0;

	if (list->head == NULL)
	{
		if (node != NULL) return 0;
		
		list->head = malloc(sizeof(Node));
		if (list->head == NULL) exit(1);

		list->tail = list->head;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->head->value = value;
		return 1;
	}

	if (node == NULL) return 0;

	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) exit(1);

	new_node->prev = node->prev;
	new_node->next = node;

	node->prev = new_node;
	if (new_node->prev != NULL) new_node->prev->next = new_node;
	else list->head = new_node;

	new_node->value = value;

	return 1;
}

int insert_after(LinkedList *list, Node *node, int value)
{
	if (list == NULL) return 0;

	if (list->head == NULL)
	{
		if (node != NULL) return 0;
		
		list->head = malloc(sizeof(Node));
		if (list->head == NULL) exit(1);

		list->tail = list->head;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->head->value = value;
		return 1;
	}

	if (node == NULL) return 0;

	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL) exit(1);

	new_node->prev = node;
	new_node->next = node->next;

	node->next = new_node;
	if (new_node->next != NULL) new_node->next->prev = new_node;
	else list->tail = new_node;

	new_node->value = value;

	return 1;
}

int delete_node(LinkedList *list, Node *node)
{
	if (list == NULL) return -1;

	if (node == NULL) return 0;

	if (node == list->head)
	{
		if (node == list->tail)
		{
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
			return 1;
		}

		list->head = list->head->next;
		free(list->head->prev);
		list->head->prev = NULL;
		return 1;
	}

	if (node == list->tail)
	{
		list->tail = list->tail->prev;
		free(list->tail->next);
		list->tail->next = NULL;
		return 1;
	}

	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	return 1;
}
