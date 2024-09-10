#ifndef __structs__
#define __structs__

#include <stdio.h>
#include <stdbool.h>

/* 

                FILES

*/

typedef struct _files {
    FILE* Input;
    FILE* Output;
} *Files;

/* 

                MATRIX

*/

typedef struct _parameters {
    
    int L;
    int C;
    int l_1;
    int c_1;
    int k;
    int l_2;
    int c_2;

    
} *Parameters;


typedef struct _element {
    
    int colour;
    bool empty;
    bool occupied;  // serve para mostrar que um elemento pertence/ou não a uma mancha
    
} *Element;

typedef struct _list_matrix {
    
    Element** matrix;  // serve para mostrar que um elemento pertence/ou não a uma mancha
    int size;
    
} *List_Matrix;


/* 

                MANCHA

*/


typedef struct _coordinates{
    int row;
    int col;
} *Coordinate;

typedef struct _mancha{
    Coordinate* coordinates;
    int size;
    int capacity;
    int score;
} *Mancha;

typedef struct _list_mancha{
    Mancha* mancha;
    int size;
    int capacity;
    
} *List_Mancha;



/* 

                STACK

*/



typedef struct _stacknode{
    int row;
    int col;
    int stack_size;
}* StackNode;

typedef struct _stackresult{
    StackNode stack;
    int added;
} StackResult;



/* 

                SOLUTION

*/

typedef struct _solution{
    int *sequence;
    int length;
    int score;
} *Solution;

#endif
