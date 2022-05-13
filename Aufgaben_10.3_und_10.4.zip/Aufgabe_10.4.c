#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	setbuf(stdout, NULL);
	// Dateipfad + Dateiname einlesen, maximal 250 Zeichen
	char absolutePath[250];
	printf("Dateipfad:   ");
	scanf("%250s", absolutePath);

	FILE* lesenDatei = fopen(absolutePath, "r");
	if (lesenDatei == NULL) {
		printf("Datei existiert nicht");
		return -1;
	}

	// Zeichen zaehlen, mit fscanf()
	char zeichen;
	long zeichenZaehler = 0;
	while(feof(lesenDatei) == 0) {
		fscanf(lesenDatei, "%c", &zeichen);
		if(feof(lesenDatei) == 0) zeichenZaehler++;
	}

	printf("Anzahl Zeichen: %ld\n", zeichenZaehler);

	//Alternatives Zeichen zaehlen, mit fgetc()
	rewind(lesenDatei); // Rewind, weil wir nach dem obigen Zeichen zaehlen am EOF angekommen sind
	int zeichen2;
	long zeichenZaehler2 = 0;
	while( (zeichen2 = fgetc(lesenDatei)) != EOF) {
		zeichenZaehler2++;
	}

	printf("Anzahl Zeichen: %ld\n", zeichenZaehler2);
}
