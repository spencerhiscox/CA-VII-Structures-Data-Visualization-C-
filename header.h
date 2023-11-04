/*
Copyright© Spencer Hiscox, 2023
All Rights Reserved
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


/*			A NOTE TO THE MARKER:
				I *may* have gone a *little* overboard on this assignment... I have therefore
				made use of a header file and functions definitions files (and plenty of comments
				next to function prototypes) in an attempt to make this a little bit easier to 
				mark. 
				
				Function definitions files are grouped into 3 categories:
					1) Anything that fetches or checks user input
					2) Anything whose primary function is to print to the console
					3) Any functions which serve to perform either:
							a) "behind-the-scenes" calculations	/ functions			--OR--
							b) write-to-file functions											
				
				I did stray from these categories mildly in an attempt to create an even easier
				to follow organization (for example, calcHist and DispHist are right next to 
				eachother in console_output.cpp - rather than putting calcHist in "rollDice_and_fileIO".

				The adjustments I made to the program were with Dr. Sabouni's express consent.
				If you're interested in confirming, see the Assignment 7 discussion board on Bsp.
				
				Hope you enjoy marking as much as I enjoyed creating!											*/



struct I00percent {									//Necessary for eatTheCrazy()
	char nomNomNom[120];
	float doOver;
	bool initial, fail;
};

struct diceRoll {								//REQUIRED STRUCT (assignment instructions)
	unsigned short int die1, die2, rollTotal;		//current value die 1 & 2, dice total of current roll. 
	unsigned int rollNumber;						//current roll number
};

struct filePath {								//We haven't gotten far enough into pointers to be returning arrays from functions
	char filePath[300];							//I tried, got all confused, this was easier.
};

I00percent eatTheCrazy(I00percent);				//Recursive function to purge buffer after user enters text into numeric format specifier
float checkInput(float, I00percent);			//Function works in tandem with eatTheCrazy(), this checks to ensure appropriate numeric entry
unsigned short int getInputF2I(void);			//Function to fetch number of dice rolls from user
void printMenu(void);							//Literally just prints out "enter number of die rolls" or something - not much of a menu here.
int rollDice(void);								//"rolls the dice" - returns the pRNG value to be used as the "dice roll"
filePath specifyFilePath(void);					//Function allows user to specify filename, absolute path or use default filename
void print2File(diceRoll, filePath);			//Literally just writes the results of the current roll to the excel file 
void printStats(unsigned short int*);			//Prints Frequency totals for each dice roll sum (2-12)
filePath fileNameX(filePath, unsigned short int);									//Function to check if filename already exists and adjust it if it does.
diceRoll cOutcome(unsigned short int, unsigned short int*, diceRoll, filePath);		//Calculates the outcome of the dice rolls - which gets sent to print2File
diceRoll initState(void);															//Initializes the struct we're using to store results of dice rolls to 0
unsigned char calcHist(unsigned short int*, unsigned short int);		//Does the majority of the number-crunching for the dispHist function
void dispHist(unsigned short int*, unsigned short int);					//Function to display the histogram according to the results of cOutcome & calcHist
