#ifndef __sort__
#define __sort__

#include "structs.h"


void Remove_Mancha(Element** new_matrix, Mancha mancha);
void Sort_Col(Element** new_matrix, int L, int C);
void Sort_Row(Element** new_matrix, int L, int C);
void Sort(Element** new_matrix, int L, int C);
Element** tileblaster (Element** matrix, Mancha mancha, int L, int C);


#endif