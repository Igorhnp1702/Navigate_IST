/******************************************************************************
 * Ficheiro c que implementa a interface das matrizes de azulejos
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"


void incializa_lista(cores **ptr)
{
    (*ptr)->next =NULL;
    (*ptr)->valor = -1;
    (*ptr)->n_azulejos = 0;
}

void insere_novacor(cores** ptr, int valor)
{
    cores *new, *tmp;

    new = (cores*)calloc(1, sizeof(cores));
    if(new == NULL){
        exit(0);
    }

    new->valor = valor;
    new->n_azulejos = 1;
    new->next = NULL;

    if(*ptr == NULL){
        *ptr = new;
    }
    else{
        tmp = *ptr;

        while(tmp->next != NULL){
            tmp = tmp->next;
        }

        tmp->next = new;
    }
}

void lista_cores(entrada ***matriz, cores **ptr, int L_max, int C_max, int* n_cores)
{
    int i, j, found = 0;
    
    for(i = 0; i < L_max; i++){
        for(j = 0; j < C_max; j++){
            if(matriz[i][j]->cor != -1){

                while((*ptr)->next != NULL){
                    if((*ptr)->valor == matriz[i][j]->cor){
                        (*ptr)->n_azulejos++;
                        found = 1;
                        break;
                    }
                    *ptr = (*ptr)->next;
                }

                if(found == 0){
                    insere_novacor(ptr, matriz[i][j]->cor);  
                    *n_cores += 1;
                    found = 0;
                }
            } 
        }
    }
}

entrada ***read_matriz(FILE *fp, int L_max, int C_max, int dimensao, cores **ptr, int *n_cores)
{
    entrada ***matriz;
    cores *aux_ptr = *ptr;
    int i, j, valor, aux = L_max - 1, found = 0;

    matriz = (entrada ***)calloc(L_max, sizeof(entrada**));
    if(matriz == NULL)
    {
        exit(0);
    }
    
    for(i = 0; i < L_max; i++)
    {
        matriz[i] = (entrada**) calloc(C_max, sizeof(entrada*));
        if(matriz[i] == NULL)
        {
            exit(0);
        }
        for(j = 0; j < C_max; j++){
            matriz[i][j] = (entrada*) calloc(1, sizeof(entrada));
            if(matriz[i][j] == NULL)
            {
                exit(0);
            } 
        }
    }

    for(i = 0, j = 0; i < dimensao; i++)
    {
        if((fscanf(fp, "%d", &valor)) != EOF){
            
            matriz[aux][j]->cor = valor;
            matriz[aux][j]->in_mancha = 0;

            if(valor != -1 && (*ptr == NULL)){

                while(aux_ptr != NULL){
                    if(aux_ptr->valor == valor){
                        aux_ptr->n_azulejos++;
                        found = 1;
                        break;
                    }
                    aux_ptr = aux_ptr->next;
                }

                if(found == 0){
                    insere_novacor(ptr, valor);  
                    *n_cores += 1;
                }

                found = 0;
                aux_ptr = *ptr;                 
            } 
           
            if(j == C_max-1)
            {
                j = 0;
                aux--;                                            
            }
            else j++;
        }
    }
    
    return matriz;
}

int **make_tc(cores ** colourlist, int *pot_inicial, int n_cores){

    cores *aux;
    int **colourtab;
    int i, j;

    colourtab = (int**)calloc(2, sizeof(int*));
    if(colourtab == NULL){
        exit(0);
    }
    for(i = 0; i < 2; i++){
        colourtab[i] = (int*)calloc(n_cores, sizeof(int));
        if(colourtab[i] == NULL){
            exit(0);
        }
    }
    aux = *colourlist;
    /* preenche a tabela de cores */
    for(j = 0; j < n_cores; j++){
        colourtab[0][j] = aux->valor;
        colourtab[0][j] = aux->n_azulejos;
        aux = aux->next;

        *pot_inicial +=  colourtab[1][j] * (colourtab[1][j] - 1); 
    }
    return colourtab;
}

void gravidade(entrada ***matriz, int L_max, int C_max)
{
    int i, j, aux, altura = 0, largura = 0, temp;

    for(i = 0; i < C_max; i++)
    {
        for(j = L_max-1; j >= 0; j--)
        {   
            if(matriz[j][i]->cor == -1)
            {
                for(aux = 0; aux < altura; aux++)
                {   
                    temp = matriz[j+aux][i]->cor;
                    matriz[j+aux][i]->cor = matriz[j+aux+1][i]->cor;
                    matriz[j+aux+1][i]->cor = temp;  
                    
                }
            }
            
            else
            {
                altura++;
            }
        }

        if(altura==0)
        {
            for(aux = 0; aux < largura; aux++)
            {
                for(j = L_max-1; j >= 0; j--)
                {
                    temp = matriz[j][i-aux]->cor;
                    matriz[j][i-aux]->cor = matriz[j][i-aux-1]->cor;
                    matriz[j][i-aux-1]->cor = temp;  
                }        
            }
        }
        else
        {
            largura++;
        }

        altura = 0;
    }

    for(i = 0; i < C_max; i++) /* dá reset a todos os azulejos */
    {
        for(j = L_max-1; j >= 0; j--)
        {   
            matriz[j][i]->in_mancha = 0;
        }
    }
}

void reset_listacor(cores **head){

    cores *listptr = *head, *aux;
    while(listptr != NULL){        
        aux = listptr;
        listptr = listptr->next;
        free(aux);
    }       
}


void reset_matriz(entrada ***matriz, int L_max, int C_max){

    int i, j;
    
    for(i = 0; i < L_max; i++){
		for(j = 0; j<C_max; j++){
			free(matriz[i][j]);
		}				
        free(matriz[i]);
    }

    free(matriz);
    matriz = NULL;
}



