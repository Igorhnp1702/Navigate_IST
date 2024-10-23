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

/*
 * Stackblock data type
 * 
 * Description: Data type to abstract the fields of the stackbox data type
 */

typedef struct _stackbox Stackblock;



/*
 * initializeStack()
 *
 * Arguments:
 * 
 * -the intended maximum size of the stack
 * -the size of each element to be sotred in the stack
 * 
 * Return: An empty stack of items, implemented as an array
 */
Stackblock* initializeStack(int, size_t);


/*
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


/*
 * pop()
 * 
 * Arguments:
 * 
 * -The memory adress of the stack
 * 
 * Description:
 * 
 * Return:
 */
int pop(Stackblock**);


/*
 * freeStack()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
void freeStack(Stackblock**);

/*
 * freeStack()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
int freeTop(Stackblock **);

/*
 * freeStack()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
int isEmpty(Stackblock**);

/*
 * freeStack()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
int isFull(Stackblock**);

/*
 * freeStack()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
int Stacklen(Stackblock**);

/*
 * freeStack()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
Item peekTop(Stackblock**);

#endif