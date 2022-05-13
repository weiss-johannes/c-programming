#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	char hallowelt[] = "Hallo Welt fuer Dateien!";
	// hallowelt in Datei schreiben
	FILE* schreibenDatei = fopen("hwfd.txt", "w");
	if (schreibenDatei == NULL) {
		printf("Konnte datei nicht oeffnen");
		return -1;
	}
	fputs(hallowelt, schreibenDatei);
	fclose(schreibenDatei);

	//hallowelt aus Datei lesen
	FILE* lesenDatei = fopen("hwfd.txt", "r");
	if (lesenDatei == NULL) {
		printf("Konnte datei nicht oeffnen");
		return -1;
	}
	char inputBuffer[256];

	// Nur eine Zeile lesen, oder maximal 256 Zeichen
	fgets(inputBuffer, 256, lesenDatei);
	printf("%s", inputBuffer);

	// Alternativ: Fuer auslesen von ganz viel Text zeilenweise
	rewind(lesenDatei); // Wieder den Anfang der Datei lesen
	while(feof(lesenDatei) == 0 && ferror(lesenDatei) == 0) {
		fgets(inputBuffer, 256, lesenDatei);
		printf("%s", inputBuffer);
	}
}
