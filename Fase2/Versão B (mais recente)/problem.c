/******************************************************************************
 *File to implement the problem solving functions and utilities
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Items.h"
#include "Stack.h"
#include "problem.h"


int read_problem(Files *fblock, ProbInfo **prob){
    
    int L, C, l_1, c_1, k, task, initial_energy, prob_flag = 0, aux;

    (*prob)->bad = 0; /* so far, its a good problem */

    /* read the header from file to memory */
    if((fscanf(fblock->Input, "%d %d %d %d %d %d %d", &L, &C, &task, &l_1, &c_1, &k, &initial_energy)) != EOF){ 
                        
        (*prob)->L = L;
        (*prob)->C = C;
        (*prob)->task = task;
        (*prob)->l_1 = l_1; 
        (*prob)->c_1 = c_1; 
        (*prob)->k = k;
        (*prob)->initial_energy = initial_energy; 
        prob_flag = 1;
        
        /* analyze the parameters, 1 = invalid parameters somewhere */        
        if (check_prob(prob, fblock) == 1){
            return prob_flag;
        } 
                
        /* read the diamond from the file to memory */
        int remaining_nums = L * C;                         // remaining map cells to read from the file
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
        int first_cell_line;                                // line of the first cell that belongs to the diamond
        int first_cell_column;                              // column of the first cell that belongs to the diamond
        int dist_Ctracker_center;                           // distance between the column tracker and the column of the diamond center
        int dist_Ltracker_center;                           // distance between the line tracker and the line of the diamond center
        int numbs_before_reduced_map_start;                 // number of integers before the first cell of the reduced map
        int numbs_2_read_to_diamond;                        // number of integers to read from the file and save in the diamond's data structure 
        int numbs_2_read_to_reduced_map;                    // number of integers to store in the reduced map                
        int i, j;                                           // iterators
        int distance;                                       // temporary variable to store a Manhattan distance between two cells
        
        (*prob)->max_pocket = 0;
               
      
        // check the portions of the diamond that are missing 

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

        //top left corner of the reduced map
        first_cell_line = l_1 - radius + lines_missing_T;
        first_cell_column = c_1 - radius + columns_missing_L;
        
        numbs_before_reduced_map_start = (first_cell_line-1)*C + first_cell_column - 1;
        numbs_2_read_to_diamond = 0;
        numbs_2_read_to_reduced_map = (2*radius + 1 - lines_missing_T - lines_missing_B) * \
                                       (2*radius + 1 - columns_missing_L - columns_missing_R);     
                                
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

        // cells on the left side of the diamond 
        for(i = 1; i <= radius - columns_missing_L; i++){
            numbs_2_read_to_diamond += (2 * (radius-i) + 1 );
            if((lines_missing_T -  i) > 0) {
                numbs_2_read_to_diamond -= lines_missing_T - i;    
            }
            if((lines_missing_B -  i) > 0) {
                numbs_2_read_to_diamond -= lines_missing_B - i;    
            }            
        }

        // cells on the right side of the diamond
        for(i = 1; i <= radius - columns_missing_R; i++){ 
            numbs_2_read_to_diamond += (2 * (radius-i) + 1 );
            if((lines_missing_T -  i)> 0) {
                numbs_2_read_to_diamond -= lines_missing_T - i;    
            }
            if((lines_missing_B -  i) > 0) {
                numbs_2_read_to_diamond -= lines_missing_B - i;    
            }           
        }

        // initialize the limits of the reduced map
        (*prob)->reduced_map_columns = 2 * radius + 1 - (columns_missing_L + columns_missing_R);
        (*prob)->reduced_map_lines = 2 * radius + 1 - (lines_missing_B + lines_missing_T);
        (*prob)->diamond_size = numbs_2_read_to_diamond; 

        // allocate memory for the reduced map
        if (numbs_2_read_to_diamond > 0){        
            (*prob)->reduced_map = (rm_cell***)calloc((*prob)->reduced_map_lines, sizeof(rm_cell**));

            for(i = 0; i < (*prob)->reduced_map_lines; i++){
                (*prob)->reduced_map[i] = (rm_cell**)calloc((*prob)->reduced_map_columns, sizeof(rm_cell*));

                for(j = 0; j < (*prob)->reduced_map_columns; j++){
                    (*prob)->reduced_map[i][j] = (rm_cell*)calloc(1, sizeof(rm_cell));
                }
            }
        }        
        

        while (numbs_before_reduced_map_start != 0 && fscanf(fblock->Input, "%d", &aux) == 1) //skip the useless numbers
        {            
            numbs_before_reduced_map_start--;
            remaining_nums--;
        }
        column_tracker = first_cell_column;
        line_tracker = first_cell_line;
        
        /* Pass the necessary information from the file to memory */

        i = 0, j = 0;
        while (numbs_2_read_to_reduced_map != 0 && fscanf(fblock->Input, "%d", &aux) == 1)
        {            
                    
            remaining_nums--;            

            dist_Ctracker_center = abs(c_1 - column_tracker);
            dist_Ltracker_center = abs(l_1 - line_tracker);

            if((dist_Ctracker_center <= radius) && (dist_Ltracker_center <= radius)){                
                
                numbs_2_read_to_reduced_map--;
                if(i < (*prob)->reduced_map_lines && j < (*prob)->reduced_map_columns){
                                    
                    (*prob)->reduced_map[i][j]->energy = aux;
                    (*prob)->reduced_map[i][j]->row = line_tracker;
                    (*prob)->reduced_map[i][j]->col = column_tracker;                    
                    (*prob)->reduced_map[i][j]->inDiamond = 0;
                    (*prob)->reduced_map[i][j]->inStack = 0;                   
                                        
                    distance = dist(l_1, c_1, line_tracker, column_tracker);
                    
                    if((distance <= radius) && (distance >= 0)){ // belongs to the diamond
                        
                        (*prob)->reduced_map[i][j]->inDiamond = 1;                    
                        numbs_2_read_to_diamond--;

                        if(distance == 0){ // coordinates of the starting cell in teh reduced map
                            (*prob)->reduced_map_l1 = i;
                            (*prob)->reduced_map_c1 = j;
                        }
                    }
                    
                    j++;
                    if(j == (*prob)->reduced_map_columns){ // carriage return, line feed in the reduced map
                        j = 0;
                        i++;
                    }
                }
            }          
            column_tracker++;            
            if(column_tracker > C){ // carriage return, line feed in the original map
                column_tracker = 1;                
                line_tracker++;            
            }
        }

        //skip the rest of the map
        while (remaining_nums != 0 && fscanf(fblock->Input, "%d", &aux) == 1) remaining_nums--;
        
    }
    return prob_flag;    
}

