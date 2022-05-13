#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	// Dateipfad + Dateiname einlesen, maximal 250 Zeichen
	char absolutePath[250];
	printf("Dateipfad:   ");
	scanf("%250s", absolutePath);
	fflush(stdin);

	// Öffne Datei zum schreiben
	FILE* output = fopen(absolutePath, "w");
	// Prüfen ob Datei geöffnet wurde
	if (output == NULL) {
		return -1;
	}

	// Nutzereingabe einlesen und schreiben, so lange bis "<ende>" eingelesen wird
	char eingabe[75];
	printf("Texteingabe: ");

	// Solange eingabe nicht "<ende>" ist
	while (strcmp(eingabe, "<ende>\n") != 0) {
		fgets(eingabe, 75, stdin);

		// Alternativ '\n' entfernen: eingabe[strlen(eingabe) - 1] = '\0';
		if(strcmp(eingabe, "<ende>\n") != 0) {
			fputs(eingabe, output);
		}
	}
	fclose(output); // output Datei schließen

	FILE* lesenDatei = fopen(absolutePath, "r");
	// Zeichenweise lesen
	int inputZeichen = fgetc(lesenDatei); // erstes Zeichen einlesen

	while(feof(lesenDatei) == 0 && ferror(lesenDatei) == 0) {
		printf("%c", inputZeichen);
		inputZeichen = fgetc(lesenDatei);
	}
}
