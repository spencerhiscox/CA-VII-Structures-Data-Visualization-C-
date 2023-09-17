©Spencer Hiscox, 2023

#include "header.h"

void printMenu(void) {

	printf("\n\n-------------------------------------------------------------------------------------\n");
	printf("Enter the number of times you wish to roll the dice: ");

	return;
}

void printStats(unsigned short int* tally) {

	printf("_____________________________________________________________________________________\n");
	printf("\n\n\n\n_____________________________________________________________________________________\n\n");
	printf("Dice Roll Statistics:\n"
		"_____________________________________________________________________________________\n\n");
	for (unsigned char i = 0; i < 11; i++) {
		printf("%7hus:", i + 2);
		printf("%8hu\n", tally[i]);
	}

	return;
}

unsigned char calcHist(unsigned short int* tally, unsigned short int userInput) {

	unsigned char maxVal = 0, scale = 0;

	for (unsigned char i = 0; i < 11; i++) {
		tally[i] = round(((float)tally[i] / (float)userInput) * 30.0f);
		if (tally[i] > maxVal) {
			maxVal = tally[i];
		}
		if (i == 10) {
			scale = 30.0f / (float)maxVal;
			for (unsigned char j = 0; j < 11; j++) {
				tally[j] *= scale;
			}
		}
	}

	return maxVal;
}

void dispHist(unsigned short int* tally, unsigned short int userInput) {

	unsigned char maxVal = calcHist(tally, userInput);
	unsigned char scale = 30.0f / (float)maxVal;
	float unit = 30.0f / (float)scale;
	unsigned char counter = 0;
	unsigned int simplify = (int)round((100.0f * ((float)maxVal / 30.0f)));

	printf("\n\n\n_____________________________________________________________________________________\n\n");
	printf("----------------  Histographic Frequency Distribution of Simulation  ----------------\n\n");
	printf("       ______________________________________________________________________________\n");
	for (unsigned char i = 0; i < 30; i++) {
		for (unsigned char j = 0; j < 11; j++) {
			if (!j) {
				if ((30 - i) == (int)round(((float)maxVal * (float)scale)) - ((float)(counter) * (((float)maxVal * (float)scale)) / (float)unit)) {
					printf(((simplify - ((counter) * (int)round((float)simplify / ((float)scale + 1.0f)))) <= 9) ? "   %i%%  |" : "  %i%%  |", (simplify - ((counter) * (int)round((float)simplify / ((float)scale + 1.0f)))));
					counter++;
				}
				else {
					printf("       |");
				}
			}
			printf((tally[j] >= (30 - i)) ? (j == 10) ? "&&&&&&|\n" : "&&&&&&|" : (i == 30) ? (!tally[j]) ? (j == 10) ? "______|\n" : "______|" : (j == 10) ? "      |\n" : "      |" : (j == 10) ? "      |\n" : "      |");
		}
	}
	for (unsigned char j = 0; j < 3; j++) {
		if ((!j) || (j == 2)) {
			for (unsigned char i = 0; i < 11; i++) {
				printf(((!j) && (!i)) ? " Roll  |      |" : (!i) ? "       |      |" : (i == 10) ? "      |\n" : "      |");
			}
		}
		else {
			for (unsigned char i = 0; i < 11; i++) {
				printf((!i) ? "  Sum  |  0%hhu  |" : (i < 8) ? "  0%hhu  |" : (i == 10) ? "  %hhu  |\n" : "  %hhu  |", i + 2);
			}
		}
	}

	return;
}
