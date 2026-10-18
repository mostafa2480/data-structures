#include <stdlib.h>
#include "binary_tree.h"

Node *create_tree(int depth, int value)
{
	Node *node = malloc(sizeof(Node));
	if (node == NULL) return NULL;

	node->value = value;
	node->ch1 = NULL;
	node->ch2 = NULL;

	if (depth == 1) return node;

	node->ch1 = create_tree(depth - 1, value + 1);
	if (node->ch1 == NULL)
	{
		free(node);
		return NULL;
	}
	node->ch2 = create_tree(depth - 1, value + 2);
	if (node->ch2 == NULL)
	{
		free_tree(node->ch1);
		free(node);
		return NULL;
	}

	return node;
}

void free_tree(Node *node)
{
	if (node == NULL) return;
	free_tree(node->ch1);
	free_tree(node->ch2);
	free(node);
}
