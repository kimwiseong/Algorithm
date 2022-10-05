#define MAX_SIZE 10
#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;

Element stack[MAX_SIZE] = { 0 };
int top = -1;

void push(Element e);
Element pop();
void stack_show();

void push(Element e) {
	if (top >= MAX_SIZE - 1) {
		printf("\n Stack is full !!! \n");
		return;
	}
	stack[++top] = e;
}

Element pop() {
	if (top < 0) {
		printf(" Stack is empty !!! \n");
		return;
	}
	return stack[top--];
}

void stack_show() {
	printf("\n");
	for (int i = 0; i <= top; i++) 
		printf("%c ", stack[i]);
	printf("\n");
}