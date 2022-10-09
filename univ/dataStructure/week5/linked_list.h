#define Element char
#define bool unsigned char
#define true 1
#define false 0

typedef struct list_node *list_pointer;
typedef struct list_node {
	Element data;
	list_pointer link;
}list_node;

void list_insert(list_pointer head, Element e);
void list_delete(list_pointer head, Element e);
list_pointer list_search(list_pointer head, Element e);
bool list_empty(list_pointer head);
void list_show(list_pointer head);

void list_insert(list_pointer head, Element e) {
	list_pointer ptr = (list_pointer)malloc(sizeof(list_node));

	ptr->data = e;
	ptr->link = head->link;
	head->link = ptr;
}

void list_show(list_pointer head) {
	printf("\n");
	if (list_empty(head)) {
		printf("List is Empty\n");
		return;
	}
	list_pointer p = head;
	while (p) {
		printf("%c ", p->data);
		p = p->link;
	}
}

list_pointer list_search(list_pointer head, Element e) {
	list_pointer p = head;
	while (p) {
		if (p->data == e) return p;
		p = p->link;
	}
	return NULL;
}

void list_delete(list_pointer head, Element e) {
	list_pointer now = head->link;
	list_pointer befo = head;

	while (now->data != e) {
		befo = now;
		now = now->link;
	}

	befo->link = now->link;
	free(now);
}

bool list_empty(list_pointer head) {
	if (head->link == NULL) return true;
	else return false;
}