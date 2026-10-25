#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_search_tree.h"

void test_bst_create_node()
{
	bst_Node *node = bst_create_node(12);
	assert(node != NULL);
	assert(node->value == 12);
	assert(node->left == NULL);
	assert(node->right == NULL);
	free(node);
}

void run_binary_search_tree_tests()
{
	printf("running binary search tree tests...\n");
	test_bst_create_node();
	printf("binary search tree tests passed\n");
}
