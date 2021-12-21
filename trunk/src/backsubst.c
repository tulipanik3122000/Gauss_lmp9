#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	if(mat->r!=mat->c || mat->r!=b->r || b->c!=1){
		return 2;
	}
	int j=1;
	int tmp;
	int h=mat->c-1;
	int l=mat->r-1;
	if(mat->data[l][h]!=0)
		x->data[l][0]=(b->data[l][0])/(mat->data[l][h]);
	else
		return 1;
	for(; l>=0;l--){
		tmp=b->data[l][0];
		for(; h>(mat->c)-j;h--)
			tmp-=(mat->data[l][h])*(x->data[h][0]);
		if(mat->data[l][(mat->c)-j]!=0)
			x->data[l][(mat->c)-j]=tmp/(mat->data[l][(mat->c)-j]);
		else{
			return 1;
			}
		j++;
}
		return 0;
}


