/******************************************************************************
 * Ficheiro *.c das funcionalidades do projeto
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include "prob_utils.h"

ProbInfo read_problem(Files fblock){

    ProbInfo prob;
    if(prob = (ProbInfo)calloc(1,sizeof(ProbInfo)) == NULL){
        exit(0);
    }
    fscanf(fblock->Input, "%d %d %d %d %d ", &(prob->L), &(prob->C), &(prob->l_1),  &(prob->c_1),  &(prob->k));

    /* if the dimensions of the matrix are negative */
    if(prob->L <= 0 || prob->C <= 0){
        prob->flag = 1; /* it's a bad problem */
        return prob;
    }
    
    /* if the start position is out of bounds */
    if((prob->l_1 > prob->L || prob->l_1 < 0) || (prob->c_1 > prob->C || prob->c_1 < 0)){
        prob->flag = 1; /* it's a bad problem */
        return prob;
    } 

    if((prob->k) == 0){
        fscanf(fblock->Input, "%d %d", &(prob->l_2), &(prob->c_2));

        /* if the end position is out of bounds */
        if((prob->l_2 > prob->L || prob->l_2 < 0) || (prob->c_2 > prob->C || prob->c_2 < 0)){
            
            prob->flag = 1; /* it's a bad problem */
            return prob;
        }
        prob->tarefa = 3;
        prob->l_2 = prob->l_2 - 1;
        prob->c_2 = prob->c_2 - 1;

    }else if(prob->k < 0){
        prob->tarefa = 1;
        prob->l_2 = -1;
        prob->c_2 = -1;
    }else if (prob->tarefa > 0){
        prob->tarefa = 2;
        prob->l_2 = -1;
        prob->c_2 = -1;
    }

    prob->l_1 = prob->l_1 - 1;
    prob->c_1 = prob->c_1 - 1;
    
    /* read the matrix from the file to memory */

    /* First, allocate memory */
    prob->matrix = (int**)calloc(prob->L, sizeof(int*));
    if(prob->matrix == NULL)
    {
        exit(0);
    }
    int i;
    
    for(i = 0; i < prob->matrix[i]; i++)
    {
        prob->matrix[i] = (int*) calloc(prob->C, sizeof(int));
        if(prob->matrix[i] == NULL)
        {
            exit(0);
        }
    }

    /* Then, pass the information from the file to memory */
    int j;

    for(i = 0; i < prob->L; i++){
        for(j = 0; j < prob->C; j++){
            
            fscanf(fblock->Input, "%d", &(prob->matrix[i][j]));            
        }
    }

    /* Problem is good */
    prob->flag = 0;
    return prob;
}

void bad_prob_ans(FILE fpOut, ProbInfo prob_node){

}

void t1_solver(FILE fpOut, ProbInfo prob_node){

}

void t2_solver(FILE fpOut, ProbInfo prob_node){

}

void t3_solver(FILE fpOut, ProbInfo prob_node){

}
