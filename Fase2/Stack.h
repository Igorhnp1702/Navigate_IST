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
 * -Maximum number of elements in the stack
 * -The size of each element to be sotred in the stack
 * 
 * Return: Pointer to an empty stack
 */
Stackblock* initializeStack(int, size_t);


/*
 * push()
 * 
 * Arguments:
 * 
 * -The adress of the stack
 * -The item to be pushed
 * 
 * Description: Adds Item to the top of the stack
 * 
 * Return: 1 if successful, 0 if not
 */
int push(Stackblock**, Item);


/*
 * pop()
 * 
 * Arguments:
 * 
 * -The memory adress of the stack
 * 
 * Description: Removes the top of the stack
 * 
 * Return: 1 if successful, 0 if not
 */
int pop(Stackblock**);


/*
 * freeStack()
 * 
 * Arguments:
 * 
 * -The memory address of the stack
 * 
 * Description: Frees s
 * 
 * Return:
 */
void freeStack(Stackblock**);

/*
 * freeTop()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
int freeTop(Stackblock **);

/*
 * isEmpty()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
int isEmpty(Stackblock**);

/*
 * isFull()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
int isFull(Stackblock**);

/*
 * Stacklen()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
int Stacklen(Stackblock**);

/*
 * peekTop()
 * 
 * Arguments:
 * 
 * Description:
 * 
 * Return:
 */
Item peekTop(Stackblock**);

#endif