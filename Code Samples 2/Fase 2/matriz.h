/******************************************************************************
 * Ficheiro h onde está definida a interface das matrizes de azulejos
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#ifndef MatrizHeader
#define MatrizHeader

#include <stdio.h>

typedef struct cores{
    int n_azulejos; /* número de azulejos com a cor pretendida*/
    int valor;     /* guarda o valor da cor dos azulejos deste elemento da lista*/    
    struct cores *next;
}cores;


typedef struct entrada{
    int cor;
    char in_mancha;
}entrada;


/*
 * inicializa_lista()
 *
 * Argumentos:
 * 
 * -ptr = apontador para a lista de cores
 * 
 * Descrição: Função que inicializa a lista das cores.
 * 
 * Retorno: void
 */

void incializa_lista(cores **ptr);
/*
 * insere_novacor()
 *
 * Argumentos:
 * 
 * -ptr = apontador para a lista de cores
 * -valor = cor a ser adicionada
 * 
 * Descrição: Cria um novo nó na nossa lista.
 * 
 * Retorno: void
 */

void insere_novacor(cores** ptr, int valor);
/*
 * lista_cores()
 *
 * Argumentos:
 * 
 * -matriz = apontador para o ficheiro de onde a matriz vai ser lida
 * -ptr = apontador para a lista de cores
 * -L_max = número de linhas da matriz do problema
 * -C_max = número de colunas da matriz do problema
 
 * 
 * Descrição: A função que cria a lista de cores existentes numa matriz.
 * 
 * Retorno: void
 */

void lista_cores(entrada ***matriz, cores **ptr, int L_max, int C_max, int *n_cores);
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
 * -ptr = apontador para a lista de cores 
 *
 * Descrição: A função lê e copia uma matriz de inteiros, de um ficheiro de texto
 * para uma secção de memória alocada dinamicamente
 * 
 * Retorno: Uma matriz de inteiros
 */
entrada ***read_matriz(FILE *fp, int L_max, int C_max, int dimensao, cores **ptr, int *n_cores);

/*
 * calculo_potencial()
 * 
 * Argumentos:
 * 
 * -ptr = Apontador para a lista de cores
 *
 * Descrição: função que efetua o cálculo da pontuação máxima se todos os azulejos da mesma cor estivessem juntos na mesma
 * mancha.
 * 
 * Retorno: void
 */
 

int **make_tc(cores ** colourlist, int *pot_inicial, int n_cores);



/*
 * reset_listacor()
 * 
 * Argumentos:
 * 
 * -head = apontador para a cabeça da lista de cores
 *
 * Descrição: Esta função liberta a memória alocada para a lista de cores
 * 
 * Retorno: void
 */
void reset_listacor(cores **head);

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
void reset_matriz(entrada ***matriz, int L_max, int C_max);

/*
 * gravidade()
 *
 * Argumentos:
 *
 *  -matriz = matriz dos "azulejos";
 *  -L_max = índice maximo das linhas da matriz;
 *  -C_max = índice máximo das colunas da matriz;
 *
 * Descrição: Função que implementa a gravidade, tanto a vertical como a horizontal.
 *
 * Retorno: void
 */
void gravidade(entrada ***matriz, int L_max, int C_max);

#endif