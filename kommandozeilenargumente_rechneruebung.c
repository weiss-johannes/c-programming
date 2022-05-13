/*
 ============================================================================
 Name        : 03_kommandozeilenargumente.c
 Author      : Tobias Hoffmann
 Version     : 1.0
 Description : Beispiele für das Arbeiten mit Kommandozeilenargumenten
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {

	if (argc < 2) {
		printf("Keine Options-Schalter eingegeben, versuche -h");
		return 0;
	}

	if (argc >= 2) {
		int hilfe, rechnen;
		for (int i = 1 ; i < argc ; i++) {
			if ( strcmp(argv[i], "-h") == 0 ) hilfe = 1;
			if ( strcmp(argv[i], "-r") == 0 ) rechnen = 1;
		}
		// Fehlermeldung wenn keine/beide Optionen gesetzt sind
		if (hilfe == 1 && rechnen == 1) {
			printf("Bitte nur entweder -h oder -r eingeben");
			return -1;
		}
		if (hilfe == 0 && rechnen == 0) {
			printf("Bitte entweder -h oder -r eingeben");
			return -1;
		}

		for (int i = 1 ; i < argc ; i++) {
			if ( strcmp(argv[i], "-h") == 0 ) {
				printf("Hilfetext");
				return 0;
			} else if ( strcmp(argv[i], "-r") == 0 ) {
				// Prüfen, kommen dannach weniger oder mehr als zwei Zahlen-Argumente -> Fehler
				if (i+2 != argc-1) {
					printf("Option -r benötigt zwei darauffolgende Zahlen (Beispiel: -r 5 5)");
					return -1;
				} else {
					// Zahlen konvertieren
					// Ohne Fehlerprüfung
					// int zahl1 = strtol(argv[i+1], NULL, 10);
					// int zahl2 = strtol(argv[i+2], NULL, 10);
					// Mit Fehlerprüfung
					char * endtoken = NULL;
					int zahl1 = strtol(argv[i+1], &endtoken, 10);
					if (*endtoken != '\0' || errno) {
						printf("%s ist keine Zahl", argv[i+1]);
						return -1;
					}
					errno = 0; // errno zurücksetzen
					int zahl2 = strtol(argv[i+2], &endtoken, 10);
					if (*endtoken != '\0' || errno) {
						printf("%s ist keine Zahl", argv[i+2]);
						return -1;
					}
					printf("%d + %d = %d", zahl1, zahl2, zahl1 + zahl2);
				}
			}
		}
	}
}
