/******************************************************************************
 * Ficheiro das structs utilizadas no projeto Navigate_IST
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef __structs__
#define __structs__

/*
 * Cell datatype
 *
 * Description: Block of memory that holds information about a cell
 * on the map
 * 
 * Members:
 * 
 * -row:       The row in which the cell is located
 * -col:       The column in which the cell is located
 * -energy:    The energy the cell possesses
 * -isVisited: Did the program visit this cell or not? 0 = no; 1 = yes
 * -inDiamond: Is this cell inside the diamond or not? 0 = no; 1 = yes
 * -inFoV:     Is this cell inside the field of view of the path? 0 = no; 1 = yes
 */
typedef struct _rm_cell{    // reduced map cell 
    
    int row;
    int col;
    int energy;        
    int inDiamond;
    int inStack;
    int inSum;
    int max_Order;
    int dist2center;

}rm_cell;

typedef struct _stat_cell{

    int rm_row;
    int rm_col;
    int energy;
    int block;

}stat_cell;

/*
 * ProbInfo datatype
 *
 * Description: Block of memory that contains the problem's parameters
 * and the data to be used to output its solution
 * 
 * Members:
 * 
 * -L = amount of lines in the problem's map
 * -C = amount of columns in the problem's map
 * -l_1 = the line of the starting cell
 * -c_1 = the column of the starting cell
 * -k = number of steps the student can take
 * -task = task to be executed on the map
 * -l_2 = the line of the target cell for task 3
 * -c_2 = the column of the target cell for task 3
 * -bad = flag to identify problems with invalid values for the parameters
 * -diamond_vect = array that holds the energy values of the cells inside the diamond 
 * -diamond_size = number of energy values in diamond_vect
 * 
 */

typedef struct _prob_info{
    
    // problem parameters
    int L;
    int C;
    int task;
    int l_1;
    int c_1;
    int k;
    int initial_energy;
    int target_energy;
        
    // problem data
    rm_cell ***reduced_map;
    stat_cell ***maxtracker;
    int *max_counter;    
    int reduced_map_lines;
    int reduced_map_columns;
    int reduced_map_l1;
    int reduced_map_c1;    
    int diamond_size;
    int max_pocket;
    int sum_maxs;
    int sum_positives;
    int bad;     
       
}ProbInfo;

#endif