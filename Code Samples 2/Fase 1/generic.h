/******************************************************************************
 * Header do ficheiro generic.c
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#ifndef genericHeader
#define genericHeader

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
int check_ext(char *argv, char *ext);

/*
 * Output()
 *
 *  Argumentos:
 * 
 *  -Input = nome do ficheiro de entrada
 *  -extIn = extensão para os ficheiros de entrada
 *  -extOut = extensão para os ficheiros de saida
 * 
 *  Descrição: Cria o nome pretendido para o ficheiro de saida 
 * 
 *  Retorno: String com o nome do ficheiro de saida, com a sua extensão 
 */
char *Output(char *Input, char *extIn, char *extOut);

/*
 * abre_ficheiros()
 *
 * Argumentos:
 * 
 * -nome = string com o nome do ficheiro que se quer abrir
 * -mode = string que indica em que modo o ficheiro será aberto
 * 
 * Descrição: Abre os ficheiros no modo pretendido.
 * 
 * Retorno: Um apontador para o início do ficheiro aberto, ou NULL em caso de erro
 */
FILE *abre_ficheiros (char *nome, char *mode);

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
int **read_matriz(FILE *fp, int L_max, int C_max, int dimensao, int *diff_flag, int *empty_flag);

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