/*******************************************************************************
 * Ficheiro c que implementa a interface da stack de lances
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "mancha.h"
#include "solver.h"

typedef struct etapa_t{
    man_list *opts_node;       /* lista de lances legais da etapa. O primeiro elemento da lista é a alternativa atual*/
    mancha_t *last_move;
    entrada ***etapa_matriz;    /* matriz que representa uma etapa da sequência */          
    struct etapa_t *next;
    struct etapa_t *prev;
}etapa_t;

typedef struct lances_t{
    int linha;
    int coluna;
    struct lances_t *next;
}lances_t;

man_list *scan_matriz(entrada ***matriz, int L_max, int C_max);

void push_mem(etapa_t **top);

void copy_matriz(etapa_t **node, int L_max, int C_max);

void clear_stack(etapa_t **top, int L_max, int C_max);

void solveprobs(FILE *fpIn, FILE *fpOut){    


    /* declaração de variáveis do solver */
    
    etapa_t *top = NULL;                  /* top da stack de lances */
    etapa_t *stackpointer = NULL;          /* apontador que vai percorrer a stack de lances */
    etapa_t *to_print = NULL;    
    cores *cores_ptr = NULL;   /* apontador para a lista de cores e apontador auxiliar*/
    lances_t *lances = NULL, *lances_aux = NULL;   /* apontador para a lista de lances */
    lances_t *novo_lance = NULL;
    entrada ***mat = NULL;                  /* matriz a utilizar em variante 1*/
    mancha_t *to_remove = NULL;            /* apontador para manchas a utilizar em variante 1*/        
    man_list *opts_aux = NULL;


    int L_max, C_max, variante;     /* variáveis do cabeçalho do problema*/     
    int dimensao = 0;               /* número de entradas da matriz*/
    int n_cores = 0;                    /* número de cores diferentes, que será o número de colunas da tabela */
    int **tabela_cores;             /* tabela de cores para facilitar o cálculo do potencial de pontos */

    int pot_inicial = 0;            /* potencial da matriz inicial do problema */
    int pot_atual = 0;              /* potencial de uma matriz de uma etapa da stack de lances*/    
    int n_lances = 0;               /* número de lances executados */
    int current_score = 0;              /* pontuação obtida */    
    int best_score = 0;
    
    /* Variáveis do varrimento do ficheiro */ 

    int tmp;		                /* espaço que guarda os inteiros que seguem o cabeçalho de um prob inválido */
    int counter = 0;                /* iterador que ajuda o apontador do ficheiro de entrada a saltar a matriz de um prob inválido */    
    int i, j;                       /* iteradores */


    /* Começa a ler o ficheiro de entrada */

    while((fscanf(fpIn, "%d %d %d", &L_max, &C_max, &variante)) != EOF)
    {                               
        /*Verificar se o cabeçalho é válido */

        if(variante == -1 || variante == -3 || variante >= 0){ /* variante correta */
            if(L_max > 0 && C_max > 0){     /* dimensões "boas" */            

                dimensao = L_max * C_max;

                if(variante == -1 || variante == 0){ /*problemas da variante 1 e da variante 2 quando não há pontuação miníma a ser atingida*/

                    /*O histograma de cores não será necessário, logo este apontador fica a NULL*/
                    cores_ptr = NULL;       

                    /*inicializa a lista de lances a imprimir */
                    lances = (lances_t*)calloc(1, sizeof(lances_t));
                    if(lances == NULL){
                        exit(0);
                    }
                    lances->next = NULL;
                    lances->linha = -1;
                    lances->coluna = -1;
                                    
                    current_score = 0;
                    n_lances = 0;
                    
                    lances_aux = lances;                    
                    mat = read_matriz(fpIn, L_max, C_max, dimensao, &cores_ptr, &n_cores); /* Se cores_ptr for NULL, não mexemos nele */
                    i = 0;
                    j = C_max - 1;

                    while(i < L_max){
                        while(j >= 0){
                            if(adj_cmp(mat, i, j, i+1, j, L_max - 1, C_max - 1) == 1 
                            || adj_cmp(mat, i, j, i, j-1, L_max - 1, C_max - 1) == 1){
                                to_remove = find_mancha(mat, L_max - 1, C_max - 1, i, j);                                 
                                remove_mancha(to_remove, mat, L_max, C_max);
                                gravidade(mat, L_max, C_max);
                                                               
                                novo_lance = (lances_t*)calloc(1, sizeof(lances_t));
                                if(novo_lance == NULL){
                                    exit(0);
                                } 
                                novo_lance->linha = i;
                                novo_lance->coluna = j;
                                novo_lance->next = NULL;
                                
                                while(lances_aux->next != NULL){
                                    lances_aux = lances_aux->next;
                                }
                                lances_aux->next = novo_lance;
                                
                                n_lances ++;
                                current_score += to_remove->m_pontos;
                                lances_aux = lances_aux->next; 
                                reset_mancha(&to_remove);
                                i = 0;
                                j = C_max - 1;    
                            }
                            else{
                                j--;
                            }    
                        }
                        j = C_max - 1;  
                        i++;       
                    }

                    lances_aux = lances;
                    fprintf(fpOut, "%d %d %d\n%d %d\n", L_max, C_max, variante, n_lances, current_score);
                    while(lances_aux->next != NULL){
                        fprintf(fpOut, "%d %d\n", lances_aux->next->linha+1, lances_aux->next->coluna+1);
                        lances_aux = lances_aux->next;
                    }
                    fprintf(fpOut, "\n");

                    /*libertar a lista lances*/
                    while(lances != NULL){
                        lances_aux = lances;
                        lances = lances->next;
                        free(lances_aux);
                    }
                                        
                    reset_matriz(mat, L_max, C_max);
                    
                }

                if(variante == -3){     /*problemas da variante 3*/ 
                   
                    /*inicializa o apontador cores_ptr*/
                    cores_ptr = (cores*)calloc(1, sizeof(cores));
                    if(cores_ptr == NULL){
                        exit(0);
                    }
                    cores_ptr->next = NULL;
                    cores_ptr->valor = -1;
                    cores_ptr->n_azulejos = 0;

                    best_score = 0;                                                        
                    current_score = 0;
                    n_lances = 0;                                        

                    push_mem(&top);                    
                    
                    top->etapa_matriz = read_matriz(fpIn, L_max, C_max, dimensao, &cores_ptr, &n_cores);

                    /* inicializa a tabela de cores */
                    tabela_cores = make_tc(&cores_ptr, &pot_inicial, n_cores);
                   
                    /* vê quais são as opções desta matriz inicial */
                    top->opts_node = scan_matriz(top->etapa_matriz, L_max, C_max);

                    if(top->opts_node == NULL){ /* não há lances legais na matriz inicial, best_score = 0 */
                        fprintf(fpOut, "%d %d %d\n0 0\n\n", L_max, C_max, variante);
                    }
                    else{                        
                        
                        stackpointer = top;
                        while((stackpointer->prev != NULL && stackpointer->opts_node != NULL) || best_score < pot_inicial){
                            
                            /*------------------------------- deslocação do apontador no sentido positivo - start -------------------------------*/

                            if(stackpointer == top){ /* stackpointer no topo da stack, é preciso adicionar memória */
                                
                                /* adiciona memória e mete a matriz no novo bloco da stack*/
                                push_mem(&top);
                                copy_matriz(&top, L_max, C_max);

                                /* faz um lance */
                                remove_mancha(top->prev->opts_node->move, top->etapa_matriz, L_max, C_max);
                                gravidade(top->etapa_matriz, L_max, C_max);
                                top->last_move = top->prev->opts_node->move;
                                current_score += top->last_move->m_pontos;
                                
                                

                                /* decrementa o número de azulejos da mesma cor que a mancha removida */
                                
                                for(j = 0; j < n_cores; j++){
                                    if(tabela_cores[0][j] == top->last_move->m_cor){
                                        tabela_cores[1][j] -= top->last_move->m_azulejos; 
                                    }
                                    pot_atual +=  tabela_cores[1][j] * (tabela_cores[1][j] - 1);
                                }
                                stackpointer = top;
                            }
                            else{ /* o stackpointer está a meio da stack */
                                stackpointer = stackpointer->next;        /* mete-o no próximo */
                                copy_matriz(&stackpointer, L_max, C_max); /* copia a matriz do anterior */
                                clear_manlist(&(stackpointer->opts_node));   /* limpa a lista de lances legais */

                                /* faz um lance */                                
                                remove_mancha(stackpointer->prev->opts_node->move, stackpointer->etapa_matriz, L_max, C_max); 
                                gravidade(stackpointer->etapa_matriz, L_max, C_max);
                                stackpointer->last_move = stackpointer->prev->opts_node->move;
                                current_score += stackpointer->last_move->m_pontos;
                                                                                                
                                /* decrementa o número de azulejos da mesma cor que a mancha removida */
                                for(j = 0; j < n_cores; j++){
                                    if(tabela_cores[0][j] == stackpointer->last_move->m_cor){
                                        tabela_cores[1][j] -= stackpointer->last_move->m_azulejos; 
                                    }
                                    pot_atual +=  tabela_cores[1][j] * (tabela_cores[1][j] - 1);
                                }
                            }
                           /*------------------------------- deslocação do apontador no sentido positivo - end -------------------------------*/

                            if((stackpointer->opts_node = scan_matriz(stackpointer->etapa_matriz, L_max, C_max)) == NULL || pot_atual + current_score < best_score){
                            /* temos de voltar para trás, não há mais lances legais ou não vale a pena continuar */
                                                                                                                                                                                                                               
                                if(best_score < current_score){ /* batemos a pontuação anterior ou chegamos ao máximo possível */
                                    
                                    best_score = current_score;
                                    to_print = stackpointer;

                                    /*inicializa a lista de lances a imprimir */

                                    lances = (lances_t*)calloc(1, sizeof(lances_t));

                                    if(lances == NULL){
                                        exit(0);
                                    }

                                    lances->next = NULL;
                                    lances->linha = to_print->last_move->m_linha;
                                    lances->coluna = to_print->last_move->m_coluna;
                                    lances_aux = lances;
                                    to_print = to_print->prev; /* recua na stack */

                                    while(to_print != NULL){ /* o último a ser inserido é o primeiro lance. Inserção no início da lista */

                                        novo_lance = (lances_t*)calloc(1, sizeof(lances_t));
                                        if(novo_lance == NULL){
                                            exit(0);
                                        } 
                                        novo_lance->linha = to_print->last_move->m_linha;
                                        novo_lance->coluna = to_print->last_move->m_coluna;
                                        novo_lance->next = lances_aux;
                                        lances = novo_lance;
                                        to_print = to_print->prev;
                                    }
                                }                                                                                                

                                /* incrementa os azulejos de uma certa cor*/
                                for(j = 0; j < n_cores; j++){
                                    if(tabela_cores[0][j] == stackpointer->last_move->m_cor){
                                        tabela_cores[1][j] += stackpointer->last_move->m_azulejos; 
                                    }
                                    pot_atual +=  tabela_cores[1][j] * (tabela_cores[1][j] - 1);
                                }
                                current_score -= stackpointer->last_move->m_pontos;

                                /* recua o apontador para trás na stack e apaga o lance usado */
                                stackpointer = stackpointer->prev;
                                opts_aux = stackpointer->opts_node;
                                stackpointer->opts_node = stackpointer->opts_node->next;
                                reset_mancha(&(opts_aux->move));
                                free(opts_aux);
                            }                                                 
                        }
                        
                        /* imprime a sequencia obtida */
                        
                        lances_aux = lances;
                        fprintf(fpOut, "%d %d %d\n%d %d\n", L_max, C_max, variante, n_lances, best_score);
                        while(lances_aux->next != NULL){
                            fprintf(fpOut, "%d %d\n", lances_aux->next->linha+1, lances_aux->next->coluna+1);
                            lances_aux = lances_aux->next;
                        }
                        fprintf(fpOut, "\n");

                        /*libertar a lista lances*/
                        while(lances != NULL){
                            lances_aux = lances;
                            lances = lances->next;
                            free(lances_aux);
                        }
                        /* liberta a stack */               
                        clear_stack(&top, L_max, C_max);                        
                    } 
                }

                if(variante > 0){   /*problemas da variante 2*/

                   /*inicializa o apontador cores_ptr*/
                    cores_ptr = (cores*)calloc(1, sizeof(cores));
                    if(cores_ptr == NULL){
                        exit(0);
                    }
                    cores_ptr->next = NULL;
                    cores_ptr->valor = -1;
                    cores_ptr->n_azulejos = 0;

                    best_score = 0;                                                        
                    current_score = 0;
                    n_lances = 0;                                        

                    push_mem(&top);                    
                    
                    top->etapa_matriz = read_matriz(fpIn, L_max, C_max, dimensao, &cores_ptr, &n_cores);

                    /* inicializa a tabela de cores */
                    tabela_cores = make_tc(&cores_ptr, &pot_inicial, n_cores);
                    
                    /* vê quais são as opções desta matriz inicial */
                    top->opts_node = scan_matriz(top->etapa_matriz, L_max, C_max);

                    /* vê se o potencial inicial é inferior à pontuação mínima */

                    if(pot_inicial >= variante || top->opts_node != NULL){ 
                        /* if false, primeira matriz não tem mancha a remover ou a variante é muito alta. O caso variante = 0 já está tratado */                                                                                                                                 
                        
                        stackpointer = top;
                        while((stackpointer->prev != NULL && stackpointer->opts_node != NULL) || current_score < variante){
                            
                            /*------------------------------- deslocação do apontador no sentido positivo - start -------------------------------*/

                            if(stackpointer == top){ /* stackpointer no topo da stack, é preciso adicionar memória */
                                
                                /* adiciona memória e mete a matriz no novo bloco da stack*/
                                push_mem(&top);
                                copy_matriz(&top, L_max, C_max);

                                /* faz um lance */
                                remove_mancha(top->prev->opts_node->move, top->etapa_matriz, L_max, C_max);
                                gravidade(top->etapa_matriz, L_max, C_max);
                                top->last_move = top->prev->opts_node->move;
                                current_score += top->last_move->m_pontos;
                                
                                

                                /* decrementa o número de azulejos da mesma cor que a mancha removida */
                                
                                for(j = 0; j < n_cores; j++){
                                    if(tabela_cores[0][j] == top->last_move->m_cor){
                                        tabela_cores[1][j] -= top->last_move->m_azulejos; 
                                    }
                                    pot_atual +=  tabela_cores[1][j] * (tabela_cores[1][j] - 1);
                                }
                                stackpointer = top;
                            }
                            else{ /* o stackpointer está a meio da stack */
                                stackpointer = stackpointer->next;        /* mete-o no próximo */
                                copy_matriz(&stackpointer, L_max, C_max); /* copia a matriz do anterior */
                                clear_manlist(&(stackpointer->opts_node));   /* limpa a lista de lances legais */

                                /* faz um lance */                                
                                remove_mancha(stackpointer->prev->opts_node->move, stackpointer->etapa_matriz, L_max, C_max); 
                                gravidade(stackpointer->etapa_matriz, L_max, C_max);
                                stackpointer->last_move = stackpointer->prev->opts_node->move;
                                current_score += stackpointer->last_move->m_pontos;
                                
                                
                                
                                /* decrementa o número de azulejos da mesma cor que a mancha removida */
                                for(j = 0; j < n_cores; j++){
                                    if(tabela_cores[0][j] == stackpointer->last_move->m_cor){
                                        tabela_cores[1][j] -= stackpointer->last_move->m_azulejos; 
                                    }
                                    pot_atual +=  tabela_cores[1][j] * (tabela_cores[1][j] - 1);
                                }
                            }
                        /*------------------------------- deslocação do apontador no sentido positivo - end -------------------------------*/

                            if((stackpointer->opts_node = scan_matriz(stackpointer->etapa_matriz, L_max, C_max)) == NULL || pot_atual + current_score < variante){
                            /* temos de voltar para trás, não há mais lances legais ou não vale a pena continuar */
                                                                                                                                                                                                                            
                                if(variante <= current_score){ /* batemos o target, limpa as manchas e sai */
                                    
                                    /*inicializa a lista de lances a imprimir */

                                    lances = (lances_t*)calloc(1, sizeof(lances_t));

                                    if(lances == NULL){
                                        exit(0);
                                    }
                                    to_print = stackpointer;

                                    lances->next = NULL;
                                    lances->linha = to_print->last_move->m_linha;
                                    lances->coluna = to_print->last_move->m_coluna;
                                    lances_aux = lances;
                                    to_print = to_print->prev; /* recua na stack */

                                    while(to_print != NULL){ /* o último a ser inserido é o primeiro lance. Inserção no início da lista */

                                        novo_lance = (lances_t*)calloc(1, sizeof(lances_t));
                                        if(novo_lance == NULL){
                                            exit(0);
                                        } 
                                        novo_lance->linha = to_print->last_move->m_linha;
                                        novo_lance->coluna = to_print->last_move->m_coluna;
                                        novo_lance->next = lances_aux;
                                        lances = novo_lance;
                                        to_print = to_print->prev;
                                    }
                                    to_print = stackpointer;                                                                                                            

                                    /* Elimina as manchas restantes arbitrariamente e insere na lista*/
                                    while(i < L_max){
                                        while(j >= 0){
                                            if(adj_cmp(to_print->etapa_matriz, i, j, i+1, j, L_max - 1, C_max - 1) == 1 
                                            || adj_cmp(to_print->etapa_matriz, i, j, i, j-1, L_max - 1, C_max - 1) == 1){
                                                to_remove = find_mancha(to_print->etapa_matriz, L_max - 1, C_max - 1, i, j);                                 
                                                remove_mancha(to_remove, to_print->etapa_matriz, L_max, C_max);
                                                gravidade(to_print->etapa_matriz, L_max, C_max);
                                                                            
                                                novo_lance = (lances_t*)calloc(1, sizeof(lances_t));
                                                if(novo_lance == NULL){
                                                    exit(0);
                                                } 
                                                novo_lance->linha = i;
                                                novo_lance->coluna = j;
                                                novo_lance->next = NULL;
                                                
                                                while(lances_aux->next != NULL){
                                                    lances_aux = lances_aux->next;
                                                }
                                                lances_aux->next = novo_lance;
                                                
                                                n_lances ++;
                                                current_score += to_remove->m_pontos;
                                                lances_aux = lances_aux->next; 
                                                reset_mancha(&to_remove);
                                                i = 0;
                                                j = C_max - 1;    
                                            }
                                            else{
                                                j--;
                                            }    
                                        }
                                        j = C_max - 1;  
                                        i++;       
                                    }                                                                        
                                }
                                else{
                                     /* incrementa os azulejos de uma certa cor*/
                                    for(j = 0; j < n_cores; j++){
                                        if(tabela_cores[0][j] == stackpointer->last_move->m_cor){
                                            tabela_cores[1][j] += stackpointer->last_move->m_azulejos; 
                                        }
                                        pot_atual +=  tabela_cores[1][j] * (tabela_cores[1][j] - 1);
                                    }
                                    current_score -= stackpointer->last_move->m_pontos;

                                    /* recua o apontador para trás na stack e apaga o lance usado */
                                    stackpointer = stackpointer->prev;
                                    opts_aux = stackpointer->opts_node;
                                    stackpointer->opts_node = stackpointer->opts_node->next;
                                    reset_mancha(&(opts_aux->move));
                                    free(opts_aux);
                                }                                                                                                                               
                            }                                                    
                        }

                        if(lances == NULL){ /* pior caso onde o programa percorre todas as sequências de lances e não encontra solução */
                        
                            fprintf(fpOut, "%d %d %d\n0 -1\n\n", L_max, C_max, variante);

                            /* liberta a stack */               
                            clear_stack(&top, L_max, C_max);   
                        }

                        else{

                            /* imprime a sequência obtida */
                        
                            lances_aux = lances;
                            fprintf(fpOut, "%d %d %d\n%d %d\n", L_max, C_max, variante, n_lances, best_score);
                            while(lances_aux->next != NULL){
                                fprintf(fpOut, "%d %d\n", lances_aux->next->linha+1, lances_aux->next->coluna+1);
                                lances_aux = lances_aux->next;
                            }
                            fprintf(fpOut, "\n");

                            /*libertar a lista lances*/
                            while(lances != NULL){
                                lances_aux = lances;
                                lances = lances->next;
                                free(lances_aux);
                            }
                            /* liberta a stack */               
                            clear_stack(&top, L_max, C_max);
                        }                                                                                                                                                        
                    }
                    else{
                        fprintf(fpOut, "%d %d %d\n0 -1\n\n", L_max, C_max, variante);
                    }
                }        
            }
            else{/* problema inválido*/   
            
                fprintf(fpOut, "%d %d %d\n0 -1\n\n", L_max, C_max, variante);
                
                while((counter < L_max*C_max) && ((fscanf(fpIn, "%d", &tmp)) != EOF)){
                
                    counter++;                
                }
                counter = 0;
            }
        }
        else{/* problema inválido*/   
            
            fprintf(fpOut, "%d %d %d\n0 -1\n\n", L_max, C_max, variante);
            
            while((counter < L_max*C_max) && ((fscanf(fpIn, "%d", &tmp)) != EOF)){
            
                counter++;                
            }
            counter = 0;
        }            
    }
}

