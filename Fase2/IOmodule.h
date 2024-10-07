/******************************************************************************
 * Ficheiro header do módulo genérico de interação com ficheiros
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef __IOmodule__
#define __IOmodule__



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
 * malloc_str()
 *
 * Argumentos:
 * 
 *  -str_len = comprimento em bytes da string que se pretende alocar
 * 
 * Descrição: aloca dinamicamente uma string com str_len bytes
 * 
 * Retorno: Um apontador para um bloco de caracteres com str_len bytes
 */
char* malloc_str(size_t str_len);

/*
 * check_ext()
 *
 * Argumentos:
 * 
 *  -argv = vetor de argumentos passados ao programa
 *  -ext = extensão dos ficheiros de entrada
 *
 *  Descrição: Verifica se o ficheiro que contém os problemas foi bem invocado pelo utilizador.
 * 
 *  Retorno: Ficheiro mal invocado => 1
 *           Ficheiro bem invocado => 0
 * 
 */
int check_ext(char *filename, char *extension);

/*
 * change_filenames_extension()
 *
 * Argumentos:
 * 
 *  -FileName = Apontador de caracteres que contém o nome do ficheiro que se pretende modificar
 *  -New_FileName = Bloco de memória vazio onde se pretende colocar o nome modificado do ficheiro
 *  -FileName_len = Tamanho em bytes da string "FileName"
 *  -Extension_len = Tamanho em bytes da extensão que se pretende substituir
 * 
 * Descrição: Substitui a extensão de FileName por outra
 * 
 * Retorno: Apontador de caracteres come do ficheiro em questão, com uma extensão diferente
 */
char* change_filenames_extension(const char* FileName, char* New_FileName, size_t FileName_len, size_t Extension_len);

/*
 * Open_Read_File()
 *
 * Argumentos:
 * 
 * -filename = Apontador de caracteres que contém o nome de um ficheiro
 * 
 * Descrição: Abre o ficheiro "filename" em modo de leitura
 * 
 * Retorno: Um apontador para o início do ficheiro "filename" onde só é possível ler informação
 */
FILE* Open_Read_File(char* filename);

/*
 * Open_Write_File()
 *
 * Argumentos:
 * 
 * -filename = Apontador de caracteres que contém o nome de um ficheiro
 * 
 * Descrição: Abre o ficheiro "filename" em modo de escrita
 * 
 * Retorno: Um apontador para o início do ficheiro "filename" onde só é possível escrever informação
 */
FILE* Open_Write_File(char* filename);

/*
 *open_files()
 *
 * Argumentos:
 * 
 * -Input_Filename = Nome de um ficheiro de entrada
 * 
 * Descrição/retorno: Cria um bloco de memória com um apontador para o ficheiro de entrada e 
 * um para o de saída. Esta função faz questão de verificar se a extensão do ficheiro de entrada
 * está correta ou não
 */
Files *open_files(char* Input_Filename, Files **File);

/*
 * close_files()
 *
 * Argumentos:
 * 
 *  -fblock = apontador para um bloco de memória que contém o apontador do 
 * ficheiro de entrada e o ficheiro de saída
 * 
 * Descrição: Fecha os ficheiros presentes no bloco e liberta a sua memória
 * 
 * Retorno: void
 */
void close_files(Files **fblock);

#endif

