#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>

typedef struct _Node* Node;

Node NodeNew( void* data , bool (*equals)(void*, void*) );
void* NodeGetData(Node node);
Node NodeGetNext(Node node);
Node NodeGetPrev(Node node);
bool NodeIsLastOne(Node node);
Node NodeInsert(Node head, void* data, bool (*equals)(void*, void*) );
void NodeSort(Node head , int (*operation)(void*, void*) );
void* NodeDeleteAll(Node* head , void (*destructor)(void*) );


#endif