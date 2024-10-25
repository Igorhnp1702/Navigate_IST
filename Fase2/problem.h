/******************************************************************************
 * Interface for the problem solving functions and utilities
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef _problem_
#define _problem_

#include <stdio.h>
#include "IOmodule.h"
#include "Items.h"
#include "Stack.h"
#include "structs.h"

/*
 * read_problem()
 *
 * Arguments:
 * 
 *  -fblock = Block of memory with the pointer to the input file and the pointer to the output file
 *  -prob = pointer to a block of memory to store the problem's parameters and data
 *  
 * Description: Reads and writes to memory the information related to the problem
 * 
 * Return: A block of memory with all the info needed to solve the problem
 */
int read_problem(Files *fblock, ProbInfo **prob);

/*
 * check_prob()
 *
 * Arguments:
 * 
 *  -prob = pointer to a block of memory with the problem's parameters and data
 *  -fblock = pointer to a block of memory with the input file pointer and the output file pointer
 * 
 * Description: Depending on the problem's parameters, it decides wheather the problem is valid or invalid
 * 
 * Return: An integer (exit_signal) to indicate whether the program flow should continue the read_problem()
 * function or return from it
 */
int check_prob(ProbInfo **prob, Files *fblock);

/*
 * bad_prob_ans()
 *
 * Arguments:
 * 
 *  -fpOut = pointer to the output file
 *  -prob_node = address of the pointer to the problem's info
 * 
 * Description: Prints the answer to an invalid problem
 *  
 * Return: Void
 */
void bad_prob_ans(FILE *fpOut, ProbInfo **prob_node);

/*
 * t1_solver()
 *
 * Arguments:
 * 
 *  -fpOut = pointer to the output file
 *  -prob_node = address of the pointer to the problem's info
 * 
 * Description: Solves the task 1 problems and prints the solution in the output file
 * 
 * Return: void
 */
void t1_solver(FILE *fpOut, ProbInfo **prob_node);

/*
 * t2_solver()
 *
 * Arguments:
 * 
  * -fpOut = pointer to the output file
 *  -prob_node = address of the pointer to the problem's info
 * 
 * Description: Solves the task 2 problems and prints the solution in the output file
 * 
 * Return: void
 */
void t2_solver(FILE *fpOut, ProbInfo **prob_node);


/*
 * insertionSort()
 *
 * Arguments:
 * 
 * -arr = address of the array of cells to be sorted
 * -left = left index of the subarray
 * -right = right index of the subarray
 * 
 * Description: Sorts a partition of arr limited by left and right 
 * with the insertion sort algorithm
 * 
 * Return: void
 */
void insertionSort(stat_cell***arr, int left, int right);

/*
 * merge()
 *
 * Arguments:
 * 
 * -arr = address of the array of cells to be sorted
 * -left = left index of the subarray
 * -mid = middle index of the subarray
 * -right = right index of the subarray
 * 
 * Description: Merges two partitions of arr. The first partition goes
 * from left to mid - 1 and the second goes from mid to right
 * 
 * Return: void
 */
void merge(stat_cell***arr, int left, int mid, int right);

/*
 * timsort()
 *
 * Arguments:
 * 
 * -arr = address of the array of cells to be sorted
 * -arrSize = number of elements inside arr
 * 
 * Description: Sorts arr with the timsort algorithm. In this algorithm, the array 
 * is divided in partitions of size "UnitSize" in a way that allows insertionSort to
 * give a small performance boost in relation to other divide and conquer algorithms 
 * like quicksort or pure mergeSort, reducing the levels of the partition tree by some amount
 * 
 * Note: Our group prefered timsort over quicksort or pure mergesort because we wanted a fast 
 * and stable algorithm that was robust against arrays where the maximum or
 * minimum cell is duplicated. We were also sold on the idea that best case 
 * scenario for timsort is O(n) (which happens for sorted or nearly sorted 
 * arrays. Unlikely to happen but you never know!!). Our implementation of 
 * timsort is an adaptation of the code in the following webpage: 
 * https://www.geeksforgeeks.org/timsort/ (visited on October 17th 2024, at 5:26 PM)
 * 
 * Return: void
 */
void timsort(stat_cell ***arr, int arrSize);

/*
 * Thereishope()
 *
 * Arguments:
 * 
 * -prob_node = address of the pointer to the problem's info;
 * -diamond_vect = address of the pointer to the array of cells inside the diamond;
 * -possible_pocket = current pocket of energy plus the energy of the next cell to analyze in the path;
 * -target = value of energy to beat after k steps;
 * -steps2take = remaining steps to take to complete a valid path;
 * 
 * Description: Checks whether the next cell in the tree search should be added to the paths's stack or not;.
 * 
 * Return: 1 => The next cell can be added to the path's stack;
 *         0 => Don't push the next cell to the stack;
 */
int Thereishope(ProbInfo **prob_node, stat_cell***diamond_vect, int possible_pocket, int target, int steps2take);

/*
 * dist()
 *
 * Arguments:
 * 
 * -a_line = line coordinate of a;
 * -a_column = column coordinate of a;
 * -b_line = line coordinate of b;
 * -b_column = column coordinate of b;
 * 
 * Description/Return: Computes and returns the Manhattan distance between a and b;
 */
int dist(int a_line, int a_column, int b_line, int b_column);

/*
 * copy_path()
 *
 * Arguments:
 * 
 * -pathstack = address of the path's stack;
 * -dest_vect = address of a 3 x k array to store the path's info;
 * -position = function call's position in the path's stack;
 * 
 * Description: Copies the path from the path's stack to a 3 x k array.
 * This array is used to store the best path so far. This function copies 
 * the top of the stack to an auxiliary block of memory, pops it, copies
 * the block of memory to the respective position in the array and then calls itself
 * until it reaches the base of the stack (starting cell). When that happens, pushes
 * the block of memory back to the stack, frees the auxiliary block of memory and
 * returns to the previous call.
 * 
 * Return:void;
 */
void copy_path(Stackblock **pathstack, int ***dest_vect, int position);

/*
 * print_path()
 *
 * Arguments:
 * 
 *  -fpOut = pointer to the output file;
 *  -prob_node = apontador para um bloco de memória que contém os dados do problema;
 *  -pathstack = address of the path's stack;
 *  -stackpos = function call's position in the path's stack;
 * 
 * Description: Prints the solution's path in the output file with recursion. It copies the 
 * top of the stack to an auxiliary block and then calls itself until it reaches the cell on top
 * of the stack's base. At that point, it starts printing the cells one by one and returning to
 * the previous call after one print. 
 * 
 * Side-effects: Since we are printing the problem's solution, each function call is going to free
 * the top of the stack after copying it to an auxiliary block of memory.
 * 
 * Return: void
 */
void print_path(FILE *fpOut, ProbInfo **prob_node, Stackblock **pathstack, int stackpos);

/*
 * free_prob_node()
 * 
 * Arguments:
 * 
 *  -prob_node = address of the pointer to the problem's info;
 * 
 * Description: Frees the memory of the reduced map.
 * 
 * Return: void
 */
void free_reduced_map(ProbInfo **prob_node);

#endif