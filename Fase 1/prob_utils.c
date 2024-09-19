/******************************************************************************
 * Ficheiro *.c das funcionalidades do projeto
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include "prob_utils.h"
#include <stdio.h>
#include "lists.h"

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

void bad_prob_ans(FILE *fpOut, ProbInfo prob_node){

}

void t1_solver(FILE *fpOut, ProbInfo prob_node){

    int max_pos_val = 0;

    /* these variables will help me see where the diamond is cutted on the map */
    int radius = - prob_node->k;
    int R_dist_to_edge = prob_node->C - prob_node->c_1; /* How far right is the diamond */
    int Dist_to_bottom = prob_node->L - prob_node->l_1; /* How far down is the diamond */
    int left_flag = 0, right_flag = 0, top_flag = 0, bottom_flag = 0;

    /*Is there lack of space on my left? */
    if(prob_node->c_1 < radius){
        left_flag = radius - prob_node->c_1; /* Space I have to my left*/
    }
    
    /* Is there lack of space on my right? */
    if(R_dist_to_edge < radius){
        right_flag = R_dist_to_edge; /* Space I have to my right */
    }

    /*Is there lack of space above me? */
    if(prob_node->l_1 < radius){
        top_flag = radius - prob_node->l_1; /* Space I have above me */
    }

    /*Is there lack of space beneath me? */
    if(Dist_to_bottom < radius){
        bottom_flag = Dist_to_bottom;  /* Space I have beneath me */
    }

    /* Traverse the diamond and find the cell with the maximum positive energy*/

    int i, j;

    for(i = prob_node->l_1 - radius + top_flag; i < prob_node->l_1 + radius - bottom_flag; i++){
        for(j = prob_node->c_1 - radius + left_flag; j < prob_node->c_1 + radius - right_flag; j++){

            if(prob_node->matrix[i][j] > max_pos_val){
                max_pos_val = prob_node->matrix[i][j];
            }
        }
    }

    fprintf(fpOut, "%d %d %d %d %d %d \n", 
        prob_node->L, prob_node->C, prob_node->l_1, prob_node->c_1, prob_node->k, max_pos_val);
    return;
}

void t2_solver(FILE *fpOut, ProbInfo prob_node){

    int sum = 0;

    /* these variables will help me see where the diamond is cutted on the map */
    int radius = - prob_node->k;
    int R_dist_to_edge = prob_node->C - prob_node->c_1; /* How far right is the diamond */
    int Dist_to_bottom = prob_node->L - prob_node->l_1; /* How far down is the diamond */
    int left_flag = 0, right_flag = 0, top_flag = 0, bottom_flag = 0;

    /*Is there lack of space on my left? */
    if(prob_node->c_1 < radius){
        left_flag = radius - prob_node->c_1; /* Space I have to my left*/
    }
    
    /* Is there lack of space on my right? */
    if(R_dist_to_edge < radius){
        right_flag = R_dist_to_edge; /* Space I have to my right */
    }

    /*Is there lack of space above me? */
    if(prob_node->l_1 < radius){
        top_flag = radius - prob_node->l_1; /* Space I have above me */
    }

    /*Is there lack of space beneath me? */
    if(Dist_to_bottom < radius){
        bottom_flag = Dist_to_bottom;  /* Space I have beneath me */
    }

    int i, j;

    /* Traverse the diamond, find cells with positive energy and add them */

    for(i = prob_node->l_1 - radius + top_flag; i < prob_node->l_1 + radius - bottom_flag; i++){
        for(j = prob_node->c_1 - radius + left_flag; j < prob_node->c_1 + radius - right_flag; j++){

            if(prob_node->matrix[i][j] > 0){
                sum += prob_node->matrix[i][j];
            }
        }
    }

    fprintf(fpOut, "%d %d %d %d %d %d \n", 
        prob_node->L, prob_node->C, prob_node->l_1, prob_node->c_1, prob_node->k, sum);
    return;
}

void t3_solver(FILE *fpOut, ProbInfo prob_node){

    int line_diff = prob_node->l_2 - prob_node->l_1;
    int column_diff = prob_node->c_2 - prob_node->c_1;
    int L_steps = 0, C_steps = 0, new_line = prob_node->c_1;
    
    fprintf(fpOut, "%d %d %d %d %d %d %d \n",prob_node->L, prob_node->C, prob_node->l_1, prob_node->c_1, 
        prob_node->k, prob_node->l_2, prob_node->c_2);

    while (line_diff != 0 && column_diff != 0){
        
        if(line_diff < 0){ /* Go up */
            L_steps--;
            line_diff++;
            new_line = prob_node->l_1 - L_steps;
            fprintf(fpOut, "%d %d %d \n", new_line, prob_node->c_1, 
            prob_node->matrix[new_line][prob_node->c_1]);

        }else if(line_diff > 0) { /* Go down */
            L_steps++;
            line_diff--;
            new_line = prob_node->l_1 + L_steps;
            fprintf(fpOut, "%d %d %d \n", new_line, prob_node->c_1, 
            prob_node->matrix[new_line][prob_node->c_1]);
        }
        /* Else, we are in the right line, start moving horizontaly */

        if(line_diff == 0 && column_diff >= 0){ /* Go right */

            C_steps++;
            column_diff--;
            fprintf(fpOut, "%d %d %d \n", new_line, prob_node->c_1 + C_steps, 
            prob_node->matrix[new_line][prob_node->c_1 + C_steps]);

        }else if(line_diff == 0 && column_diff <= 0){ /* Go left */

            C_steps++;
            column_diff--;
            fprintf(fpOut, "%d %d %d \n", new_line, prob_node->c_1 + C_steps, 
            prob_node->matrix[new_line][prob_node->c_1 + C_steps]);
        }
    }
    return;    
}

void free_prob_node(ProbInfo prob_node){

}
