#include<stdio.h>
#include<stdlib.h>
#include"Binary_tree.h"

void main() {
	char c;
	int n;
	tree_pointer t;
	t = build_simple_tree();

	printf("************* Command ************\n");
	printf("C: Count tree, A: Sum tree data \n");
	printf("H: Height of tree, S: Show preorder \n");
	printf("F: Free tree, Q: Quit \n");
	printf("**********************************\n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'C':
			n = bt_count(t);
			printf("\n Total number of node = %d \n", n);
			break;
		case 'A':
			n = bt_sum(t);
			printf("\n Sum of tree data = %d \n", n);
			sum = 0; 
			break;
		case 'H':
			n = bt_height(t);
			printf("\n Height of tree = %d \n", n);
			break;
		case 'S':
			printf("\n");
			bt_show_preorder(t);
			printf("\n");
			break;
		case 'F':
			printf("\n");
			bt_free(t);
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}