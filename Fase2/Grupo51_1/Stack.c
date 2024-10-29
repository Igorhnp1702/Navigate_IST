/******************************************************************************
 * Ficheiro com a implementação das operações sobre pilhas
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "Items.h"
#include "Stack.h"


struct _stackbox{
    Item* Itemarray;
    size_t Itemlen;
    int arraysize;
    int freeIndex;    
};

Stackblock* initializeStack(int Stacksize, size_t Itemsize){

    //Sanity check
    if(Stacksize <= 0) return NULL;

    Stackblock *Stack;
    int i;
    
    if((Stack = (Stackblock*)calloc(1, sizeof(Stackblock))) == NULL){
        exit(0);
    }
    

    if((Stack->Itemarray = (Item*)calloc(Stacksize, sizeof(Item))) == NULL){
        exit(0);
    }
    for(i = 0; i < Stacksize; i++){
        Stack->Itemarray[i] = (Item)calloc(1, Itemsize);
    }
    
    Stack->arraysize = Stacksize;
    Stack->Itemlen = Itemsize;
    Stack->freeIndex = 0;    
    return Stack;    
}

int push(Stackblock** stackptr, Item newItem){
    
    int success = 0;
    if(isFull(stackptr) == 1) return success;    
    
    memcpy((*stackptr)->Itemarray[(*stackptr)->freeIndex], newItem, (*stackptr)->Itemlen);
    (*stackptr)->freeIndex++;
    return success++;
}

int pop(Stackblock**stackptr){

    int success = 0;
    if(isEmpty(stackptr) == 1) return success;

    memset((*stackptr)->Itemarray[(*stackptr)->freeIndex - 1], 0, (*stackptr)->Itemlen);
    (*stackptr)->freeIndex--;
    return success++;
}

void freeStack(Stackblock **stackptr){
    
    int i;

    for(i = (*stackptr)->arraysize - 1; i >= 0; i--){
        
        if((*stackptr)->Itemarray[i] != NULL) free((*stackptr)->Itemarray[i]);
    }
    free((*stackptr)->Itemarray);
    free((*stackptr));    
    return;
    
}

int freeTop(Stackblock **stackptr){
    
    int success = 0;
    if(isEmpty(stackptr) == 1) return success;

    free((*stackptr)->Itemarray[(*stackptr)->freeIndex - 1]);
    (*stackptr)->Itemarray[(*stackptr)->freeIndex - 1] = NULL;
    (*stackptr)->freeIndex--;
    return success++;
}

int isEmpty(Stackblock **stackptr){

    if((*stackptr)->freeIndex == 0) return 1;
    else return 0;
}

int isFull(Stackblock **stackptr){
    
    if((*stackptr)->freeIndex == (*stackptr)->arraysize) return 1;
    else return 0;
}

int Stacklen(Stackblock **stackptr){

    return (*stackptr)->freeIndex;
    
}

Item peekTop(Stackblock **stackptr){

    if((*stackptr)->freeIndex == 0) return NULL;    

    else return (*stackptr)->Itemarray[(*stackptr)->freeIndex - 1];
}

