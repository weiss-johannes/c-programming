#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char hallowelt[] = "Hallo Welt fuer Dateien!";
	// hallowelt in Datei schreiben
	FILE* schreibenDatei = fopen("hwfd.txt", "w");
	fputs(hallowelt, schreibenDatei);
	fclose(schreibenDatei);

	//hallowelt aus Datei lesen
	FILE* lesenDatei = fopen("hwfd.txt", "r");

	// Zeichenweise lesen
	int inputZeichen = fgetc(lesenDatei); // erstes Zeichen einlesen

	while(feof(lesenDatei) == 0 && ferror(lesenDatei) == 0) { // solange bis dateiende erreicht ist
		printf("%c", (char) inputZeichen); // zeichen in konsole ausgeben
		inputZeichen = fgetc(lesenDatei); // n�chstes zeichen einlesen
	}
}
