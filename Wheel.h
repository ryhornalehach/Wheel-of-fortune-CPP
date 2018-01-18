// Programmer: James P. Rizzitano
// Date: 12/8/2015
// File: Wheel.h

#include <iostream>
#include <iomanip>  // needed for formatting
#include <cstdlib>
#include <fstream>
#include "Utility.h"
using namespace std;
// Class Declaration  ************************
class Wheel
{

      private:
      		  int max;			   // max value for inputs
              int wValues[36];     // array to store wheel point values.
              string Prizes[20];   // array to store prizes
              int PrizeValues[20]; // stores prize values
              int curLetterValue;  // stores the spin value for current letter 
              string curPrize;     // stores the current prize description
              int curPrizeValue;   // stores the current prize value
                 
      public:
      		 
      		 string filename;    // stores names of text files.
      		 void FillPrizes();  // fills the prize array
      		 void FillPrizeValues(); // fills the PrizeValues array
             void FillWheel();  // fills the 36 positon wheel with point values          
             void PrintWheel(); // prints wheel values
             int SumTurnPoints(int matchedLetters, int spinValue); // Calculates points for correctly guessed letters
             int SpinWheel(); // gets wheel value
             string GetPrize();  //searches prize text and takes random line
             int GetPrizeValue();  // returns the curPrizeValue
             int CheckSpin();  // checks spinvalue for prize or other operation
};

void Wheel::FillWheel()  // fills the prize wheel.
{
  	int i = 0;  // sets index value
	string filename = "prizewheel.txt"; // assigns filename
   	ifstream inFile; // creates ifstream object inFile

  	inFile.open(filename.c_str()); // opens file for reading

  	if (inFile.fail())  // check for successful open
   	{
        	cout << "\nThe file was not successfully opened"
	             << "\n Please check that the file currently exists."
	             << endl;
        	exit(1);
   }
  
   while ( inFile >> wValues[i] )  // fills wValues array from text file
   { 
      	i++;  // increase index
   }
   
   inFile.close(); // closes textfile


   
   return;
}

void Wheel::FillPrizeValues()  // fills the prize wheel.
{
  	int i = 0;  // sets index value
	string filename = "prizevalues.txt";   // assigns filename
   	ifstream inFile;  // creates ifstream object inFile

  	inFile.open(filename.c_str());  // opens textfile for reading

  	if (inFile.fail())  // check for successful open
   	{
        	cout << "\nThe file was not successfully opened"
	             << "\n Please check that the file currently exists."
	             << endl;
        	exit(1);
   }
  
   while ( inFile >> PrizeValues[i] )  // fills PrizeValue array from textfile
   { 
      	i++; // increase index
   }
   
   inFile.close(); 

   
   return;
}
void Wheel::PrintWheel()  // prints wheel values
{	 
	 int wIndex;
	    
     for(wIndex = 0; wIndex < 36 ; wIndex++ )
     {
          cout << wValues[wIndex] << endl ;
    
	}
         
     return; 
}  

int Wheel::SumTurnPoints(int matchedLetters, int spinValue) // calculates points for correct letter guesses during turn.
    {
         int turnPoints; // declares integer variable turnPoints
         turnPoints =  (matchedLetters * curLetterValue);  // sets turnPoints value
         return(turnPoints);  // returns value 
    }
    
int Wheel::SpinWheel()  // spins the wheel to determine letter value
    {
    	max =36;  // sets the size of the wheel value for random generation.
    	int letterValue, spinIndex;  // declares integers
    	Utility Ut1;  // creates Utility object Ut1
    	spinIndex = Ut1.Random(max);  //  assigns random number to spinIndex
    	curLetterValue = wValues[spinIndex];  // assigns vale to curLetterValue
    	switch(curLetterValue)  // switch statement.
    	{
		case 0:
			letterValue = 1500;  // case for prize
			break;
    		case 1:
			letterValue = 0;  // case for lose turn
			break;
		case 2:
			letterValue = 0;  // case for go bankrupt
			break;
		default:
			letterValue = wValues[spinIndex];  // case for normal value
		}
    	
    	
    return(letterValue); //  returns the letter value
    }

void Wheel::FillPrizes()  // Fills the prize arrar with prizes
{
  int i = 0;  // assign index
  string filename = "prizes.txt"; // assign filename to string
   string phrase;  // declares string variable phrase
   ifstream inFile;  // creates ifstream object inFile

   inFile.open(filename.c_str());  // opens file for reading

   if (inFile.fail())  // check for successful open
   {
        cout << "\nThe file was not successfully opened"
	          << "\n Please check that the file currently exists."
	          << endl;
        exit(1);
   }
  
   while ( getline(inFile, phrase) ) // loop on line read in store line in phrase 
   { 
      Prizes[i] = phrase;  // assigns the value of phrase to Prizes Array
      i++;  // increment counter
   }
   
   inFile.close(); // close text file

 
   return;

}
string Wheel::GetPrize()  // gets the prize description
{
	max = 20;  // sets max amount of prizes
	int pindex;  // declare index
	string prize; // declare string for prize description
	Utility Ut2;  // creates Utility object Ut2
	pindex = Ut2.Random(max); // generates random number 0-19
	prize = Prizes[pindex]; // assigns value to prize
	curPrize = prize;  // assigns the same value to class variable curPrize
	curPrizeValue = PrizeValues[pindex];  // assigns value to class variable curPrizeValue
	
	return(prize);  // returns string prize 
	
}

int Wheel::CheckSpin()  // Checks the wheel spin for special cases
{
	int value;
	switch(curLetterValue)
	{
		case 0:
			  cout << endl << "You have won a prize";  // check for won prize
			  value = 0;
			  break;
		case 1:
			  cout << endl << "LOSE TURN!!!";  // check for lose turn
			  value = 1;
			  break;
		case 2:
			  cout << endl << "BANKRUPT!!!";  // check for bankrupt
			  value = 2;
			  break;
		default:
			  value = 3;	  
		  
	}
return (value);
}

int Wheel::GetPrizeValue()  // gets value of prize
{
	int prizevalue;  // declares integer prizevalue
	prizevalue = curPrizeValue;  // assigns integer prizevalue
	
	return(prizevalue); // returns prizevalue
}
