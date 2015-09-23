//#define 

/*
	Para copiar el float a entero sin perdida de info
	int *p = (int *)&f;
	int i = p[0];
	
*/
#include<ieee754.h>
#define FRAC(a) (0x7fffff & (((int *)&a)[0]))
#define EXP(a) (0x7f800000 & (((int *)&a)[0]))
void main(){
	ieee754_float a = 3.14;
	printf("%f\n", a);
	printf("%d\n", FRAC(a));
	printf("%d\n", EXP(a));
}

