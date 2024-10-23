/******************************************************************************
 * Ficheiro header das funções de análise e resolução dos problemas
 * 
 * Autores:
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
 * Argumentos:
 * 
 *  -fblock = bloco de memória com os apontadores dos ficheiros de entrada e de saída
 *  -prob = apontador para um bloco de memória com a informação de um problema
 *  
 * Descrição: Lê e carrega para memória a informação de um problema a resolver
 * 
 * Retorno: Um bloco de memória com toda a informação de um dos problemas do ficheiro
 * de entrada
 */
int read_problem(Files *fblock, ProbInfo **prob);

/*
 * check_prob()
 *
 * Argumentos:
 * 
 *  -prob = apontador para um boco de memória que contém os dados do problema
 *  -fblock = bloco de memória com os apontadores dos ficheiros de entrada e de saída
 * 
 * Descrição: Em função dos valores dos parâmetros do problema, decide 
 * se o problema está bem definido ou não e qual é a tarefa. Para problemas da tarefa 3, 
 * ele guarda em memória as coordenadas das células que pertencem ao caminho
 * 
 * Retorno: Um inteiro (exit_signal) que diz se o fluxo do programa deve continuar na função
 * read_problem() ou não.
 */
int check_prob(ProbInfo **prob, Files *fblock);

//void DFS_max_energy(ProbInfo **prob_node, int row, int col, int energy, int k, int* max_energy, int* max_path_length, struct _cel_list*** max_path);

/*
 * bad_prob_ans()
 *
 * Argumentos:
 * 
 *  -fpOut = apontador para o ficheiro de saída
 *  -prob_node = apontador para o bloco de memória com a informação do problema
 * 
 * Descrição: Imprime a resposta adequada a um problema mal definido no ficheiro de
 * saída
 * 
 * Retorno: Void
 */
void bad_prob_ans(FILE *fpOut, ProbInfo **prob_node);

/*
 * t1_solver()
 *
 * Argumentos:
 * 
 *  -fpOut = apontador para o ficheiro de saída onde deve ser impressa a solução do problema
 *  -prob_node = apontador para um bloco de memória que contém os dados do problema
 * 
 * Descrição: Função que resolve os problemas com a tarefa 1 e imprime a solução no ficheiro
 * de saída
 * 
 * Retorno: void
 */
void t1_solver(FILE *fpOut, ProbInfo **prob_node);

/*
 * t2_solver()
 *
 * Argumentos:
 * 
 *  -fpOut = apontador para o ficheiro de saída onde deve ser impressa a solução do problema
 *  -prob_node = apontador para um bloco de memória que contém os dados do problema
 * 
 * Descrição: Função que resolve os problemas com a tarefa 2 e imprime a solução no ficheiro
 * de saída
 * 
 * Retorno: void
 */
void t2_solver(FILE *fpOut, ProbInfo **prob_node);

void insertionSort(stat_cell***arr, int left, int right);

void merge(stat_cell***arr, int left, int mid, int right);

void timsort(stat_cell ***arr, int arrSize);

int Thereishope(ProbInfo **prob_node, stat_cell***diamond_vect, int pocket, int target, int l_position, int c_position, int steps2take);

int dist(int, int, int, int);

void copy_path(Stackblock **pathstack, int ***dest_vect, int position);

int min(int, int);

/*
 * print_path()
 *
 * Argumentos:
 * 
 *  -fpOut = apontador para o ficheiro de saída onde deve ser impressa a solução do problema
 *  -prob_node = apontador para um bloco de memória que contém os dados do problema
 * 
 * Descrição: Função que imprime a solução no ficheiro de saída
 * 
 * Retorno: void
 */
void print_path(FILE *fpOut, ProbInfo **prob_node, Stackblock **pathstack, int stackpos);

/*
 * free_prob_node()
 * 
 * Argumentos:
 * 
 *  -prob_node = apontador para um bloco de memória que contém a informação de um problema
 * 
 * Descrição: Função que liberta toda a memória alocada dinamicamente para conter a
 * informação de um problema
 * 
 * Retorno: void
 */
void free_prob_node_data(ProbInfo **prob_node);

#endif