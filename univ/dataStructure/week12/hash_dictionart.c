#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_dictionary.h"
void main()
{
	char c, fname[20];
	char key[100], *data;
	int wcount;
	
	printf("************* Command ************* \n");
	printf("R: Read data, S: Search data \n");
	printf("P: Print hash table, Q: Quit \n");
	printf("*********************************** \n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'R':
			printf("\n Dictionary file name: ");
			scanf("%s", fname);
			wcount = build_dictionary(fname);
			printf(" Total number of words: %d \n", wcount);
			break;
		case 'S':
			printf("\n Word: ");
			scanf("%s", key);
			num_comparison = 0;
			data = hash_search(key);
			if (data) printf(" Meaning: %s \n", data);
			else printf(" No such word ! \n");
			printf(" Tatal number of comparison = %d \n", num_comparison);
			break;
		case 'P':
			printf("\n");
			hash_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}

int build_dictionary(char *fname)
{
	int i = 0; 
	char key[100], data[200];
	FILE *ifp;
	if ((ifp = fopen(fname, "r")) == NULL) {
		printf("No such file ! \n");
		exit(1);
	}
	while (fscanf(ifp, "%s %s", key, data) == 2) {
		hash_insert(key, data);
		i++;
	}
	fclose(ifp);
	return(i);
}

void hash_insert(char *key, char *data) {
	int i, hash_value;
	i = hash_value = hash(key);
	while (strlen(hash_table[i].key) != 0) {
		if (strcmp(hash_table[i].key, key) == 0) {
			printf(" overlap!! \n");
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			return;
		}
	}
	strcpy(hash_table[i].key, key);
	strcpy(hash_table[i].data, data);
}

char * hash_search(char *key) {
	int i, hash_value;
	i = hash_value = hash(key);
	printf(" hash value = %d \n", hash_value);
	while (strlen(hash_table[i].key) != 0) {
		num_comparison++;
		if (strcmp(hash_table[i].key, key) == 0) {
			return hash_table[i].data;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) { 
			return NULL;
		}
	}
}

void hash_show() {
	for (int i = 0;i < TABLE_SIZE; i++) 
		printf("hash_table[%d] : <%s> \n", i, hash_table[i].key);
}

int hash(char *key) {
	return(transform(key) % TABLE_SIZE);
}

int transform(char *key) {
	int number = 0;
	while (*key)
		number += *key++;
	return number;
}