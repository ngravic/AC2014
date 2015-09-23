/*
	Nicolas Grabich
	PLANCHA 0: Introduccion y operadores de bits		
*/

/*
	EJERCICIO 1
	1000 0000  0000 0000  0000 0000  0000 0000 == 1 << 31 
	1000 0000  0000 0000  1000 0000  0000 0000 == (1 << 31) | (1 << 15)
	1111 1111  1111 1111  1111 1111  0000 0000 == -1 & -256
	1010 1010  0000 0000  0000 0000  1010 1010 == 0xAA | (0xAA << 24)
	0000 0000  0000 0000  0000 0101  0000 0000 == 5 << 8
	1111 1111  1111 1111  1111 1110  1111 1111 == -1 & (~(1 << 8))  	

*/

#define LONG_BITS	sizeof(long int) * 8
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/* EJERCICIO 2 */

int isOne (long int n, int b) {
	long int a = 1L << b;
	if(n & a)
		return 1;
	return 0;
}

/* EJERCICIO 3 */

void printBin (long int n) {
	int i;
	for(i = LONG_BITS - 1; i >= 0; i--) {
		printf("%d", isOne(n, i));
	}
	puts("");
}	

/* EJERCICIO 4 */

void rotateBits(long int n) {
	long int r1 = (n >> 1);
	long int r2 = n << LONG_BITS - 1;	
	printf("Before Rotate:\t");
	printBin(n);
	printf("%s", "After Rotate:\t") ;
	printBin(r1 | r2);
}

/* EJERCICIO 5 */
/* Se puede implementar sin variables auxiliares, utilizando las propiedades del XOR como se muestra a continuacion */

void exchange(int *a, int *b, int *c) {
	*a = *a ^ *b;
	*b = *a ^ *b;	/* b = a ^ b ^ b = a */
	*a = *a ^ *b;	/* a = a ^ b ^ a = b */
	
	*a = *a ^ *c;	/* a = b ^ c */
	*c = *a ^ *c;	/* c = b ^ c ^ c = b */
	*a = *a ^ *c;	/* a = b ^ c ^ b = c */
}

/* EJERCICIO 6 */
/*
	No hay que realizar modificaciones para decodificar. Tan solo hay que ejecutar el programa con la misma clave con la que se codifico el archivo para decodificarlo.
	No se gana nada codificando mas de una vez, ya que segun las propiedades del XOR: (A ^ B) ^ C = A ^ (B ^ C), es decir que es lo mismo codificar el archivo con una clave A que con las claves (B ^ C)
*/

void encodeXor(int code) {	
	char toenc = getchar();
	while(toenc != EOF) {
		putchar(toenc ^ code);
		toenc = getchar();		
	}
}

int main(int argc, char **argv) {

}
