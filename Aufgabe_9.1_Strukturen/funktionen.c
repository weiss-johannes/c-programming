#include <stdlib.h>
#include "strukturen.h"
#include "funktionen.h"
unsigned int einlesen(TDATEN telefonliste[], int max) {

	unsigned int eintraege;
	printf("Wie viele Einträge? : ");
	scanf("%du", &eintraege);

	if (eintraege > max) {
		printf("Nur maximal %du Einträge möglich", max);
		eintraege = max;
	}

	for(int i = 0; i < eintraege; i++) {
		printf("-----------\nEingabe von Telefonspeichereintrag %d\n", i);
		printf("Vorname: ");
		scanf("%s", telefonliste[i].vorname);
		printf("Nachname: ");
		scanf("%s", telefonliste[i].nachname);
		printf("Ländercode: ");
		scanf("%du", &telefonliste[i].laendercode);
		printf("vorwahl: ");
		scanf("%du", &telefonliste[i].vorwahl);
		printf("Rufnummer: ");
		scanf("%du", &telefonliste[i].rufnummer);
	}

	return eintraege;
}

void ausgeben(TDATEN* telefoneintrag) {
	printf("\nVorname: %s\n", telefoneintrag->vorname);
	printf("Nachname: %s\n", telefoneintrag->nachname);
	printf("Ländercode: %d\n", telefoneintrag->laendercode);
	printf("vorwahl: %d\n", telefoneintrag->vorwahl);
	printf("Rufnummer: %d\n", telefoneintrag->rufnummer);
}

TDATEN* suche_rufnr(TDATEN telefonliste[], unsigned int anzahl, unsigned int suchnummer) {
	for(int i = 0; i < anzahl; i++) {
		if (telefonliste[i].rufnummer == suchnummer) {
			return &telefonliste[i];
		}
	}
	return NULL;
}
