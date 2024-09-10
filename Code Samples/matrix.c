
/*

{

}

[]

*/

#include <stdlib.h>

#include "structs.h"
#include "matrix.h"

/*

Frees a fazer: 1 parametros, 1 matriz

*/


Parameters READ_PARAMETERS(Files File){

    Parameters parameters = (Parameters)malloc(sizeof(struct _parameters));
    fscanf(File->Input, "%d %d %d %d %d ", &(parameters->L), &(parameters->C), &(parameters->l_1),  &(parameters->c_1),  &(parameters->k));

    if((parameters->k) == 0){
        fscanf(File->Input, "%d %d", &(parameters->l_2), &(parameters->c_2));
        return parameters;
    }
    parameters->l_2 = NULL;
    parameters->c_2 = NULL;
    return parameters;
}

Element** READ_MATRIX(Files File, int L, int C){
    int i, j;
    Element** matrix = (Element**)malloc(L * sizeof(Element*));
    if (matrix == NULL){
        FREE_MATRIX(matrix, 0, 0);
        return NULL;
    }


    for (i = 0; i < L; i++) {
        matrix[i] = (Element*)malloc(C * sizeof(Element));

        // Handle allocation failure
        if (matrix[i] == NULL) {
            /*while (--i >= 0) free(matrix[i]);
            free(matrix);*/
            FREE_MATRIX(matrix, i, 0);
            return NULL;
        }
        for (j = 0; j < C; j++) {
            matrix[i][j] = (Element)malloc(sizeof(struct _element));

            // Handle allocation failure
            if (matrix[i][j] == NULL) {
                // Free previously allocated memory
                FREE_MATRIX(matrix, i, j);
                return NULL;
            }

            // READ
            fscanf(File->Input, "%d ", &(matrix[i][j]->colour));
            matrix[i][j]->empty = (matrix[i][j]->colour == -1);
            matrix[i][j]->occupied = false;
        }
    }

    return matrix;
}

Element** Copy_Matrix(Element** matrix, int L, int C){

    if (matrix==NULL){
        return 0;
    }

    int i, j;
    Element** new_matrix = (Element**)malloc(L * sizeof(Element*));
    if (new_matrix == NULL){
        FREE_MATRIX(new_matrix, 0, 0);
        return NULL;
    }


    for (i = 0; i < L; i++) {

        new_matrix[i] = (Element*)malloc(C * sizeof(Element));
        if (new_matrix[i] == NULL) {
            FREE_MATRIX(new_matrix, i, 0);
            return NULL;
        }
        
        for (j = 0; j < C; j++) {

            new_matrix[i][j] = (Element)malloc(sizeof(struct _element));
            if (new_matrix[i][j] == NULL) {
                FREE_MATRIX(new_matrix, i, j);
                return NULL;
            }

            // COPY
            new_matrix[i][j]->colour = matrix[i][j]->colour;
            new_matrix[i][j]->empty = matrix[i][j]->empty;
            new_matrix[i][j]->occupied = matrix[i][j]->occupied;
                

        }
    }

    return new_matrix;
}

void Print_Matrix(Element** matrix, int L, int C) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", matrix[i][j]->colour);
        }
        printf("\n");
    }
}


void FREE_MATRIX(Element** matrix, int L, int C) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}
