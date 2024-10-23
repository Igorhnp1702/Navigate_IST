/******************************************************************************
 * Ficheiro h onde está definida a interface das manchas de azulejos
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Gonçalo Pires ist199947
*******************************************************************************/

#ifndef ManchaHeader
#define ManchaHeader

#include "matriz.h"

/*
 * typedef struct azulejos_t
 * 
 * Descrição: Tipo de dados estruturado para a informação sobre
 * os azulejos
*/

typedef struct azlman{ /* azulejo da mancha */
    int azl_linha;   /* linha do azulejo*/
    int azl_coluna;  /* coluna do azulejo */       
    int azl_status; /* Procurei os vizinhos => 1; não os procurei => 0 */    
    struct azlman *next; /* apontador para o próximo elemento da lista de azulejos */
    struct azlman *prev; /* apontador para o elemento anterior da lista de azulejos */
}azlman;

/*
* typedef struct Manchas
* 
* Descrição: Tipo de dados estruturado para as manchas
*/

typedef struct mancha_t{
    azlman *m_head;     /* Cabeça da lista de blocos que contêm informação sobre os azulejos da mancha */
    azlman *m_tail;     /* Cauda da mesma lista */    
    int m_cor;          /* Cor da mancha */
    int m_pontos;       /* Número de pontos da mancha */
    int m_azulejos;     /* Número de azulejos da mancha */
    int m_linha;        /* linha do primeiro azulejo da mancha */
    int m_coluna;       /* coluna do primeiro azulejo da mancha */
}mancha_t;

typedef struct man_list{    /* Definição do conteúdo de um elemento da lista de manchas */
    mancha_t *move;       /* Cabeça de uma mancha */
    struct man_list *next;  /* Apontador para o próximo elemento */
}man_list;

/*
 * adj_cmp()
 *
 * Argumentos:
 * 
 * -head = cabeça da lista de azulejos da mancha
 * -matriz = matriz de azulejos
 * -l_start = linha do azulejo inicial
 * -c_start = coluna do azulejo inicial
 * -l_end = linha do azulejo a comparar
 * -c_end = coluna do azulejo a comparar
 * -L_max = número de linhas da matriz
 * -C_max = número de colunas da matriz
 * 
 * Descrição:
 * 
 * -Esta função compara a cor de dois azulejos
 * 
 * Retorno: 1 = são iguais; 0 = são diferentes
 * 
 */
int adj_cmp(entrada ***matriz, int l_start, int c_start, int l_end, int c_end, int L_max, int C_max);

/*
 * InsereAzulejo()
 *
 * Argumentos:
 * 
 * -mp = apontador para a informação da mancha (serve para atualizar a cauda da lista)
 * -head = apontador para a cabeça da lista
 * -linha = linha onde se situa o azulejo a inserir
 * -coluna = coluna onde se situa o azulejo a inserir
 * -n_azulejos = número de azulejos presentes na mancha
 * 
 * Descrição: A função insere um azulejo no fim da lista de azulejos
 * 
 * Retorno: void
 */
void InsereAzulejo(azlman **head, int linha, int coluna, int n_azulejos);

/*
 * find_mancha()
 *
 * Argumentos:
 * 
 * -matriz = matriz de inteiros que contém os "azulejos"
 * -L_max = número de linhas da matriz
 * -C_max = números de colunas da matriz
 * -l_prob = linha do azulejo pedido
 * -c_prob = coluna do azulejo pedido
 * -diff_flag = flag para o caso em que a mancha ocupa toda a matriz
 * -empty_flag = flag que diz se a matriz está vazia ou não
 * 
 * Descrição:
 * 
 * -Para um par de coordenadas na matriz, a função regista a mancha que começa
 * nesse par de coordenadas.
 * 
 * Retorno: Um apontador para um bloco de memória que contém informação da mancha 
 * registada
 */
mancha_t *find_mancha(entrada ***matriz, int L_max, int C_max, int l_aux, int c_aux);

/*
 * remove_mancha()
 * 
 * Argumentos:
 * 
 * -matriz = matriz dos "azulejos"
 * -mptr = apontador para o bloco de memória que contém informação sobre a mancha
 * 
 * Descrição: A função remove a mancha da matriz
 * 
 * Retorno: void
*/
void remove_mancha(mancha_t *mptr, entrada ***matriz, int L_max, int C_max);

/*
 * reset_mancha()
 * 
 * Argumentos:
 * 
 * -mptr = apontador para o bloco de memória que contém informação sobre a mancha
 * 
 * Descrição: A função liberta a memória alocada para a mancha
 * 
 * Retorno: void
 */
void reset_mancha(mancha_t **head);

void insert_manlist(man_list **head, mancha_t *nova_m);

void clear_manlist(man_list **head);

#endif
