#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	// Nutzereingabe einlesen, maximal 75 zeichen
	char eingabe[75];
	printf("Texteingabe: ");
//	scanf("%75s", eingabe);
	fgets(eingabe, 75, stdin);

	// Dateipfad + Dateiname einlesen, maximal 250 Zeichen
	char absolutePath[250];
	printf("Dateipfad:   ");
	scanf("%250s", absolutePath);
//	fgets(absolutePath, 250, stdin);
//	printf("%s", absolutePath);

	// Datei schreiben
	FILE* output = fopen(absolutePath, "w");
	// Prüfen ob Datei geöffnet wurde
	if (output == NULL) {
		printf("Konnte datei nicht oeffnen.");
		return -1;
	}
	fputs(eingabe, output);
	fclose(output);

	FILE* lesenDatei = fopen(absolutePath, "r");
	// Zeichenweise lesen
	int inputZeichen = fgetc(lesenDatei); // erstes Zeichen einlesen

	while(feof(lesenDatei) == 0 && ferror(lesenDatei) == 0) {
		printf("%c", inputZeichen);
		inputZeichen = fgetc(lesenDatei);
	}
}
