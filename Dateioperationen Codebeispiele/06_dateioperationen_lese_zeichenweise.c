#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	FILE *datei;
	datei = fopen("textdatei.txt", "r");

	printf("Text in der Datei:\n");
	int c;
	while ((c = fgetc(datei)) != EOF) {
		printf("%c", (char) c);
	}
}
