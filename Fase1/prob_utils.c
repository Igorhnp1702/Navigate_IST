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
    
    (*prob)->bad = 0; /* so far, its a good problem */
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
        
        /* analyze the parameters */        
        if (check_prob(prob, fblock) == 1){
            return prob_flag;
        } 
                
        /* read the diamond from the file to memory */
        
        int line_tracker = 1, column_tracker = 1;           // trackers to know my position on the map, while reading the file        
        int radius = k; if(radius < 0) radius = - radius;   // radius of the diamond
        int dist_to_edge_R = C - c_1;                       // distance between the center of the diamond and the right edge of the map
        int dist_to_edge_L = c_1 - 1;                       // distance between the center of the diamond and the left edge of the map
        int dist_to_bottom = L - l_1;                       // same as above for the bottom edge
        int dist_to_top = l_1 - 1;                          // same as above for the top edge
        int columns_missing_R;                              // columns missing to the right of the center of the diamond
        int columns_missing_L;                              // same as above, to the left of the center of the diamond
        int lines_missing_B;                                // lines missing beneath the center of the diamond
        int lines_missing_T;                                // same as above, above the center of the diamond
        int first_cell_line;
        int first_cell_column;
        int dist_Ctracker_center;
        int dist_Ltracker_center;
        int numbs_before_diamond_start;
        int numbs_2_read_to_diamond;
    
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

        if(lines_missing_T == 0){ // top vertice of the diamond
            first_cell_line = l_1 - radius;
            first_cell_column = c_1;
        }
        
        if(lines_missing_T > 0 && lines_missing_T < c_1){ // lines_missing_T > 0, each line missing on top subtracts 1 to the column
            first_cell_line = 1;            
            first_cell_column = c_1 - lines_missing_T;
        }

        else{
            first_cell_line = 1;            
            first_cell_column = 1;
        }      
        
        numbs_before_diamond_start = (first_cell_line-1)*C + first_cell_column - 1;
        numbs_2_read_to_diamond = 0;     
                                
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
        
        //cells in the center column of the diamond
        numbs_2_read_to_diamond = 2 * radius + 1 - lines_missing_T - lines_missing_B; 
        int i;               

        // left side of the diamond 
        for(i = 1; i <= radius - columns_missing_L; i++){
            numbs_2_read_to_diamond += (2 * (radius-i) + 1 );
            if((lines_missing_T -  i) > 0) {
                numbs_2_read_to_diamond -= lines_missing_T - i;    
            }
            if((lines_missing_B -  i) > 0) {
                numbs_2_read_to_diamond -= lines_missing_B - i;    
            }            
        }

        // right side of the diamond
        for(i = 1; i <= radius - columns_missing_R; i++){ 
            numbs_2_read_to_diamond += (2 * (radius-i) + 1 );
            if((lines_missing_T -  i)> 0) {
                numbs_2_read_to_diamond -= lines_missing_T - i;    
            }
            if((lines_missing_B -  i) > 0) {
                numbs_2_read_to_diamond -= lines_missing_B - i;    
            }           
        }
    
        numbs_2_read_to_diamond--; // the center of the diamond does not count
        (*prob)->diamond_size = numbs_2_read_to_diamond; // the center of the diamond does not count

        if (numbs_2_read_to_diamond > 0){        
            (*prob)->diamond_vect = (int*)calloc(numbs_2_read_to_diamond, sizeof(int));
        }        
        i = 0;

        while (numbs_before_diamond_start != 0)
        {
            fscanf(fblock->Input, "%d", &aux);
            numbs_before_diamond_start--;
            remaining_nums--;
        }
        column_tracker = first_cell_column;
        line_tracker = first_cell_line;
        
        /* Then, pass the information from the file to memory */
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

