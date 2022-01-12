#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
void diagonala(Matrix *mat, Matrix *b, int i){
	int j;
	int potmax=i;
	double *c;
	for(j=i+1;j<mat->r;j++)
		if(mat->data[potmax][i]<mat->data[j][i])
			potmax=j;
	if(potmax!=i){
		c=mat->data[i];
		mat->data[i]=mat->data[potmax];
		mat->data[potmax]=c;
		j=b->data[i][0];
		b->data[i][0]=b->data[potmax][0];
		b->data[potmax][0]=j;
	 }
}

int eliminate(Matrix *mat, Matrix *b){
	int i,j,k;
	double dziel;
	for(i=0; i<mat->c; i++){
		diagonala(mat, b, i);
		if((mat->data[i][i])==0)
			return 1;
		diagonala(mat, b, i);
		for(j=i+1; j<mat->r; j++){
			dziel=((mat->data[j][i])/(mat->data[i][i]));
			for(k=i; k<mat->c;k++)
				mat->data[j][k]=(mat->data[j][k])-((mat->data[i][k])*dziel);

			b->data[j][0]=(b->data[j][0])-((b->data[i][0])*dziel);
		
	}
	}

		return 0;
}
