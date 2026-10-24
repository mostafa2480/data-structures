typedef struct bst_Node
{
	int value;
	struct bst_Node *left;
	struct bst_Node *right;
} bst_Node;

bst_Node *bst_create_node(int value);
void bst_free_tree(bst_Node *root);
bst_Node *bst_insert(bst_Node *root, int value);
bst_Node *bst_find(bst_Node *root, int value);
int bst_node_count(bst_Node *root);
int bst_height(bst_Node *root);
void bst_traverse_preorder(bst_Node *root, void (*callback)(bst_Node *node));
void bst_traverse_inorder(bst_Node *root, void (*callback)(bst_Node *node));
void bst_traverse_postorder(bst_Node *root, void (*callback)(bst_Node *node));
void bst_traverse_level_order(bst_Node *root, void (*callback)(bst_Node *node));
