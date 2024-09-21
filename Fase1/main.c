/******************************************************************************
 * Ficheiro da função principal do projeto Navigate_IST
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "IOmodule.h"
#include "prob_utils.h"

int main (int argc, char* argv[]){

    /*Verifica o número de argumentos*/
    if(argc !=2){
        return 0;
    }

    /* Tenta abrir os ficheiros de entrada e de saída */
    Files *fblock = open_files(argv[1], &fblock);

    if(fblock == NULL){
        exit(0);
    }
    

    /* Resolução de problemas */
    ProbInfo *problem;
    if((problem = (ProbInfo*)calloc(1, sizeof(ProbInfo))) == NULL){
        exit(0);
    }

    while((read_problem(fblock, &problem)) == 1){        

        if(problem->flag == 1){
            bad_prob_ans(fblock->Output, &problem);
        }
        else if(problem->tarefa == 1){
            t1_solver(fblock->Output, &problem);
        }
        else if(problem->tarefa == 2){
            t2_solver(fblock->Output, &problem);
        }
        else if(problem->tarefa == 3){
            t3_solver(fblock->Output, &problem);
        }
        free_prob_node_data(&problem);        
    }

    /* Prepara para fechar o programa */
    free(problem);
    close_files(&fblock);
    free(fblock);

    return 0;
}