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

#include <stdio.h>

/*
 * Files datatype
 *
 * Description: Block of memory with two file pointers
 * 
 * Members:
 * 
 * -Input: File pointer for the input file
 * -Output: File pointer for the output file
 */
typedef struct _files {
    FILE* Input;
    FILE* Output;
} Files;

/*
 * Cell datatype
 *
 * Description: Block of memory that holds information about a cell
 * on the map
 * 
 * Members:
 * 
 * -row: The row in which the cell is located
 * -col: The column in which the cell is located
 * -energy: The energy the cell possesses
 */
typedef struct _cell{
    
    int row;
    int col;
    int energy;    

}cell;


typedef struct _cel_list
{
    cell celula;
    Cel_List next; 

}*Cel_List;




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
 * -bad = flag to identify problems with ivalid values for the parameters
 * -diamond_vect = array that holds the energy values of the cells inside the diamond
 * -path_vect = array that holds the blocks of memory associated with the cells inside
 * the path that solves problems of  the 3rd task 
 * -path_size = number of cells in path_vect
 * -diamond_size = number of energy values in diamond_vect
 * 
 **/

typedef struct _prob_info{
    
    int L;
    int C;
    int task;
    int l_1;
    int c_1;
    int k;
    int inicial_energy;
    int minimum_energy;

    int bad;
    int *diamond_vect;
    cell **path_vect;
    int path_size;
    int diamond_size;    

}ProbInfo;

#endif