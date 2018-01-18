//Nischal Paudyal
//Declear a Player and add his score

#include <iostream>
#include <cstdlib>  		 // needed for exit()
#include <string> 		// to work with the strings

using namespace std;

/*********Class declearation**********/
class Player
{
	private:
		string name;		//name of the player;			
		string prize[36];	//prize player gets from wheel
		int score;		//player score
		int numPrizes;		//number of prizes players get
		
		
	public:
		Player();	//constructor
		string getName();	//member methods to set name
		int getScore();		//methods to return score
		void addScore(int);	//method to add the score, returns total score
		void setPrizes(string);	//method to print the prize of the player
		void printPrizes();
		void setName (string);	//to set player's name
		
		
}; // end class

/********Class Implementation*********/

Player::Player()	
{
	for(int i = 1; i < 36; i++)
	{		
		prize[i] = "\0";
	}

	score = 0;
	numPrizes = 0;
}
/*******************
Player::Player(string pname)	
{
	name = pname;
	for(int i = 1; i < 36; i++)
	{		
		prize[i] = "\0";
	}

	score = 0;
	numPrizes = 0;
}*************/

//method to return the player name
string Player::getName()
{
	return name;			
}

//mathod to return the player score
int Player::getScore()
{
    return score;			//person score is returned
}

//method to sum the score of player to get total score
void Player::addScore(int pscore) 	//person score for each round 
{
	
	score = score + pscore; 	// sum the score 
	
}
//method to add the prizes
void Player::setPrizes(string pprize) 	//person prizes
{
	
	prize[numPrizes] = pprize;
	numPrizes++;
}

//method t0 print all the prizes
void Player::printPrizes()
{
	
	for(int i = 0; i <= numPrizes; i++)
	{
		cout << prize[i] << endl; 
	}
}


void Player::setName (string pname)
{
	name = pname;
}
		