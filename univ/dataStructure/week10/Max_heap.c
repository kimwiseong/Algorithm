#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Max_heap.h"

void main() {
	char c, data;
	int key;
	Element item;
	printf("************* Command ************ \n");
	printf("I: Insert data, D: Delete max data \n");
	printf("P: Print heap, Q: Quit \n");
	printf("********************************** \n");
	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'I':
			printf("\n key and data: ");
			scanf("%d %c", &key, &data);
			item.key = key;
			item.data = data;
			insert_max_heap(item);
			break;
		case 'D':
			item = delete_max_heap();
			printf("\n Max: key %d, data %c \n", item.key, item.data);
			break;
		case 'P':
			printf("\n");
			max_heap_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}