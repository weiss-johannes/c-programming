#include <stdio.h>
#include <stdlib.h>


struct pers {
	char vname[20];
	char nname[20];
	long PLZ;
	char ort[20];
	int geburtsjahr;
};

int main(void) {
	struct pers person1 = { "Max", "Mustermann", 10115, "Berlin", 1990};
	struct pers person2 = { "Bob", "Mustermann", 10115, "Berlin", 1990};
	struct pers person3 = { "Anna", "Musterfrau", 10115, "Berlin", 1990};

	// Wir speichern diese Struktur in einer Datei "personen.dat"
	FILE* personenDatei = fopen("personen.dat", "wb");
	// Daten speichern
	fwrite(&person1, sizeof(struct pers), 1, personenDatei);
	fwrite(&person2, sizeof(struct pers), 1, personenDatei);
	fwrite(&person3, sizeof(struct pers), 1, personenDatei);
	fclose(personenDatei);

	FILE* personenDateiLesen = fopen("personen.dat", "rb");

	fseek(personenDateiLesen, 0, SEEK_END);
	int position = ftell(personenDateiLesen);
	printf("Lesen-Position (in Byte): %d \n", position);
	int anzahlPersonenStrukturen = position / sizeof(struct pers);
	printf("Anzahl Personen: %d \n", anzahlPersonenStrukturen);

	// rewind, damit wir wieder von Anfang an auslesen können (mit fseek sind wir ja zuvor ans Ende gesprungen)
	rewind(personenDateiLesen);

	struct pers tempPerson;
	for (int i = 0; i < anzahlPersonenStrukturen; i++) {
		fread(&tempPerson, sizeof(struct pers), 1, personenDateiLesen);
		printf("%s %s\n%ld %s\n%d \n\n", tempPerson.vname, tempPerson.nname, tempPerson.PLZ, tempPerson.ort, tempPerson.geburtsjahr);
	}

}



