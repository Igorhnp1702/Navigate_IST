/******************************************************************************
 * Header do ficheiro nav_InOut.c
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#ifndef InOutFileHeader
#define InOutFileHeader

#include <stdio.h>

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
 * fecha_ficheiros()
 *
 * Argumentos:
 * 
 * fp = apontador para o ficheiro que se quer fechar
 * 
 * Descrição: Fecha o ficheiro associado ao apontador passado.
 * 
 * Retorno: void
 */
void fecha_ficheiros(*FILE fp);

#endif