int check_prob(ProbInfo **prob, Files *fblock) {

    int remaining_nums = (*prob)->L * (*prob)->C;                 // remaining map cells to read from the file        
    int aux = 0;                                                  // temporary variable
    int exit_signal = 0;                                          // 1 = read_problem() terminates earlier

    if (((*prob)->task) == -2){
        (*prob)->task = 2;
    }
    else if(((*prob)->task) > 0){
        (*prob)->target_energy = (*prob)->task;
        (*prob)->task = 1;
    }
    else{
        
        (*prob)->bad = 1; /* it's a bad problem */
        
        exit_signal++;
        
        while (remaining_nums != 0 && fscanf(fblock->Input, "%d", &aux) == 1) remaining_nums--; // skip the map
       
        return exit_signal;
    }
    
    /* if the initial energy is a non-positive number */
    if((*prob)->initial_energy <= 0){
        
        (*prob)->bad = 1; /* it's a bad problem */        
        
        exit_signal++;

        while (remaining_nums != 0 && fscanf(fblock->Input, "%d", &aux) == 1) remaining_nums--; // skip the map
         
        return exit_signal; 
    }
    
    /* if the number of steps is not valid */
    if((*prob)->k <= 0){
        
        (*prob)->bad = 1; /* it's a bad problem */        
        
        exit_signal++;
        
        while (remaining_nums != 0 && fscanf(fblock->Input, "%d", &aux) == 1) remaining_nums--; // skip the map
        
        return exit_signal; 
    }

    /* if the start position is out of bounds */
    if((((*prob)->l_1 > (*prob)->L || (*prob)->l_1 <= 0) || 
    ((*prob)->c_1 > (*prob)->C || (*prob)->c_1 <= 0)) && (*prob)->bad == 0){
        
        (*prob)->bad = 1; /* it's a bad problem */        
        
        exit_signal++;
        
        while (remaining_nums != 0 && fscanf(fblock->Input, "%d", &aux) == 1) remaining_nums--; // skip the map
        
        return exit_signal; 
    } 
    return exit_signal;
}

void bad_prob_ans(FILE *fpOut, ProbInfo **prob_node){
    
    if((*prob_node)->task == 1){
        fprintf(fpOut, "%d %d %d %d %d %d %d\n\n", 
                (*prob_node)->L, (*prob_node)->C, (*prob_node)->target_energy, (*prob_node)->l_1, 
                (*prob_node)->c_1, (*prob_node)->k, (*prob_node)->initial_energy);
        return;
    }

    if((*prob_node)->task == 2){
         fprintf(fpOut, "%d %d %d %d %d %d %d\n\n", 
                (*prob_node)->L, (*prob_node)->C, -(*prob_node)->task, (*prob_node)->l_1, 
                (*prob_node)->c_1, (*prob_node)->k, (*prob_node)->initial_energy);
        return;
    }
    else{ // incorrect problem variant
        fprintf(fpOut, "%d %d %d %d %d %d %d\n\n", 
                (*prob_node)->L, (*prob_node)->C, (*prob_node)->task, (*prob_node)->l_1, 
                (*prob_node)->c_1, (*prob_node)->k, (*prob_node)->initial_energy);            
    }
    return;
}

