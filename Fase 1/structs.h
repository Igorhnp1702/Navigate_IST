/******************************************************************************
 * Ficheiro das structs utilizadas no projeto Navigate_IST
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef __structs__
#define __structs__

#include <stdio.h>
#include <stdbool.h>


typedef struct _files {
    FILE* Input;
    FILE* Output;
} *Files;

typedef struct _prob_info{
    
    int L;
    int C;
    int l_1;
    int c_1;
    int k;
    int tarefa;
    int l_2;
    int c_2;
    int flag;
    int **matrix;

}*ProbInfo;

typedef struct Node {

    int l;
    int c;
    int energia;    
} Item;

#endif