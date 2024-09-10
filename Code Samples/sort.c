#include <stdlib.h>
#include <stdbool.h>


#include "structs.h"
#include "matrix.h"
#include "stack.h"
#include "mancha.h"
#include "sort.h"

/*
{

}
*/

/*
[]
*/


void Remove_Mancha(Element** new_matrix, Mancha mancha){

    // todos os números da mancha têm de passar a -1 na matrix cópia

    if (new_matrix==NULL || mancha==NULL){
        return;
    }
    for(int k=0; k<mancha->size; k++){
        new_matrix[mancha->coordinates[k]->row][mancha->coordinates[k]->col]->colour = -1;
    }

}


void Sort_Col(Element** new_matrix, int L, int C){
    // Primeiro, iterar por cada coluna e ordenar cada uma individualmente
    for (int j = 0; j < C; j++) {
        int position = 0;  // Para compactar os -1 no topo

        // Primeira passagem para compactar -1 no topo da coluna
        for (int i = 0; i < L; i++) {
            if (new_matrix[i][j]->colour == -1) {
                if (i != position) {
                    // Mover o elemento -1 para o topo
                    Element temp = new_matrix[i][j];
                    for (int k = i; k > position; k--) {
                        new_matrix[k][j] = new_matrix[k-1][j];
                    }
                    new_matrix[position][j] = temp;
                }
                position++;
            }
        }
    }
}

void Sort_Row(Element** new_matrix, int L, int C){

    // Depois, iterar por cada linha e ordenar cada uma individualmente
    for (int i = 0; i < L; i++) {
        int position = 0;  // Para compactar os -1 à esquerda

        // Passagem para compactar -1 à esquerda na linha
        for (int j = 0; j < C; j++) {
            if (new_matrix[i][j]->colour == -1) {
                if (j != position) {
                    // Mover o elemento -1 para a esquerda
                    Element temp = new_matrix[i][j];
                    for (int k = j; k > position; k--) {
                        new_matrix[i][k] = new_matrix[i][k-1];
                    }
                    new_matrix[i][position] = temp;
                }
                position++;
            }
        }
    }
}

void Sort(Element** new_matrix, int L, int C){

    Sort_Col(new_matrix, L, C);
    Sort_Row(new_matrix, L, C);
    
}


Element** tileblaster (Element** matrix, Mancha mancha, int L, int C){

    Element** new_matrix = Copy_Matrix(matrix, L, C);
    Remove_Mancha(new_matrix, mancha);
    Sort(new_matrix, L, C);
        
    return new_matrix;
}