void t1_solver(FILE *fpOut, ProbInfo **prob_node){      

    int pocket = (*prob_node)->initial_energy;             // energy tracker along the path    
    int distance = 0;                                      // auxiliary variable to store a Manhattan distance
    int sum_positives = 0;                                 // sum of the highest positives in the array
    int step_counter = 0;                                  // steps taken
    int target = (*prob_node)->target_energy;              // target energy to achieve               
    int i, j, m;                                           // iterators
    int path_found = 0;                                    // flag that indicates whether a path was found or not
    int line_tracker = (*prob_node)->reduced_map_l1;       // line coordinate of the path's current endpoint
    int col_tracker = (*prob_node)->reduced_map_c1;        // column coordinate of the path's current endpoint   
    int *child_tracker;                                    // to keep track of the child to visit at each step of the path    
    stat_cell **diamond_vect;                              // array to store the diamond's cells in descending order    
    Stackblock* pathStack;                                 // auxiliary stack for the DFS algorithm

    // not allowed to have repeated cells in the path, therefore no solution
    if((*prob_node)->k >= (*prob_node)->L * (*prob_node)->C){ 
        
        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, 
                                                   (*prob_node)->target_energy, (*prob_node)->l_1, (*prob_node)->c_1, 
                                                   (*prob_node)->k, (*prob_node)->initial_energy, -1);
        fprintf(fpOut,"\n");
        return;
        
    }
        
    /* initialize the diamond_vect */

    // diamond size - 1 => the starting cell does not count
    // distance = 0 <=> starting cell

    diamond_vect = (stat_cell**)calloc((*prob_node)->diamond_size - 1, sizeof(stat_cell*));
    
    for(i = 0; i < (*prob_node)->diamond_size - 1; i++){
        diamond_vect[i] = (stat_cell*)calloc(1, sizeof(stat_cell));
        diamond_vect[i]->rm_col = 0;
        diamond_vect[i]->rm_row = 0;
        diamond_vect[i]->energy = 0;        
    }

    /* Extract the diamond from the reduced map */
    m = 0;
    for(i = 0; i < (*prob_node)->reduced_map_lines; i++){
        for (j = 0; j < (*prob_node)->reduced_map_columns; j++){

            distance = dist(i, j, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);        

            if((distance <= (*prob_node)->k) && (distance > 0)){
                    
                diamond_vect[m]->rm_row = i;
                diamond_vect[m]->rm_col = j;
                diamond_vect[m]->energy = (*prob_node)->reduced_map[i][j]->energy;
                m++;                
            }
        }
    }

    /* Sort the diamond */
    timsort(&diamond_vect, (*prob_node)->diamond_size - 1);    

    /* add the first k cells of the diamond */

    for(i = 0; i < (*prob_node)->diamond_size - 1; i++){
                            
        if(diamond_vect[i]->energy <= 0){ // the positives are over
            break;
        }
        
        sum_positives += diamond_vect[i]->energy;
        
    }
                                                                                                                                         
    (*prob_node)->max_pocket = sum_positives + pocket;
    
    
    // if max pocket is smaller or equal to zero, OR smaller than target, problem has no solution, there's no need to search

    if((*prob_node)->max_pocket < target ){
        
        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->target_energy, (*prob_node)->l_1, (*prob_node)->c_1, 
                                                   (*prob_node)->k, (*prob_node)->initial_energy, -1);
        fprintf(fpOut,"\n");

        for(i = 0; i < (*prob_node)->diamond_size - 1; i++){ // free the diamond
            free(diamond_vect[i]);
        }
        free(diamond_vect);        
        
        return;
    }
    
    /* Initialize the stack */
    
    pathStack = initializeStack((*prob_node)->k + 1, sizeof(rm_cell));

    // the starting cell is always in the stack
    push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker])); 
    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;

    // initialize the child_tracker
    
    child_tracker = (int*)calloc((*prob_node)->k + 1, sizeof(int));

    for(i = 0; i < (*prob_node)->k; i++){
        child_tracker[i] = 0;
    }

    while(child_tracker[0] <= 4){

        /* Do I have steps to take ? Do I have energy to take a step? */

        if(step_counter < (*prob_node)->k && pocket > 0){
            
            /* if so, pick a node to visist */

            if(child_tracker[step_counter] == 0){ // above me

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // Is it within the map's bounds?
                if((0 <= line_tracker - 1 && line_tracker - 1 < (*prob_node)->reduced_map_lines) &&
                   (0 <= col_tracker && col_tracker < (*prob_node)->reduced_map_columns)){

                    // Is it within the diamond's bounds?

                    distance = dist(line_tracker - 1, col_tracker, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);

                    if((0 < distance) && (distance <= (*prob_node)->k)){
                        
                        //Is it inside the stack?
                        if((*prob_node)->reduced_map[line_tracker - 1][col_tracker]->inStack == 0){ 
                            
                            if(Thereishope(prob_node, &diamond_vect, 
                                           pocket + (*prob_node)->reduced_map[line_tracker - 1][col_tracker]->energy,
                                           target, (*prob_node)->k - step_counter - 1, line_tracker - 1, col_tracker) == 1){
                                
                                // push to stack and update variables
                                line_tracker--;
                                step_counter++;
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker]));
                                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;                                
                            }                                                                                                   
                        }
                    }
                }
            }

            if(child_tracker[step_counter] == 1){ // to my right

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // Is it within the map's bounds?
                if((0 <= line_tracker && line_tracker < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker + 1 && col_tracker + 1 < (*prob_node)->reduced_map_columns)){
                    
                    // Is it within the diamond's bounds?

                    distance = dist(line_tracker, col_tracker + 1, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);

                    if((0 < distance) && (distance <= (*prob_node)->k)){
                    
                        //Is it inside the stack?
                        if((*prob_node)->reduced_map[line_tracker][col_tracker + 1]->inStack == 0){
                            
                            if(Thereishope(prob_node, &diamond_vect, 
                                           pocket + (*prob_node)->reduced_map[line_tracker][col_tracker + 1]->energy, target,
                                           (*prob_node)->k - step_counter - 1, line_tracker, col_tracker + 1) == 1){
                                // push to stack and update variables
                                col_tracker ++;
                                step_counter++;
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker]));
                                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                            }                                                                                                     
                        }
                    }
                }
            }

            if(child_tracker[step_counter] == 2){ // below me

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // Is it within the map's bounds?            
                if((0 <= line_tracker + 1 && line_tracker + 1 < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker && col_tracker < (*prob_node)->reduced_map_columns)){
                    
                    // Is it within the diamond's bounds?

                    distance = dist(line_tracker + 1, col_tracker, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);

                    if((0 < distance) && (distance <= (*prob_node)->k)){

                        //Is it inside the stack?
                        if((*prob_node)->reduced_map[line_tracker + 1][col_tracker]->inStack == 0){
                            
                            if(Thereishope(prob_node, &diamond_vect, 
                                           pocket + (*prob_node)->reduced_map[line_tracker + 1][col_tracker]->energy, target,
                                           (*prob_node)->k - step_counter - 1, line_tracker + 1, col_tracker) == 1){
                                // push to stack and update variables            
                                line_tracker++;
                                step_counter++;                                
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker]));
                                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                            }                                                            
                        }
                    }
                }
            }

            if(child_tracker[step_counter] == 3){ // to my left

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // Is it within the map's bounds?
                if((0 <= line_tracker && line_tracker < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker - 1 && col_tracker - 1 < (*prob_node)->reduced_map_columns)){
                    
                    // Is it within the diamond's bounds?                 

                    distance = dist(line_tracker, col_tracker - 1, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);

                    if((0 < distance ) && (distance <= (*prob_node)->k)){

                        //Is it inside the stack?
                        if((*prob_node)->reduced_map[line_tracker][col_tracker - 1]->inStack == 0){

                            if(Thereishope(prob_node, &diamond_vect, pocket + (*prob_node)->reduced_map[line_tracker][col_tracker - 1]->energy,
                                           target, (*prob_node)->k - step_counter - 1, line_tracker, col_tracker - 1) == 1){

                                // push to stack and update variables                                                        
                                col_tracker--;
                                step_counter++;                                
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker]));
                                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                            }                                                                                                                    
                        }
                    }
                }                
            }

            // no more options, go back, (it's not the first cell)
            if(child_tracker[step_counter] == 4 && step_counter != 0){ 

                child_tracker[step_counter] = 0;

                if(child_tracker[step_counter - 1] == 1){ // went up, now Im suppoused to go right

                    pop(&pathStack);
                    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                    
                    pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;                                                           
                    line_tracker++;
                    step_counter--;
                }

                else if(child_tracker[step_counter - 1] == 2){ // went right, now Im suppoused to go down

                    pop(&pathStack);
                    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                    
                    pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                    col_tracker--;
                    step_counter--;
                }

                else if(child_tracker[step_counter - 1] == 3){ // went down, now Im suppoused to go left

                    pop(&pathStack);
                    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                    
                    pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                    line_tracker--;
                    step_counter--;
                }

                else if(child_tracker[step_counter - 1] == 4){ // went left, no more options available
                    
                    pop(&pathStack);
                    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                       
                    pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                    col_tracker++;
                    step_counter--;
                }
            }
            else if(child_tracker[step_counter] == 4 && step_counter == 0) break; // tree search is over                        
        }
        else if((step_counter == (*prob_node)->k && pocket < target) ||
                (step_counter < (*prob_node)->k && pocket <= 0)){ // k steps, but below target, or less than k steps and negative energy

            //go back. step_counter == k, avoid segfault  with step_counter--            

            if(child_tracker[step_counter - 1] == 1){ // went up, now Im suppoused to go right

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                               
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                line_tracker++;
                step_counter--;
            }

            else if(child_tracker[step_counter - 1] == 2){ // went right, now Im suppoused to go down

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                     
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                col_tracker--;
                step_counter--;
            }

            else if(child_tracker[step_counter - 1] == 3){ // went down, now Im suppoused to go left

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                line_tracker--;
                step_counter--;
            }

            else if(child_tracker[step_counter - 1] == 4){ // went left, no more options available

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                col_tracker++;
                step_counter--;
            }
        }
        else if(step_counter == (*prob_node)->k && pocket >= target){ // solution was found, print stack from 2nd base to top, with recursion

            fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->target_energy, (*prob_node)->l_1, (*prob_node)->c_1, 
            (*prob_node)->k, (*prob_node)->initial_energy, pocket);

            print_path(fpOut, prob_node, &pathStack, step_counter);
            freeTop(&pathStack);
            freeStack(&pathStack);
            path_found = 1;
            break; // target was reached and the path has k steps        
        }
    }
    
    if(path_found == 0){
        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->target_energy, (*prob_node)->l_1, (*prob_node)->c_1, 
        (*prob_node)->k, (*prob_node)->initial_energy, -1);
        freeStack(&pathStack);
    }

    for(i = 0; i < (*prob_node)->diamond_size - 1; i++){ // free the diamond
        free(diamond_vect[i]);
    }
    free(diamond_vect);
    
    free(child_tracker);

    fprintf(fpOut,"\n");
    return;
}

