/* Operações com Ponteiros*/

#include<stdio.h>

int main() {

	int x = 5;
	int y = 6;
	int *px, *py;

	px = &x;
	py = &y;

	if( px < py )
		printf("py - px = %u\n", py - px);
	else
		printf(" px - py = %u\n", px - py);

	printf(" px = %u, *px = %d, &px = %u\n", px, *px, &px);
	printf(" py = %u, *py = %d, &py = %u\n", py, *py, &py);
	px++;

	printf(" px = %u, *px = %d, &px = %u\n", px, *px, &px);
	py = px + 3;
	printf(" py = %u, *py = %d, &py = %u\n", py, *py, &py);

	printf(" py - px = %u\n", py - px);


}


