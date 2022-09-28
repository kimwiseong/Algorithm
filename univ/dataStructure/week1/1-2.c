#include<stdio.h>

int main() {
	int a = 10, b[5] = { 10, 20, 30, 40, 50 }, *p;

	p = &a;

	printf(" a = %d, address of a = %p \n", a, &a);
	printf(" p = %p, *p = %d\n\n", p, *p);

	p = b;
	printf("b = %p, b[0] = %d, b[1] = %d, b[2] = %d\n", b, b[0], b[1], b[2]);
	printf("p = %p, *p = %d, *(p+1) = %d, *(p+2) = %d\n", p, *p, *(p + 1), *(p + 2));

}