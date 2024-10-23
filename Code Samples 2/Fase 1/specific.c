/******************************************************************************
 * Ficheiro com o código-fonte das funções e structs específicas deste projeto
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#include <stdlib.h>
#include "specific.h"

void gravidade(int **matriz, int L_max, int C_max)
{
    int i, j, aux, altura = 0, largura = 0, temp;

    for(i = 0; i < C_max; i++)
    {
        for(j = L_max-1; j >= 0; j--)
        {   
            if(matriz[j][i] == -1)
            {
                for(aux = 0; aux < altura; aux++)
                {   
                    temp = matriz[j+aux][i];
                    matriz[j+aux][i] = matriz[j+aux+1][i];
                    matriz[j+aux+1][i] = temp;    
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
                    temp = matriz[j][i-aux];
                    matriz[j][i-aux] = matriz[j][i-aux-1];
                    matriz[j][i-aux-1] = temp;  
                }        
            }
        }
        else
        {
            largura++;
        }

        altura = 0;
    }
}

void InsereAzulejo(mancha_t **mp, azulejo_t **tail, int linha, int coluna, int n_azulejos){ /* recebe o último elemento */

    azulejo_t *new;

    new = (azulejo_t*)calloc(1, sizeof(azulejo_t));
    if(new == NULL){
        exit(0);
    }

    if(*tail == NULL){ /* lista vazia, inserção do primeiro azulejo */
        
        *tail = new;
        (*tail)->azl_coluna = coluna;
        (*tail)->azl_linha = linha;
        (*tail)->azl_status = 0;
        (*tail)->index = n_azulejos+1; /* 0 + 1 = 1 */
        (*tail)->prev = NULL;

        (*tail)->next = NULL;
        (*mp)->m_head = *tail;        
        return;
    }
       /* inserção do N-ésimo azulejo no fim */
    new->azl_coluna = coluna;
    new->azl_linha = linha;
    new->azl_status = 0;
    new->index = n_azulejos + 1;
    new->prev = *tail;
    new->next = NULL;    
    (*tail)->next = new;
    (*mp)->m_tail = new;

    return;        
}

int adj_cmp(azulejo_t **head, int **matriz, int l_start, int c_start, int l_end, int c_end, int L_max, int C_max){ 
    /*Lmax e Cmax estão decrementados */
    
    int result = 0;
    azulejo_t *aux;

    if(l_end >= 0 && l_end <= L_max && c_end >= 0 && c_end <= C_max){ /* A entrada pertence à matriz ? */

        if(matriz[l_end][c_end] == matriz[l_start][c_start]){ /* Os valores das entradas são iguais ? */

           for(aux = *head; aux != NULL; aux = aux->next){ /* percorre a lista do início ao fim */

                if(aux->azl_linha == l_end && aux->azl_coluna == c_end){
                /*este adjacente já foi registado na lista? */
                    return result;
                }            
           }
            return result+1;            
        }
        return result;
    }
    return result;   
}

