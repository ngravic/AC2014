/*
	Nicolas Grabich
	Sebastian Meli

	PLANCHA 1: C y sistemas de numeracion posicional
*/

#include <stdio.h>
#include <gmp.h>
#define USHORT_SIZE (sizeof(short) * 8)

typedef unsigned short ushort;

typedef struct {
	ushort n[16];
} nro;

void print(nro n) {
	int i;
	char str[1024];
	short sign[16], num[16];
	mpz_t n1, n2;
	for (i=0; i<15; i++) {
		num[i] = n.n[i];
		sign[i] = 0;
	}
	num[15] = n.n[15] & 0x7FFF;
	sign[15] = n.n[15] & 0x8000;
	mpz_init(n1);
	mpz_init(n2);
	mpz_import(n1, 16, -1, 2, 0, 0, num);
	mpz_import(n2, 16, -1, 2, 0, 0, sign);
	mpz_neg(n2, n2);
	mpz_add(n2, n1, n2);
	mpz_get_str(str, 10, n2);
	printf("%s", str);
	mpz_clear(n1);
	mpz_clear(n2);
}

/*	EJERCICIO 1	*/

unsigned multC (unsigned a, unsigned b) {
	if(b == 0)
		return 0;	
	if(b == 1)
		return a;
	if((b & 1) == 0)
		return multC(a << 1, b >> 1);
	return (multC(a << 1, b >> 1) + a);
}

/*	EJERCICIO 2	*/

int isZero(nro n) {
	int i;
	for (i = 0; i < 16; i++) {
		if(n.n[i])
			return 0;
	}
	return 1;
}

int isOne(nro n) {
	int i;
	for(i = 1; i < 16; i++) {
		if(n.n[i])
			return 0;
	}
	return n.n[0] == 1;
}
int isEven(nro a){
	return !(a.n[0] & 1);
}

nro bwLeft(nro n1){
	char i, bit, last_bit = 0;
	for (i = 0; i < 16; i++) {
		bit = n1.n[i] >> (USHORT_SIZE - 1);
		n1.n[i] = (n1.n[i] << 1) | last_bit;
		last_bit = bit;
	}
	return n1;
}

nro bwRight(nro n1){
	char i, bit, last_bit = 0;
	for (i = 15; i >= 0; i--) {
		bit = (n1.n[i] & 1);
		n1.n[i] = (n1.n[i] >> 1) | (last_bit << (USHORT_SIZE - 1));
		last_bit = bit;
	}
	return n1;
}

nro add(nro n1, nro n2){
	int i, carry = 0;
	nro toRet;
	for (i = 0; i < 16; i++){		
		int v = n1.n[i] + (n2.n[i] + carry);
		toRet.n[i]=v;
		carry = v >> USHORT_SIZE;
	}
	return toRet;
}

/*	EJERECICIO 3	*/

nro mult(nro n1, nro n2) {
	int i;
	nro toRet;
	if (isZero(n2)) {		
		for(i = 0; i < 16; i++)
			toRet.n[i] = 0;
		return toRet;
	}
	if (isOne(n2))
		return n1;		
	if (isEven(n2))
		return mult(bwLeft(n1), bwRight(n2));
	return add(mult(bwLeft(n1), bwRight(n2)), n1);
}


int main (int argc, char *argv[]) {
	return 0;	
}


