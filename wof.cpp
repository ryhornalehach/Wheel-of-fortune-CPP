/**** Ryhor Nalehach ****/
#include <iostream>
#include <fstream>
#include <cstdlib>   // needed for exit()
#include <string>
#include "wof-ryhor.h" //to use classes created by Ryhor
#include "playerclass.h" //to use classes created by Nischal
#include "Wheel.h" //to use classes created by James


using namespace std;

int main ()
{
int i, j, pn, k=1; //looping variables
int numPlayers;  //number of players
string temp; // temporary string used for players creation
char action; // variable to store the current spin 
int players_scores[4]; //array to store final player's scores
int max_score =0; //variable to store the highest score in the game

int turnPoints, spinValue, prizecheck, prizevalue, current_score;
string turnPrize; // current turn possible prize is stored here







    Wheel wh1;  // creating object - wheel
    wh1.FillWheel(); //filling the wheel
    wh1.FillPrizes(); //filling the prizes
    wh1.FillPrizeValues(); //filling the prize values


cout << "\nHow many Players 1-4 >  ";
cin >> numPlayers;



Player players[4]; //creating array of players


for (i=0; i<numPlayers ; i++)
	{
	cout << "Please enter player " << i+1 << " name: ";
	cin >> temp;
	players[i].setName (temp);
	}




Phrases Phrase_object;   //creating an object of phrases class



//Phrase_object.printPhrase (); //printing the phrase


while ( k < 4 )
{
cout << "Round " << k << " begins >" << endl;

Phrase_object.phraseReading ();  //reading a phrase from the file
Phrase_object.triggerInitializing ();  //initializing trigger array to 0's

Phrase_object.printPhrase (); //printing the phrase

for (j = 0; j < 26 ; j++)
	{
	//cout << "Round " << j+1 << " begins >" << endl;
	Phrase_object.printCategory ();

	for (i = 0; i < numPlayers ; i++)
	{
	cout << "\nPlayer " << players[i].getName() << " is up." << endl;  
	
	do
		{
 		cout << "Press 's' to spin the wheel > ";
		cin >> action;

		spinValue = wh1.SpinWheel();
		prizecheck = wh1.CheckSpin();

		
		if(prizecheck == 0)
			{
			cout << endl << "Your Letter value is $" << spinValue << endl;
    			turnPrize = wh1.GetPrize();
    			cout << "You can Win a " << turnPrize << endl;
    			prizevalue = wh1.GetPrizeValue();
    			cout << "Worth $" << prizevalue << endl;
			turnPoints = (Phrase_object.letterCompare () * spinValue);
			players[i].addScore(turnPoints);
			if(turnPoints)
				players[i].setPrizes(turnPrize);
			Phrase_object.printPhrase ();
			current_score = players[i].getScore();
			cout << "Player " << players[i].getName() << " current score: " << current_score << endl;

			if (!turnPoints)
				cout << "Sorry, no such letter in the phrase, or it has been already opened" << endl ;
			}

		else if(prizecheck == 1)
			{
    			cout << endl << "Lose turn!  Next Player is up." << endl;
			turnPoints = 0;
			}

		else if(prizecheck == 2)
			{
    			cout << endl << "Sorry you went bankrupt!  Next Player is up." << endl;
			turnPoints = (-1) * (players[i].getScore());
			players[i].addScore(turnPoints);
			turnPoints = 0;
			}

		else if(prizecheck > 2)
			{
			cout << endl << "Your Letter value is $" << spinValue << endl;
			turnPoints = (Phrase_object.letterCompare () * spinValue);
			players[i].addScore(turnPoints);
			Phrase_object.printPhrase ();
			current_score = players[i].getScore();
			cout << "Player " << players[i].getName() << " current score: " << current_score << endl;

			if (!turnPoints)
				cout << "Sorry, no such letter in the phrase, or it has been already opened" << endl ;
			}

		if (Phrase_object.endOfGame())
			{
			j=26;
			cout << "Congratulations! " << players[i].getName() << " won this play!" <<endl;
			cout << "Player " << players[i].getName() << " current score: "<< players[i].getScore() << endl;
			players[i].printPrizes();
			i = numPlayers;
			}

		} while ((turnPoints) && (!Phrase_object.endOfGame()));

	}
	}
k++;
}
for (i = 0; i < numPlayers ; i++)
	{
	players_scores[i] = players[i].getScore() ;
	if (max_score < players_scores[i])
		{
		max_score = players_scores[i];
		j = i; //player [j] will be the winner of the game
		}
	}

cout << endl << "Congratulations! " << players[j].getName() << " won the game!" <<endl;
cout << players[j].getName() << "'s winning score: "<< players[j].getScore() << endl;
players[j].printPrizes();


return 0; 
} // end main