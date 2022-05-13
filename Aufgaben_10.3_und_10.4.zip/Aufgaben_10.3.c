#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	// Dateipfad + Dateiname einlesen, maximal 250 Zeichen
	char absolutePath[250];
	printf("Dateipfad:   ");
	scanf("%250s", absolutePath);

	// Schreiben oder Lesen fragen
	printf("Schreiben (w) oder lesen (r) ? : ");
	fflush(stdin); // Flush stdin um den LF (newline) \n character zu entfernen
	char mode;
	scanf("%c", &mode);

	if (mode != 'w' && mode != 'r') {
		printf("Entweder w oder r eingeben");
		return -1;
	}
	char modestring[2];
	modestring[0] = mode;
	modestring[1] = '\0';

//	// Alternativ: Schreiben oder Lesen fragen
//	printf("Schreiben (w) oder lesen (r) ? : ");
//	fflush(stdin); // Flush stdin um den LF (newline) \n character zu entfernen
//	char modestring[2];
//	scanf("%2s", modestring);
//	if (strcmp(modestring, "w") != 0 && strcmp(modestring, "r") != 0) {
//		printf("Entweder w oder r eingeben");
//		return -1;
//	}

	// Öffne Datei mit Modus"mode"
	FILE* output = fopen(absolutePath, modestring);
	// Prüfen ob Datei geöffnet wurde
	if (output == NULL) {
		printf("Konnte Datei nicht öffnen: %s", absolutePath);
		return -1;
	}

	// Beliebig langen text zeichenweise einlesen
	char eingabe;
	printf("Texteingabe: ");
	fflush(stdin); // flush '\n' aus stdin
	while ((eingabe = getchar()) != '\n') {
		fputc(eingabe, output);
	}

	fclose(output); // output Datei schließen

	FILE* lesenDatei = fopen(absolutePath, "r");
	// Zeichenweise lesen
	int inputZeichen = fgetc(lesenDatei); // erstes Zeichen einlesen

	while(feof(lesenDatei) == 0 && ferror(lesenDatei) == 0) {
		printf("%c", (char) inputZeichen);
		inputZeichen = fgetc(lesenDatei);
	}
	fclose(lesenDatei);
}
