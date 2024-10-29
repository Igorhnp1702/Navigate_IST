/******************************************************************************
 * Interface for the input/output operations
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef __IOmodule__
#define __IOmodule__

#include <stdio.h>

/*
 * Files datatype
 *
 * Description: Block of memory with two file pointers
 * 
 * Members:
 * 
 * -Input:       File pointer for the input file
 * -Output:      File pointer for the output file
 * -outfile_str: Dynamicaly allocated string to store the name of the output file
 */
typedef struct _files {
    FILE* Input;
    FILE* Output;
    char *outfile_str;    
} Files;

/*
 * malloc_str()
 *
 * Arguments:
 * 
 *  -str_len = length in bytes of the memory block to allocate
 * 
 * Description: Allocates a block of dynamic memory for a sequence of chars
 * 
 * Return: A pointer to a block of memory of str_len bytes to store a string of chars
 */
char* malloc_str(size_t str_len);

/*
 * check_ext()
 *
 * Arguments:
 * 
 *  -filename = string with the file name to be verified
 *  -extension = file extension to be searched in the "filename" string
 *
 *  Description: Check if the string <filename> contains <extension> at the end of it
 * 
 *  Return: <filename> string contains <extension> => 1
 *          <filename> string does not contain <extension> => 0
 * 
 */
int check_ext(char *filename, char *extension);

/*
 * change_filenames_extension()
 *
 * Arguments:
 * 
 *  -FileName = Name of the file to modify
 *  -New_FileName = Block of memory to place the modified name
 *  -FileName_len = Size in bytes of the string "FileName"
 *  -Extension_len = Size in bytes of the extension we want to replace
 * 
 * Description: Replaces the file's extension
 * 
 * Return: A string that contains the same file name, with a different extension
 */
void change_filenames_extension(const char* FileName, char** New_FileName, size_t FileName_len, size_t Extension_len);

/*
 * Open_Read_File()
 *
 * Arguments:
 * 
 * -filename = name of the file to open
 * 
 * Description: Opens "filename" in read mode
 * 
 * Return: Pointer to a file in read mode
 */
FILE* Open_Read_File(char* filename);

/*
 * Open_Write_File()
 *
 * Arguments:
 * 
 * -filename = name of teh file to open
 * 
 * Description: Opens "filename" in write mode
 * 
 * Return: Pointer to a file in write mode
 */
FILE* Open_Write_File(char* filename);

/*
 *open_files()
 *
 * Arguments:
 * 
 * -Input_Filename = Name of an input file
 * 
 * Description/Return: Creates and returns a block of memory
 * with the file pointer to the input file and the file pointer
 * to the output file
 */
Files *open_files(char* Input_Filename);

/*
 * close_files()
 *
 * Arguments:
 * 
 *  -fblock = Pointer to a block of memory that possesses the pointers 
 * to the input and output files
 * 
 * Description: Closes the files in the block and frees the memory of
 * the output file's string
 * 
 * Return: void
 */
void close_files(Files **fblock);

#endif

