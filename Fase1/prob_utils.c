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
    
    int L, C, l_1, c_1, k, prob_flag = 0, aux;
    
    (*prob)->flag = 0; /* so far, its a good problem */
    if (fblock->Input == NULL) {
        printf("Error: fblock->Input is null\n");
        exit(1);
    }

    if((fscanf(fblock->Input, "%d %d %d %d %d", &L, &C, &l_1, &c_1, &k)) != EOF){ /* read the header from file to memory */
        
        int remaining_nums = L * C;     // remaining map cells to read from the file
        (*prob)->L = L;
        (*prob)->C = C; 
        (*prob)->l_1 = l_1; 
        (*prob)->c_1 = c_1; 
        (*prob)->k = k; 
        prob_flag = 1;
        
        Get_tarefa(prob, fblock,  (*prob)->L,  (*prob)->C); /* figure out which task we should solve */        

        /* if the dimensions of the matrix are negative */
        if((*prob)->L <= 0 || (*prob)->C <= 0){
            (*prob)->flag = 1; /* it's a bad problem */
            while (remaining_nums != 0)
            {
                fscanf(fblock->Input, "%d", &aux);
                remaining_nums--;
            }  
            return prob_flag; 
        }
        
        /* if the start position is out of bounds */
        if(((*prob)->l_1 > (*prob)->L || (*prob)->l_1 < 0) || ((*prob)->c_1 > (*prob)->C || (*prob)->c_1 < 0)){
            (*prob)->flag = 1; /* it's a bad problem */
            while (remaining_nums != 0)
            {
                fscanf(fblock->Input, "%d", &aux);
                remaining_nums--;
            }  
            return prob_flag; 
        } 
                           
        if((*prob)->tarefa == 3){  // no diamond to read, the map is in memory
            while (remaining_nums != 0)
            {
                fscanf(fblock->Input, "%d", &aux);
                remaining_nums--;
            }  
            return prob_flag;
        }
        
        /* read the diamond from the file to memory */
        int i;                                              // iterator
        int line_tracker = 1, column_tracker = 1;           // trackers to know my position on the map, while reading the file        
        int radius = k; if(radius < 0) radius = -radius;    // radius of the diamond
        int dist_to_edge_R = C - c_1;                       // distance between the center of the diamond and the right edge of the map
        int dist_to_edge_L = c_1 - 1;                       // distance between the center of the diamond and the left edge of the map
        int dist_to_bottom = L - l_1;                       // same as above for the bottom edge
        int dist_to_top = l_1 - 1;                          // same as above for the top edge
        int columns_missing_R;                              // columns missing to the right of the center of the diamond
        int columns_missing_L;                              // same as above, to the left of the center of the diamond
        int lines_missing_B;                                // lines missing beneath the center of the diamond
        int lines_missing_T;                                // same as above, above the center of the diamond

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

        /************************************************************************************************
         * Explanation
         * 
         * The center column (or line) has 2 * radius + 1 cells in a full diamond. The remaining columns
         * (or lines) have the same amount of cells - 2 * (distance to the center column (or line))
         * 
         * When analyzing the diamond with columns, the lines missing on top or bottom will subtract
         * 1 cell each to each column
         * 
         ************************************************************************************************/
        
        for(i = 1; i <= 2*radius + 1 - lines_missing_tot; i++){ 

            if((columns_missing_tot - abs(l_1 - i)) > 0){
                numbs_2_read_to_diamond += (2*radius + 1) - 2*(abs(l_1 - i)) - (columns_missing_tot - abs(l_1 - i));
            }else numbs_2_read_to_diamond += abs((2*radius + 1) - 2*abs(l_1 - i));
        }

        numbs_2_read_to_diamond--; // the center of the diamond does not count
        (*prob)->diamond_size = numbs_2_read_to_diamond; // the center of the diamond does not count

        if (numbs_2_read_to_diamond > 0){        
            (*prob)->diamond_vect = (int*)calloc(numbs_2_read_to_diamond, sizeof(int));
        }        
        i = 0;

        /* Then, pass the information from the file to memory */
        // O SEGFAULT É NESTE WHILE
        while (numbs_2_read_to_diamond != 0)
        {
            
            fscanf(fblock->Input, "%d", &aux);
            
            remaining_nums--;
            dist_Ctracker_center = abs(c_1 - column_tracker);
            dist_Ltracker_center = abs(l_1 - line_tracker);

            if((dist_Ctracker_center + dist_Ltracker_center <= radius) && (dist_Ctracker_center + dist_Ltracker_center > 0)){
    
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

void Get_tarefa(ProbInfo **prob, Files *fblock, int L, int C) {

        int aux = 0;
        int i, j;
        if(((*prob)->k) == 0){
            fscanf(fblock->Input, "%d", &aux);
            (*prob)->l_2 = aux;
            fscanf(fblock->Input, "%d", &aux);
            (*prob)->c_2 = aux;
            /* if the end position is out of bounds */
            if(((*prob)->l_2 > (*prob)->L || (*prob)->l_2 < 0) || ((*prob)->c_2 > (*prob)->C || (*prob)->c_2 < 0)){
                
                (*prob)->flag = 1; /* it's a bad problem */
                return ;
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
            return ;

        }else if((*prob)->k < 0){

            (*prob)->tarefa = 1;
            (*prob)->l_2 = -1;
            (*prob)->c_2 = -1;
        }else if ((*prob)->k > 0){
            (*prob)->tarefa = 2;
            (*prob)->l_2 = -1;
            (*prob)->c_2 = -1;
        }

}


void bad_prob_ans(FILE *fpOut, ProbInfo **prob_node){
    
    if((*prob_node)->tarefa == 1){
         fprintf(fpOut, "%d %d %d %d %d\n\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k);
    }

    if((*prob_node)->tarefa == 2){
         fprintf(fpOut, "%d %d %d %d %d\n\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k);
    }

    if((*prob_node)->tarefa == 3){
         fprintf(fpOut, "%d %d %d %d %d %d %d\n\n", 
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

    fprintf(fpOut, "%d %d %d %d %d %d\n\n", 
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
            
    fprintf(fpOut, "%d %d %d %d %d %d\n\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, sum);
    return;
}

void t3_solver(FILE *fpOut, ProbInfo **prob_node){

    int line_diff = (*prob_node)->l_2 - (*prob_node)->l_1;
    int column_diff = (*prob_node)->c_2 - (*prob_node)->c_1;
    int L_steps = 0, C_steps = 0, new_line = (*prob_node)->l_1, new_column = (*prob_node)->c_1;
    
    fprintf(fpOut, "%d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, 
        (*prob_node)->k, (*prob_node)->l_2, (*prob_node)->c_2);

    do{
        
        if(line_diff < 0){ /* Go up */
            L_steps--;
            line_diff++;
            new_line = (*prob_node)->l_1 + L_steps;
            fprintf(fpOut, "%d %d %d\n", new_line, new_column, 
            (*prob_node)->matrix[new_line - 1][new_column - 1]);

        }else if(line_diff > 0){ /* Go down */
            L_steps++;
            line_diff--;
            new_line = (*prob_node)->l_1 + L_steps;
            fprintf(fpOut, "%d %d %d\n", new_line, new_column, 
            (*prob_node)->matrix[new_line - 1][new_column - 1]);
        }
        /* Else, we are in the right line, start moving horizontaly */

        if(line_diff == 0 && column_diff > 0){ /* Go right */

            C_steps++;
            column_diff--;
            new_column = (*prob_node)->c_1 + C_steps;
            fprintf(fpOut, "%d %d %d\n", new_line, new_column, 
            (*prob_node)->matrix[new_line - 1][new_column- 1]);

        }else if(line_diff == 0 && column_diff < 0){ /* Go left */

            C_steps--;
            column_diff++;
            new_column = (*prob_node)->c_1 + C_steps ;
            fprintf(fpOut, "%d %d %d\n", new_line, new_column, 
            (*prob_node)->matrix[new_line - 1][new_column - 1]);
        }
    }while (line_diff != 0 || column_diff != 0);
    fprintf(fpOut,"\n");
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