void t2_solver(FILE *fpOut, ProbInfo **prob_node) {

    int pocket = (*prob_node)->initial_energy;             // energy tracker along the path            
    int distance = 0;                                      // auxiliary variable to compute the manhattan distance between two cells
    int sum_positives = 0;                                 // sum of the highest positive cells within k steps
    int step_counter = 0;                                  // steps taken
    int target = 0;                                        // target energy to achieve (final energy of the best path so far)        
    int i, j, m;                                           // iterator
    int line_tracker = (*prob_node)->reduced_map_l1;       // line coordinate of the path's current endpoint
    int col_tracker = (*prob_node)->reduced_map_c1;        // column coordinate of the path's current endpoint    
    int path_found = 0;                                    // tells the program that a path was found after traversing the entire map
    int *child_tracker;                                    // to keep track of the child to visit at each step of the path    
    int **best_path_copy;                                  // copy of the best path so far
    stat_cell **diamond_vect;                              // array to store the diamond's cells in descending order
    Stackblock* pathStack;                                 // auxiliary stack to use for the DFS algorithm

    
        
    if((*prob_node)->k >= (*prob_node)->L * (*prob_node)->C){ // not allowed to have repeated cells in the path, therefore no solution
        
        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, -(*prob_node)->task, (*prob_node)->l_1, (*prob_node)->c_1, 
        (*prob_node)->k, (*prob_node)->initial_energy, -1);
        fprintf(fpOut,"\n");
        return;        
    }

    /* initialize best_path_copy */

    best_path_copy = (int**)calloc((*prob_node)->k, sizeof(int*));

    for(i = 0; i < (*prob_node)->k; i++){
        best_path_copy[i] = (int*)calloc(3, sizeof(int));
        best_path_copy[i][0] = 0; // row 
        best_path_copy[i][1] = 0; // col
        best_path_copy[i][2] = 0; // energy        
    }

    /* initialize the diamond_vect */

    // diamond size - 1 => the starting cell does not count
    // distance = 0 <=> starting cell

    diamond_vect = (stat_cell**)calloc((*prob_node)->diamond_size - 1, sizeof(stat_cell*));
    
    for(i = 0; i < (*prob_node)->diamond_size - 1; i++){
        diamond_vect[i] = (stat_cell*)calloc(1, sizeof(stat_cell));
        diamond_vect[i]->rm_col = 0;
        diamond_vect[i]->rm_row = 0;
        diamond_vect[i]->energy = 0;        
    }

    /* Extract the diamond from the reduced map */
    m = 0;
    for(i = 0; i < (*prob_node)->reduced_map_lines; i++){
        for (j = 0; j < (*prob_node)->reduced_map_columns; j++){
            
            distance = dist(i, j, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);

            if((distance <= (*prob_node)->k) && (distance > 0)){
                    
                diamond_vect[m]->rm_row = i;
                diamond_vect[m]->rm_col = j;
                diamond_vect[m]->energy = (*prob_node)->reduced_map[i][j]->energy;
                m++;
            }            
        }
    }

    /* Sort the diamond */
    timsort(&diamond_vect, (*prob_node)->diamond_size - 1);     

    /* Compute the upper bound by adding all the cells in the diamond */

    for(i = 0; i < (*prob_node)->diamond_size - 1; i++){
                            
        if(diamond_vect[i]->energy <= 0){ // the positives are over
            break;
        }
        
        sum_positives += diamond_vect[i]->energy;
        
    }
                                                                                                                                         
    (*prob_node)->max_pocket = sum_positives + pocket;            
    
    /* Initialize the stack */
    
    pathStack = initializeStack((*prob_node)->k + 1, sizeof(rm_cell));

    // the starting cell is always in the stack
    push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker])); 
    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;

    // initialize the child_tracker
    
    child_tracker = (int*)calloc((*prob_node)->k + 1, sizeof(int));  

    while(child_tracker[0] <= 4){

        /* Do I have steps to take ? Do I have energy to take a step? */

        if(step_counter < (*prob_node)->k && pocket > 0){ // positive pocket with steps to take
            
            /* if so, pick a node to visist */

            if(child_tracker[step_counter] == 0){ // above me

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // Is it within the map's bounds?
                if((0 <= line_tracker - 1 && line_tracker - 1 < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker && col_tracker < (*prob_node)->reduced_map_columns)){

                    // Is it within the diamond's bounds?

                    distance = dist(line_tracker - 1, col_tracker, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);

                    if((0 < distance ) && (distance <= (*prob_node)->k)){
                        
                        //Is it inside the stack?
                        if((*prob_node)->reduced_map[line_tracker - 1][col_tracker]->inStack == 0){ 
                            
                            if(Thereishope(prob_node, &diamond_vect, 
                                           pocket + (*prob_node)->reduced_map[line_tracker - 1][col_tracker]->energy,
                                          target, (*prob_node)->k - step_counter - 1, line_tracker - 1, col_tracker) == 1){
                                
                                // push to stack and update variables
                                line_tracker--;
                                step_counter++;
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker]));
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;
                                
                            }                                                                                                   
                        }
                    }
                }
            }

            if(child_tracker[step_counter] == 1){ // to my right

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // Is it within the map's bounds?
                if((0 <= line_tracker && line_tracker < (*prob_node)->reduced_map_lines) &&
                   (0 <= col_tracker + 1 && col_tracker + 1 < (*prob_node)->reduced_map_columns)){
                    
                    // Is it within the diamond's bounds?                    

                    distance = dist(line_tracker, col_tracker + 1, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);

                    if((0 < distance ) && (distance <= (*prob_node)->k)){
                    
                        //Is it inside the stack?
                        if((*prob_node)->reduced_map[line_tracker][col_tracker + 1]->inStack == 0){
                            
                            if(Thereishope(prob_node, &diamond_vect, 
                                           pocket + (*prob_node)->reduced_map[line_tracker][col_tracker + 1]->energy, target,
                                           (*prob_node)->k - step_counter - 1, line_tracker, col_tracker + 1) == 1){
                                
                                // push to stack and update variables
                                col_tracker ++;
                                step_counter++;
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker]));                                
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;
                            }                                                                                                     
                        }
                    }
                }
            }

            if(child_tracker[step_counter] == 2){ // below me

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // Is it within the map's bounds?            
                if((0 <= line_tracker + 1 && line_tracker + 1 < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker && col_tracker < (*prob_node)->reduced_map_columns)){
                    
                    // Is it within the diamond's bounds?

                    distance = dist(line_tracker + 1, col_tracker, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);

                    if((0 < distance ) && (distance <= (*prob_node)->k)){

                        //Is it inside the stack?
                        if((*prob_node)->reduced_map[line_tracker + 1][col_tracker]->inStack == 0){
                            
                            if(Thereishope(prob_node, &diamond_vect, pocket + (*prob_node)->reduced_map[line_tracker + 1][col_tracker]->energy, 
                            target, (*prob_node)->k - step_counter - 1, line_tracker + 1, col_tracker) == 1){
                                
                                // push to stack and update variables            
                                line_tracker++;
                                step_counter++;                                
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker]));
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;
                                
                            }                                                            
                        }
                    }
                }
            }

            if(child_tracker[step_counter] == 3){ // to my left

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // Is it within the map's bounds?
                if((0 <= line_tracker && line_tracker < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker - 1 && col_tracker - 1 < (*prob_node)->reduced_map_columns)){
                    
                    // Is it within the diamond's bounds?

                    distance = dist(line_tracker, col_tracker - 1, (*prob_node)->reduced_map_l1, (*prob_node)->reduced_map_c1);

                    if((0 < distance ) && (distance <= (*prob_node)->k)){

                        //Is it inside the stack?
                        if((*prob_node)->reduced_map[line_tracker][col_tracker - 1]->inStack == 0){

                            if(Thereishope(prob_node, &diamond_vect, pocket + (*prob_node)->reduced_map[line_tracker][col_tracker - 1]->energy, 
                            target, (*prob_node)->k - step_counter - 1, line_tracker, col_tracker - 1) == 1){

                            
                                // push to stack and update variables
                                col_tracker--;
                                step_counter++;                                                        
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker]));
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;
                                
                            }
                        }
                    }
                }                
            }

           // no more options, go back, (it's not the first cell)
            if(child_tracker[step_counter] == 4 && step_counter != 0){ 

                child_tracker[step_counter] = 0;

                if(child_tracker[step_counter - 1] == 1){ // went up, now I'm suppoused to go right

                    pop(&pathStack);
                    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;
                    pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                    line_tracker++;
                    step_counter--;
                }

                else if(child_tracker[step_counter - 1] == 2){ // went right, now I'm suppoused to go down

                    pop(&pathStack);
                    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                  
                    pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                    col_tracker--;
                    step_counter--;
                }

                else if(child_tracker[step_counter - 1] == 3){ // went down, now I'm suppoused to go left

                    pop(&pathStack);
                    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                       
                    pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                    line_tracker--;
                    step_counter--;
                }

                else if(child_tracker[step_counter - 1] == 4){ // went left, no more options available

                    pop(&pathStack);
                    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                        
                    pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                    col_tracker++;
                    step_counter--;
                }
            }
            // no more options, tree search is over
            else if(child_tracker[0] == 4 && step_counter == 0) break;                         
        
        }
        // ideal path was found, print stack from 2nd base to top, with recursion
        else if(step_counter == (*prob_node)->k && pocket == (*prob_node)->max_pocket){         

            fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, -(*prob_node)->task, (*prob_node)->l_1, (*prob_node)->c_1, 
                                                        (*prob_node)->k, (*prob_node)->initial_energy, pocket);

            print_path(fpOut, prob_node, &pathStack, step_counter);
            freeTop(&pathStack);
            freeStack(&pathStack);
            
            // free the diamond
            for(i = 0; i < (*prob_node)->diamond_size - 1; i++){ 
                free(diamond_vect[i]);
            }
            free(diamond_vect);

            // free the child_tracker                        
            free(child_tracker);

            // free best_path_copy
            for(i = 0; i < (*prob_node)->k; i++){ 
                free(best_path_copy[i]);
            }
            free(best_path_copy);            

            fprintf(fpOut,"\n");
            return;
            
        }
        // What if I didn't reach the score of the previous path? 
        else if(step_counter <= (*prob_node)->k && pocket <= target){ 
        // worse or equal path was found

            //go back and keep looking until the maximum energy is reached or until you run out of options in the diamond
            //step_counter == k, avoid segfault with step_counter--

            if(child_tracker[step_counter - 1] == 1){ // went up, now I'm suppoused to go right

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                line_tracker++;
                step_counter--;
            }

            else if(child_tracker[step_counter - 1] == 2){ // went right, now I'm suppoused to go down

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                               
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                col_tracker--;
                step_counter--;
            }

            else if(child_tracker[step_counter - 1] == 3){ // went down, now I'm suppoused to go left

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                line_tracker--;
                step_counter--;
            }

            else if(child_tracker[step_counter - 1] == 4){ // went left, no more options available

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                                                
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                col_tracker++;
                step_counter--;
            }
        }
        else if(step_counter == (*prob_node)->k && pocket > target){ 
        // a better path was found 

            //update the flag
            path_found = 1;
            
            // update the target
            target = pocket;            

            // copy the stack to the temporary array            
            copy_path(&pathStack, &best_path_copy, step_counter - 1);
            
            //go back and try to find a better one

            if(child_tracker[step_counter - 1] == 1){ // went up, now I'm suppoused to go right

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                               
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                line_tracker++;
                step_counter--;
            }

            else if(child_tracker[step_counter - 1] == 2){ // went right, now I'm suppoused to go down

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                col_tracker--;
                step_counter--;
            }

            else if(child_tracker[step_counter - 1] == 3){ // went down, now I'm suppoused to go left

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                line_tracker--;
                step_counter--;
            }

            else if(child_tracker[step_counter - 1] == 4){ // went left, no more options available

                pop(&pathStack);
                (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 0;                
                pocket -= (*prob_node)->reduced_map[line_tracker][col_tracker]->energy;
                col_tracker++;
                step_counter--;
            }
        }
    }

    if(path_found == 0){ // a path with k steps is impossible
        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, -(*prob_node)->task, (*prob_node)->l_1, (*prob_node)->c_1, 
                                                    (*prob_node)->k, (*prob_node)->initial_energy, -1);
        freeStack(&pathStack);
    }
    
    // print the best path you found after traversing the entire diamond
    else{
        
        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, -(*prob_node)->task, (*prob_node)->l_1, (*prob_node)->c_1, 
                                                    (*prob_node)->k, (*prob_node)->initial_energy, target);
        
        for(i = 0; i < (*prob_node)->k; i++){
            
            fprintf(fpOut, "%d %d %d\n", best_path_copy[i][0], best_path_copy[i][1], best_path_copy[i][2]);   
        }
        freeStack(&pathStack);
    }
 
    // free the diamond_vect
    for(i = 0; i < (*prob_node)->diamond_size - 1; i++){ 
        free(diamond_vect[i]);
    }
    free(diamond_vect);

    // free the child_tracker
    free(child_tracker);

    // free best_path_copy
    for(i = 0; i < (*prob_node)->k; i++){ 
        free(best_path_copy[i]);
    }
    free(best_path_copy);    

    fprintf(fpOut,"\n");
    return;
}

