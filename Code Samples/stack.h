#ifndef __stack__
#define __stack__

#include "structs.h"

StackNode Malloc_Stack(int L, int C);
StackResult ADD_Neighbours_to_Stack(StackNode stack, bool** visited, int stack_size, int L, int C, int row, int col);


#endif