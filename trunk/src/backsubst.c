#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	if(mat->r!=mat->c || mat->r!=b->r){
		return 2;
	}
	int j=1;
	int tmp;
	int h=mat->c;
	int l=mat->r-1;
	x->data[l][0]=(b->data[l][0])/(mat->data[l][h]);
	for(l; l>=0;l--){
		tmp=b->data[l][mat->c];
		for(h; h>(mat->c)-j;h--){
			tmp=b->data[l][0]-((mat->data[l][h])*(x->data[h][0]));
			}
		if(mat->data[(mat->c)-j][l]!=0){
			x->data[(mat->c)-j][l]=tmp/(mat->data[l][(mat->c)-j]);
		}else{
			return 1;
			}
		j++;
}
		return 0;
}


