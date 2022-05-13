/*
 ============================================================================
 Name        : 05_structs.c
 Author      : Tobias Hoffmann
 Version     : 1.0
 Description : Structs beispielcode
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structBeispiel {
   char a;
   int b;
   double c;
};

union unionBeispiel {
   char a;
   int b;
   double c;
};


struct pers {
	char vname[20];
	char nname[20];
	long PLZ;
	char ort[20];
	int geburtsjahr;
};

int cmp_persons(struct pers* p1, struct pers* p2) {
	int nichtgleich = 0;

	if (strcmp(p1->vname, p2->vname) != 0) {
		nichtgleich = 1;
	}
	if (strcmp(p1->nname, p2->nname) != 0) {
		nichtgleich = 1;
	}
	if (p1->PLZ != p2->PLZ) {
		nichtgleich = 1;
	}
	if (strcmp(p1->ort, p2->ort) != 0) {
		nichtgleich = 1;
	}
	if (p1->geburtsjahr != p2->geburtsjahr) {
		nichtgleich = 1;
	}

	return nichtgleich;
}

void ausgabe(struct pers x) {
   printf("\n\nSie gaben ein:\n\n");
   printf("Vorname.........:%s\n",  x.vname);
   printf("Nachname........:%s\n",  x.nname);
   printf("Postleitzahl....:%ld\n", x.PLZ);
   printf("Ort.............:%s\n",  x.ort);
   printf("Geburtsjahr.....:%d\n",  x.geburtsjahr);
}

void ausgabe_ptr(struct pers* x) {
   printf("\n\nSie gaben ein:\n\n");
   printf("Vorname.........:%s\n",  (*x).vname);
   printf("Nachname........:%s\n",  (*x).nname);
   printf("Postleitzahl....:%ld\n", x->PLZ);
   printf("Ort.............:%s\n",  x->ort);
   printf("Geburtsjahr.....:%d\n",  x->geburtsjahr);
}

struct pers* eingabe(void) {
	// Besser, da hier keine Kopie von person zur Rückgabe angelegt werden muss
	// Es wird der Pointer übergeben
	static struct pers* person;
	person = malloc(sizeof(struct pers));
	printf("Vorname : ");
	fgets(person->vname, 20, stdin);
	printf("Nachname : ");
	fgets(person->nname, 20, stdin);
	printf("Postleitzahl : ");
	do {
		scanf("%ld", &person->PLZ);
	} while(getchar()!= '\n');
	printf("Wohnort : ");
	fgets(person->ort, 20, stdin);
	printf("Geburtsjahr : ");
	do {
		scanf("%d",&person->geburtsjahr);
	}while(getchar()!='\n' );
	return person;
}

struct pers eingabe_by_value(void) {
	// Durch die Rückgabe von person muss erst eine Kopie von person erstellt werden,
	// dies geschieht zwar automatisch, ist aber langsamer als einen Pointer zu übergeben
	//  Wichtig, wenn wir einen Pointer übergeben wollen, müssen wir mit malloc allokieren !
	// Siehe Funktion -- struct pers *eingabe(void)
	static struct pers person;
	printf("Vorname : ");
	fgets(person.vname, 20, stdin);
	printf("Nachname : ");
	fgets(person.nname, 20, stdin);
	printf("Postleitzahl : ");
	do {
		scanf("%ld", &person.PLZ);
	} while(getchar()!= '\n');
	printf("Wohnort : ");
	fgets(person.ort, 20, stdin);
	printf("Geburtsjahr : ");
	do {
		scanf("%d", &person.geburtsjahr);
	}while(getchar()!='\n');
	return person;
}

void alle_vornamen(struct pers personen[], int len) {
//void alle_vornamen_ptr(struct pers* personen, int len) { // <-- gleichwertige schreibweise
	printf("Personen-Array Pointeradresse: %p\n", personen);
	for(int i = 0 ; i < len; i++) {
//		printf("Vorname: %s\n", (personen + i)->vname);
		printf("Vorname: %s\n", personen[i].vname);
	}
}

int main(void) {
	setbuf(stdout, NULL);
	struct pers person1 = { "Max", "Mustermann", 10115, "Berlin", 1990 };
	printf("Person vergleich: %d\n", cmp_persons(&person1, &person1));


	printf("structBeispiel Speicherbedarf: %d Byte\n", sizeof(struct structBeispiel));
	printf("unionBeispiel Speicherbedarf:  %d Byte\n", sizeof(union unionBeispiel));
	printf("%d %d %d\n", sizeof(char), sizeof(int), sizeof(double));

	union Data {
	   int i;
	   float f;
	   char str[20];
	} data;

	data.i = 10;
	data.f = 220.5;
	strcpy( data.str, "C Programming");

	printf( "data.i : %d\n", data.i);
	printf( "data.f : %f\n", data.f);
	printf( "data.str : %s\n", data.str);


	struct pers person2;
	strcpy(person2.vname, "Bob");
	printf("%s", person2.vname);
	person2.geburtsjahr = 1990;

	ausgabe(person1);
	ausgabe_ptr(&person1);

//	struct pers* person3;
//	person3 = eingabe();
//	ausgabe(*person3);

	// Arrays von Strukturen
	struct pers personen[3];
	strcpy(personen[0].vname, "Max");
	strcpy(personen[1].vname, "Alice");
	strcpy(personen[2].vname, "Bob");

	printf("Personen-Array Pointeradresse: %p\n", personen);
	alle_vornamen(personen, 3);

}
