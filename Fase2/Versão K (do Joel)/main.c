/******************************************************************************
 * (c) GRUPO 018 - PROJETO IST NAVIGATE
 *     Filipa Cunha-96016
 *     Joel Graça -102256
 *
 * NOME DO FICHEIRO
 *   main.c
 *
 * DESCRIÇÃO
 *   Programa principal para processamento do projeto IST Navigate, que lê 
 *   mapas e executa tarefas para alcançar energia-alvo ou maximizar energia.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tasks.h"
#include "file.h"

/*****************************************************************************
 * main ()
 *
 * Argumentos: argc - número de argumentos passados pela linha de comando
 *             argv - array de strings com os argumentos do ficheiro de entrada
 *
 * Retorna:     0 no caso de sucesso da execução; outro valor caso contrário
 * Side-Effects: (Nenhum)
 *
 * Descrição:   Este programa recebe um arquivo de entrada com extensão .maps
 *              e gera um arquivo de saída com os resultados processados.
 *              Lê os parâmetros de cada mapa, verifica se o cabeçalho é válido
 *              e executa a respetiva tarefa (tarefa_1 ou tarefa_2) com base no 
 *              valor de task_energy. Os resultados são guardados num novo arquivo 
 *              com extensão .solmaps em caso de sucesso, caso contrário programa
 *              sai silenciosamente.
 ****************************************************************************/
int main(int argc, char* argv[]) {
    
    /* verifica a quantidade de argumentos */
    if(argc != 2){
        return 0;
    }
    
    /* verifica a extensao do arquivo de entrada */
    const char *extensao = strrchr(argv[1], '.'); 

    if (extensao == NULL || strcmp(extensao, ".maps") != 0) {
        return 0; 
    }


    /* aloca memoria e prepara o nome do arquivo de saida com dimensao para a extensao .solmaps */
    size_t len = strlen(argv[1]);

    char *filename_out = (char*) malloc(sizeof(char) * (len - 5 + 10));
    if (filename_out == NULL) {
        return 0;   /* sai se a alocacao de memoria falhar*/
    }

    /* copia o nome do arquivo sem a extensao .maps*/
    strcpy(filename_out, argv[1]);
    filename_out[len - 5] = '\0';

    /* adiciona _out ao final do nome do arquivo e substitui a extensao para .solmaps*/
    strcat(filename_out, ".solmaps");

    /* le o arquivo de entrada */
    FILE *f_in;
    f_in = fopen(argv[1],"r");

    if (f_in == NULL){
        return 0;
    }

    /* Abre o arquivo de saída para escrita */
    FILE *f_out;
    f_out = fopen(filename_out,"w");

    free(filename_out);
    
    /* loop para processar cada cabeçalho no arquivo de entrada */

    while(1){
        NV_Param par;

        /* le o cabeçalho e verifica se há mais dados no arquivo */
        if (!leitura_cabecalho(&par,f_in)){
            break;
        }

       /* Verifica task_energy para determinar a tarefa a executar:
        * - Se task_energy = -2, executa tarefa_2 após validar o cabeçalho.
        * - Para outros valores de task_energy, executa tarefa_1 após validação.
        * em caso de problema mal definido, adiciona uma linha de saída apropriada e ignora o cabeçalho.
         */

        if(par.task_energy == -2){
            
            if(!verificar_cabecalho(par)){
                problema_mal_definido(par, f_in, f_out);  
                continue;
                 }
            tarefa_2(par,f_in,f_out); /* executa tarefa_2*/
        }
        else { 
            if(!verificar_cabecalho(par)){
                problema_mal_definido(par, f_in, f_out);
                continue;
            }
            tarefa_1(par,f_in,f_out); /* executa tarefa_1*/
        }
        
        fprintf(f_out,"\n"); /* adiciona nova linha depois de executar cada tarefa no arquivo de saída*/
    }
    
    /* fecha os arquivos de entrada e saida*/
    fclose(f_in);
    fclose(f_out);

    return 0;
}


