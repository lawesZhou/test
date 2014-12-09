#include <stdio.h>

#include "print.h"

int main()
{
	double d[10] = {1.3, 3.3, 3.4};
	print_doubleArrray(d, 3);
	
	int a[10] = {1, 2, 3};
	print_intArrray(a, 3);

	return 0;
}
