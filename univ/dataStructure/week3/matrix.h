#define ROW 3 
#define COL 3

void matrix_init(int a[ROW][COL]); 
void matrix_add(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]); 
void matrix_mult(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]); 
void matrix_trans(int a[ROW][COL], int b[ROW][COL]); 
void matrix_print(int a[ROW][COL]);

void matrix_init(int a[ROW][COL]) {
	int i, j;
	for (i = 0; i < ROW; i++) 
		for (j = 0; j < COL; j++) 
			a[i][j] = 0;
}

void matrix_add(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]) {

	printf("a + b = \n\n");
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			c[i][j] = a[i][j] + b[i][j];
}

void matrix_mult(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]) {
	printf("a * b = \n\n");
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			int sum = 0;
			for (int k = 0; k < ROW; k++) {
				c[i][j] = a[i][k] * b[k][j];
			}
		}
	}
}

void matrix_trans(int a[ROW][COL], int b[ROW][COL]) {
	printf("a transpose = \n\n");
	for (int i = 0; i < ROW; i++) 
		for (int j = 0; j < COL; j++)
			b[i][j] = a[j][i];
}

void matrix_print(int a[ROW][COL]) {
	//printf("\n");
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			printf(" %d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}