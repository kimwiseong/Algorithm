#define MAX_SIZE 10
#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;

Element queue[MAX_SIZE];
int front = 0;
int rear = 0;

void addq(Element e);
Element deleteq();
void queue_show();

void addq(Element e) {
	if (front == (rear + 1) % MAX_SIZE) {
		printf("\n Queue is full !!!\n");
		return;
	}
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = e;
}

Element deleteq() {
	if (front == rear) {
		printf("\n Queue is empty !!!\n");
		return;
	}
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

void queue_show() {
	printf("\n");
	
	if (front < rear) {
		for (int i = front + 1; i <= rear; i++)
			printf("%c ", queue[i]);
	}
	else if (front > rear) {
		for (int i = front + 1; i < MAX_SIZE; i++)
			printf(" %c", queue[i]);
		for (int i = 0; i <= rear; i++)
			printf(" %c", queue[i]);
	}
	else {
		printf(" Queue is empty !!!\n");
	}
}