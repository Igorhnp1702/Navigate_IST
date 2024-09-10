#include <stdlib.h>
#include <stdbool.h>


#include "structs.h"
#include "stack.h"
#include "mancha.h"
#include "solution.h"

//    printf("%d\n", );

/*
{
    
} 
*/

bool is_within_bouds(int L, int C, int l, int c){

    return (l>=0 && l<L && c>=0 && c<C);

}

bool is_mancha(Mancha mancha){

    return (mancha->size>1);

}

Mancha return_not_mancha(Mancha mancha, bool** visited, int L, StackNode stack){
    
    FREE_MANCHA(mancha);
    mancha = NULL;
    FREE_Visited(visited, L);
    free(stack);

    return (mancha);

}

Mancha return_is_mancha(Mancha mancha, bool** visited, int L, StackNode stack){
    
    Calculate_Score(mancha);
    FREE_Visited(visited, L);
    free(stack);

    return (mancha);

}

void Print_Mancha(Mancha mancha, Element** matrix) {
    printf("mancha->colour: %d\n", matrix[mancha->coordinates[0]->row][mancha->coordinates[0]->col]->colour);
    for (int i = 0; i < mancha->size; i++){
        printf("mancha->l: %d  mancha->c: %d\n", mancha->coordinates[i]->row, mancha->coordinates[i]->col);
    }

    printf("mancha->score: %d\n", mancha->score);
}

void Calculate_Score(Mancha mancha){

    mancha->score = mancha->size*(mancha->size-1);
}


Mancha Malloc_Mancha(int L, int C){

    Mancha mancha = (Mancha)malloc(sizeof(struct _mancha));
    if (mancha == NULL) {
        printf("Error: Failed to allocate memory for mancha in Malloc_Mancha\n");
        free(mancha);
        exit(EXIT_FAILURE);
    }

    // qual a diferença entre: ?????
    // mancha->coordinates = (Coordinate*)malloc(L*C*sizeof(Coordinate));
    // mancha->coordinates = (Coordinate*)calloc(mancha->capacity, sizeof(Coordinate));

    mancha->capacity = L * C;
    mancha->size = 0;

    mancha->coordinates = (Coordinate*)calloc(mancha->capacity, sizeof(Coordinate));
        if (mancha->coordinates == NULL) {
        printf("Error: Failed to allocate memory for coordinates in Malloc_Mancha\n");
        FREE_MANCHA(mancha);
        exit(EXIT_FAILURE);
    }
    
    return mancha;
}

void FREE_MANCHA(Mancha mancha){

    if (mancha == NULL) {
        return;
    }
    if (mancha->coordinates != NULL) {
        for (int i = 0; i < mancha->size; i++) {
            if (mancha->coordinates[i] != NULL) {
                free(mancha->coordinates[i]);
            }
        }
        free(mancha->coordinates);
    }
    free(mancha);

}


bool** Malloc_Visited(int L, int C){

    bool** visited = (bool**)malloc(L * sizeof(bool*));
    
    if (visited == NULL) {
        free(visited);
        return 0;
    }

    for (int i = 0; i < L; i++) {
        visited[i] = (bool*)malloc(C*sizeof(bool));
        // Handle alloc error
        if (visited[i] == NULL) {
            FREE_Visited(visited, i);
            return 0;
        }

        // Initialize
        for (int j = 0; j < C; j++) {
            visited[i][j] = false;
        }
    }

    return visited;
}

void FREE_Visited(bool** visited, int L) {
    
    for (int i = 0; i < L; i++) {
        free(visited[i]);
    }
    free(visited);
}


Mancha ADD_to_mancha(Mancha mancha, int row, int col){

    if (mancha == NULL) {
        printf("Error: mancha is NULL in ADD_to_mancha\n");
        exit(EXIT_FAILURE);
    }
    
    if (mancha->coordinates == NULL) {
        printf("Error: mancha->coordinates is NULL in ADD_to_mancha\n");
        exit(EXIT_FAILURE);
    }

   // Ao fazer esta alocação aqui, fazemos menos allocs
    mancha->coordinates[mancha->size] = (Coordinate)malloc(sizeof(struct _coordinates));
    if (mancha->coordinates[mancha->size] == NULL) {
        printf("Error: Failed to allocate memory for new coordinate in ADD_to_mancha\n");
        exit(EXIT_FAILURE);
    }


    mancha->coordinates[mancha->size]->row = row;
    mancha->coordinates[mancha->size]->col = col;
    mancha->size++;
    
    return mancha;
}

