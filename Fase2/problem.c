/******************************************************************************
 * Ficheiro *.c com as funções de análise e resolução dos problemas 
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include "problem.h"
#include <stdio.h>

// ler coordenadas no read_problem
// DFS acessar coordenadas do read_problem


int read_problem(Files *fblock, ProbInfo **prob){
    
    int L, C, l_1, c_1, k, task, inicial_energy, prob_flag = 0, aux;

    (*prob)->bad = 0; /* so far, its a good problem */

    if (fblock->Input == NULL) {   // nós já verificámos isto     
        exit(0);
    }

    if((fscanf(fblock->Input, "%d %d %d %d %d %d %d", &L, &C, &task, &l_1, &c_1, &k, &inicial_energy)) != EOF){ /* read the header from file to memory */
        
        int remaining_nums = L * C;     // remaining map cells to read from the file        
        (*prob)->L = L;
        (*prob)->C = C;
        (*prob)->task = task;
        (*prob)->l_1 = l_1; 
        (*prob)->c_1 = c_1; 
        (*prob)->k = k;
        (*prob)->inicial_energy = inicial_energy; 
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
        int first_cell_line;                                // line of the first cell that belongs to the path
        int first_cell_column;                              // column of the first cell that belongs to the path
        int dist_Ctracker_center;                           // distance between the column tracker and the column of the diamond center
        int dist_Ltracker_center;                           // distance between the line tracker and the line of the diamond center
        int numbs_before_diamond_start;                     // number of integers to skip in order to find the first cell that belongs to the diamond
        int numbs_2_read_to_diamond;                        // number of integers to read from the file and save in the diamond's data structure
    
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
    
        // numbs_2_read_to_diamond--;  // the center of the diamond does not count
        (*prob)->diamond_size = numbs_2_read_to_diamond; 

        if (numbs_2_read_to_diamond > 0){        
            (*prob)->diamond_vect = (cell*)calloc(numbs_2_read_to_diamond, sizeof(cell));
        }        
        i = 0;

        while (numbs_before_diamond_start != 0) //skip the useless numbers
        {
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            numbs_before_diamond_start--;
            remaining_nums--;
        }
        column_tracker = first_cell_column;
        line_tracker = first_cell_line;
        
        /* Then, pass the information from the file to memory */
        while (numbs_2_read_to_diamond != 0)
        {
            
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            
            remaining_nums--;
            dist_Ctracker_center = abs(c_1 - column_tracker);
            dist_Ltracker_center = abs(l_1 - line_tracker);

            if((dist_Ctracker_center + dist_Ltracker_center <= radius) && (dist_Ctracker_center + dist_Ltracker_center >= 0)){
    
                (*prob)->diamond_vect[i].energy = aux;
                (*prob)->diamond_vect[i].row = line_tracker;
                (*prob)->diamond_vect[i].col = column_tracker;
                (*prob)->diamond_vect[i].isVisited = 0;
                i++;
                numbs_2_read_to_diamond--;
            }
            column_tracker++;  
            if(column_tracker > C){
                column_tracker = 1;
                line_tracker++;
            }
        }

        while (remaining_nums != 0) //skip the rest of the map
        {
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            remaining_nums--;
        }                
    }
    return prob_flag;    
}

int check_prob(ProbInfo **prob, Files *fblock) {

    int remaining_nums = (*prob)->L * (*prob)->C;                 // remaining map cells to read from the file        
    int aux = 0;
    int exit_signal = 0;                                          // 1 = read_problem() terminates earlier

    if (((*prob)->task) == -2){
        (*prob)->task = 2;
    }
    else if(((*prob)->task) > 0){
        (*prob)->minimum_energy = (*prob)->task;
        (*prob)->task = 1;
    }
    else{
        (*prob)->bad = 1; /* it's a bad problem */
        exit_signal++;
        while (remaining_nums != 0) // skip the map
        {
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            remaining_nums--;
        }  
        return exit_signal;
    }

    /* if the initial energy is a non-positive number */
    if((*prob)->inicial_energy <= 0){
        (*prob)->bad = 1; /* it's a bad problem */
        exit_signal++;
        while (remaining_nums != 0) // skip the map
        {
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            remaining_nums--;
        }  
        return exit_signal; 
    }

    
    /* if the number of steps is not valid */
    if((*prob)->k < 0 || (*prob)->k >= (*prob)->L * (*prob)->C){
        (*prob)->bad = 1; /* it's a bad problem */
        exit_signal++;
        while (remaining_nums != 0) // skip the map
        {
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            remaining_nums--;
        }  
        return exit_signal; 
    }

    /* if the start position is out of bounds */
    if((((*prob)->l_1 > (*prob)->L || (*prob)->l_1 <= 0) || 
    ((*prob)->c_1 > (*prob)->C || (*prob)->c_1 <= 0)) && (*prob)->bad == 0){
        (*prob)->bad = 1; /* it's a bad problem */
        exit_signal++;
        while (remaining_nums != 0) // skip the map
        {
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            remaining_nums--;
        }  
        return exit_signal; 
    } 
     /* if the dimensions of the matrix are negative */
    if(((*prob)->L <= 0 || (*prob)->C <= 0) && (*prob)->bad == 0){
        (*prob)->bad = 1; /* it's a bad problem */
        exit_signal++;
        while (remaining_nums != 0) // skip the map
        {
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            remaining_nums--;
        }  
        return exit_signal; 
    }

    return exit_signal;
}


