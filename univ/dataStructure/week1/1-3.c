#include<stdio.h>

void main() {
	int i, max_index;
	int score[10] = { 55, 20, 33, 85, 13, 22, 45, 98, 67, 77 };

	int max = score[0];
	for (i = 0; i < 10; i++) {
		if (score[i] > max) {
			max = score[i];
			max_index = i;
		}
	}
	printf("max_index : %d \n, max_score : %d.\n\n", max_index, score[max_index]);

}