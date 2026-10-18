typedef struct Node
{
	int value;
	struct Node *ch1;
	struct Node *ch2;
} Node;

Node *create_tree(int depth, int value);
void free_tree(Node *node);
