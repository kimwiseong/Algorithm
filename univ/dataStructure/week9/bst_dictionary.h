typedef struct tree_node *tree_pointer;
typedef struct tree_node {
	char w1[100];
	char w2[100];
	tree_pointer left;
	tree_pointer right;
}tree_node;
tree_pointer root;


int build_dictionary(char *fname);
void bst_insert(char *w1, char *w2);
char * bst_search(char *w1);
void bst_show_inorder(tree_pointer ptr);

int build_dictionary(char *fname) {
	int i = 0;
	char e[100] = "", k[100] = "";
	FILE *ifp;

	ifp = fopen(fname, "r");
	while (fscanf(ifp, "%s %s", e, k) == 2) {
		bst_insert(e, k);
		i++;
	}

	fclose(ifp);
	return i;
}

void bst_insert(char *w1, char *w2) {
	tree_pointer r = root;
	tree_pointer temp = (tree_pointer)malloc(sizeof(tree_node));
	strcpy(temp->w1, w1);
	strcpy(temp->w2, w2);
	temp->left = NULL;
	temp->right = NULL;


	if (root == NULL) {
		root = temp;
		return;
	}

	tree_pointer t = NULL;
	while (r != NULL) {
		if (!strcmp(r->w1, w1))
			return;
		t = r;
        
		if (strcmp(r->w1, w1) > 0) r = r->left;
		else r = r->right;
	}

	if (strcmp(t->w1,w1) > 0) t->left = temp;
	else t->right = temp;
}

char * bst_search(char *w1) {
	tree_pointer temp = root;

	while (temp != NULL) {
		if (!strcmp(temp->w1, w1)) return temp->w2;

		if (strcmp(temp->w1, w1) > 0) temp = temp->left;
		else temp = temp->right;
	}
	return NULL;
}

void bst_show_inorder(tree_pointer ptr) {
	if (ptr == NULL) return;

	bst_show_inorder(ptr->left);
	printf(" %s %s \n", ptr->w1, ptr->w2);
	bst_show_inorder(ptr->right);
}