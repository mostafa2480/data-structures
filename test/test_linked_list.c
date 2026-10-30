#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

void test_list_create_list()
{
	LinkedList *list = list_create_list();
	assert(list != NULL);
	assert(list->head == NULL);
	assert(list->tail == NULL);
	free(list);
}

void test_list_push_front()
{
	LinkedList *list = list_create_list();
	list_push_front(list, 1);
	assert(list->head != NULL);
	assert(list->tail != NULL);
	assert(list->head == list->tail);
	assert(list->head->prev == NULL);
	assert(list->head->next == NULL);
	assert(list->head->value == 1);
	list_push_front(list, 2);
	assert(list->head != NULL);
	assert(list->tail != NULL);
	assert(list->head != list->tail);
	assert(list->head->prev == NULL);
	assert(list->head->next == list->tail);
	assert(list->tail->prev == list->head);
	assert(list->tail->next == NULL);
	assert(list->head->value == 2);
	assert(list->tail->value == 1);
	list_push_front(list, 3);
	assert(list->head != NULL);
	assert(list->tail != NULL);
	assert(list->head->prev == NULL);
	assert(list->head->next != NULL);
	assert(list->head->next == list->tail->prev);
	assert(list->head->next->prev == list->head);
	assert(list->head->next->next == list->tail);
	assert(list->tail->next == NULL);
	assert(list->head->value == 3);
	assert(list->head->next->value == 2);
	assert(list->tail->value == 1);
	list_clear_list(list);
	int total = 1000;
	for (int i = 1; i <= total; i++) list_push_front(list, i);
	list_Node *current = list->head;
	int expected_value = total;
	int count = 0;
	while(current != NULL)
	{
		assert(current->value == expected_value);
		if (current->next != NULL)
		{
			assert(current->next->prev == current);
			assert(current->next->value == expected_value - 1);
		}
		else assert(current == list->tail);
		if (current->prev != NULL) assert(current->prev->next == current);
		else assert(current == list->head);
		expected_value--;
		count++;
		current = current->next;
	}
	assert(count == total);
	list_clear_list(list);
	free(list);
}

void run_linked_list_tests()
{
	printf("running linked list tests...\n");

	test_list_create_list();
	test_list_push_front();

	printf("linked list tests passed\n");
}