man_list *scan_matriz(entrada ***matriz, int L_max, int C_max){

    man_list *ret_list = NULL;
    mancha_t *aux;
    

    int i, j, empty_flag = 1;

    for(i = 0; i < L_max; i++){
        for(j = 0; j < C_max; j++){
            if(adj_cmp(matriz, i, j, i+1, j, L_max, C_max) == 1 
             || adj_cmp(matriz, i, j, i, j+1, L_max, C_max) == 1){
                empty_flag = 0;
                if(matriz[i][j]->in_mancha == 0){
                   aux = find_mancha(matriz, L_max, C_max, i, j);
                   insert_manlist(&ret_list, aux);
                   reset_mancha(&aux);
                }
            }                       
        }
    }
    if(empty_flag == 0){
        return NULL;
    }

    return ret_list;
}

void push_mem(etapa_t **node){ /* só acrescenta memória à stack */

    etapa_t *aux, *new;    
    new = (etapa_t*)calloc(1, sizeof(etapa_t));

    if(new == NULL){
        exit(0);
    }
   
    if(*node == NULL){ /* inserção do primeiro elemento da stack */
        new->etapa_matriz = NULL;
        new->last_move = NULL;
        new->opts_node = NULL;
        new->next = NULL;
        new->prev = NULL;                              
        *node = new;
        return;
    }
    
    if(((*node)->next) == NULL){ /* if true, a stack estica */
        aux = *node;    
        
        new->etapa_matriz = NULL;
        new->last_move = NULL;
        new->opts_node = NULL;
        new->next = NULL;
        new->prev = aux;
        *node = new;
        return;
    }          
}

void copy_matriz(etapa_t **node, int L_max, int C_max){ 
    /* assumindo que o próximo bloco de memória da stack existe */    
    int i, j; 
    
    for(i = 0; i < L_max; i++){
        for(j = 0; j < C_max; j++){
            (*node)->etapa_matriz[i][j] = (*node)->prev->etapa_matriz[i][j];
        }
    }
    return;
}

void clear_stack(etapa_t **top, int L_max, int C_max){

    etapa_t *aux, *listptr;

    listptr = *top;
    while(listptr != NULL){
        aux = listptr;
        listptr = listptr->prev;
        reset_matriz(aux->etapa_matriz, L_max, C_max);
        reset_mancha(&(aux->last_move));
        clear_manlist(&(aux->opts_node));
        free(aux);        
    }
    *top = NULL;
}


