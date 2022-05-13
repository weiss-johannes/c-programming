#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	// Dateipfad + Dateiname einlesen, maximal 250 Zeichen
	char fullPath[250];

	char dateiPath[250];
	char dateiName[250];
	printf("Dateipfad:   ");
	scanf("%250s", dateiPath);
	printf("Dateiname:   ");
	scanf("%250s", dateiName);
	// Pruefen ob pfad und name zusammen maximal 250 zeichen sind
	if (strlen(dateiName) + strlen(dateiPath) <= 250) {
		strcpy(fullPath, dateiPath); // kopiere pfad nach fullPath , mit strcpy!
		strcat(fullPath, dateiName); // hänge den dateinamen an fullPath an, mit strcat!
	} else {
		// zu viele Zeichen -> Fehler
		printf("Dateipfad + Dateiname maximal 250 zeichen erlaubt. Eingabe hat %d", strlen(dateiName) + strlen(dateiPath));
		return -1;
	}

	// Öffne Datei zum schreiben
	FILE* output = fopen(fullPath, "w");
	// Prüfen ob Datei geöffnet wurde
	if (output == NULL) {
		printf("Konnte Datei nicht öffnen: %s", fullPath);
		return -1;
	}

	// Nutzereingabe einlesen und schreiben, so lange bis "<ende>" eingelesen wird
	char eingabe[75];
	printf("Texteingabe: ");

	// Solange eingabe nicht "<ende>\n" ist - Anmerkung: fgets liefert uns die Enter-Taste, also \n am Ende mit
	while (strcmp(eingabe, "<ende>\n") != 0) {
		fgets(eingabe, 75, stdin);
		if(strcmp(eingabe, "<ende>\n") != 0) {
			fputs(eingabe, output);
		}
	}
	fclose(output); // output Datei schließen

	FILE* lesenDatei = fopen(fullPath, "r");
	// Zeichenweise lesen
	int inputZeichen = fgetc(lesenDatei); // erstes Zeichen einlesen

	while(feof(lesenDatei) == 0 && ferror(lesenDatei) == 0) {
		printf("%c", inputZeichen);
		inputZeichen = fgetc(lesenDatei);
	}
}
