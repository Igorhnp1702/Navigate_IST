/******************************************************************************
 * Ficheiro *.c com as funções de análise e resolução dos problemas 
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include "problem.h"
#include "Stack.h"
#include <stdio.h>

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

        (*prob)->reduced_map_columns = 2 * radius + 1 - (columns_missing_L + columns_missing_R);
        (*prob)->reduced_map_lines = 2 * radius + 1 - (lines_missing_B + lines_missing_T);
        (*prob)->diamond_size = numbs_2_read_to_diamond; 

        if (numbs_2_read_to_diamond > 0){        
            (*prob)->reduced_map = (rm_cell***)calloc((*prob)->reduced_map_lines, sizeof(rm_cell**));

            for(i = 0; i < (*prob)->reduced_map_lines; i++){
                (*prob)->reduced_map[i] = (rm_cell**)calloc((*prob)->reduced_map_columns, sizeof(rm_cell*));

                for(j = 0; j < (*prob)->reduced_map_columns; j++){
                    (*prob)->reduced_map[i][j] = (rm_cell*)calloc(1, sizeof(rm_cell));
                }
            }
        }        
        

        while (numbs_before_reduced_map_start != 0) //skip the useless numbers
        {
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            numbs_before_reduced_map_start--;
            remaining_nums--;
        }
        column_tracker = first_cell_column;
        line_tracker = first_cell_line;

        i = 0, j = 0;
        /* Then, pass the information from the file to memory */
        while (numbs_2_read_to_reduced_map != 0)
        {            
            if(fscanf(fblock->Input, "%d", &aux)!= 1){
                exit(0);
            }
            
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
                    
                                
                    
                    if((dist_Ctracker_center + dist_Ltracker_center <= radius) && (dist_Ctracker_center + dist_Ltracker_center >= 0)){
                        
                        (*prob)->reduced_map[i][j]->inDiamond = 1;                    
                        numbs_2_read_to_diamond--;
                    }
                    
                    j++;
                    if(j == (*prob)->reduced_map_columns){
                        j = 0;
                        i++;
                    }
                }
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
        (*prob)->target_energy = (*prob)->task;
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
    if((*prob)->initial_energy <= 0){
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
    if((*prob)->k <= 0){
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
    return exit_signal;
}

void bad_prob_ans(FILE *fpOut, ProbInfo **prob_node){
    
    if((*prob_node)->task == 1){
         fprintf(fpOut, "%d %d %d %d %d %d %d\n\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->target_energy, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, (*prob_node)->initial_energy);
    }

    if((*prob_node)->task == 2){
         fprintf(fpOut, "%d %d %d %d %d %d %d\n\n", 
        (*prob_node)->L, (*prob_node)->C, (*prob_node)->target_energy, (*prob_node)->l_1, (*prob_node)->c_1, (*prob_node)->k, (*prob_node)->initial_energy);
    }
    return;    
}

void t1_solver(FILE *fpOut, ProbInfo **prob_node){      

    int pocket = (*prob_node)->initial_energy;             // energy tracker along the path        
    int step_counter = 0;                                  // steps taken
    int target = (*prob_node)->target_energy;              // target energy to achieve
    int start_line = (*prob_node)->reduced_map_l1;         // line of the starting cell in the reduced map
    int start_col = (*prob_node)->reduced_map_c1;          // column of the starting cell in the reduced map            
    int i, j;                                              // iterator
    int line_tracker = start_line;                         // line coordinate of the path's current endpoint
    int col_tracker = start_col;                           // column coordinate of the path's current endpoint
    int dist_Ltracker_center = line_tracker - start_line;  // distance in lines between an iterator and the center cell    
    int dist_Ctracker_center = col_tracker - start_col;    // distance in columns between an iterator and the center cell
    int *child_tracker;                                    // to keep track of the child to visit at each step of the path
    stat_cell **diamond_vect;                              // array to store the diamond's cells in descending order
    Stackblock* pathStack;                                 // auxiliary stack to use for the DFS algorithm

    if((*prob_node)->k >= (*prob_node)->L * (*prob_node)->C){ // not allowed to have repeated cells in the path, therefore no solution
        
        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->task, (*prob_node)->l_1, (*prob_node)->c_1, 
        (*prob_node)->k, (*prob_node)->initial_energy, -1);
        fprintf(fpOut,"\n");
        return;
        
    }
        
    /* initialize the diamond_vect */

    // diamond size - 1 => the starting cell does not count
    // dist_Ctracker_center + dist_Ltracker_center = 0 <=> starting cell

    diamond_vect = (stat_cell**)calloc((*prob_node)->diamond_size - 1, sizeof(stat_cell*));
    
    for(i = 0; i < (*prob_node)->diamond_size - 1; i++){
        diamond_vect[i] = (stat_cell*)calloc(1, sizeof(stat_cell));
        diamond_vect[i]->rm_col = 0;
        diamond_vect[i]->rm_row = 0;
        diamond_vect[i]->energy = 0;        
    }

    /* Extract the diamond from the reduced map */

    for(i = 0; i < (*prob_node)->reduced_map_lines; i++){
        for (j = 0; j < (*prob_node)->reduced_map_columns; j++){

            dist_Ltracker_center = abs((*prob_node)->reduced_map[i][j]->row - (*prob_node)->l_1);
            dist_Ctracker_center = abs((*prob_node)->reduced_map[i][j]->col - (*prob_node)->c_1);

            if((dist_Ctracker_center + dist_Ltracker_center <= step_counter) && (dist_Ctracker_center + dist_Ltracker_center > 0)){
    
                diamond_vect[i]->rm_col = (*prob_node)->reduced_map[i][j]->col;
                diamond_vect[i]->rm_row = (*prob_node)->reduced_map[i][j]->row;
                diamond_vect[i]->energy = (*prob_node)->reduced_map[i][j]->energy;                
            }
        }
    }

    /* Sort the diamond */
    timsort(&diamond_vect, (*prob_node)->diamond_size); //shell sort with tokuda's sequence    

    /* Check for hope */

    if(Thereishope(prob_node, pocket, line_tracker, col_tracker, target, step_counter, &diamond_vect) != 1){
        
        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->task, (*prob_node)->l_1, (*prob_node)->c_1, 
                                                   (*prob_node)->k, (*prob_node)->initial_energy, -1);
        fprintf(fpOut,"\n");

        for(i = 0; i < (*prob_node)->diamond_size; i++){ // free the diamond
            free(diamond_vect[i]);
        }
        free(diamond_vect);
        return;
    }
    
    /* There is hope, initialize the stack */
    
    pathStack = initializeStack((*prob_node)->k + 1, sizeof(rm_cell));

    // the starting cell is always in the stack
    push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker])); 
    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;

    // initialize the child_tracker
    
    child_tracker = (int*)calloc((*prob_node)->k, sizeof(int));

    for(i = 0; i < (*prob_node)->k; i++){
        child_tracker[i] = 0;
    }

    while(child_tracker[0] != 4){

        /* Do I have steps to take ? Do I have energy to take a step? */

        if(step_counter < (*prob_node)->k && pocket > 0){
            
            /* if so, pick a node to visist */

            if(child_tracker[step_counter] == 0){ // above me

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // check map bounds
                if((0 <= line_tracker - 1 && line_tracker - 1 < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker && col_tracker < (*prob_node)->reduced_map_columns)){

                    // check diamond bounds
                    dist_Ltracker_center = abs(line_tracker - 1 - (*prob_node)->reduced_map_l1);
                    dist_Ctracker_center = abs(col_tracker - (*prob_node)->reduced_map_l1);

                    if((0 < dist_Ctracker_center + dist_Ltracker_center ) && (dist_Ctracker_center + dist_Ltracker_center <= step_counter)){
                        
                        //check presence in stack
                        if((*prob_node)->reduced_map[line_tracker - 1][col_tracker]->inStack == 0){ 
                            
                            // check for hope
                            if(Thereishope(prob_node, pocket + (*prob_node)->reduced_map[line_tracker - 1][col_tracker]->energy, 
                                           line_tracker - 1, col_tracker, target, (*prob_node)->k - step_counter + 1, &diamond_vect) == 1){
                                
                                // push to stack and update variables
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker - 1][col_tracker]));
                                (*prob_node)->reduced_map[line_tracker - 1][col_tracker]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker - 1][col_tracker]->energy;
                                line_tracker--;
                                step_counter++;
                            }            
                        }
                    }
                }
            }

            else if(child_tracker[step_counter] == 1){ // to my right

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // check map bounds
                if((0 <= line_tracker && line_tracker < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker + 1 && col_tracker + 1 < (*prob_node)->reduced_map_columns)){
                    
                    // check diamond bounds
                    dist_Ltracker_center = abs(line_tracker - (*prob_node)->reduced_map_l1);
                    dist_Ctracker_center = abs(col_tracker + 1 - (*prob_node)->reduced_map_l1);

                    if((0 < dist_Ctracker_center + dist_Ltracker_center ) && (dist_Ctracker_center + dist_Ltracker_center <= step_counter)){
                    
                        //check presence in stack
                        if((*prob_node)->reduced_map[line_tracker][col_tracker + 1]->inStack == 0){

                            // check for hope
                            if(Thereishope(prob_node, pocket + (*prob_node)->reduced_map[line_tracker][col_tracker + 1]->energy,
                                           line_tracker, col_tracker + 1, target, (*prob_node)->k - step_counter + 1, &diamond_vect) == 1){
                                
                                // push to stack and update variables
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker + 1]));
                                (*prob_node)->reduced_map[line_tracker][col_tracker + 1]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker + 1]->energy;            
                                col_tracker ++;
                                step_counter++;       
                            }
                        }
                    }
                }
            }

            else if(child_tracker[step_counter] == 2){ // below me

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // check map bounds            
                if((0 <= line_tracker + 1 && line_tracker + 1 < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker && col_tracker < (*prob_node)->reduced_map_columns)){
                    
                    // check diamond bounds
                    dist_Ltracker_center = abs(line_tracker + 1 - (*prob_node)->reduced_map_l1);
                    dist_Ctracker_center = abs(col_tracker - (*prob_node)->reduced_map_l1);

                    if((0 < dist_Ctracker_center + dist_Ltracker_center ) && (dist_Ctracker_center + dist_Ltracker_center <= step_counter)){

                        //check presence in stack
                        if((*prob_node)->reduced_map[line_tracker + 1][col_tracker]->inStack == 0){

                            // check for hope
                            if(Thereishope(prob_node, pocket + (*prob_node)->reduced_map[line_tracker + 1][col_tracker]->energy, 
                                           line_tracker + 1, col_tracker, target, (*prob_node)->k - step_counter + 1, &diamond_vect) == 1){

                                // push to stack and update variables            
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker + 1][col_tracker]));
                                (*prob_node)->reduced_map[line_tracker + 1][col_tracker]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker + 1][col_tracker]->energy;
                                line_tracker ++;
                                step_counter++;
                            }
                        }
                    }
                }
            }

            else if(child_tracker[step_counter] == 3){ // to my left

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // check map bounds
                if((0 <= line_tracker && line_tracker < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker - 1 && col_tracker - 1 < (*prob_node)->reduced_map_columns)){
                    
                    // check diamond bounds
                    dist_Ltracker_center = abs(line_tracker - (*prob_node)->reduced_map_l1);
                    dist_Ctracker_center = abs(col_tracker - 1 - (*prob_node)->reduced_map_l1);

                    if((0 < dist_Ctracker_center + dist_Ltracker_center ) && (dist_Ctracker_center + dist_Ltracker_center <= step_counter)){

                        //check presence in stack
                        if((*prob_node)->reduced_map[line_tracker][col_tracker - 1]->inStack == 0){

                            // check for hope
                            if(Thereishope(prob_node, pocket + (*prob_node)->reduced_map[line_tracker][col_tracker - 1]->energy, 
                                           line_tracker, col_tracker - 1, target, (*prob_node)->k - step_counter + 1, &diamond_vect) == 1){

                                // push to stack and update variables                                                        
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker - 1]));
                                (*prob_node)->reduced_map[line_tracker][col_tracker - 1]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker - 1]->energy;
                                col_tracker --;
                                step_counter++;
                            }
                        }
                    }
                }                
            }

            else if(child_tracker[step_counter] == 4){ // no more options, go back

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
        }
        else if(pocket < target){ // No. What if I didn't reach the target? 

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
        else break; // target was reached and the path has k steps
    }

    if(pocket >= target){ // solution was found, print stack from 2nd base to top, with recursion

        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->target_energy, (*prob_node)->l_1, (*prob_node)->c_1, 
        (*prob_node)->k, (*prob_node)->initial_energy, pocket);

        print_path(fpOut, prob_node, &pathStack, step_counter);
        freeTop(&pathStack);
        freeStack(&pathStack);        
    }
    else{
        fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, (*prob_node)->target_energy, (*prob_node)->l_1, (*prob_node)->c_1, 
        (*prob_node)->k, (*prob_node)->initial_energy, -1);
        freeStack(&pathStack);
    }

    for(i = 0; i < (*prob_node)->diamond_size; i++){ // free the diamond
        free(diamond_vect[i]);
    }
    free(diamond_vect);
    
    free(child_tracker);

    fprintf(fpOut,"\n");
    return;
}

