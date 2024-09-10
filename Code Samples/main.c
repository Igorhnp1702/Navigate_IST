#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "files.h"
#include "matrix.h"
#include "mancha.h"
#include "sort.h"
#include "solution.h"


// valgrind --leak-check=full ./programa teste.tilewalls


int main (int argc, char* argv[]){

    char* inputFileName = argv[1];
    Files File = open_files(inputFileName);


    while (1){

        Parameters parameters = READ_PARAMETERS(File);
        Element** matrix = READ_MATRIX(File, parameters->L, parameters->C);
        if (matrix == NULL) {
            break;  // não está a funcionar porque matrix nunca é NULL
        }

        int max_moves = (parameters->L)*(parameters->C)/2;
        Solution solution = find_optimal_sequence(matrix, parameters->L, parameters->C, max_moves);

        print_solution_sequence(solution);


        FREE_Solution(solution);
        FREE_MATRIX(matrix, parameters->L, parameters->C);
        free(parameters);

        break;
    }

           


    fclose(File->Input);
    fclose(File->Output);
    free(File);
    return 0;



}

