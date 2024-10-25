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
 * Description: Block of memory that holds information about a cell.
 * 
 * Members:
 * 
 * -row:        The row in which the cell is located
 * -col:        The column in which the cell is located
 * -energy:     The energy the cell possesses
 * -isStack:    Is this cell inside the stack/path? 0 = no; 1 = yes
 * -inDiamond:  Is this cell inside the diamond or not? 0 = no; 1 = yes
 * -inSum_maxs: Is this cell's energy value inside the upper bound? 0 = 0; 1 = yes
 * -isCounted:  Is this cell's energy value inside the sum of the highest cells available? 0 = no; 1 = yes
 */
typedef struct _rm_cell{   
    
    int row;
    int col;
    int energy;        
    int inDiamond;
    int inStack;
    int inSum_maxs;
    int isCounted;   

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
 * -initial_energy = energy at the start of the path
 * -target_energy = energy value to reach in task 1 problems
 * 
 * Members related to auxiliary data:
 * 
 * -reduced_map = matrix with just enough cells to fit the diamond
 * -reduced_map_lines = number of lines of the reduced map
 * -reduced_map_columns = number of columns of the reduced map
 * -reduced_map_l1 = line coordinate of the starting cell in the reduced map
 * -reduced_map_c1 = column coordinate of the starting cell in the reduced map
 * -diamond_size = number of energy values in diamond_vect
 * -max_pocket = upper bound for the energy
 * -sum_maxs = sum of the k highest cells in the diamond
 * -bad = flag to identify problems with invalid values for the parameters  
 */
typedef struct _prob_info{
        
    
    int L; 
    int C;
    int task;
    int l_1;
    int c_1;
    int k;
    int initial_energy;
    int target_energy;
                        
    rm_cell ***reduced_map;       
    int reduced_map_lines;
    int reduced_map_columns;
    int reduced_map_l1;
    int reduced_map_c1;    
    int diamond_size;
    int max_pocket;
    int last_max;
    int sum_maxs;  
    int bad;     
       
}ProbInfo;

#endif