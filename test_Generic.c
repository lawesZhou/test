#include <stdio.h>
#define printX(x, n) _Generic((x),			\
			double *: print_double,		 \
			int *: print_int)(x, n)
			

void print_double(double arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("double %lf\n", arr[i]);
}

void print_int(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("int %d\n", arr[i]);
}

int main()
{
	double darr[] = {1.0, 2.5, 3.0};
	int iarr[] = {1, 2, 3};
			
	printX(darr, 3);
	printX(iarr, 3);
					
	return 0;
}	
