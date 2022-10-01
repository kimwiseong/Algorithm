#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include"ex1.h"
#define _CRT_SECURE_NO_WARNINGS

void main() {

	char c;

	printf("Reading record from grade.txt... \n6 records have read. \n\n");

	read_record(fname);
	
	printf("**************************** \n");
	printf("P: Print all records \n");
	printf("S: Search record \n");
	printf("C: Change record \n");
	printf("W: Write record \n");
	printf("Q: Save and quit \n");
	printf("**************************** \n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);

		switch (c) {
		case 'P':
			print_record();
			break;
		case 'S':
			search_record();
			break;
		case 'C':
			change_record();
			break;
		case 'W':
			write_record(fname);
			break;
		case 'Q':
			printf("\n");
			exit(1);
			break;
		default : 
			printf("\nUnknown command ! \n");
			break;
		}
	}
	
}