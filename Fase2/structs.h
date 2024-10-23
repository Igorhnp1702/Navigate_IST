/******************************************************************************
 * File to define the structs of the project
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef __structs__
#define __structs__

/*
 * rm_cell datatype
 *
 * Description: Block of memory that holds information about a cell
 * on the map
 * 
 * Members:
 * 
 * -row:       The row in which the cell is located
 * -col:       The column in which the cell is located
 * -energy:    The energy the cell possesses
 * -isVisited: Is this cell inside the stack/path? 0 = no; 1 = yes
 * -inDiamond: Is this cell inside the diamond or not? 0 = no; 1 = yes
 * -inSum:     Is this cell inside the field of view of the path? 0 = no; 1 = yes
 */
typedef struct _rm_cell{    // reduced map cell 
    
    int row;
    int col;
    int energy;        
    int inDiamond;
    int inStack;
    int inSum;   

}rm_cell;

/*
 * stat_cell datatype
 *
 * Description: Block of memory that holds information about a cell
 * on the map
 * 
 * Members:
 * 
 * -rm_row:       The row in which the cell is located
 * -rm_col:       The column in which the cell is located
 * -rm_energy:    The energy the cell possesses
 * 
 * */

typedef struct _stat_cell{

    int rm_row;
    int rm_col;
    int energy;    

}stat_cell;

/*
 * ProbInfo data type
 *
 * Description: Block of memory that contains the problem's parameters
 * and the data to be used to output its solution
 * 
 * Members related to problem parameters:
 * 
 * -L = amount of lines in the problem's map
 * -C = amount of columns in the problem's map
 * -task = task to be executed on the map
 * -l_1 = the line of the starting cell
 * -c_1 = the column of the starting cell
 * -k = number of steps the student can take
 * -initial_energy = 
 * -target_energy = 
 * 
 * Members related to auxiliary data:
 * -reduced_map = 
 * -reduced_map_lines = 
 * -reduced_map_columns =
 * -reduced_map_l1 = 
 * -reduced_map_c1 =
 * -diamond_size = number of energy values in diamond_vect
 * -max_pocket = 
 * -sum_maxs = 
 * -bad = flag to identify problems with invalid values for the parameters  
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
    int reduced_map_lines;
    int reduced_map_columns;
    int reduced_map_l1;
    int reduced_map_c1;    
    int diamond_size;
    int max_pocket;
    int sum_maxs;  
    int bad;     
       
}ProbInfo;

#endif