#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;

typedef struct queue *queue_pointer;
typedef struct queue {
	Element item;
	queue_pointer link;
}queue;
queue_pointer front, rear;

void addq(Element e);
Element deleteq();
void queue_show();
boolean is_queue_empty();

void addq(Element e) {
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	temp->item = e;
	temp->link = NULL;

	if (front == NULL) front = rear = temp;
	else {
		rear->link = temp;
		rear = temp;
	}
}

Element deleteq() {
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	Element a;	

    a = front->item;
	temp = front;
	front = front->link;

	free(temp);
	return a;
}

void queue_show() {
	printf("\n");
	if (is_queue_empty()) {
		printf(" Queue is empty !!!\n");
		return;
	}
	for (queue_pointer temp = front; temp != NULL; temp = temp->link)
		printf(" %c", temp->item);
	printf("\n");
}

boolean is_queue_empty() {
	if (front == NULL) return true;
	else return false;
}