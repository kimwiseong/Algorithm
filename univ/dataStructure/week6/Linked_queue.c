#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Linked_queue.h"

void main() {
	char c, e;
	front = rear = NULL;
	printf("********** Command ********** \n");
	printf("+<c>: AddQ c, -: DeleteQ, \n");
	printf("S: Show, Q: Quit \n");
	printf("***************************** \n");

	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);
		switch (c) {
		case '+':
			e = _getch(); _putch(e);
			addq(e);
			break;
		case '-':
			if (is_queue_empty()) {
				printf("\n Queue is empty !!! \n");
			}
			else {
				e = deleteq();
				printf("\n %c", e);
			}
			break;
		case 'S': queue_show(); break;
		case 'Q': printf("\n"); exit(1);
		default: break;
		}
	}
}