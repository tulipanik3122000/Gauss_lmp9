#include "gauss.h"
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
                for(j=i+1; j<row; j++)  //Szukamy najwiekszego elementu pod przekatna
                {
                        if(fabs(ma[j][i])>fabs(ma[i][i]))
                                max = j;
                }

                if(max != i)    //Zamiana wierszy jesli znajdziemy wiekszy element
                {
                        tem = ma[max];
                        ma[max] = ma[i];
                        ma[i] = tem;

                        tem2 = mar[max][0];
                        mar[max][0] = mar[i][0];
                        mar[i][0] = tem2;
                }


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