void t2_solver(FILE *fpOut, ProbInfo **prob_node) {

    int pocket = (*prob_node)->initial_energy;             // energy tracker along the path    
    int max_pocket = 0;                                    // final energy of the ideal path
    int step_counter = 0;                                  // steps taken
    int target = 0;                                        // target energy to achieve (final energy of the best path so far)
    int start_line = (*prob_node)->reduced_map_l1;         // line of the starting cell in the reduced map
    int start_col = (*prob_node)->reduced_map_c1;          // column of the starting cell in the reduced map            
    int i, j;                                              // iterator
    int line_tracker = start_line;                         // line coordinate of the path's current endpoint
    int col_tracker = start_col;                           // column coordinate of the path's current endpoint
    int dist_Ltracker_center = line_tracker - start_line;  // distance in lines between an iterator and the center cell    
    int dist_Ctracker_center = col_tracker - start_col;    // distance in columns between an iterator and the center cell
    int path_found = 0;
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
    // dist_Ctracker_center + dist_Ltracker_center = 0 <=> starting cell

    diamond_vect = (stat_cell**)calloc((*prob_node)->diamond_size - 1, sizeof(stat_cell*));
    
    for(i = 0; i < (*prob_node)->diamond_size - 1; i++){
        diamond_vect[i] = (stat_cell*)calloc(1, sizeof(stat_cell));
        diamond_vect[i]->rm_col = 0;
        diamond_vect[i]->rm_row = 0;
        diamond_vect[i]->energy = 0;        
    }

    /* Extract the diamond from the reduced map */

    for(i = 0; i < (*prob_node)->reduced_map_lines; i++){
        for (j = 0; j < (*prob_node)->reduced_map_columns; j++){

            dist_Ltracker_center = abs((*prob_node)->reduced_map[i][j]->row - (*prob_node)->l_1);
            dist_Ctracker_center = abs((*prob_node)->reduced_map[i][j]->col - (*prob_node)->c_1);

            if((dist_Ctracker_center + dist_Ltracker_center <= step_counter) && (dist_Ctracker_center + dist_Ltracker_center > 0)){
    
                diamond_vect[i]->rm_col = (*prob_node)->reduced_map[i][j]->col;
                diamond_vect[i]->rm_row = (*prob_node)->reduced_map[i][j]->row;
                diamond_vect[i]->energy = (*prob_node)->reduced_map[i][j]->energy;                
            }
        }
    }

    /* Sort the diamond */
    timsort(&diamond_vect, (*prob_node)->diamond_size); //shell sort with tokuda's sequence    

    /* Compute the final energy of the ideal path */
    
    int sum_maxs = 0;

    j = 0;
    for(i = 0; i < (*prob_node)->diamond_size; i++){
 
        sum_maxs += diamond_vect[i]->energy;
        j++;
        if(j == (*prob_node)->k)break;
        
    }

    max_pocket = sum_maxs + pocket;

    /* Initialize the stack */
    
    pathStack = initializeStack((*prob_node)->k + 1, sizeof(rm_cell));

    // the starting cell is always in the stack
    push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker])); 
    (*prob_node)->reduced_map[line_tracker][col_tracker]->inStack = 1;

    // initialize the child_tracker
    
    child_tracker = (int*)calloc((*prob_node)->k, sizeof(int));

    for(i = 0; i < (*prob_node)->k; i++){
        child_tracker[i] = 0;
    }

    while(child_tracker[0] != 4){

        /* Do I have steps to take ? Do I have energy to take a step? */

        if(step_counter < (*prob_node)->k && pocket > 0){
            
            /* if so, pick a node to visist */

            if(child_tracker[step_counter] == 0){ // above me

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // check map bounds
                if((0 <= line_tracker - 1 && line_tracker - 1 < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker && col_tracker < (*prob_node)->reduced_map_columns)){

                    // check diamond bounds
                    dist_Ltracker_center = abs(line_tracker - 1 - (*prob_node)->reduced_map_l1);
                    dist_Ctracker_center = abs(col_tracker - (*prob_node)->reduced_map_l1);

                    if((0 < dist_Ctracker_center + dist_Ltracker_center ) && (dist_Ctracker_center + dist_Ltracker_center <= step_counter)){
                        
                        //check presence in stack
                        if((*prob_node)->reduced_map[line_tracker - 1][col_tracker]->inStack == 0){ 
                            
                            // check for hope
                            if(Thereishope(prob_node, pocket + (*prob_node)->reduced_map[line_tracker - 1][col_tracker]->energy, 
                                           line_tracker - 1, col_tracker, target, (*prob_node)->k - step_counter + 1, &diamond_vect) == 1){
                                
                                // push to stack and update variables
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker - 1][col_tracker]));
                                (*prob_node)->reduced_map[line_tracker - 1][col_tracker]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker - 1][col_tracker]->energy;
                                line_tracker--;
                                step_counter++;
                            }            
                        }
                    }
                }
            }

            else if(child_tracker[step_counter] == 1){ // to my right

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // check map bounds
                if((0 <= line_tracker && line_tracker < (*prob_node)->reduced_map_lines) &&
                   (0 <= col_tracker + 1 && col_tracker + 1 < (*prob_node)->reduced_map_columns)){
                    
                    // check diamond bounds
                    dist_Ltracker_center = abs(line_tracker - (*prob_node)->reduced_map_l1);
                    dist_Ctracker_center = abs(col_tracker + 1 - (*prob_node)->reduced_map_l1);

                    if((0 < dist_Ctracker_center + dist_Ltracker_center ) && (dist_Ctracker_center + dist_Ltracker_center <= step_counter)){
                    
                        //check presence in stack
                        if((*prob_node)->reduced_map[line_tracker][col_tracker + 1]->inStack == 0){

                            // check for hope
                            if(Thereishope(prob_node, pocket + (*prob_node)->reduced_map[line_tracker][col_tracker + 1]->energy,
                                           line_tracker, col_tracker + 1, target, (*prob_node)->k - step_counter + 1, &diamond_vect) == 1){
                                
                                // push to stack and update variables
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker + 1]));
                                (*prob_node)->reduced_map[line_tracker][col_tracker + 1]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker + 1]->energy;            
                                col_tracker ++;
                                step_counter++;       
                            }
                        }
                    }
                }
            }

            else if(child_tracker[step_counter] == 2){ // below me

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // check map bounds            
                if((0 <= line_tracker + 1 && line_tracker + 1 < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker && col_tracker < (*prob_node)->reduced_map_columns)){
                    
                    // check diamond bounds
                    dist_Ltracker_center = abs(line_tracker + 1 - (*prob_node)->reduced_map_l1);
                    dist_Ctracker_center = abs(col_tracker - (*prob_node)->reduced_map_l1);

                    if((0 < dist_Ctracker_center + dist_Ltracker_center ) && (dist_Ctracker_center + dist_Ltracker_center <= step_counter)){

                        //check presence in stack
                        if((*prob_node)->reduced_map[line_tracker + 1][col_tracker]->inStack == 0){

                            // check for hope
                            if(Thereishope(prob_node, pocket + (*prob_node)->reduced_map[line_tracker + 1][col_tracker]->energy, 
                                           line_tracker + 1, col_tracker, target, (*prob_node)->k - step_counter + 1, &diamond_vect) == 1){
                                            
                                // push to stack and update variables
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker + 1][col_tracker]));
                                (*prob_node)->reduced_map[line_tracker + 1][col_tracker]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker + 1][col_tracker]->energy;
                                line_tracker ++;
                                step_counter++;
                            }
                        }
                    }
                }
            }

            else if(child_tracker[step_counter] == 3){ // to my left

                // indicate the next child to visit
                child_tracker[step_counter]++;

                // check map bounds
                if((0 <= line_tracker && line_tracker < (*prob_node)->reduced_map_lines) &&
                (0 <= col_tracker - 1 && col_tracker - 1 < (*prob_node)->reduced_map_columns)){
                    
                    // check diamond bounds
                    dist_Ltracker_center = abs(line_tracker - (*prob_node)->reduced_map_l1);
                    dist_Ctracker_center = abs(col_tracker - 1 - (*prob_node)->reduced_map_l1);

                    if((0 < dist_Ctracker_center + dist_Ltracker_center ) && (dist_Ctracker_center + dist_Ltracker_center <= step_counter)){

                        //check presence in stack
                        if((*prob_node)->reduced_map[line_tracker][col_tracker - 1]->inStack == 0){

                            // check for hope
                            if(Thereishope(prob_node, pocket + (*prob_node)->reduced_map[line_tracker][col_tracker - 1]->energy, 
                                           line_tracker, col_tracker - 1, target, (*prob_node)->k - step_counter + 1, &diamond_vect) == 1){

                                // push to stack and update variables                                                        
                                push(&pathStack, (Item)((*prob_node)->reduced_map[line_tracker][col_tracker - 1]));
                                (*prob_node)->reduced_map[line_tracker][col_tracker - 1]->inStack = 1;
                                pocket += (*prob_node)->reduced_map[line_tracker][col_tracker - 1]->energy;
                                col_tracker --;
                                step_counter++;
                            }
                        }
                    }
                }                
            }

            else if(child_tracker[step_counter] == 4){ // no more options, go back

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
        }
        else if(step_counter == (*prob_node)->k && pocket == max_pocket){ // ideal path was found, print stack from 2nd base to top, with recursion

            fprintf(fpOut, "%d %d %d %d %d %d %d %d\n",(*prob_node)->L, (*prob_node)->C, -(*prob_node)->task, (*prob_node)->l_1, (*prob_node)->c_1, 
                                                        (*prob_node)->k, (*prob_node)->initial_energy, pocket);

            print_path(fpOut, prob_node, &pathStack, step_counter);
            freeTop(&pathStack);
            freeStack(&pathStack);

            // free the diamond
            for(i = 0; i < (*prob_node)->diamond_size; i++){ 
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
        else if(step_counter == (*prob_node)->k && pocket <= target){ // What if I didn't reach the score of the previous path? 

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
        else if(step_counter == (*prob_node)->k && pocket > target){ // a better path was found 

            // update the target
            target = pocket;

            // copy the stack to the temporary array            
            copy_path(&pathStack, &best_path_copy, step_counter);
            
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
                                                    (*prob_node)->k, (*prob_node)->initial_energy, pocket);
        
        for(i = 0; i < (*prob_node)->k; i++){
            
            fprintf(fpOut, "%d %d %d\n", best_path_copy[i][0], best_path_copy[i][1], best_path_copy[i][2]);   
        }
    }
    
    // free the diamond_vect
    for(i = 0; i < (*prob_node)->diamond_size; i++){ 
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

    rm_cell *aux;

    aux = (rm_cell*)peekTop(pathstack);
    pop(pathstack);
    (*dest_vect)[position][0] = aux->row;
    (*dest_vect)[position][1] = aux->col;
    (*dest_vect)[position][2] = aux->energy;

    if(position == 0){

        push(pathstack, (Item)aux);
        return;
    }
    copy_path(pathstack, dest_vect, --position);
    push(pathstack, (Item)aux);
    return;

}

// Insertion sort for small arrays
void insertionSort(stat_cell***arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        stat_cell* temp = (*arr)[i];
        int j = i - 1;
        while (j >= left && (*arr)[j]->energy > temp->energy) {
            (*arr)[j + 1]->rm_row = (*arr)[j]->rm_row;
            (*arr)[j + 1]->rm_row = (*arr)[j]->rm_col;
            (*arr)[j + 1]->rm_row = (*arr)[j]->energy;
            j--;
        }
        (*arr)[j + 1]->rm_row = temp->rm_row;
        (*arr)[j + 1]->rm_row = temp->rm_col;
        (*arr)[j + 1]->rm_row = temp->energy;
    }
}

// Merge function to merge two sorted halves
void merge(stat_cell***arr, int left, int mid, int right) {
    
    int i, j, k;
    int len1 = mid - left + 1, len2 = right - mid;
    
    stat_cell** leftArr = (stat_cell**)calloc(len1, sizeof(stat_cell*));
    for(i = 0; i < len1; i++){
        leftArr[i] = (stat_cell*)calloc(1, sizeof(stat_cell));
    }
    
    stat_cell** rightArr = (stat_cell**)calloc(len2, sizeof(stat_cell*));
    for(i = 0; i < len2; i++){
        rightArr[i] = (stat_cell*)calloc(1, sizeof(stat_cell));
    }
    
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
    i = 0, j = 0, k = left;
    
    while (i < len1 && j < len2) {
        if (leftArr[i]->energy <= rightArr[j]->energy) {
            (*arr)[k]->rm_row = leftArr[i]->rm_row;
            (*arr)[k]->rm_col = leftArr[i]->rm_col;
            (*arr)[k]->energy = leftArr[i]->energy;
            i++;
        } else {
            (*arr)[k]->rm_row = rightArr[j]->rm_row;
            (*arr)[k]->rm_col = rightArr[j]->rm_col;
            (*arr)[k]->energy = rightArr[j]->energy;
            j++;
        }
        k++;
    }

    while (i < len1) {
        
        (*arr)[k]->rm_row = leftArr[i]->rm_row;
        (*arr)[k]->rm_col = leftArr[i]->rm_col;
        (*arr)[k]->energy = leftArr[i]->energy;
        i++;
        k++;
    }

    while (j < len2) {
        
        (*arr)[k]->rm_row = rightArr[j]->rm_row;
        (*arr)[k]->rm_col = rightArr[j]->rm_col;
        (*arr)[k]->energy = rightArr[j]->energy;
        j++;
        k++;
    }
    
    free(leftArr);
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

int Thereishope(ProbInfo **prob_node, int pocket, int line_tracker, int column_tracker, int target, int steps2take, stat_cell***diamond_vect){

    int i, j;
    int sum_maxs;
    int sum_positives = 0;
    int isRelevant = 0;

     for(i = 0; i < (*prob_node)->diamond_size; i++){
        
        if((*diamond_vect[i])->energy > 0){
            
            isRelevant = in_Fov((*diamond_vect[i])->rm_row, (*diamond_vect[i])->rm_col, line_tracker, column_tracker, steps2take);
            
            if(isRelevant == 1 && 
            (*prob_node)->reduced_map[(*diamond_vect[i])->rm_row][(*diamond_vect[i])->rm_row]->inStack == 0){
            
                sum_positives += (*diamond_vect[i])->energy;    
            }
                
        }
        else break;
    }

    /* Should I proceed ? */

    if(sum_positives + pocket < target){ // below target, without considering losses of energy
        return 0;
    }

    j = 0;
    for(i = 0; i < (*prob_node)->diamond_size; i++){

        isRelevant = in_Fov((*diamond_vect[i])->rm_row, (*diamond_vect[i])->rm_col, line_tracker, column_tracker, steps2take);

        if(isRelevant == 1 &&
        (*prob_node)->reduced_map[(*diamond_vect[i])->rm_row][(*diamond_vect[i])->rm_row]->inStack == 0){  

            sum_maxs += (*diamond_vect[i])->energy;
            j++;
            if(j == steps2take)break;
        }
    }

    /* Should I proceed ? */    

    if(sum_maxs + pocket < target){ // below target with the best possible path (highest gains and lowest losses)
        return 0;
    }
    return 1;
}

int in_Fov(int input_line, int input_column, int line_tracker, int column_tracker, int steps2take){

    int line_dist = abs(input_line - line_tracker);
    int column_dist = abs(input_column - column_tracker);
    int steps = line_dist + column_dist;

    return steps <= steps2take ? 1 : 0;
}

void print_path(FILE *fpOut, ProbInfo **prob_node, Stackblock **pathstack, int stackpos){

    rm_cell *aux;
    aux = (rm_cell*)peekTop(pathstack);
    freeTop(pathstack);

    if(stackpos == 1){        
        fprintf(fpOut, "%d %d %d\n", aux->row, aux->col, aux->energy);        
        return;
    }
    print_path(fpOut, prob_node, pathstack, stackpos - 1);
    fprintf(fpOut, "%d %d %d\n", aux->row, aux->col, aux->energy);    
    return;    
}

void free_prob_node_data(ProbInfo **prob_node){
    int i, j;

    for(i = 0; i < (*prob_node)->reduced_map_lines; i++){
        for(j = 0; j < (*prob_node)->reduced_map_columns; j++){
            free((*prob_node)->reduced_map[i][j]);
        }
        free((*prob_node)->reduced_map[i]);
    }
    free((*prob_node)->reduced_map);
    return;
}