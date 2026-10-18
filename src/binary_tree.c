#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node *ch1;
	struct Node *ch2;
} Node;

Node *create_tree(int depth, int value);
void free_tree(Node *node);

int main()
{
	Node *root = create_tree(4, 1);
	if (root == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}
	free_tree(root);
	return 0;
}

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
