/*
 ============================================================================
 Name        : 03_kommandozeilenargumente_12.1.c
 Author      : Tobias Hoffmann
 Version     : 1.0
 Description : Kommandozeilenoptionen Umwandlung MeterCentimeter & FussInches
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>


void mtofi(double meter, int* fussanteil, double* inchanteil) {
	double fuss = meter * 3.280839895;
	printf("feet: %lf\n", fuss);

	*fussanteil = (int) floor(fuss);
	*inchanteil = (fuss - *fussanteil) * 12;

//	 Alternativ
//	 double inches = meter * 39.37007874;
//	 int foot = (int) floor(inches/12);
//	 *fussanteil = foot;
//	 *inchanteil = inches - foot*12 ;
}

void ftomcm(double feet, int* meteranteil, double* centimeteranteil) {
	double centimeter = feet * 30.48;

	*meteranteil = (int) floor(centimeter / 100);
	*centimeteranteil = centimeter - 100 * (*meteranteil);
}


int main(int argc, char *argv[])
{
	setbuf(stdout, NULL);
	double werteingabe;

	if (argc < 3) {
		printf("Nicht genugen Argumente");
		return -1;
	} else {
		char *endtoken = NULL;
		werteingabe = strtod(argv[2], &endtoken);
		if (endtoken != '\0' || errno) {
			printf("Fehler beim parsen der Kommazahl\n");
			return -1;
		}
	}

	if (strcmp(argv[1], "-f") == 0 ) {
		int fuss;
		double inches;

		mtofi(werteingabe, &fuss, &inches);
		printf("%d feet - %.2lf inches\n", fuss, inches);
	}

	if (strcmp(argv[1], "-m") == 0 ) {
		int meter;
		double centimeter;

		ftomcm(werteingabe, &meter, &centimeter);
		printf("%d meter - %.2lf cm", meter, centimeter);
	}
}
