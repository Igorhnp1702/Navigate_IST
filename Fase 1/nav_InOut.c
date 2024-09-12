/******************************************************************************
 * Ficheiro com o código-fonte das funções de tratamento 
 * dos ficheiros de entrada e de saída
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
*******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "nav_InOut.h"

int check_ext(char *argstr, char *extIn)
{
    char *aux;
    int argsize = 0, extsize = 0, start = 0, result = 0, i;
    
    extsize = strlen(extIn);
    argsize = strlen(argstr);
    start = argsize - extsize;

    if((aux = (char*)calloc(extsize+1, sizeof(char))) == NULL){
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

char *Out_string(char *Input, char *extIn, char *extOut)
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

void fecha_ficheiros(FILE *fp){
    fclose(fp);
}




