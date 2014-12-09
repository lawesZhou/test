#ifndef PRINT_H
#define PRINT_H
#define printA(x,n) _Generic((x), int    *: print_intArray,	\
				  double *: print_doubleArray)(x, n)

void print_intArray(int *array, int n);

void print_doubleArray(double *array, int n);

#endif
