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


int read_problem(Files *fblock, ProbInfo **prob){
    
    int L, C, l_1, c_1, k, l_2 = -1, c_2 = -1, prob_flag = 0;
    
    (*prob)->flag = 0;
    if (fblock->Input == NULL) {
        printf("Error: fblock->Input is null\n");
        exit(1);
    }

    if((fscanf(fblock->Input, "%d %d %d %d %d", &L, &C, &l_1, &c_1, &k)) != EOF){
        prob_flag = 1;
        (*prob)->L = L;
        (*prob)->C = C;
        (*prob)->l_1 = l_1;
        (*prob)->c_1 = c_1;
        (*prob)->k = k;
        
        /* if the dimensions of the matrix are negative */
        if((*prob)->L <= 0 || (*prob)->C <= 0){
            (*prob)->flag = 1; /* it's a bad problem */
            Get_tarefa( prob, fblock,  L,  C,  l_2,  c_2,  prob_flag);
            return prob_flag; 
        }
        
        /* if the start position is out of bounds */
        if(((*prob)->l_1 > (*prob)->L || (*prob)->l_1 < 0) || ((*prob)->c_1 > (*prob)->C || (*prob)->c_1 < 0)){
            (*prob)->flag = 1; /* it's a bad problem */
            Get_tarefa( prob, fblock,  L,  C,  l_2,  c_2,  prob_flag);
            return prob_flag; 
        } 

        int i;
        int line_tracker = 1, column_tracker = 1;
        int remaining_nums = L * C;   

        int aux = 0;
        prob_flag = Get_tarefa( prob, fblock,  L,  C,  l_2,  c_2,  prob_flag);

        
        /* read the diamond from the file to memory */

        int radius = k; if(radius < 0) radius = -radius;
        int dist_to_edge_R = C - c_1;
        int dist_to_edge_L = c_1 - 1;
        int dist_to_bottom = L - l_1;
        int dist_to_top = l_1 - 1;       
        int columns_missing_R;
        int columns_missing_L;
        int lines_missing_B;
        int lines_missing_T;

        if(radius >= dist_to_edge_R){
            columns_missing_R = abs(dist_to_edge_R - radius);
        }else columns_missing_R = 0;

        if(radius >= dist_to_edge_L){
            columns_missing_L = abs(dist_to_edge_L - radius);
        }else columns_missing_L = 0;

        if(radius >= dist_to_bottom){
            lines_missing_B = abs(dist_to_bottom - radius);
        }else lines_missing_B = 0;

        if(radius >= dist_to_top){
            lines_missing_T = abs(dist_to_top - radius);
        }else lines_missing_T = 0;       
        
        int lines_missing_tot = lines_missing_B + lines_missing_T;
        int columns_missing_tot = columns_missing_L + columns_missing_R;
        int dist_Ctracker_center = abs(c_1 - column_tracker);
        int dist_Ltracker_center = abs(l_1 - line_tracker);
        int numbs_2_read_to_diamond = 0;                
        
        for(i = 1; i <= 2*radius + 1 - lines_missing_tot; i++){

            if((columns_missing_tot - abs(l_1 - i)) > 0){
                numbs_2_read_to_diamond += (2*radius + 1) - 2*(abs(l_1 - i)) - (columns_missing_tot - abs(l_1 - i));
            }else numbs_2_read_to_diamond += (2*radius + 1) - 2*abs(l_1 - i);
        }

        (*prob)->diamond_size = numbs_2_read_to_diamond;

        if (numbs_2_read_to_diamond > 0){        
            (*prob)->diamond_vect = (int*)calloc(numbs_2_read_to_diamond, sizeof(int));
        }
        else{
            
        }
     
        i = 0;


        /* Then, pass the information from the file to memory */
        while (numbs_2_read_to_diamond != 0)
        {
            
            fscanf(fblock->Input, "%d", &aux);
            
            remaining_nums--;
            dist_Ctracker_center = abs(c_1 - column_tracker);
            dist_Ltracker_center = abs(l_1 - line_tracker);

            if(dist_Ctracker_center + dist_Ltracker_center <= radius){
    
                (*prob)->diamond_vect[i] = aux;
                i++;
                numbs_2_read_to_diamond--;
            }
            column_tracker++;  
            if(column_tracker > C){
                column_tracker = 1;
                line_tracker++;
            }
                               
        }

        while (remaining_nums != 0)
        {
            fscanf(fblock->Input, "%d", &aux);
            remaining_nums--;
        }                
    }
    return prob_flag;    
}

