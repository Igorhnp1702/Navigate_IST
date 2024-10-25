/******************************************************************************
 * File to implement the main funtion of the program
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "IOmodule.h"
#include "structs.h"
#include "problem.h"

int main (int argc, char* argv[]){

    /*Check the number of arguments*/
    if(argc !=2){
        return 0;
    }

    /* Try to open the files */
    Files *fblock; 
    fblock = open_files(argv[1]);

    if(fblock == NULL){        
        exit(0);
    }
    
    /* Allocate memory for a problem */
    ProbInfo *problem;
    
    if((problem = (ProbInfo*)calloc(1, sizeof(ProbInfo))) == NULL){
        close_files(&fblock);
        free(fblock->outfile_str);
        free(fblock);
        exit(0);
    }
    
    //As long as there's a problem to solve, keep processing the input file

    int alert = read_problem(fblock, &problem);

    while(alert == 1){        

        if(problem->bad == 1){            
            bad_prob_ans(fblock->Output, &problem);
        }
        else if(problem->task == 1){
            t1_solver(fblock->Output, &problem);
        }
        else if(problem->task == 2){
            t2_solver(fblock->Output, &problem);
        }
        free_reduced_map(&problem); 
        free(problem);
        if((problem = (ProbInfo*)calloc(1, sizeof(ProbInfo))) == NULL){
            close_files(&fblock);
            free(fblock->outfile_str);
            free(fblock);
            exit(0);
        }
        alert = read_problem(fblock, &problem);       
    }
    
    /* Free the remaining memory, close all files and exit */
    free_reduced_map(&problem);
    free(problem);
    close_files(&fblock);
    free(fblock->outfile_str);
    free(fblock);

    return 0;
}