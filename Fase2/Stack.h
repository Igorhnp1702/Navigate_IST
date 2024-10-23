/******************************************************************************
 * Interface for the stack of items 
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef _Stack_
#define _Stack_

#include <stddef.h>
#include "Items.h"


typedef struct _stackbox Stackblock;



/*
 * initializeStack()
 *
 * Arguments:
 * 
 * -the intended maximum size of the stack
 * -the size of each element to be sotred in the stack
 * 
 * Return: An empty stack of items
 */
Stackblock* initializeStack(int, size_t);


/*
 *
 * push()
 * 
 * Arguments:
 * 
 * -The adress of the stack;
 * -The item to be pushed
 * 
 * Return: 1 if successfull, 0 if not
 */
int push(Stackblock**, Item);

int pop(Stackblock**);

void freeStack(Stackblock**);

int freeTop(Stackblock **);

int isEmpty(Stackblock**);

int isFull(Stackblock**);

int Stacklen(Stackblock**);

Item peekTop(Stackblock**);

#endif