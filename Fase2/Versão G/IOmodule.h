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
 * -Input: File pointer for the input file
 * -Output: File pointer for the output file
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
 *           <filename> string does not contain <extension> => 0
 * 
 */
int check_ext(char *filename, char *extension);

/*
 * change_filenames_extension()
 *
 * Arguments:
 * 
 *  -FileName = Apontador de caracteres que contém o nome do ficheiro que se pretende modificar
 *  -New_FileName = Bloco de memória vazio onde se pretende colocar o nome modificado do ficheiro
 *  -FileName_len = Tamanho em bytes da string "FileName"
 *  -Extension_len = Tamanho em bytes da extensão que se pretende substituir
 * 
 * Description: Substitui a extensão de FileName por outra
 * 
 * Return: Apontador de caracteres come do ficheiro em questão, com uma extensão diferente
 */
void change_filenames_extension(const char* FileName, char** New_FileName, size_t FileName_len, size_t Extension_len);

/*
 * Open_Read_File()
 *
 * Arguments:
 * 
 * -filename = Apontador de caracteres que contém o nome de um ficheiro
 * 
 * Description: Abre o ficheiro "filename" em modo de leitura
 * 
 * Return: Um apontador para o início do ficheiro "filename" onde só é possível ler informação
 */
FILE* Open_Read_File(char* filename);

/*
 * Open_Write_File()
 *
 * Arguments:
 * 
 * -filename = Apontador de caracteres que contém o nome de um ficheiro
 * 
 * Description: Abre o ficheiro "filename" em modo de escrita
 * 
 * Return: Um apontador para o início do ficheiro "filename" onde só é possível escrever informação
 */
FILE* Open_Write_File(char* filename);

/*
 *open_files()
 *
 * Arguments:
 * 
 * -Input_Filename = Nome de um ficheiro de entrada
 * 
 * Description/Return: Cria um bloco de memória com um apontador para o ficheiro de entrada e 
 * um para o de saída. Esta função faz questão de verificar se a extensão do ficheiro de entrada
 * está correta ou não
 */
Files *open_files(char* Input_Filename);

/*
 * close_files()
 *
 * Arguments:
 * 
 *  -fblock = apontador para um bloco de memória que contém o apontador do 
 * ficheiro de entrada e o ficheiro de saída
 * 
 * Description: Fecha os ficheiros presentes no bloco e liberta a sua memória
 * 
 * Return: void
 */
void close_files(Files **fblock);

#endif

