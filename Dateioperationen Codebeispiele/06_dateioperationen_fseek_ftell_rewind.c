#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *datei;
	datei = fopen("fseek_ftell.txt", "a+");
	// Springen ans Ende der Textdatei
	printf("Position im File: %ld\n", ftell(datei));
	fputc((int) 'A', datei);
	// Neue Position in der Textdatei
	printf("Position im File: %ld\n", ftell(datei));
	fclose(datei);

	datei = fopen("fseek_ftell.txt", "r+");
	// Schreibe an Position 0 der Textdatei
	fputc((int) 'A', datei); // Dateizeiger+1 !
	// Springe zum Ende
	fseek(datei, 0, SEEK_END);
	fputc((int) 'Z', datei); // Dateizeiger+1 !
	// Springen zum Position 4 der Textdatei
	fseek(datei, 4, SEEK_SET);
	fputc((int) 'E', datei); // Dateizeiger+1 !
	// Springe 3 Zeichen weiter
	fseek(datei, 3, SEEK_CUR);
	fputc((int) 'I', datei);
	fclose(datei);
}