Mancha find_mancha(Element** matrix, int L, int C, int l, int c) {
    
    Mancha mancha = Malloc_Mancha(L, C);
    bool** visited = Malloc_Visited(L, C);
    StackNode stack = Malloc_Stack(L, C);

    int colour = matrix[l][c]->colour;
    int stack_size = 0;

    // Push the starting position
    stack[stack_size].row = l;
    stack[stack_size].col = c;
    stack_size++;



    while (stack_size > 0) {
        // Pop from stack
        stack_size--;
        int row = stack[stack_size].row;
        int col = stack[stack_size].col;

        if (!is_within_bouds(L, C, row, col) || visited[row][col]) {
            continue;
        }

        visited[row][col] = true;

        if (matrix[row][col]->colour == colour) {

            mancha = ADD_to_mancha(mancha, row, col);
            matrix[row][col]->occupied = true;

            StackResult result = ADD_Neighbours_to_Stack(stack, visited, stack_size, L, C, row, col);
            stack = result.stack;
            stack_size += result.added;

        }
    }

    if (!is_mancha(mancha))  {
        mancha = return_not_mancha(mancha, visited, L, stack);
        return mancha;
    }

    mancha = return_is_mancha(mancha, visited, L, stack);

    return mancha;
}








List_Mancha Malloc_List_Mancha(int L, int C){

    List_Mancha list_mancha = (List_Mancha)malloc(sizeof(struct _list_mancha));
    if (list_mancha == NULL) {
        printf("Error: Failed to allocate memory for list_mancha in Malloc_List_Mancha\n");
        free(list_mancha);
        exit(EXIT_FAILURE);
    }

    list_mancha->capacity=(L*C)/2;
    list_mancha->size=0;

    list_mancha->mancha = (Mancha*)calloc(list_mancha->capacity, sizeof(Mancha));
        if (list_mancha->mancha == NULL) {
        printf("Error: Failed to allocate memory for manchas in Malloc_List_Mancha\n");
        FREE_LIST_MANCHA(list_mancha);
        exit(EXIT_FAILURE);
    }

    return list_mancha;
}

void FREE_LIST_MANCHA(List_Mancha list_mancha){

    if (list_mancha == NULL) {
        return;
    }

    if (list_mancha->mancha != NULL) {
        for (int i = 0; i < list_mancha->size; i++) {
            if (list_mancha->mancha[i] != NULL) {
                FREE_MANCHA(list_mancha->mancha[i]);
            }
        }
        free(list_mancha->mancha);
    }

    free(list_mancha);


}

void ADD_mancha_to_List(List_Mancha list_mancha, Mancha mancha){
    

    if (list_mancha == NULL || mancha == NULL) {
        return;
    }
    
    if (list_mancha->size >= list_mancha->capacity) {
        // Optionally, you could resize the array here
        return;
    }

    // Instead of allocating new memory, just assign the pointer
    list_mancha->mancha[list_mancha->size] = mancha;
    list_mancha->size++;

}

List_Mancha find_ALL_manchas(Element** matrix, int L, int C){
    
    int l=0, c=0;
    List_Mancha list_mancha = Malloc_List_Mancha(L, C);

    for(l=0; l<L; l++){

        for(c=0; c<C ; c++){

            if ( !(matrix[l][c]->occupied) ){
                
                Mancha mancha = find_mancha(matrix, L, C, l, c);
                if (mancha != NULL && mancha->size > 0) {
                    ADD_mancha_to_List(list_mancha, mancha);
                } else {
                    FREE_MANCHA(mancha);  // Free it if it's not valid
                }
            } 
            
        } 
        
    }

    // Reset matrix[l][c]->occupied
    // Dentro desta função vou ter de dar free das manchas
    // Fora desta função eventualmente vou ter de dar free da lista



    return list_mancha;
    
} 

void Print_List_Mancha(List_Mancha list, Element** matrix) {
    
    printf("Print_List_Mancha:\n");
    for (int i = 0; i < list->size; i++) {
        Print_Mancha(list->mancha[i], matrix);
        printf("\n");
    }
}




