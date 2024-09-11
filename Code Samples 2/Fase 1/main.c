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
#include "generic.h"
#include "specific.h"

/******************************************************************************
 * main()
 *
 * Argumentos: argc - número de argumentos da linha de comando
 *             argv - vetor de strings com os argumentos passados
 *
 * Descrição: Função principal do programa 
 * 
 * Retorno: Estado de sucesso da execução do programa sob a forma de um inteiro
 * 0 = sucesso; 1 = insucesso
 *****************************************************************************/
int main (int argc, char* argv[])
{    
    if(argc !=2)
    {
        exit(0);
    }

    if((check_ext(argv[1], ".tilewalls1")) == 1)
    {
        exit(2);
    }
    FILE *fpIn;
    fpIn = abre_ficheiros(argv[1], "r");
    
    FILE *fpOut; /* apontadores para o ficheiro de entrada e de saída */
    mancha_t *manptr;   /* apontador para a mancha */
    char* saida;        /* string para o nome do ficheiro de saída */
    int **matriz;       /* matriz para os azulejos */
    int L_max, C_max, variante, coordenada_l, coordenada_c;     /* variáveis do cabeçalho do problema*/
    int dimensao, aux, i;/* variáveis auxiliares */
    int diff = 0, empty = 0;       /* flag para ver se a matriz é toda igual*/
    int counter = 0, tmp;

    saida = Output(argv[1], ".tilewalls1", ".singlestep");

    fpOut = abre_ficheiros(saida, "w");

    while((fscanf(fpIn, "%d %d %d %d %d", &L_max, &C_max, &variante, &coordenada_l, &coordenada_c)) != EOF)
    {                
        /*Verificar se a variante é 1 ou 2, e se as coordenadas l e c se encontram dentro da matriz. */
       
        if(variante == 1 || variante == 2){ /* variante correta */
            if(L_max > 0 && C_max > 0){     /* dimensões "boas" */
                if((0 < coordenada_l && coordenada_l <= L_max) && (0 < coordenada_c && coordenada_c <= C_max)){
                    /* coordenadas dentro da matriz */ 
                    dimensao = L_max * C_max;
                    matriz = read_matriz(fpIn, L_max, C_max, dimensao, &diff, &empty);
                                            
                    manptr = find_mancha(matriz, L_max-1, C_max-1, coordenada_l-1, coordenada_c-1, diff, empty);
                                
                    if(variante == 1){
                        fprintf(fpOut, "%d %d %d %d %d\n", L_max, C_max, variante, coordenada_l, coordenada_c); /*cabeçalho*/
                        fprintf(fpOut, "%d\n\n", manptr->m_pontos); /*pontos da mancha*/
                        reset_matriz(matriz, L_max, C_max); /* deita fora a matriz */
                        reset_mancha(&(manptr->m_head)); /* deita fora a mancha */
                        manptr->m_head = NULL;
                        manptr->m_tail = NULL;
                        manptr->m_azulejos = 0;
                        manptr->m_cursor = 0;
                        manptr->m_pontos = 0;
                        free(manptr);
                        
                    }            
                    else if(variante == 2){
                        if(manptr->m_azulejos > 1){ /* verifica se a mancha existe */
                            remove_mancha(manptr, matriz, L_max, C_max, diff); /* remove a mancha da matriz */
                            gravidade(matriz, L_max, C_max); /* aplica os efeitos gravíticos */
                        }
                        fprintf(fpOut, "%d %d %d %d %d\n", L_max, C_max, variante, coordenada_l, coordenada_c); /*cabeçalho */
                        for(i = L_max-1; i >= 0 ; i--) /* imprime a matriz resultante */
                        {
                            for(aux = 0; aux < C_max; aux++)
                            {                       
                                fprintf(fpOut,"%d ", matriz[i][aux]);
                            }
                            fprintf(fpOut, "\n");
                        }
                        fprintf(fpOut, "\n");
                        reset_matriz(matriz, L_max, C_max); /* deita fora a matriz */
                        reset_mancha(&(manptr->m_head)); /* deita fora a mancha */
                        manptr->m_head = NULL;
                        manptr->m_tail = NULL;
                        manptr->m_azulejos = 0;
                        manptr->m_cursor = 0;
                        manptr->m_pontos = 0;
                        free(manptr);                
                    }
                }
                else/* problema inválido*/   
                {
                    fprintf(fpOut, "%d %d %d %d %d\n\n", L_max, C_max, variante, coordenada_l, coordenada_c);
                    
                    while((counter < L_max*C_max) && ((fscanf(fpIn, "%d", &tmp)) != EOF)){
                    
                        counter++;                
                    }
                    counter = 0;
                }
            }
            else/* problema inválido*/   
            {
                fprintf(fpOut, "%d %d %d %d %d\n\n", L_max, C_max, variante, coordenada_l, coordenada_c);
                
                while((counter < L_max*C_max) && ((fscanf(fpIn, "%d", &tmp)) != EOF)){
                
                    counter++;                
                }
                counter = 0;
            }
            
        }
        else/* problema inválido*/   
        {
            fprintf(fpOut, "%d %d %d %d %d\n\n", L_max, C_max, variante, coordenada_l, coordenada_c);
            
            while((counter < L_max*C_max) && ((fscanf(fpIn, "%d", &tmp)) != EOF)){
            
                counter++;                
            }
            counter = 0;
        }   
    }
    fclose(fpIn);
    fclose(fpOut);    
    free(saida);

    return 0;
}