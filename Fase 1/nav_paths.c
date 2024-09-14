#include <stdio.h>
#include <stdlib.h>

#include "structs.h"


// Cria a ramificação de um caminho
Node* Create_Node (Position *path, int passos, int energia) {
    
    Node *node = (Node*)malloc(sizeof(node));
    if(node == NULL)
    {
        exit(0);
    }

    node->path = (Position*)malloc(passos * sizeof(Position));
    if(node->path == NULL)
    {
        exit(0);
    }


    for (int i = 0; i < passos; i++) {
        node->path[i] = path[i];
    }
    node->passos = passos;
    node->energia = energia;
    node->next = NULL;
    return node;
}




void ADD_Path (List_Path *paths, Node node){

    Node *newNode = createPathNode(node.path, node.passos, node.energia);
    newNode->next = paths->head;
    paths->head = newNode;
    paths->n_paths++;
    
}



List_Path* Create_List_Path() {

    List_Path *list = (List_Path*)malloc(sizeof(List_Path));
    list->head = NULL;
    list->n_paths = 0;

    return list;
}




void FREE_Node(Node* node){

    free(node->path);
    free(node);

}


void FREE_List_Path(List_Path *paths) {
    
    if (paths != NULL) {
        Node *current = paths->head;
        while (current != NULL) {
            Node *next = current->next;
            FREE_Node(current);
            current = next;
        }
        free(paths);
    }

}