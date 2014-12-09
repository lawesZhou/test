#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union ArrayType {
	int *d;
	double *lf;
	char *c;
};

enum DATATYPE {
	CHAR	= 'c',
	DOUBLE	= 'l',
	INT 	= 'd'
};

struct ArrayType2 {
	enum DATATYPE flag;

	union {
		int *d;
		double *lf;
		char *c;
	};
};

void printArray(struct ArrayType2 array,int n)
{
	int i;
	int sizea = n;

	int flag = array.flag;

	switch(flag) {
	case 'd':
		for (i = 0; i < sizea; ++i) {
                	printf("%d%c", array.d[i], i == sizea-1 ? '\n':'\t');
		}

		break;
	case 'l':
		for (i = 0; i < sizea; ++i) {
                	printf("%lf%c", array.lf[i], i == sizea-1 ? '\n':'\t');
		}

		break;
	case 'c':
		for (i = 0; i < sizea; ++i) {
                	printf("%c%c", array.c[i], i == sizea-1 ? '\n':'\t');
		}

		break;
	default:
		printf("invalid data type input");
		exit(-1);
		break;
	}
}

void printArray2(void *val, int n, char flag)
{
        int i;
        int sizea = n + 1;
	union ArrayType a;

	switch(flag) {
	case 'd':
		a.d = (int *)val;

		for (i = 0; i < sizea; ++i) {
                	printf("%d%c", a.d[i], i == sizea-1 ? '\n':'\t');
		}

		break;
	case 'a':
		a.lf = (double *)val;

		for (i = 0; i < sizea; ++i) {
                	printf("%lf%c", a.lf[i], i == sizea-1 ? '\n':'\t');
		}

		break;
	case 'c':
		a.c = (char *)val;

		for (i = 0; i < sizea; ++i) {
                	printf("%c%c", a.c[i], i == sizea-1 ? '\n':'\t');
		}

		break;
	default:
		break;
	}
}

int main()
{
	struct ArrayType2 type_int;
	struct ArrayType2 type_double;

	int a[] = {1, 3, 5, 6};
	double d[] = {3.5, 3.22, 54.4};

	type_int.flag = INT;
	type_int.d = a;
	printArray(type_int, sizeof(a)/sizeof(int));	

	type_double.flag = DOUBLE; 
	type_double.lf = d;
	printArray(type_double, sizeof(d)/sizeof(double));	

	return 0;
}
