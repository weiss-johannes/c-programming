#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	FILE *datei;
	datei = fopen("textdatei.txt", "r");

	char text[12];

	while(feof(datei) == 0 && ferror(datei) == 0) {
		fgets(text, 12, datei);
		printf("%s", text);
		// printf("[DEBUG] %d %d\n", feof(datei), ferror(datei));
	}
}
