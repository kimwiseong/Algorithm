#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "adj_matrix.h"
void main()
{
	char c;
	int i, v;
	front = rear = NULL;
	build_simple_graph();
	printf("********* Command *********\n");
	printf("D: DFS, B: BFS, Q: Quit\n");
	printf("***************************\n");
	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'D':
			printf("\n Start vertex: ");
			scanf("%d", &v);
			for (i = 0; i < MAX_VERTICES; i++) visited[i] = false;
			dfs(v);
			printf("\n");
			break;
		case 'B':
			printf("\n Start vertex: ");
			scanf("%d", &v);
			for (i = 0; i < MAX_VERTICES; i++) visited[i] = false;
			bfs(v);
			printf("\n");
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}