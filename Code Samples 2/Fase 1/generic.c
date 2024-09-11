/******************************************************************************
 * Ficheiro com o código-fonte das funções genéricas utilizadas no projeto
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic.h"

int check_ext(char *argstr, char *extIn)
{
    char *aux;
    int argsize = 0, extsize = 0, start = 0, result = 0, i;
    
    extsize = strlen(extIn);
    argsize = strlen(argstr);
    start = argsize - extsize;

    if((aux = (char*)calloc(extsize+1, sizeof(char))) == NULL)
    {
        exit(0);
    }

    for(i = 0; i < extsize; i++){
        aux[i] = argstr[i+start];
    }

    if (strcmp(aux, extIn) != 0){
        free(aux);
        return result + 1;
    }
                    
    else{
        free(aux);
        return result;
    }    
}

char *Output(char *Input, char *extIn, char *extOut)
{
    int argsize = 0, Insize = 0, Outsize = 0, start = 0;
    char *outstr;
    
    Insize = strlen(extIn);
    Outsize = strlen(extOut);
    argsize = strlen(Input);
    start = argsize - Insize; /* índice da entrada onde deve estar o último ponto */

    outstr = (char*)calloc((start + Outsize +1), sizeof(char));

    if(outstr == NULL){
        exit(0);
    }

    strcpy(outstr, Input);
    outstr[start] = '\0';
    strcat(outstr, extOut);

    return outstr;   
}


FILE *abre_ficheiros (char *nome, char *mode)
{
    FILE *f;

    f = fopen ( nome, mode);

    if ( f == NULL ) 
    {        
        exit(0);
    }
    return (f);
}



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

