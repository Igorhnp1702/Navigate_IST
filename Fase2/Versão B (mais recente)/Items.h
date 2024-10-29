/******************************************************************************
 * File to define the abstract data type for the Navigate_IST project
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#ifndef _Items_
#define _Items_

/*
 * Item data type
 *
 * Description: Abstract data type to help store elements of any kind
 * 
 * Note: With this void pointer, all the client needs to do is cast the 
 * elements to be pushed to the stack to an Item an cast the elements read 
 * from the stack to the desired pointer
 */

typedef void* Item;

#endif