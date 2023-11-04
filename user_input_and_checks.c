/*
Copyright© Spencer Hiscox, 2023
All Rights Reserved
*/


#include "header.h"

I00percent eatTheCrazy(I00percent crazyFree) {

	if (!crazyFree.initial) {
		printf("Confirm entry [Y/N]: ");
		crazyFree.initial++;
	}
	scanf_s("%s", crazyFree.nomNomNom, 100);
	bool crazy = strcmp(crazyFree.nomNomNom, "Y");
	bool crazy2 = strcmp(crazyFree.nomNomNom, "y");
	bool crazy3 = strcmp(crazyFree.nomNomNom, "N");
	bool crazy4 = strcmp(crazyFree.nomNomNom, "n");
	if ((crazy == 0) || (crazy2 == 0) || (crazy3 == 0) || (crazy4 == 0)) {
		if (((!crazyFree.fail) && (crazyFree.nomNomNom[0] == 'Y')) || ((!crazyFree.fail) && (crazyFree.nomNomNom[0] == 'y'))) {
			crazyFree.initial = 0;
			crazyFree.fail = 0;
			return crazyFree;
		}
		else if (((crazyFree.doOver == NULL) && (crazyFree.nomNomNom[0] == 'Y')) || (crazyFree.nomNomNom[0] == 'y') && (crazyFree.doOver == NULL)) {
			crazyFree.fail = 0;
			crazyFree.initial = 0;
			printf("\nInvalid entry. Entry must be a number.\nPlease make your entry again: ");
			scanf_s("%f", &crazyFree.doOver);
			crazyFree = eatTheCrazy(crazyFree);
		}
		else {
			crazyFree.fail = 0;
			crazyFree.initial = 0;
			printf("\nEntry discarded.\nPlease make your entry: ");
			scanf_s("%f", &crazyFree.doOver);
			crazyFree = eatTheCrazy(crazyFree);
		}
		return crazyFree;
	}
	else {
		if (!crazyFree.fail) {
			crazyFree.fail = true;
			crazyFree.doOver = NULL;
		}
		crazyFree = eatTheCrazy(crazyFree);
		return crazyFree;
	}
}

float checkInput(float userInput, I00percent crazyFree) {

	while ((userInput < 0) || (userInput > 36000) || (userInput != (int)userInput)) {
		if (userInput == 0) {
			return 0;
		}
		else {
			printf("\nInvalid entry. ");
			printf((userInput < 0) ? "The number you have entered is a negative number.\n" :
				(userInput > 36000) ? "The number you have entered is outside the maximum range.\nThe number should be between 0 and 36000.\n" :
				(userInput != (int)userInput) ? "The number you have entered is not an integer value.\n" : "Unknown error occurred.\n");
			printf("Please make your entry again: ");
			scanf_s("%f", &userInput);
			crazyFree.doOver = NULL;
			crazyFree = eatTheCrazy(crazyFree);
			if (crazyFree.doOver != NULL) {
				userInput = crazyFree.doOver;
			}
			printf("\n");
		}
	}

	return userInput;
}

unsigned short int getInputF2I(void) {
	float userInput;

	I00percent crazyFree;
	crazyFree.doOver = NULL;
	crazyFree.initial = 0;
	crazyFree.fail = 0;
	strcpy_s(crazyFree.nomNomNom, 120, "nuffin");

	scanf_s("%f", &userInput);
	crazyFree = eatTheCrazy(crazyFree);

	if (crazyFree.doOver != NULL) {
		userInput = crazyFree.doOver;
	}

	userInput = checkInput(userInput, crazyFree);

	return (unsigned short int)userInput;
}

filePath specifyFilePath(void) {

	filePath holder;

	printf("_____________________________________________________________________________________\n");
	printf("\n\n\nPlease enter absolute file path of destination excel file.\n"
		"For example, enter: \"C:\\Users\\<userName>\\OneDrive\\Desktop\\<filename>\"\n"
		"Please note: do not enter a file extension after the filename, the program will do \nthis for you.\n\n"
		"If you would like to save the file in the program's local directory,\n"
		"you may do so by entering only the desired filename.\n\n"
		"Should you prefer not to specify a filename, simply enter \"d\" and hit <enter>\n"
		"to utilize the program's default filename. The file will be saved in the program's \n"
		"local directory as: \"DiceRollsSimulation-<number of trials>.csv\"\n\n"
		"_____________________________________________________________________________________\n\n"
		"Enter desired filename / filepath:\t");
	scanf_s("%s", holder.filePath, 300);
	if ((!strcmp(holder.filePath, "d"))||(!strcmp(holder.filePath, "D"))) {
		strcpy_s(holder.filePath, "DiceRollsSimulation-");
	}
	else {
		strcat_s(holder.filePath, sizeof(holder.filePath) / sizeof(holder.filePath[0]), "-");
	}
	return holder;
}

filePath fileNameX(filePath output, unsigned short int userInput) {

	FILE* checkID;
	char tempStore[300];
	strcpy_s(tempStore, output.filePath);
	unsigned char i = 0;
	char number[6];

	do {
		if (i) {
			strcpy_s(output.filePath, tempStore);
		}
		_itoa_s(userInput, number, 10);
		strcat_s(output.filePath, sizeof(output.filePath) / sizeof(output.filePath[0]), number);
		if (!i) {
			strcat_s(output.filePath, sizeof(output.filePath) / sizeof(output.filePath[0]), "trials.csv");
		}
		else {
			strcat_s(output.filePath, sizeof(output.filePath) / sizeof(output.filePath[0]), "trials");
			strcat_s(output.filePath, sizeof(output.filePath) / sizeof(output.filePath[0]), "-");
			_itoa_s(i, number, 10);
			strcat_s(output.filePath, sizeof(output.filePath) / sizeof(output.filePath[0]), number);
			strcat_s(output.filePath, sizeof(output.filePath) / sizeof(output.filePath[0]), ".csv");
		}
		fopen_s(&checkID, output.filePath, "r");
		i++;
	} while (checkID != NULL);

	return output;
}
