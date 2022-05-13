/*
 ============================================================================
 Name        : 01_rekursive_funktionen.c
 Author      : Tobias Hoffmann
 Version     : 1.0
 Description : Beispiele für rekursive Funktionen
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

long fakultaet(long n) {
	if (n > 0) {
		return n * fakultaet(n - 1);
	} else {
		return 1;
	}
}

int fibonacci(int n) {
	if (n > 1) {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
	return 1;
}

int recursiveMult3(int n) {
	if (n == 1) {
		return 3;
	}
	return recursiveMult3(n - 1) + 3;
}

int recursiveSum(int n) {
	if (n == 1) {
		return 1;
	}
	return recursiveSum(n - 1) + n;
}

int itterativerGGT(int a, int b)
{
    if (a == 0) return abs(b);
    if (b == 0) return abs(a);

    int rest;
    do {
        rest = a % b;
        a = b;
        b = rest;
    } while (b != 0);

    return abs(a);
}

int rekursiverGGT(int a, int b) {
	if ( b == 0) {
		return a;
	}
	return rekursiverGGT(b, a % b);
}


int main(void) {

	// Fakultät
	printf("Fakultät von 5 => %ld\n", fakultaet(5));

	// Fibonacci
	for (int i = 0; i < 10; i++) {
		printf("F(%d) = %d\n", i, fibonacci(i));
	}

	// Recursive multiply by 3, Recursive sum
	int zahl = 30;
//	printf("Zahl eingeben: ");
//	fflush(stdout); // Needed for eclipse to flush stdout buffer
//	scanf("%d", &zahl);
	printf("Zahl mal drei => %d\n", recursiveMult3(zahl));
	printf("Zahl Summe von 1 bis Zahl => %d\n", recursiveSum(zahl));

	// ggT
	printf("GGT von 18 und 30 ist %d\n", itterativerGGT(18, 30));
	printf("GGT von 18 und 30 ist %d\n", rekursiverGGT(18, 30));
}
