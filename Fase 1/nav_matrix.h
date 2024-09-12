/******************************************************************************
 * Header do ficheiro nav_matrix.h
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
*******************************************************************************/

#ifndef MatrixFileHeader
#define MatrixFileHeader

/*
 * read_matriz()
 *
 * Argumentos:
 * 
 * -fp = apontador para o ficheiro de onde a matriz vai ser lida
 * -L_max = número de linhas da matriz do problema
 * -C_max = número de colunas da matriz do problema
 * -dimensao = número total de entradas da matriz
 * -diff_flag = flag para o caso em que a mancha ocupa toda a matriz
 * -empty_flag = flag que diz se a matriz está vazia ou não
 * 
 * Descrição: A função lê e copia uma matriz de inteiros, de um ficheiro de texto
 * para uma secção de memória alocada dinamicamente
 * 
 * Retorno: Uma matriz de inteiros
 */
int **read_matriz(Files File, int L_max, int C_max, int dimensao, int *diff_flag, int *empty_flag);

/*
 * reset_matriz()
 * 
 * Argumentos:
 * 
 * -matriz = matriz de inteiros que contém os azulejos de um problema
 * -L_max = número de linhas da matriz do problema
 * -C_max = número de colunas da matriz do problema
 *
 * Descrição: Esta função liberta a memória alocada para a matriz recebida e 
 * põe o apontador a apontar para NULL
 * 
 * Retorno: void
 */
void reset_matriz(int **matriz, int L_max, int C_max);

#endif