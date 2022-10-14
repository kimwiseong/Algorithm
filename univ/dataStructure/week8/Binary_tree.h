#define boolean unsigned char
#define true 1
#define false 0

typedef int Element;

typedef struct tree_node *tree_pointer;
typedef struct tree_node {
	Element data;
	tree_pointer left;
	tree_pointer right;
}tree_node;

tree_pointer build_simple_tree();
int bt_count(tree_pointer ptr);
int bt_sum(tree_pointer ptr);
int bt_height(tree_pointer ptr);
void bt_show_preorder(tree_pointer ptr);
void bt_free(tree_pointer ptr);

tree_pointer build_simple_tree() {
	tree_pointer n1 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n2 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n3 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n4 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n5 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n6 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n7 = (tree_pointer)malloc(sizeof(tree_node));

	n1->data = 10; n1->left = n2; n1->right = n3;
	n2->data = 20; n2->left = n4; n2->right = n5;
	n3->data = 30; n3->left = n6; n3->right = n7;
	n4->data = 40; n4->left = NULL; n4->right = NULL;
	n5->data = 50; n5->left = NULL; n5->right = NULL;
	n6->data = 60; n6->left = NULL; n6->right = NULL;
	n7->data = 70; n7->left = NULL; n7->right = NULL;

	return n1;
}

int bt_count(tree_pointer ptr) {
	if (ptr == NULL) return 0;
	return(1 + bt_count(ptr->left) + bt_count(ptr->right));
}

int sum = 0;
int bt_sum(tree_pointer ptr) {
	if (ptr) {
		sum += ptr->data;
		bt_sum(ptr->left);
		bt_sum(ptr->right);
	}
	return sum;
}

int bt_height(tree_pointer ptr) {
	int height = 0;
	if (ptr) 
		height = 1 + max(bt_height(ptr->left), bt_height(ptr->right));
	return height;
}


void bt_show_preorder(tree_pointer ptr) {
	if (ptr) {
		printf(" %d ", ptr->data);
		bt_show_preorder(ptr->left);
		bt_show_preorder(ptr->right);
	}
}

void bt_free(tree_pointer ptr) {
	if (ptr) {
		bt_free(ptr->left);
		bt_free(ptr->right);
		printf("free node with item %d \n", ptr->data);
	}
	free(ptr);
}