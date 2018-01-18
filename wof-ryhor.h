/**** Ryhor Nalehach ****/
#include <iostream>
#include <fstream>  // to work with files
#include <cstdlib>   // needed for exit()
#include <string> // to work with the strings
#include "Utility.h" //to use random numbers generator

using namespace std;


/****************  class declaration section  **********************/
class Phrases
{
private: 
	string filename;
	string category;
	string phrase;	//our phrase will be stored here
	int trigger_array [50]; // this array will be used as a trigger that shows wheter to display the letter or no

public:
	Phrases ();
	int i;  //looping variable
	int trigger_length; //variable to store the length of the trigger array
	void printPhrase ();
	void phraseReading ();
	void triggerInitializing ();
	void triggerSet (int);
	char current_letter;  // variable to store current letter
	int letterCompare ();
	int endOfGame ();
	void printCategory ();



}; //end class


/*********************************************************************/
/***                class implementation section                   ***/
/*********************************************************************/

Phrases::Phrases () //constructor
{
Utility random_generator; // object to use random number generator
int random_choice;
random_choice = random_generator.Random (6);

if (random_choice ==0)
	{filename = "books.txt";
	category = "Books";}
else if (random_choice ==1)
	{filename = "celebs.txt";
	category = "Celebrities";}
else if (random_choice ==2)
	{filename = "foods.txt";
	category = "Foods";}
else if (random_choice ==3)
	{filename = "movies.txt";
	category = "Movies";}
else if (random_choice ==4)
	{filename = "places.txt";
	category = "Places";}
else if (random_choice ==5)
	{filename = "songs.txt";
	category = "Songs";}

cout	<< endl << "Welcome to Wheel of Fortune!" << endl
	<< "Today we are playing " << category << " category." << endl
	<< "Here is the phrase for you to guess: " << endl;
}



/*****  Method to read the randomly chosen phrase  *******
*****     from the file and store it into memory  *********/
void Phrases::phraseReading ()
{
ifstream inFile; //object of input file stream class
int random_choice; //variable to store random choice here
Utility random_generator; // object to use random number generator

// This section to open a file and check for it's success
inFile.open(filename.c_str());

if (inFile.fail())  // check for successful open
	{
	cout 	<< "\nThe file was not successfully opened"
		<< "\n Please check that the file currently exists."
		<< endl;
	exit(1);
	}



random_choice = random_generator.Random(43); //random choose of a phrase to play (44 - total number of phrases in each file)
// Loading randomly chosen phrase into memory
for (i=0 ; i <= random_choice ; i++ )
	{ 
	getline(inFile, phrase);
	//cout << "Phrase is: " << phrase << endl;
	}
inFile.close(); // closing the file with phrases

trigger_length = phrase.length(); //lenght of chosen phrase
}


/********** Method to initialize the trigger array to 0's ************/
void Phrases::triggerInitializing ()
{
for (i=0 ; i < 50 ; i++)
	if (phrase[i] == ' ')
		trigger_array[i] = 1; /* in case of spaces in the phrase - display them */
	else if (phrase[i] == '\'')
		trigger_array[i] = 1; /* in case of "'" in the phrase - display them */
	else
		trigger_array[i] = 0;

}


/***************** Method to set the trigger to '1' ******************/
/************ in cade if we need to set trigger manually ***********/
void Phrases::triggerSet (int i)
{
trigger_array[i] = 1;
}


/**************** Method to print the phrase ************************/
void Phrases::printPhrase ()
{
for (i=0 ; i < trigger_length ; i++)
	cout << "*" ; /******* print a line of stars *******/
cout << endl;

for (i=0 ; i < trigger_length ; i++)
	if (trigger_array [i])
		cout << phrase [i];
	else
		cout << "-" ; /* print a placeholder if letter wasn't opened so far */

cout << endl;
for (i=0 ; i < trigger_length ; i++)
	cout << "*" ; /******* print a line of stars *******/
cout << endl;
}


/**************** Method to compare letters ************************/
int Phrases::letterCompare ()
{
int success_status =0;
int amount_of_letters =0;
cout << "Enter your letter choice: ";
cin >> current_letter;

for (i=0 ; i < trigger_length ; i++)
	if ((phrase[i] == current_letter) && !(trigger_array[i])) /* double check for letters that were already opened */
		{
			trigger_array[i] = 1; /* set corresponding trigger to 1 */
			success_status = 1;
			amount_of_letters++;
		}

if (success_status)
	return (amount_of_letters); /* return number of current letters in the phrase */
else
	return (0); /* return 0 in case if letter was not found */
}


/********* Method to check for a whole phrase being opened *************/
int Phrases::endOfGame ()
{
int sum=0;
for (i=0 ; i < trigger_length ; i++)
	if (trigger_array [i])
		sum++;

if (sum == trigger_length) /* if all triggers are "1" - phrase is fully opened */
	return (1); /* return true in case of success */
else
	return (0); /* return false in case if not all letters are opened so far */
}


/************* Method to print the current cathegory *********************/
void Phrases::printCategory ()
{
cout << "We are playing " << category << " category." << endl;
}