void copy_path(Stackblock **pathstack, int ***dest_vect, int position){

    // copy the top to an auxiliary block of memory
    
    rm_cell *aux1, *aux2;    
    aux1 = (rm_cell*)calloc(1, sizeof(rm_cell));
    aux2 = (rm_cell*)peekTop(pathstack);    
    aux1->row = aux2->row;
    aux1->col = aux2->col;
    aux1->energy = aux2->energy;

    // pop it from the stack
    pop(pathstack);

    //place it in the vector
    (*dest_vect)[position][0] = aux1->row;
    (*dest_vect)[position][1] = aux1->col;
    (*dest_vect)[position][2] = aux1->energy;

    // check the recursion's stop condition
    if(position == 0){    

        // push the cell back to the stack, free the auxiliary variable and
        // return to the previous call

        push(pathstack, (Item)aux1);
        free(aux1);
        return;
    }
    copy_path(pathstack, dest_vect, --position);
    push(pathstack, (Item)aux1);
    free(aux1);
    return;

}

// Insertion sort for small arrays
void insertionSort(stat_cell***arr, int left, int right) {
    
    stat_cell* temp = (stat_cell*)calloc(1, sizeof(stat_cell));

    for (int i = left + 1; i <= right; i++) {

        // place the next cell in a temporary block
        temp->rm_row = (*arr)[i]->rm_row;
        temp->rm_col = (*arr)[i]->rm_col;
        temp->energy = (*arr)[i]->energy;
        int j = i - 1;

        // while the cells on the left side of temp are smaller than temp
        // move them to the right
        while (j >= left && (*arr)[j]->energy < temp->energy) {
            (*arr)[j + 1]->rm_row = (*arr)[j]->rm_row;
            (*arr)[j + 1]->rm_col = (*arr)[j]->rm_col;
            (*arr)[j + 1]->energy = (*arr)[j]->energy;
            j--;
        }
        //insert temp in the right place
        (*arr)[j + 1]->rm_row = temp->rm_row;
        (*arr)[j + 1]->rm_col = temp->rm_col;
        (*arr)[j + 1]->energy = temp->energy;
    }
    free(temp);
    return;
}

