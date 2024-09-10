#include <stdlib.h>

#include "structs.h"
#include "stack.h"
#include "mancha.h"


StackNode Malloc_Stack(int L, int C){

    StackNode stack = (StackNode)malloc( L*C*sizeof(struct _stacknode) );
    return stack;
}





StackResult ADD_Neighbours_to_Stack(StackNode stack, bool** visited, int stack_size, int L, int C, int row, int col) {
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int added = 0;

    for (int i = 0; i < 4; i++) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];
        if (is_within_bouds(L, C, new_row, new_col) && !visited[new_row][new_col]) {
            stack[stack_size+added].row = new_row;
            stack[stack_size+added].col = new_col;
            added++;
        }
    }
    
    StackResult result = {stack, added};
    return result;

}
