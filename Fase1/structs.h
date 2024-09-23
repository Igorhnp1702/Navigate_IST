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

typedef struct _files {
    FILE* Input;
    FILE* Output;
} Files;


typedef struct _path_vect{
    
    int row;
    int col;
    int energy;

}path_vect;

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
    int *diamond_vect;
    path_vect *path_vect;
    int path_size;
    int diamond_size;
    int **matrix;

}ProbInfo;





#endif