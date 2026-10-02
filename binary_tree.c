#include <stdlib.h>

struct Node
{
	int data;
	struct Node *ch1;
	struct Node *ch2;
};

struct Node* create_tree(int depth);
int int_pow(int base, int exponent);

int main()
{
	struct Node *root = create_tree(3);
	if (root == NULL) return 1;

	return 0;
}

struct Node* create_tree(int depth)
{
	int node_count = int_pow(2, depth) - 1;
	struct Node *nodes[node_count];
	struct Node *root = malloc(sizeof(struct Node));
	if (root == NULL) return NULL;

	nodes[0] = root;

	int value = 1;
	root->data = value++;
	for (int i = 0; i < depth - 1; i++)
	{
		int index = int_pow(2, i) - 1;
		for (int j = index; j < 2 * index + 1; j++)
		{
			nodes[j]->ch1 = malloc(sizeof(struct Node));
			if (nodes[j]->ch1 == NULL) return NULL;
			nodes[j]->ch2 = malloc(sizeof(struct Node));
			if (nodes[j]->ch2 == NULL) return NULL;

			nodes[j]->ch1->data = value++;
			nodes[j]->ch2->data = value++;

			nodes[2 * j + 1] = nodes[j]->ch1;
			nodes[2 * j + 2] = nodes[j]->ch2;
		}
	}

	for (int i = node_count - int_pow(2, depth - 1); i < node_count; i++)
	{
		nodes[i]->ch1 = NULL;
		nodes[i]->ch2 = NULL;
	}

	return root;
}

int int_pow(int base, int exponent)
{
	int result = 1;
	for (int i = 0; i < exponent; i++) result *= base;
	return result;
}
