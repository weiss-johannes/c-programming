/*
 * strukturen.h
 *
 *  Created on: 25.02.2022
 *      Author: Administrator
 */

#ifndef STRUKTUREN_H_
#define STRUKTUREN_H_


struct datum {
	int tag;
	int monat;
	int jahr;
};

struct uhrzeit {
	int minute;
	int stunde;
};

struct terminDaten {
	char titel[20];
	char beschreibung[20];
	char ort[20];
};

struct termin {
	struct datum dat;
	struct uhrzeit uhr;
	struct datum dat_erinnerung;
	struct uhrzeit uhr_erinnerung;
	struct terminDaten termin_daten;
};

#endif /* STRUKTUREN_H_ */
