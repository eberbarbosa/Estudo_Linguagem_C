/* imprime os valores da Matriz */

#include<stdio.h>

/*
int main(){

	static int nums[] = { 92, 81, 70, 69, 58 };
	int d;

	for( d = 0; d < 5; d++)
		printf(" %d\n", nums[d] );
} */


                      /* Versão com Ponteiros */

/* Usa ponteiros para imprimir valores da matriz */

int main(){


	static int nums[] = { 92, 81, 70, 69, 58 };
	int d;


	for( d = 0; d < 5; d++)

		printf(" %d\n", *(nums+d) );

}
