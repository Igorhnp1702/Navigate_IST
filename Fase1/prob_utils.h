/******************************************************************************
 * Ficheiro header das funcionalidades do projeto 
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef _prob_utils_
#define _prob_utils_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

/*
 * read_problem()
 *
 * Argumentos:
 * 
 *  -fpIn = apontador para o ficheiro de entrada
 *  -prob_node = apontador para um bloco de memória com a informação de um problema
 *  
 * Descrição: Lê e carrega para memória a informação de um problema a resolver
 * 
 * Retorno: Um bloco de memória com toda a informação de um problema do ficheiro
 * de entrada
 */
ProbInfo *read_problem(Files *fblock);

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
void bad_prob_ans(FILE *fpOut, ProbInfo *prob_node);

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
void t1_solver(FILE *fpOut, ProbInfo *prob_node);

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
void t2_solver(FILE *fpOut, ProbInfo *prob_node);

/*
 * t3_solver()
 *
 * Argumentos:
 * 
 *  -fpOut = apontador para o ficheiro de saída onde deve ser impressa a solução do problema
 *  -prob_node = apontador para um bloco de memória que contém os dados do problema
 * 
 * Descrição: Função que resolve os problemas com a tarefa 3 e imprime a solução no ficheiro
 * de saída
 * 
 * Retorno: void
 */
void t3_solver(FILE *fpOut, ProbInfo *prob_node);

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
void free_prob_node(ProbInfo *prob_node);

#endif