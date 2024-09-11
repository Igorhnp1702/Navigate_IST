/******************************************************************************
 * Ficheiro c que implementa a interface das manchas de azulejos
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#include <stdlib.h>
#include "matriz.h"
#include "mancha.h"

int adj_cmp(entrada ***matriz, int l_start, int c_start, int l_end, int c_end, int L_max, int C_max){ 
    /* Lmax e Cmax estão decrementados */
    
    int result = 0;    

    if(matriz[l_start][c_start]->cor == -1){
        return result;
    }
    
    if(l_end >= 0 && l_end < L_max && c_end >= 0 && c_end < C_max){ /* A entrada pertence à matriz ? */

        if(matriz[l_end][c_end]->cor == matriz[l_start][c_start]->cor){ /* Os valores das entradas são iguais ? */

           if(matriz[l_end][c_end]->in_mancha == 0){ 
            /* if true, a cor é igual, estão lado a lado e é preciso registar o azulejo como parte da mancha */
                return result+1;            
           }           
            return result;
        }
        return result;
    }
    return result;   
}

void InsereAzulejo(azlman **tail, int linha, int coluna, int n_azulejos){ /* recebe o último elemento */

    azlman *new;

    new = (azlman*)calloc(1, sizeof(azlman));
    if(new == NULL){
        exit(0);
    }

    if(*tail == NULL){ /* lista vazia, inserção do primeiro azulejo */
        
        *tail = new;
        (*tail)->azl_coluna = coluna;
        (*tail)->azl_linha = linha;
        (*tail)->azl_status = 0;        
        (*tail)->prev = NULL;
        (*tail)->next = NULL;              
        return;
    }
       /* inserção do N-ésimo azulejo no fim */
    new->azl_coluna = coluna;
    new->azl_linha = linha;
    new->azl_status = 0;    
    new->prev = *tail;
    new->next = NULL;    
    (*tail)->next = new;

    return;        
}



mancha_t *find_mancha(entrada ***matriz, int L_max, int C_max , int l_start, int c_start)
{   
    /* assume que o programa já viu se existe uma mancha por registar ou não */ 
        
    azlman *listptr;    /* apontador da lista de azulejos */
    int l_aux , c_aux;  /* auxiliares para as coordenadas dos azulejos */

    azlman *aux = (azlman*)calloc(1, sizeof(azlman));
    if(aux == NULL){
        exit(0);
    }
      
    /* inicialização do apontador da mancha */    
    mancha_t *mptr = (mancha_t*)calloc(1, sizeof(mancha_t));
     if(mptr == NULL){
        exit(0);
    }
    
    mptr->m_head = NULL;
    mptr->m_tail = NULL;
    mptr->m_azulejos = 0;
    mptr->m_pontos = 0;      

    /* insere o primeiro azulejo */
    
    InsereAzulejo(&(mptr->m_tail), l_start, c_start, mptr->m_azulejos);
    mptr->m_head = mptr->m_tail;
    mptr->m_azulejos++;
    mptr->m_linha = mptr->m_head->azl_linha;
    mptr->m_coluna = mptr->m_head->azl_coluna;
    mptr->m_cor = matriz[l_start][c_start]->cor;
    matriz[l_start][c_start]->in_mancha = 1;
    

    listptr = mptr->m_head;

    while(listptr != NULL){        
        
        l_aux = listptr->azl_linha;
        c_aux = listptr->azl_coluna;

        if(adj_cmp(matriz, l_aux, c_aux, l_aux+1, c_aux, L_max, C_max) == 1 && matriz[l_aux+1][c_aux]->in_mancha == 0){                        
                                    
            InsereAzulejo(&(mptr->m_tail), l_aux+1, c_aux, mptr->m_azulejos);
            matriz[l_aux+1][c_aux]->in_mancha = 1;
            mptr->m_tail = mptr->m_tail->next;
            mptr->m_azulejos++;
        }

        if(adj_cmp(matriz, l_aux, c_aux, l_aux, c_aux+1, L_max, C_max) == 1 && matriz[l_aux][c_aux+1]->in_mancha == 0){
        
            
            InsereAzulejo(&(mptr->m_tail), l_aux, c_aux+1, mptr->m_azulejos);
            matriz[l_aux][c_aux+1]->in_mancha = 1;
            mptr->m_tail = mptr->m_tail->next;            
            mptr->m_azulejos++;
        }
        if(adj_cmp(matriz, l_aux, c_aux, l_aux-1, c_aux, L_max, C_max) == 1 && matriz[l_aux-1][c_aux]->in_mancha == 0){

            
            InsereAzulejo(&(mptr->m_tail), l_aux-1, c_aux, mptr->m_azulejos);
            matriz[l_aux-1][c_aux]->in_mancha = 1;
            mptr->m_tail = mptr->m_tail->next;            
            mptr->m_azulejos++;
        }
        if(adj_cmp(matriz, l_aux, c_aux, l_aux, c_aux-1, L_max, C_max) == 1 && matriz[l_aux][c_aux-1]->in_mancha == 0){

            
            InsereAzulejo(&(mptr->m_tail), l_aux, c_aux-1, mptr->m_azulejos);
            matriz[l_aux][c_aux-1]->in_mancha = 1;  
            mptr->m_tail = mptr->m_tail->next;                        
            mptr->m_azulejos++;
        }

        listptr = listptr->next;                             
    } 

    mptr->m_pontos = mptr->m_azulejos * (mptr->m_azulejos -1);
    free(aux);

    return mptr;        
}

void remove_mancha(mancha_t *mptr, entrada ***matriz, int L_max, int C_max){
   
    azlman *listptr;

    for(listptr = mptr->m_head; listptr != NULL; listptr = listptr->next)
    {
        matriz[listptr->azl_linha][listptr->azl_coluna]->cor = -1;
        matriz[listptr->azl_linha][listptr->azl_coluna]->in_mancha = 0;         
    }

}

void reset_mancha(mancha_t **mptr){

    azlman *listptr = (*mptr)->m_head, *aux;
    while(listptr != NULL){        
        aux = listptr;
        listptr = listptr->next;
        free(aux);
    }
    free(*mptr);
}

void insert_manlist(man_list **head, mancha_t *nova_m){

    man_list *new_node, *aux;
    new_node = (man_list*)calloc(1, sizeof(man_list));

    if(new_node == NULL){
        exit(0);
    }

    new_node->move = nova_m;

    if(*head == NULL){
        new_node->next = NULL;
        *head = new_node;
        return;
    }

    aux = *head;
    new_node->next = aux;
    *head = new_node;
  
    return;
}

void clear_manlist(man_list **listhead){

    man_list *aux, *listptr;

    listptr = *listhead;
    while(listptr != NULL){
        aux = listptr;
        listptr = listptr->next;
        reset_mancha(&(aux->move));
        free(aux);
    }
    *listhead = NULL;
}