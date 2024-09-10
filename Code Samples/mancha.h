#ifndef __mancha__
#define __mancha__

#include "structs.h"


bool is_within_bouds(int L, int C, int l, int c);
bool is_mancha(Mancha mancha);

Mancha return_not_mancha(Mancha mancha, bool** visited, int L, StackNode stack);
Mancha return_is_mancha(Mancha mancha, bool** visited, int L, StackNode stack);

void Print_Mancha(Mancha mancha, Element** matrix);
void Calculate_Score(Mancha mancha);

Mancha Malloc_Mancha(int L, int C);
void FREE_MANCHA(Mancha mancha);

bool** Malloc_Visited(int L, int C);
void FREE_Visited(bool** visited, int L);

Mancha find_mancha(Element** matrix, int L, int C, int l, int c);



List_Mancha Malloc_List_Mancha(int L, int C);
void FREE_LIST_MANCHA(List_Mancha list_mancha);

void ADD_mancha_to_List(List_Mancha list_mancha, Mancha mancha);

List_Mancha find_ALL_manchas(Element** matrix, int L, int C);

void Print_List_Mancha(List_Mancha list, Element** matrix);


#endif