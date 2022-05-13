#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	FILE *umlauteDatei, *ohneUmlauteDatei;
	umlauteDatei = fopen("umlaute.txt", "r");
	ohneUmlauteDatei = fopen("ohneumlaute.txt", "w");

	char umlaute[6][3] = {"Ae", "ae", "Oe", "oe", "Ue", "ue"};
	int c;
	while ((c = fgetc(umlauteDatei)) != EOF) {
		switch(c) {
			case '�':
				fputs(umlaute[0], ohneUmlauteDatei);
				// Alternativ
				// fputc('a', ohneUmlauteDatei);
				// fputc('e', ohneUmlauteDatei);
				break;
			case '�':
				fputs(umlaute[1], ohneUmlauteDatei);
				break;
			case '�':
				fputs(umlaute[2], ohneUmlauteDatei);
				break;
			case '�':
				fputs(umlaute[3], ohneUmlauteDatei);
				break;
			case '�':
				fputs(umlaute[4], ohneUmlauteDatei);
				break;
			case '�':
				fputs(umlaute[5], ohneUmlauteDatei);
				break;
			default:
				fputc(c, ohneUmlauteDatei);
		}
	}
	fclose(ohneUmlauteDatei);
	fclose(umlauteDatei);
}
