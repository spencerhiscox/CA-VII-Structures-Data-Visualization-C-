/*
Copyright© Spencer Hiscox, 2023
All Rights Reserved
*/


#include "header.h"

int main() {

	unsigned short int userInput = 1;
	diceRoll currentState;
	filePath output;

	printf("\n\n-------------------------------------------------------------------------------------\n");
	printf("---------------  WELCOME TO DICE ROLL NORMAL DISTRIBUTION SIMULATOR!!  --------------\n");			//80 characters max display width.
	printf("-------------------------------------------------------------------------------------\n\n\n");		//Later adjusted to 85.

	printf("**This program is designed to simulate rolling a pair of dice. \n"
		"You will be prompted to enter the number of rolls you wish to simulate,\n"
		"you must enter an integer value between 0 and 36000, inclusive.\n"
		"Once you have entered a value, the program will simulate rolling a pair\n"
		"of die the number of times you have specified. Each roll will be tracked\n"
		"in a Microsoft Excel spreadsheet saved under the file name and in the\n"
		"directory you specify.The filename will have the entered number of rolls\n"
		"appended to it. The program will then tabulate the distribution of the\n"
		"simulated rolls and generate a histographic representation of the result.\n\n"
		"When you are finished, simply enter \"0\" as the number of roles, the \n"
		"program will exit.\n\n\n");

	do {
		srand(time(NULL));
		currentState = initState();
		printMenu();
		userInput = getInputF2I();
		if (userInput) {
			unsigned short int tally[11] = { 0 };
			output = specifyFilePath();												//This is obviously unneccessary per assignment requirements,
			currentState = cOutcome(userInput, tally, currentState, output);		//however, it seemed to me to be a very small adjustment which
			dispHist(tally, userInput);												//greatly increased the functionality of the program.
		}																			
	} while (userInput);

	printf("_____________________________________________________________________________________\n\n"
			"-----------  Thank you for using Dice Roll Normal Distribution Simulator!  ----------\n"
			"_____________________________________________________________________________________\n\n"
			"Exiting...\n\n\n\n\n");

	return 0;
}
