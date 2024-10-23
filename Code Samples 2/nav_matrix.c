/******************************************************************************
 * Ficheiro com o código-fonte das funções para o tratamento de matrizes
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nav_matrix.h"
#include "structs.h"


Parameters READ_PARAMETERS(Files fblock){

    Parameters parameters = (Parameters)malloc(sizeof(struct _parameters));
    fscanf(fblock->Input, "%d %d %d %d %d ", &(parameters->L), &(parameters->C), &(parameters->l_1),  &(parameters->c_1),  &(parameters->k));

    if((parameters->k) == 0){
        fscanf(fblock->Input, "%d %d", &(parameters->l_2), &(parameters->c_2));
        return parameters;
    }
    parameters->l_2 = NULL;
    parameters->c_2 = NULL;
    return parameters;
}


Element **read_matriz(Files File, int L_max, int C_max, int dimensao, int *diff_flag, int *empty_flag)
{

    Element **matriz;

    int i, j, valor, aux = L_max-1, line_feed = 0;

    matriz = (Element**)calloc(L_max, sizeof(Element*));
    if(matriz == NULL)
    {
        exit(0);
    }
    
    for(i = 0; i < L_max; i++)
    {
        matriz[i] = (Element*) calloc(C_max, sizeof(Element));
        if(matriz[i] == NULL)
        {
            exit(0);
        }
    }

    for(i = 0, j = 0; i < dimensao; i++)
    {
        if((fscanf(File->Input, "%d", &valor)) != EOF){
            
            //matriz[aux][j] = valor;
            matriz[aux][j] = (Element)malloc(sizeof(struct _element));
            matriz[aux][j]->energia = valor;
            matriz[aux][j]->paths = Create_List_Path(); // Inicializar List_Path


            if((j-1) > 0){
                if((matriz[aux][j]->energia != matriz[aux][j-1]->energia) && *diff_flag == 0){
                    *diff_flag = 1;
                }
            }
             if(aux < (L_max-1) && line_feed == 1){
                if((matriz[aux][j]->energia != matriz[aux+1][j]->energia) && *diff_flag == 0){
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
    if(*diff_flag == 0 && matriz[0][0]->energia == -1){
        *empty_flag = 1;
    }
    
    return matriz;
}

void reset_matriz(Element **matriz, int L_max, int C_max){
    int i, j;

    for (i = 0; i < L_max; i++) {
        for (j = 0; j < C_max; j++) {
            if (matriz[i][j] != NULL) {
                FREE_List_Path(matriz[i][j]->paths);
                free(matriz[i][j]);
            }
        }
        free(matriz[i]);
    }

    free(matriz);
}
