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

#include "strukturen.h"
#include "funktionen.h"

int main(void) {
	setbuf(stdout, NULL);

	struct termin term;

	read_termin(&term);
	display_termin(&term);

}
