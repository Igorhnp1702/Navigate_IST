/******************************************************************************
 * Ficheiro com o código-fonte das funções para o tratamento de matrizes
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nav_matrix.h"

int **read_matriz(FILE *fp, int L_max, int C_max, int dimensao, int *diff_flag, int *empty_flag)
{
    int **matriz, i, j, valor, aux = L_max-1, line_feed = 0;

    matriz = (int**)calloc(L_max, sizeof(int*));
    if(matriz == NULL)
    {
        exit(0);
    }
    
    for(i = 0; i < L_max; i++)
    {
        matriz[i] = (int*) calloc(C_max, sizeof(int));
        if(matriz[i] == NULL)
        {
            exit(0);
        }
    }

    for(i = 0, j = 0; i < dimensao; i++)
    {
        if((fscanf(fp, "%d", &valor)) != EOF){
            
            matriz[aux][j] = valor;

            if((j-1) > 0){
                if((matriz[aux][j] != matriz[aux][j-1]) && *diff_flag == 0){
                    *diff_flag = 1;
                }
            }
             if(aux < (L_max-1) && line_feed == 1){
                if((matriz[aux][j] != matriz[aux+1][j]) && *diff_flag == 0){
                    *diff_flag = 1;
                }
                line_feed = 0;
            }
            if(j == C_max-1)
            {
                j = 0;
                aux--;
                line_feed++;                               
            }
            else j++;
        }
    }
    if(*diff_flag == 0 && matriz[0][0] == -1){
        *empty_flag = 1;
    }
    
    return matriz;
}

void reset_matriz(int **matriz, int L_max, int C_max){

    int i;
    
    for(i = 0; i < L_max; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}
