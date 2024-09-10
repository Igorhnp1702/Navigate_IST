#include <stdlib.h>
#include <stdbool.h>


#include "structs.h"
#include "matrix.h"
#include "stack.h"
#include "mancha.h"
#include "sort.h"
#include "solution.h"



/*
{

}
*/

/*
[]
*/

/*
Já tenho como detetar todas as find_ALL_manchas
Já tenho o algoritmo de tileblaster

1 - Passar a nova matriz no find_ALL_manchas
2 - Keep tracking of all matrizes que ainda tenho que passar no tileblaster
3 - Usar pilha para o tracking
Como escolher o próximo bom next move?
*/



Solution Malloc_Solution(int max_moves) {

    Solution solution = (Solution)malloc(sizeof(struct _solution));
    if (solution == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for solution\n");
        exit(EXIT_FAILURE);
    }

    solution->sequence = (int*)malloc(max_moves * sizeof(int));
    if (solution->sequence == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for solution sequence\n");
        free(solution);
        exit(EXIT_FAILURE);
    }

    solution->length = 0;
    solution->score = 0;

    return solution;
}


void Update_Best_Solution(Solution solution, int *current_sequence, int current_length, int current_score) {
    
    if (current_score > solution->score) {
        solution->score = current_score;
        solution->length = current_length;
        for (int i = 0; i < current_length; i++) {
            solution->sequence[i] = current_sequence[i];
        }
    }

}


void DFS(Element** matrix, int L, int C, int *current_sequence, int current_length, int current_score, int max_moves, Solution best_solution) {
    
    if (current_length == max_moves) {
        Update_Best_Solution(best_solution, current_sequence, current_length, current_score);
        return;
    }

    

    List_Mancha list_mancha = find_ALL_manchas(matrix, L, C);

    for (int i = 0; i < list_mancha->size; i++) {
        
        Mancha mancha = list_mancha->mancha[i];
        
        // Remove mancha + gravity
        Element** new_matrix = tileblaster(matrix, mancha, L, C);
        
        // Update the current sequence and score
        current_sequence[current_length] = i;
        int new_score = current_score + mancha->score;
        
        // Recursive call
        DFS(new_matrix, L, C, current_sequence, current_length + 1, new_score, max_moves, best_solution);
        
        // Backtrack
        FREE_MATRIX(new_matrix, L, C);
    }

    FREE_LIST_MANCHA(list_mancha);
}


Solution find_optimal_sequence(Element** initial_matrix, int L, int C, int max_moves) {
    
    int *current_sequence = (int*)malloc(max_moves * sizeof(int));
    if (current_sequence == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for current sequence\n");
        exit(EXIT_FAILURE);
    }

    Solution solution = Malloc_Solution(max_moves);
    
    
    DFS(initial_matrix, L, C, current_sequence, 0, 0, max_moves, solution);

    free(current_sequence);

    return solution;
}



void FREE_Solution(Solution solution){

    if (solution != NULL) {
        free(solution->sequence);
        free(solution);
    }
}



void print_solution_sequence(Solution solution) {
    if (solution == NULL) {
        printf("Error: Solution is NULL\n");
        return;
    }

    printf("Optimal Sequence:\n");
    printf("Length: %d\n", solution->length);
    printf("Score: %d\n", solution->score);
    printf("Sequence: ");
    
    for (int i = 0; i < solution->length; i++) {
        printf("%d", solution->sequence[i]);
        if (i < solution->length - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}



















// não sei se vou usar esta função porque acho qe isto não atende à categoria Stack
void ADD_matrix_to_List (List_Matrix list_matrix, Element** matrix){

    if (list_matrix==NULL || matrix==NULL){
        return;
    }

    /*if (list_matrix->size >= list_matrix->capacity) {
        // Optionally, you could resize the array here
        return;
    }
    
    posso usar isto futuramente para através de capacity decidir se vale a pena 
    usar DFS/BFS/etc. porque o tipo de procura pode depender da quantidade de
    possibilidades, isto é, list_matrix->size.

    */

    //list_matrix->matrix[list_matrix->size] = matrix;
    list_matrix->size++;


}

