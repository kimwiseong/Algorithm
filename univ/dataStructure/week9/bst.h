typedef struct tree_node *tree_pointer;
typedef struct tree_node {
	int key;
	char data;
	tree_pointer left;
	tree_pointer right;
}tree_node;
tree_pointer root; 


void bst_insert(int key, char data);
char bst_search(int key);
void bst_show_inorder(tree_pointer ptr);

void bst_insert(int key, char data) {
	tree_pointer r = root;
	tree_pointer temp = (tree_pointer)malloc(sizeof(tree_node));
	temp->data = data;
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;

	if (root == NULL) {
		root = temp;
		return;
	}

	tree_pointer t = NULL;
	while (r != NULL) {
		if (key == r->key) return;

		t = r;
		if (r->key > key) r = r->left;
		else r = r->right;
	}

	if (t->key > key) t->left = temp;
	else t->right = temp;
}

char bst_search(int key) {
	tree_pointer temp = root;
	while (temp != NULL) {
		if (temp->key == key) return temp->data;
		if (temp->key > key) temp = temp->left;
		else temp = temp->right;
	}
	return NULL;
}

void bst_show_inorder(tree_pointer ptr) {
	if (ptr == NULL) return;
	
	bst_show_inorder(ptr->left);
	printf(" %d %c \n", ptr->key, ptr->data);
	bst_show_inorder(ptr->right);
}

