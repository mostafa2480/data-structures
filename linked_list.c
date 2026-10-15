#include <stdlib.h>

struct Node
{
	int value;
	struct Node *prev;
	struct Node *next;
};

struct LinkedList
{
	struct Node *head;
	struct Node *tail;
};

int main()
{
	return 0;
}

struct LinkedList *create_list()
{
	struct LinkedList *linked_list = malloc(sizeof(struct LinkedList));
	if (linked_list == NULL) exit(1);

	linked_list->head = NULL;
	linked_list->tail = NULL;
	return linked_list;
}

void clear_list(struct LinkedList *linked_list)
{
	if (linked_list == NULL) return;

	if (linked_list->head == NULL) return;

	struct Node *temp;
	while (linked_list->head != NULL)
	{
		temp = linked_list->head;
		linked_list->head = linked_list->head->next;
		free(temp);
	}

	linked_list->tail = NULL;
}

void free_list(struct LinkedList *linked_list)
{
	clear_list(linked_list);
	free(linked_list);
}

int push_front(struct LinkedList *linked_list, int value)
{
	if (linked_list == NULL) return 0;

	if (linked_list->head == NULL)
	{
		linked_list->head = malloc(sizeof(struct Node));
		if (linked_list->head == NULL) exit(1);

		linked_list->tail = linked_list->head;
		linked_list->head->prev = NULL;
		linked_list->head->next = NULL;
	}
	else
	{
		linked_list->head->prev = malloc(sizeof(struct Node));
		if (linked_list->head->prev == NULL) exit(1);

		linked_list->head->prev->prev = NULL;
		linked_list->head->prev->next = linked_list->head;
		linked_list->head = linked_list->head->prev;
	}
	linked_list->head->value = value;

	return 1;
}

int push_back(struct LinkedList *linked_list, int value)
{
	if (linked_list == NULL) return 0;

	if (linked_list->tail == NULL)
	{
		linked_list->tail = malloc(sizeof(struct Node));
		if (linked_list->tail == NULL) exit(1);

		linked_list->head = linked_list->tail;
		linked_list->tail->prev = NULL;
		linked_list->tail->next = NULL;
	}
	else
	{
		linked_list->tail->next = malloc(sizeof(struct Node));
		if (linked_list->tail->next == NULL) exit(1);

		linked_list->tail->next->prev = linked_list->tail;
		linked_list->tail->next->next = NULL;
		linked_list->tail = linked_list->tail->next;
	}
	linked_list->tail->value = value;

	return 1;
}

int pop_front(struct LinkedList *linked_list)
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

int pop_back(struct LinkedList *linked_list)
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

int insert_before(struct LinkedList *linked_list, struct Node *node, int value)
{
	if (linked_list == NULL) return 0;

	if (linked_list->head == NULL)
	{
		if (node != NULL) return 0;
		
		linked_list->head = malloc(sizeof(struct Node));
		if (linked_list->head == NULL) exit(1);

		linked_list->tail = linked_list->head;
		linked_list->head->prev = NULL;
		linked_list->head->next = NULL;
		linked_list->head->value = value;
		return 1;
	}

	if (node == NULL) return 0;

	struct Node *new_node = malloc(sizeof(struct Node));
	if (new_node == NULL) exit(1);

	new_node->prev = node->prev;
	new_node->next = node;

	node->prev = new_node;
	if (new_node->prev != NULL) new_node->prev->next = new_node;
	else linked_list->head = new_node;

	new_node->value = value;

	return 1;
}

int insert_after(struct LinkedList *linked_list, struct Node *node, int value)
{
	if (linked_list == NULL) return 0;

	if (linked_list->head == NULL)
	{
		if (node != NULL) return 0;
		
		linked_list->head = malloc(sizeof(struct Node));
		if (linked_list->head == NULL) exit(1);

		linked_list->tail = linked_list->head;
		linked_list->head->prev = NULL;
		linked_list->head->next = NULL;
		linked_list->head->value = value;
		return 1;
	}

	if (node == NULL) return 0;

	struct Node *new_node = malloc(sizeof(struct Node));
	if (new_node == NULL) exit(1);

	new_node->prev = node;
	new_node->next = node->next;

	node->next = new_node;
	if (new_node->next != NULL) new_node->next->prev = new_node;
	else linked_list->tail = new_node;

	new_node->value = value;

	return 1;
}
