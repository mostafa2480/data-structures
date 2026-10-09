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

int push_front(struct LinkedList *linked_list, int value)
{
	if (linked_list == NULL) return -1;

	if (linked_list->head == NULL)
	{
		linked_list->head = malloc(sizeof(struct Node));
		if (linked_list->head == NULL) return 0;

		linked_list->tail = linked_list->head;
		linked_list->head->prev = NULL;
		linked_list->head->next = NULL;
	}
	else
	{
		linked_list->head->prev = malloc(sizeof(struct Node));
		if (linked_list->head->prev == NULL) return 0;

		linked_list->head->prev->prev = NULL;
		linked_list->head->prev->next = linked_list->head;
		linked_list->head = linked_list->head->prev;
	}
	linked_list->head->value = value;

	return 1;
}

int push_back(struct LinkedList *linked_list, int value)
{
	if (linked_list == NULL) return -1;

	if (linked_list->tail == NULL)
	{
		linked_list->tail = malloc(sizeof(struct Node));
		if (linked_list->tail == NULL) return 0;

		linked_list->head = linked_list->tail;
		linked_list->tail->prev = NULL;
		linked_list->tail->next = NULL;
	}
	else
	{
		linked_list->tail->next = malloc(sizeof(struct Node));
		if (linked_list->tail->next == NULL) return 0;

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
