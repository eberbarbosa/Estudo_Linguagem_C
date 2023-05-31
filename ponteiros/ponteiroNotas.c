/* Versão Ponteiros */
/* Media de um número arbitrário de notas */

#include <stdio.h>
#define LIM 10

int main(){

	float notas[LIM];
	float soma = 0.0;
	int   i = 0;
	float *ptr;

	ptr = notas;

	do{
		printf(" Digite a nota do Aluno %d: ", i++);
		scanf("%f", ptr);

		if( *ptr > 0 )
			soma += *ptr;
		
		ptr++;

	}while ( *(ptr - 1) > 0 && i < LIM );
	
			printf("Medias das notas: %.2f\n", soma / i );

	return 0;


}
