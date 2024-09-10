#ifndef __solution__
#define __solution__

#include "structs.h"

Solution Malloc_Solution(int max_moves);
void Update_Best_Solution(Solution solution, int *current_sequence, int current_length, int current_score);
void DFS(Element** matrix, int L, int C, int *current_sequence, int current_length, int current_score, int max_moves, Solution best_solution);
Solution find_optimal_sequence(Element** initial_matrix, int L, int C, int max_moves);
void FREE_Solution(Solution solution);

void print_solution_sequence(Solution solution);

#endif