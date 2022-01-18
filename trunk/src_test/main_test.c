#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("Test macierzy %d X %d", A->r, A->c);
	printToScreen(A);
	printToScreen(b);

	if((A->r!=A->c) | (b->r!=A->r)){
		printf("Macierze mają nieprawidłowe wymiary!\n");
		return EXIT_SUCCESS;
	}

	res = eliminate(A,b);
	if (res==1){
		printf("Macierz jest macierzą osobliwą!\n");
		return EXIT_SUCCESS;
	}
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		if(res==1){
			printf("Dzielenie przez 0!\n");
			return EXIT_SUCCESS;
		}
		else if (res==2){
			printf("Podana macierz ma nieprwaidłowe wymairy!\n");
			return EXIT_SUCCESS;
		}

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
