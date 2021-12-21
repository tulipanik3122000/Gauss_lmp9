include "gauss.h"
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){

        double **ma=mat->data;   //macierz
        double **mar=b->data;   //rozszerzenie macierzy
        double *tem, tem2, factor;
        int row = mat->r;
        int column = mat->c;
        int i, j, q, p, max;

        for(i=0; i<column-1; i++)
        {

              for(q=i+1; q<row; q++)
                {
                        if(ma[0][0] != 0)
                        {
                                factor = ma[q][i]/ma[i][i];
                                for(p=0; p<column; p++)
                                        {
                                        ma[q][p] -= ma[i][p]*factor;
                                        mar[q][0] -= mar[i][0]*factor;
                                        }
                        }
                        return 1;
                }

        }

        return 0;
}

