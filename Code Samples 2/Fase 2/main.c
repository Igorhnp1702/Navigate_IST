/******************************************************************************
 * Ficheiro da função principal do projeto dISTiling
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"

#define EXTIN ".tilewalls"
#define EXTOUT ".tileblasts"

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
 * main()
 *
 * Argumentos: argc - número de argumentos da linha de comando
 *             argv - vetor de strings com os argumentos passados
 *
 * Descrição: Função principal do programa que contém o fluxo de alta abstração
 * do programa
 * 
 * Retorno: Estado de sucesso da execução do programa sob a forma de um inteiro
 * 0 = sucesso; 1 = insucesso
 */
int main (int argc, char* argv[])
{    
    /* verifica o número de argumentos */
    
    if(argc !=2){
        exit(0);
    }

    /* verifica a extensão do ficheiro de entrada*/

    if((check_ext(argv[1], EXTIN)) == 1){
        exit(0);
    }

    /* abre o ficheiro de entrada */

    FILE *fpIn;
    if((fpIn = fopen(argv[1], "r")) == NULL){
        exit(0);
    }
    
    /* cria e abre o ficheiro de saída */

    FILE *fpOut;    /* apontadores para o ficheiro de entrada e de saída */
    char* saida;    /* string para o nome do ficheiro de saída */

    saida = Output(argv[1], EXTIN, EXTOUT);

    if((fpOut = fopen(saida, "w")) == NULL){
        exit(0);
    } 
     
    /* resolve os problemas do ficheiro de entrada e imprime as soluções no ficheiro de saída */
    solveprobs(fpIn, fpOut);

    /* prepara para sair, fechando ambos os ficheiros e libertando a string "saida" */
    
    fclose(fpIn);
    fclose(fpOut);    
    free(saida);
    
    return 0; /* sai */
}


int check_ext(char *argstr, char *extIn)
{
    char *aux;
    int argsize = 0, extsize = 0, start = 0, result = 0, i;
    
    extsize = strlen(extIn);
    argsize = strlen(argstr);
    start = argsize - extsize;

    if((aux = (char*)calloc(extsize+1, sizeof(char))) == NULL)
    {
        exit(0);
    }

    for(i = 0; i < extsize; i++){
        aux[i] = argstr[i+start];
    }

    if (strcmp(aux, extIn) != 0){
        free(aux);
        return result + 1;
    }
                    
    else{
        free(aux);
        return result;
    }    
}

char *Output(char *Input, char *extIn, char *extOut)
{
    int argsize = 0, Insize = 0, Outsize = 0, start = 0;
    char *outstr;
    
    Insize = strlen(extIn);
    Outsize = strlen(extOut);
    argsize = strlen(Input);
    start = argsize - Insize; /* índice da entrada onde deve estar o último ponto */

    outstr = (char*)calloc((start + Outsize +1), sizeof(char));

    if(outstr == NULL){
        exit(0);
    }

    strcpy(outstr, Input);
    outstr[start] = '\0';
    strcat(outstr, extOut);

    return outstr;   
}