int Get_tarefa(ProbInfo **prob, Files *fblock, int L, int C, int l_2, int c_2, int prob_flag) {

        int aux = 0;
        int i, j;
        if(((*prob)->k) == 0){
            fscanf(fblock->Input, "%d %d", &l_2, &c_2);
            (*prob)->l_2 = l_2;
            (*prob)->c_2 = c_2;
            /* if the end position is out of bounds */
            if(((*prob)->l_2 > (*prob)->L || (*prob)->l_2 < 0) || ((*prob)->c_2 > (*prob)->C || (*prob)->c_2 < 0)){
                
                (*prob)->flag = 1; /* it's a bad problem */
                return prob_flag;
            }
            (*prob)->tarefa = 3;            
            
            if(((*prob)->matrix = (int**)calloc(L, sizeof(int*))) == NULL){
                exit(0);        
            }

            for(i = 0; i < L; i++){
                if(((*prob)->matrix[i] = (int*)calloc(C, sizeof(int))) == NULL){
                    exit(0);
                }
            }

            for(i = 0; i < L; i++){
                for(j = 0; j < C; j++){
                    fscanf(fblock->Input, "%d", &aux);
                    (*prob)->matrix[i][j] = aux;
                }
            }                        
            return prob_flag;

        }else if((*prob)->k < 0){

            (*prob)->tarefa = 1;
            (*prob)->l_2 = -1;
            (*prob)->c_2 = -1;
        }else if ((*prob)->k > 0){
            (*prob)->tarefa = 2;
            (*prob)->l_2 = -1;
            (*prob)->c_2 = -1;
        }
    return prob_flag;
}


void bad_prob_ans(FILE *fpOut, ProbInfo **prob_node){

    printf("(*prob_node)->tarefa: %d\n", (*prob_node)->tarefa);
    if((*prob_node)->tarefa == 1){
         fprintf(fpOut, "%d %d %d %d %d %d\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, 0);
    }

    if((*prob_node)->tarefa == 2){
         fprintf(fpOut, "%d %d %d %d %d %d\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, 0);
    }

    if((*prob_node)->tarefa == 3){
         fprintf(fpOut, "%d %d %d %d %d %d %d\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, (*prob_node)->l_2, (*prob_node)->c_2);
    }
    return;
    
}

void t1_solver(FILE *fpOut, ProbInfo **prob_node){

    int max_pos_val = 0;
    
    /* Traverse the diamond and find the cell with the maximum positive energy*/

    int i;

    for(i = 0; i < (*prob_node)->diamond_size; i++){
                    
        if((*prob_node)->diamond_vect[i] > max_pos_val){
            max_pos_val = (*prob_node)->diamond_vect[i];
        }    
    }

    fprintf(fpOut, "%d %d %d %d %d %d\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, max_pos_val);
    return;
}

void t2_solver(FILE *fpOut, ProbInfo **prob_node){

    int sum = 0, i;

    /* Traverse the diamond, find cells with positive energy and add them */

    for(i = 0; i < (*prob_node)->diamond_size; i++){
        if((*prob_node)->diamond_vect[i] > 0){
            sum += (*prob_node)->diamond_vect[i];
        }
    }
            
    fprintf(fpOut, "%d %d %d %d %d %d\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, sum);
    return;
}

void t3_solver(FILE *fpOut, ProbInfo **prob_node){

    int line_diff = (*prob_node)->l_2 - (*prob_node)->l_1;
    int column_diff = (*prob_node)->c_2 - (*prob_node)->c_1;
    int L_steps = 0, C_steps = 0, new_line = (*prob_node)->c_1;
    
    fprintf(fpOut, "%d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, 
        (*prob_node)->k, (*prob_node)->l_2, (*prob_node)->c_2);

    do{
        
        if(line_diff < 0){ /* Go up */
            L_steps--;
            line_diff++;
            new_line = (*prob_node)->l_1 - L_steps;
            fprintf(fpOut, "%d %d %d\n", new_line, (*prob_node)->c_1, 
            (*prob_node)->matrix[new_line - 1][(*prob_node)->c_1 - 1]);

        }else if(line_diff > 0){ /* Go down */
            L_steps++;
            line_diff--;
            new_line = (*prob_node)->l_1 + L_steps;
            fprintf(fpOut, "%d %d %d\n", new_line, (*prob_node)->c_1, 
            (*prob_node)->matrix[new_line - 1][(*prob_node)->c_1 - 1]);
        }
        /* Else, we are in the right line, start moving horizontaly */

        if(line_diff == 0 && column_diff > 0){ /* Go right */

            C_steps++;
            column_diff--;
            fprintf(fpOut, "%d %d %d\n", new_line, (*prob_node)->c_1 + C_steps, 
            (*prob_node)->matrix[new_line - 1][(*prob_node)->c_1 + C_steps - 1]);

        }else if(line_diff == 0 && column_diff < 0){ /* Go left */

            C_steps++;
            column_diff--;
            fprintf(fpOut, "%d %d %d\n", new_line, (*prob_node)->c_1 + C_steps, 
            (*prob_node)->matrix[new_line - 1][(*prob_node)->c_1 + C_steps - 1]);
        }
    }while (line_diff != 0 || column_diff != 0);
    return;    
}

void free_prob_node_data(ProbInfo **prob_node){    
    if((*prob_node)->tarefa == 3){
        for (int i= 0; i < (*prob_node)->L; i++) {        
            free((*prob_node)->matrix[i]);
        }
        free((*prob_node)->matrix);
        return;
    }
    free((*prob_node)->diamond_vect);
    return;
}