int check_prob(ProbInfo **prob, Files *fblock) {

    int remaining_nums = (*prob)->L * (*prob)->C;                 // remaining map cells to read from the file        
    int aux = 0;
    int exit_signal = 0;

    if(((*prob)->k) == 0){
        (*prob)->tarefa = 3;        
        fscanf(fblock->Input, "%d", &aux);
        (*prob)->l_2 = aux;
        fscanf(fblock->Input, "%d", &aux);
        (*prob)->c_2 = aux;

        /* if the end position is out of bounds */
        if(((*prob)->l_2 > (*prob)->L || (*prob)->l_2 <= 0) || ((*prob)->c_2 > (*prob)->C || (*prob)->c_2 <= 0)){
            
            (*prob)->bad = 1; /* it's a bad problem */
            exit_signal++;            
            //skip the map
            while (remaining_nums != 0)
            {
                fscanf(fblock->Input, "%d", &aux);
                remaining_nums--;
            }    
            return exit_signal;
        }
    }
    else if((*prob)->k < 0){
        (*prob)->tarefa = 1;
        (*prob)->l_2 = -1;
        (*prob)->c_2 = -1;
    }
    else if ((*prob)->k > 0){
        (*prob)->tarefa = 2;
        (*prob)->l_2 = -1;
        (*prob)->c_2 = -1;
    }
      
    /* if the start position is out of bounds */
    if((((*prob)->l_1 > (*prob)->L || (*prob)->l_1 <= 0) || 
    ((*prob)->c_1 > (*prob)->C || (*prob)->c_1 <= 0)) && (*prob)->bad == 0){
        (*prob)->bad = 1; /* it's a bad problem */
        exit_signal++;
        while (remaining_nums != 0)
        {
            fscanf(fblock->Input, "%d", &aux);
            remaining_nums--;
        }  
        return exit_signal; 
    } 
     /* if the dimensions of the matrix are negative */
    if(((*prob)->L <= 0 || (*prob)->C <= 0) && (*prob)->bad == 0){
        (*prob)->bad = 1; /* it's a bad problem */
        exit_signal++;
        while (remaining_nums != 0)
        {
            fscanf(fblock->Input, "%d", &aux);
            remaining_nums--;
        }  
        return exit_signal; 
    }
    if ((*prob)->tarefa == 3){
                
        exit_signal++;        // no diamond to read, the path is in memory
        int i = 0, j;
        int line_tracker = 1, column_tracker = 1;   // trackers to know my position on the map, while reading the file          
        int numbs_2_first_cell;                
                                               
        numbs_2_first_cell = path_vect_solver(prob);        
        
        // read the file and save the path in memory

        while(numbs_2_first_cell != 0) //skip the numbers before the path
        {
            fscanf(fblock->Input, "%d", &aux);
            numbs_2_first_cell--;
            remaining_nums--;
            column_tracker++;  
            if(column_tracker > (*prob)->C){
                column_tracker = 1;
                line_tracker++;
            }
        }
        i = 0;
                
        while(i < (*prob)->path_size){ //fill the path vector

            fscanf(fblock->Input, "%d", &aux); // get an integer
            remaining_nums--;

            for(j = 0; j < (*prob)->path_size; j++){

                // see if it belongs to the path
                if(((*prob)->path_vect[j]->row == line_tracker) && ((*prob)->path_vect[j]->col == column_tracker)){
                    (*prob)->path_vect[j]->energy = aux;
                    i++;
                    break;
                }
            }
            // update the trackers
            column_tracker++;  
            if(column_tracker > (*prob)->C ){
                column_tracker = 1;
                line_tracker++;
            }                          
        }        
        while (remaining_nums != 0)
        {
            fscanf(fblock->Input, "%d", &aux);
            remaining_nums--;
        }
        return exit_signal;                                  
    }
    return exit_signal;
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
    int i;
    
    /* Traverse the diamond and find the cell with the maximum positive energy */
    
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

    int i;    
    
    fprintf(fpOut, "%d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, 
        (*prob_node)->k, (*prob_node)->l_2, (*prob_node)->c_2);

    for(i = 0; i < (*prob_node)->path_size; i++){
        fprintf(fpOut, "%d %d %d\n", (*prob_node)->path_vect[i]->row, (*prob_node)->path_vect[i]->col, (*prob_node)->path_vect[i]->energy);
    }        
    
    fprintf(fpOut,"\n");
    return;    
}

int path_vect_solver(ProbInfo **prob_node){

    int line_diff = (*prob_node)->l_2 - (*prob_node)->l_1;
    int column_diff = (*prob_node)->c_2 - (*prob_node)->c_1;
    int L_steps = 0, C_steps = 0, new_line = (*prob_node)->l_1, new_column = (*prob_node)->c_1;
    int i, first_cell_line, first_cell_col, numbs_2_first;

    if(line_diff < 0){
        first_cell_line = (*prob_node)->l_1 + line_diff;
    }else{
        first_cell_line = (*prob_node)->l_1;
    }

    if(column_diff < 0){
        first_cell_col = (*prob_node)->c_1 + column_diff;
    }
    else{
        first_cell_col = (*prob_node)->c_1;
    }
    numbs_2_first = (first_cell_line - 1) * (*prob_node)->C + first_cell_col - 1;

    (*prob_node)->path_size = abs(line_diff) + abs(column_diff);
    (*prob_node)->path_vect = (cell**)calloc((*prob_node)->path_size,sizeof(cell*));

    for(i = 0; i<(*prob_node)->path_size; i++){
       (*prob_node)->path_vect[i] = (cell*)calloc(1,sizeof(cell));
    }
    i = 0;
    do{
        
        if(line_diff < 0){ /* Go up */
            L_steps--;
            line_diff++;
            new_line = (*prob_node)->l_1 + L_steps;
            (*prob_node)->path_vect[i]->row = new_line;
            (*prob_node)->path_vect[i]->col = new_column;            
            i++;

        }else if(line_diff > 0){ /* Go down */
            L_steps++;
            line_diff--;
            new_line = (*prob_node)->l_1 + L_steps;
            (*prob_node)->path_vect[i]->row = new_line;
            (*prob_node)->path_vect[i]->col = new_column;            
            i++;

        }
        /* Else, we are in the right line, start moving horizontaly */

        if(line_diff == 0 && column_diff > 0){ /* Go right */

            C_steps++;
            column_diff--;
            new_column = (*prob_node)->c_1 + C_steps;
            (*prob_node)->path_vect[i]->row = new_line;
            (*prob_node)->path_vect[i]->col = new_column;            
            i++;


        }else if(line_diff == 0 && column_diff < 0){ /* Go left */

            C_steps--;
            column_diff++;
            new_column = (*prob_node)->c_1 + C_steps ;
            (*prob_node)->path_vect[i]->row = new_line;
            (*prob_node)->path_vect[i]->col = new_column;            
            i++;

        }
    }while ((line_diff != 0 || column_diff != 0) && i < (*prob_node)->path_size);
    return numbs_2_first;    
}

void free_prob_node_data(ProbInfo **prob_node){    
    if((*prob_node)->tarefa == 3){
        for (int i= 0; i < (*prob_node)->path_size; i++) {        
            free((*prob_node)->path_vect[i]);
        }
        free((*prob_node)->path_vect);
        return;
    }
    free((*prob_node)->diamond_vect);
    return;
}