// Merge function to merge two sorted halves
void merge(stat_cell***arr, int left, int mid, int right) {
    
    int i, j, k;                                    // iterators
    int len1 = mid - left + 1, len2 = right - mid;  // sizes of the two halves

    // Allocate memory for the two partitions
    
    stat_cell** leftArr = (stat_cell**)calloc(len1, sizeof(stat_cell*));
    for(i = 0; i < len1; i++){
        leftArr[i] = (stat_cell*)calloc(1, sizeof(stat_cell));
    }
    
    stat_cell** rightArr = (stat_cell**)calloc(len2, sizeof(stat_cell*));
    for(i = 0; i < len2; i++){
        rightArr[i] = (stat_cell*)calloc(1, sizeof(stat_cell));
    }

    // copy the memory from the array to the partitions
    
    for (i = 0; i < len1; i++){
     
        leftArr[i]->rm_row = (*arr)[left + i]->rm_row;
        leftArr[i]->rm_col = (*arr)[left + i]->rm_col;
        leftArr[i]->energy = (*arr)[left + i]->energy;
    }    
    
    for (i = 0; i < len2; i++){
        rightArr[i]->rm_row = (*arr)[mid + 1 + i]->rm_row;
        rightArr[i]->rm_col = (*arr)[mid + 1 + i]->rm_col;
        rightArr[i]->energy = (*arr)[mid + 1 + i]->energy;
    }

    // merge the two partitions

    i = 0, j = 0, k = left;    
    while (i < len1 && j < len2) {
        if (leftArr[i]->energy >= rightArr[j]->energy){ // cell from the left partition goes first

            (*arr)[k]->rm_row = leftArr[i]->rm_row;
            (*arr)[k]->rm_col = leftArr[i]->rm_col;
            (*arr)[k]->energy = leftArr[i]->energy;
            i++;
        } else {                                        // cell from the right partition goes first
            (*arr)[k]->rm_row = rightArr[j]->rm_row;
            (*arr)[k]->rm_col = rightArr[j]->rm_col;
            (*arr)[k]->energy = rightArr[j]->energy;
            j++;
        }
        k++;
    }

    // if all the cells from the right partition were used, 
    // fill the remaining spaces with the cells from the left partition
    while (i < len1) { 
        
        (*arr)[k]->rm_row = leftArr[i]->rm_row;
        (*arr)[k]->rm_col = leftArr[i]->rm_col;
        (*arr)[k]->energy = leftArr[i]->energy;
        i++;
        k++;
    }

    // if all the cells from the left partition were used, 
    // fill the remaining spaces with the cells from the right partition
    while (j < len2) {
        
        (*arr)[k]->rm_row = rightArr[j]->rm_row;
        (*arr)[k]->rm_col = rightArr[j]->rm_col;
        (*arr)[k]->energy = rightArr[j]->energy;
        j++;
        k++;
    }

    // free the auxiliary partitions
        
    for(i = 0; i < len1; i++){
        free(leftArr[i]);
    }
    free(leftArr);
    
    for(i = 0; i < len2; i++){
        free(rightArr[i]);
    }
    free(rightArr);
}

