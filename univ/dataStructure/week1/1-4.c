#include<stdio.h>

int find_max(int *arr, int size);
int main() {
	int i, max_index;
	int score[10] = { 55, 20, 33, 85, 13, 22, 45, 98, 67, 77 };

	for (i = 0; i < 10; i++) 
		printf("index : %d, score : %d\n", i, score[i]);
	
	max_index = find_max(score, 10);
	printf("\n max_index : %d, max_score : %d\n\n", max_index, score[max_index]);
}

int find_max(int *arr, int size) {
	int max = arr[0];
	int temp = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			temp = i;
		}
	}
	return temp;
}
