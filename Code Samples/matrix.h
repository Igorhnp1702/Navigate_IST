#ifndef __matrix__
#define __matrix__

Parameters READ_PARAMETERS(Files File);
Element** READ_MATRIX(Files File, int L, int C);
Element** Copy_Matrix(Element** matrix, int L, int C);
void Print_Matrix(Element** matrix, int L, int C);

void FREE_MATRIX(Element** matrix, int L, int C);

#endif