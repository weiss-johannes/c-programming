#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	FILE *datei;
	// Loescht Datei, falls sie existiert und erstellt leere Datei
	// datei = fopen("textdatei.txt", "w");
	// Haengt Text an das Ende der Datei - erstellt Datei falls nicht existent
	datei = fopen("textdatei.txt", "a+");

	printf("Gib den Text ein, der gespeichert werden soll:\n");
	char c;
	while ((c = getchar()) != '\n') {
		fputc(c, datei);
		// Alternativ
		// fprintf(datei, "%c", c);
	}
}