// Iterative Timsort function
void timsort(stat_cell ***arr, int arrSize) {

    int unitSize = 32; // size of the unit block of the array where insertion sort can be used. Chosen empirically

    // Sort individual subarrays of size "unitSize" using insertion sort
    for (int i = 0; i < arrSize; i += unitSize) {
        int right = (i + unitSize - 1 < arrSize - 1) ? i + unitSize - 1 : arrSize - 1;
        insertionSort(arr, i, right);
    }

    // Start merging from size "unitSize" (32). After each merge, the size of merged subarrays is doubled.
    for (int size = unitSize; size < arrSize; size = 2 * size) {
        for (int left = 0; left < arrSize; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < arrSize - 1) ? left + 2 * size - 1 : arrSize - 1;

            // Merge subarrays [left...mid] and [mid+1...right]
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}


int Thereishope(ProbInfo **prob_node, stat_cell***diamond_vect, int new_pocket, int target, int new_steps2take, int new_line, int new_col){
 
    int i, sum_positives = 0, distance, sum = 0;
    

    for(i = 0; i < (*prob_node)->diamond_size - 1; i++){
        
        if((*diamond_vect)[i]->energy <= 0 && sum_positives == 0){
        
            sum_positives = sum + new_pocket;
            if(sum_positives < target) {return 0;}
            else break;

        
        }  // check if the sum of the positives is enough                                        

        if((*prob_node)->reduced_map[(*diamond_vect)[i]->rm_row][(*diamond_vect)[i]->rm_col]->inStack == 1) continue;
        
        distance = dist((*diamond_vect)[i]->rm_row, (*diamond_vect)[i]->rm_col, new_line, new_col);
        
        if(distance > new_steps2take) continue;   
        
        sum += (*diamond_vect)[i]->energy;            
    }           
    return 1;
}

int dist(int a_line, int a_column, int b_line, int b_column){

    int line_dist = abs(a_line - b_line);        // distance in the lines
    int column_dist = abs(a_column - b_column);  // distance in the columns
    int steps = line_dist + column_dist;         // Manhattan distance

    return steps;
}

void print_path(FILE *fpOut, ProbInfo **prob_node, Stackblock **pathstack, int stackpos){

    // copy the top to an auxiliary block of memory
    
    rm_cell *aux1, *aux2;
    aux1 = (rm_cell*)calloc(1, sizeof(rm_cell));
    aux2 = (rm_cell*)peekTop(pathstack);
    aux1->row = aux2->row;
    aux1->col = aux2->col;
    aux1->energy = aux2->energy;

    // pop it from the stack by freeing its memory
    freeTop(pathstack);

    // check the recursion's stop condition
    if(stackpos == 1){        
        
        // when the first cell of the path is reached, print the cell
        // free the auxiliary variable and return to the previous call
        fprintf(fpOut, "%d %d %d\n", aux1->row, aux1->col, aux1->energy);
        free(aux1);
        return;
    }
    print_path(fpOut, prob_node, pathstack, stackpos - 1);
    fprintf(fpOut, "%d %d %d\n", aux1->row, aux1->col, aux1->energy);
    free(aux1);
    return;    
}

void free_reduced_map(ProbInfo **prob_node){
    int i, j;

    for(i = 0; i < (*prob_node)->reduced_map_lines; i++){
        for(j = 0; j < (*prob_node)->reduced_map_columns; j++){

            //free each cell of the current line
            free((*prob_node)->reduced_map[i][j]);
        }
        // free the entire line
        free((*prob_node)->reduced_map[i]);
    }
    free((*prob_node)->reduced_map); // free the entire thing
    
    return;
}

