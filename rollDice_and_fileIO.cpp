©Spencer Hiscox, 2023

#include "header.h"

int rollDice(void) {
	return ((rand() % 6) + 1);
}

void print2File(diceRoll currentState, filePath output) {
	FILE* fid;

	fopen_s(&fid, output.filePath, "a");
	fprintf_s(fid, (currentState.rollNumber == 1) ? "Roll Number,Die 1,Die 2,Sum\n%i,%hu,%hu,%hu\n"
		: "%i,%hu,%hu,%hu\n", currentState.rollNumber, currentState.die1, currentState.die2, currentState.rollTotal);
	fclose(fid);

	return;
}

diceRoll cOutcome(unsigned short int userInput, unsigned short int* tally, diceRoll currentStatus, filePath output) {

	output = fileNameX(output, userInput);

	while (currentStatus.rollNumber < userInput) {
		currentStatus.die1 = rollDice();
		currentStatus.die2 = rollDice();
		currentStatus.rollTotal = currentStatus.die1 + currentStatus.die2;
		tally[currentStatus.rollTotal - 2] += 1;
		currentStatus.rollNumber++;
		print2File(currentStatus, output);
	}
	if (currentStatus.rollNumber != userInput) {
		printf("counting error in cOutcome, number of iterations does not match user input.\n");
	}

	printStats(tally);

	return currentStatus;
}

diceRoll initState(void) {
	diceRoll init;
	init.die1 = init.die2 = init.rollTotal = init.rollNumber = 0;
	return init;
}
