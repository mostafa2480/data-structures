#include <stdlib.h>
#include "binary_search_tree.h"

bst_Node *bst_create_node(int value)
{
	bst_Node *node = malloc(sizeof(bst_Node));
	if (node == NULL) return NULL;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}
