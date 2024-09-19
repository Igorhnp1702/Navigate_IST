/******************************************************************************
 * Ficheiro das structs utilizadas no projeto Navigate_IST
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef __structs__
#define __structs__

#include <stdio.h>
#include <stdbool.h>


typedef struct _files {
    FILE* Input;
    FILE* Output;
} *Files;


typedef struct _parameters {
    
    int L;
    int C;
    int l_1;
    int c_1;
    int k;
    int l_2;
    int c_2;

} *Parameters;


typedef struct {
    int l;
    int c;
} Position;


typedef struct Node {

    Position *path;
    int passos;
    int energia;
    struct Node *next;

} Node;

typedef struct {

    Node *head;
    int n_paths;

} List_Path;


typedef struct _element {
    
    int energia;
    List_Path *paths;

} *Element;

#endif