#include <stdio.h>
#include <stdlib.h>
#include "strukturen.h"
#include "funktionen.h"

#define MAX 15

int main(void) {
	setbuf(stdout, NULL);
	unsigned int anzahlGespeichert = 0;
	TDATEN telefonliste[MAX];

	anzahlGespeichert = einlesen(telefonliste, MAX);

	for(int i=0; i < anzahlGespeichert; i++) {
		ausgeben(&telefonliste[i]);
	}

	// suche telefonnummer 555
	TDATEN* gesucht = suche_rufnr(telefonliste, anzahlGespeichert, 555);
	printf("%p", gesucht);
}
