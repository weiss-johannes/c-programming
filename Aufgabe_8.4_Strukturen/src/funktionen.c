#include "strukturen.h"
#include "funktionen.h"

#include "stdio.h"


void read_termin(struct termin* term) {
	printf("Neuen Termin einlesen...\n");

	printf("[Terminbeschreibung]\n");
	printf("Titel: ");

	scanf("%s", term->termin_daten.titel);
	printf("Beschreibung: ");
	scanf("%s", term->termin_daten.beschreibung);
	printf("Ort: ");
	scanf("%s", term->termin_daten.ort);

	printf("--Termineingabe--\n");
	printf("[Datum]\n");
	printf("Jahr: ");
	scanf("%d", &term->dat.jahr);
	printf("Monat: ");
	scanf("%d", &term->dat.monat);
	printf("Tag: ");
	scanf("%d", &term->dat.tag);
	printf("[Uhrzeit]\n");
	printf("Stunde: ");
	scanf("%d", &term->uhr.stunde);
	printf("Minute: ");
	scanf("%d", &term->uhr.minute);

	printf("Erinnerung wann?\n");
	printf("[Datum]\n");
	printf("Jahr: ");
	scanf("%d", &term->dat_erinnerung.jahr);
	printf("Monat: ");
	scanf("%d", &term->dat_erinnerung.monat);
	printf("Tag: ");
	scanf("%d", &term->dat_erinnerung.tag);
	printf("[Uhrzeit]\n");
	printf("Stunde: ");
	scanf("%d", &term->uhr_erinnerung.stunde);
	printf("Minute: ");
	scanf("%d", &term->uhr_erinnerung.minute);
}

void display_termin(struct termin* term) {
	printf("[Termin]\n");
	printf("Titel: %s\n", term->termin_daten.titel);
	printf("Beschreibung: %s\n", term->termin_daten.beschreibung);
	printf("Ort: %s\n", term->termin_daten.ort);

	printf("[Datum]\n");
	printf("Jahr: %d\n", term->dat.jahr);
	printf("Monat: %d\n", term->dat.monat);
	printf("Tag: %d\n", term->dat.tag);
	printf("[Uhrzeit]\n");
	printf("Stunde: %d\n", term->uhr.stunde);
	printf("Minute: %d\n", term->uhr.minute);

	printf("[Erinnerung - Datum]\n");
	printf("Jahr: %d\n", term->dat_erinnerung.jahr);
	printf("Monat: %d\n", term->dat_erinnerung.monat);
	printf("Tag: %d\n", term->dat_erinnerung.tag);
	printf("[Erinnerung - Uhrzeit]\n");
	printf("Stunde: %d\n", term->uhr_erinnerung.stunde);
	printf("Minute: %d\n", term->uhr_erinnerung.minute);

}
