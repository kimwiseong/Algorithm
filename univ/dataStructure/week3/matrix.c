#include<stdio.h>
#include"matrix.h"

void main() {
	int a[ROW][COL] = { {1,0,0},{1,0,0},{1,0,0} }; 
	int b[ROW][COL] = { {1,1,1},{0,0,0},{0,0,0} }; 
	int c[ROW][COL] = { {0,0,0},{0,0,0},{0,0,0} };
	matrix_print(a); 
	matrix_print(b);

	matrix_add(a, b, c); 
	matrix_print(c);

	matrix_init(c);
	matrix_mult(a, b, c); 
	matrix_print(c);

	matrix_init(c); 
	matrix_trans(a, c); 
	matrix_print(c);
}