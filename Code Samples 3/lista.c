#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Estrutura da listas
struct _Node {
    void* data;                   //Receber informação
    bool (*equals)(void*, void*); //Servirá para comparações
    struct _Node* prev;           //Aponta para o nó anterior
    struct _Node* next;           //Aponta para o nó seguinte
};

Node NodeNew(void* data , bool (*equals)(void*, void*) ) {
    Node newNode = (Node) malloc(sizeof(struct _Node));
    newNode->equals = equals;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/*Funções que dão return de "node->data", "node->next",
 "node->prev" e "node == NULL", para, posteriormente,
 facilitar a escrita e leitura do código*/
void* NodeGetData(Node node) { return node->data; }
Node NodeGetNext(Node node) { return node->next; }
Node NodeGetPrev(Node node) { return node->prev; }
bool NodeIsLastOne(Node node) { return node == NULL; }

//Coloca um nó numa lista
Node NodeInsert(Node head, void* data, bool (*equals)(void*, void*) ) {
    if(head == NULL)
        return NodeNew(data,equals);

    Node lastone = head;
    for ( ; lastone->next != NULL ; lastone = lastone->next );

    Node newNode = NodeNew(data,equals);
    newNode->prev = lastone;
    lastone->next = newNode;

    return head;
}

/*"int (*operation)(void*, void*)" é substituído,noutras
  partes do código, por "CandidatoGreaterNota"
  (função "matcher") e "CandidatoSmallerID"
  (função "escrever_nao_colocados"),dependendo
  de qual é o parâmetro pelo qual se quer ordenar
  (decrescente de nota de candidatura
  e crescente de id, respetivamente)*/
void NodeSort(Node head , int (*operation)(void*, void*) ) {
    void* temp;

    for ( Node i = head ; i != NULL ; i = i->next ) {
        for ( Node j = head ; j->next != NULL ; j = j->next ) {
            if ( operation( j->data , j->next->data ) < 0 ) {
                /* swap the nodes */
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

}

//Retira um nó de uma lista
void* NodeDelete(Node* head) {
    void* data = (*head)->data;
    if (*head == NULL)
        return data;

    if ((*head)->prev == NULL) {
        // Its the first element
        free(*head);
        return data;
    }

    (*head)->prev->next = (*head)->next;
    (*head)->next->prev = (*head)->prev;

    free(*head);
    return data;
}

//Retira todos os nós da lista
void* NodeDeleteAll(Node* head , void (*destructor)(void*) ) {
    Node current = *head, next;

    while( current != NULL ) {
        next = current->next;
        destructor(current->data);
        free(current);
        current = next;
    }

    *head = NULL;
    return head;
}


