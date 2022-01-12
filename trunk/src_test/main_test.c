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

	res = eliminate(A,b);
	if (res==1){
		printf("Macierz jest macierzą osobliwą!");
		exit(1);
	}
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		if(res==1){
			printf("Dzielenie przez 0!");
			exit(1);
		}
		else if (res==2){
			printf("Podana macierz ma nieprwaidłowe wymairy!");
			exit(1);
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