mancha_t *find_mancha(int **matriz, int L_max, int C_max, int l_prob, int c_prob, int diff_flag, int empty_flag)
{
    int l_aux, c_aux; /*inteiros auxiliares para percorrer a matriz */
    int check_status; /* verificar se ainda tem um azulejo para visistar */
    azulejo_t *listptr;


    azulejo_t *aux = (azulejo_t*)calloc(1, sizeof(azulejo_t));
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
    mptr->m_cursor = 0;

    /* Entrada vazia */
    if(matriz[l_prob][c_prob] < 1 ) 
    {
        free(aux);
        return mptr;
    }    

    if(diff_flag == 0 && empty_flag == 0) /* mancha == matriz */
    {
        mptr->m_azulejos = (L_max+1) * (C_max+1);
        mptr->m_pontos = mptr->m_azulejos * (mptr->m_azulejos -1);
        free(aux);
        return mptr;
    }
    else if(diff_flag == 0 && empty_flag == 1){  /* matriz vazia */
        mptr->m_azulejos = 0;
        mptr->m_pontos = 0;
        free(aux);
        return mptr;
    }               

    /*mptr->m_head = InsereAzulejo(&(mptr->m_head), aux); */
    InsereAzulejo(&mptr, &(mptr->m_tail), l_prob, c_prob, mptr->m_azulejos);    
    mptr->m_azulejos++;
    mptr->m_cursor = 1;

    l_aux = l_prob;
    c_aux = c_prob;

    do{
        check_status = 0;
        if(adj_cmp(&(mptr->m_head), matriz, l_aux, c_aux, l_aux+1, c_aux, L_max, C_max) == 1){                        
                                    
            InsereAzulejo(&mptr, &(mptr->m_tail), l_aux+1, c_aux, mptr->m_azulejos);
            mptr->m_azulejos++;
        }

        if(adj_cmp(&(mptr->m_head), matriz, l_aux, c_aux, l_aux, c_aux+1, L_max, C_max) == 1){
        
            
            InsereAzulejo(&mptr, &(mptr->m_tail), l_aux, c_aux+1, mptr->m_azulejos);            
            mptr->m_azulejos++;
        }
        if(adj_cmp(&(mptr->m_head), matriz, l_aux, c_aux, l_aux-1, c_aux, L_max, C_max) == 1){

            
            InsereAzulejo(&mptr, &(mptr->m_tail), l_aux-1, c_aux, mptr->m_azulejos);            
            mptr->m_azulejos++;
        }
        if(adj_cmp(&(mptr->m_head), matriz, l_aux, c_aux, l_aux, c_aux-1, L_max, C_max) == 1){

            
            InsereAzulejo(&mptr, &(mptr->m_tail), l_aux, c_aux-1, mptr->m_azulejos);                        
            mptr->m_azulejos++;
        }

        if(mptr->m_cursor <= (mptr->m_azulejos)/2){ /* começa do início */
            for(listptr = mptr->m_head; listptr != NULL; listptr = listptr->next) /* Meter o status do visitado a 1 */
            {                
                if(listptr->index == mptr->m_cursor){
                
                    listptr->azl_status = 1;
                    if(listptr->next != NULL){ /* Vê se ainda há mais azulejos por visitar */
                        check_status = 1;
                        l_aux = listptr->next->azl_linha;
                        c_aux = listptr->next->azl_coluna;
                        mptr->m_cursor = listptr->next->index;
                        break;
                    }
                }           
            }                           
        }
        else if(mptr->m_cursor > (mptr->m_azulejos)/2){ /* começa do fim */
            for(listptr = mptr->m_tail; listptr != NULL; listptr = listptr->prev) /* Meter o status do visitado a 1*/
            {                
                if(listptr->index == mptr->m_cursor){
                
                    listptr->azl_status = 1;
                    if(listptr->next != NULL){ /* Vê se ainda há mais azulejos por visitar */
                        check_status = 1;
                        l_aux = listptr->next->azl_linha;
                        c_aux = listptr->next->azl_coluna;
                        mptr->m_cursor = listptr->next->index;
                        break;
                    }                         
                }           
            }                           
        }           
    }while(check_status == 1); /*check_status = 0 && azl_status == 1 para todo o azl => mancha concluída*/

    mptr->m_pontos = mptr->m_azulejos * (mptr->m_azulejos -1);
    free(aux);

    return mptr;
    
    /*for(i = L_max; i>0; i--) para a próxima fase
    {
        for(j = 1; j <= C_max ; j++)
        {   
            if(i==1 && j==C_max) break;

            if(i == 1) 
            {
                if(matriz[i][j-1] == matriz[i][j])
                {   
                    p->Lista = insertUnsortedLinkedList(p, E1);
                    
                    (*E1).linha = i;
                    (*E1).coluna = j-1;

                    p->Lista = insertUnsortedLinkedList(p, E2);
                    
                    (*E2).linha = i;
                    (*E2).coluna = j;
                }
            }

            else if (matriz[i-1][j] == matriz[i][j])
            {
                (*E1).linha = i-1;
                (*E1).coluna = j;

                (*E2).linha = i;
                (*E2).coluna = j;
            }
            
            if(j == C_max)
            {
                if (matriz[i-1][j] == matriz[i][j])
                {
                    (*E1).linha = i-1;
                    (*E1).coluna = j;

                    (*E2).linha = i;
                    (*E2).coluna = j;
                }
            }

            else if(matriz[i][j-1] == matriz[i][j])
            {
                    (*E1).linha = i;
                    (*E1).coluna = j-1;

                    (*E2).linha = i;
                    (*E2).coluna = j;
            }
        }
    }*/
}

void remove_mancha(mancha_t *mptr, int **matriz, int L_max, int C_max, int diff_flag){

    if(diff_flag == 0){ /* mancha == matriz */
        
        int i, j;
        for(i= 0; i <L_max; i++){
            for(j = 0; j < C_max; j++){
                matriz[i][j] = -1;
                
            }
        }
        return;
    }
    azulejo_t *listptr;

    for(listptr = mptr->m_head; listptr != NULL; listptr = listptr->next)
    {
        matriz[listptr->azl_linha][listptr->azl_coluna] = -1;         
    }

}

void reset_mancha(azulejo_t **head){

    azulejo_t *listptr = *head, *aux;
    while(listptr != NULL){        
        aux = listptr;
        listptr = listptr->next;
        free(aux);
    }       
}