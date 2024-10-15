/******************************************************************************
 * Interface do tipo abstrato para pilhas 
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef Stackheader
#define Stackheader

#include "Items.h"
#include <stdlib.h>

typedef struct _stackbox Stackblock;

Stackblock* initializeStack(int, size_t);

int push(Stackblock**, Item);

int pop(Stackblock**);

void freeStack(Stackblock**);

int freeTop(Stackblock **);

int isEmpty(Stackblock**);

int isFull(Stackblock**);

int Stacklen(Stackblock**);

Item peekTop(Stackblock**);

#endif