void bad_prob_ans(FILE *fpOut, ProbInfo **prob_node){
    
    if((*prob_node)->task == 1){
         fprintf(fpOut, "%d %d %d %d %d %d %d\n\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->minimum_energy, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, (*prob_node)->inicial_energy);
    }

    if((*prob_node)->task == 2){
         fprintf(fpOut, "%d %d %d %d %d %d %d\n\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->minimum_energy, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, (*prob_node)->inicial_energy);
    }

    return;    
}

/*void DFS(ProbInfo** prob, ) {

    Cel_List c_list = (Cel_List)calloc(1, sizeof(struct _cel_list));
    return c_list;
}*/

void DFS_max_energy(ProbInfo **prob_node, int row, int col, int energy, int k, int* max_energy, int* max_path_length, struct _cel_list*** max_path) {
    
    if (row >= 1 && row <= (*prob_node)->L && col >= 1 && col <= (*prob_node)->C) {
        int index = (row - 1) * (*prob_node)->C + col - 1;
        if (index >= 0 && index < (*prob_node)->diamond_size && (*prob_node)->diamond_vect[index].energy == energy) {
            if (k == 0) {
                if (energy > *max_energy) {
                    *max_energy = energy;
                    *max_path_length = 0;
                    struct _cel_list* new_cell = (struct _cel_list*)calloc(1, sizeof(struct _cel_list));
                    new_cell->celula.row = row;
                    new_cell->celula.col = col;
                    new_cell->next = **max_path;
                    **max_path = new_cell;
                }
            } else {
                DFS_max_energy(prob_node, row - 1, col, energy, k - 1, max_energy, max_path_length, max_path);
                DFS_max_energy(prob_node, row + 1, col, energy, k - 1, max_energy, max_path_length, max_path);
                DFS_max_energy(prob_node, row, col - 1, energy, k - 1, max_energy, max_path_length, max_path);
                DFS_max_energy(prob_node, row, col + 1, energy, k - 1, max_energy, max_path_length, max_path);
            }
        }
    }
}


void t2_solver(FILE *fpOut, ProbInfo **prob_node) {
    int max_energy = 0;
    int max_path_length = 0;
    struct _cel_list* max_path = NULL;
    struct _cel_list** max_path_ptr = &max_path;
    for (int i = 0; i < (*prob_node)->diamond_size; i++) {
        DFS_max_energy(prob_node, (*prob_node)->diamond_vect[i].row, (*prob_node)->diamond_vect[i].col, (*prob_node)->diamond_vect[i].energy, (*prob_node)->k, &max_energy, &max_path_length, &max_path_ptr);
    }
    fprintf(fpOut, "%d %d %d %d %d %d\n", (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, max_energy);
    struct _cel_list* current = *max_path_ptr;
    while (current != NULL) {
        fprintf(fpOut, "%d %d %d\n", current->celula.row, current->celula.col, max_energy);
        current = current->next;
    }
    fprintf(fpOut, "\n");
    return;
}




void t1_solver(FILE *fpOut, ProbInfo **prob_node){

    int max_pos_val = 0;
    int i;
    
    /* Traverse the diamond and find the cell with the maximum positive energy */
    
    
    
    for(i = 0; i < (*prob_node)->diamond_size; i++){
                    
        if((*prob_node)->diamond_vect[i].energy > max_pos_val){
            max_pos_val = (*prob_node)->diamond_vect[i].energy;
        }    
    }

    fprintf(fpOut, "%d %d %d %d %d %d\n\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, max_pos_val);
    return;
}

void t2_solver_1_fase(FILE *fpOut, ProbInfo **prob_node){

    int sum = 0, i;

    /* Traverse the diamond, find cells with positive energy and add them */

    for(i = 0; i < (*prob_node)->diamond_size; i++){
        if((*prob_node)->diamond_vect[i].energy > 0){
            sum += (*prob_node)->diamond_vect[i].energy;
        }
    }
            
    fprintf(fpOut, "%d %d %d %d %d %d\n\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, sum);
    return;
}

void print_path(FILE *fpOut, ProbInfo **prob_node){

    int i;    
    
    fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->task, (*prob_node)->l_1, (*prob_node)->c_1, 
        (*prob_node)->k, (*prob_node)->inicial_energy, (*prob_node)->minimum_energy);

    /* Just read the matrix from start to finish and print the values in each entry */
    
    for(i = 0; i < (*prob_node)->path_size; i++){        
        fprintf(fpOut, "%d %d %d\n", (*prob_node)->path_vect[i]->row, (*prob_node)->path_vect[i]->col, (*prob_node)->path_vect[i]->energy);
    }        
    
    fprintf(fpOut,"\n");
    return;    
}

int path_vect_solver(ProbInfo **prob_node){

    int line_diff = (*prob_node)->l_1;   // difference of lines between the starting cell and the target cell
    int column_diff = (*prob_node)->c_1; // difference of columns between the starting cell and the target cell
    int L_steps = 0, C_steps = 0, new_line = (*prob_node)->l_1, new_column = (*prob_node)->c_1;
    int i, first_cell_line, first_cell_col, numbs_2_first;

    if(line_diff < 0){ // first line is above the starting point
        first_cell_line = (*prob_node)->l_1 + line_diff;
    }else{
        first_cell_line = (*prob_node)->l_1; // first line is the line of the starting point
    }

    if(column_diff < 0){  // first column is to the left of the starting point
        first_cell_col = (*prob_node)->c_1 + column_diff;
    }
    else{
        first_cell_col = (*prob_node)->c_1; // first column is the column of the starting point
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
    if((*prob_node)->task == 3){
        for (int i= 0; i < (*prob_node)->path_size; i++) {        
            free((*prob_node)->path_vect[i]);
        }
        free((*prob_node)->path_vect);
        return;
    }
    free((*prob_node)->diamond_vect);
    return;
}