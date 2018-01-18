#include <cstdlib>
#include <iostream>
#include "Wheel.h"
//#include "Utility.h"


using namespace std;

//Prototypes:


int main()
{
	string PlayerName ="James";
	string turnPrize;
	int prizecheck, prizevalue, turnPoints, spinValue;
    char action;
	int i = 0;
    Wheel wh1;
    wh1.FillWheel();
    wh1.FillPrizes();
    wh1.FillPrizeValues();
    
    cout << "Player " << PlayerName << " is up." << endl;  
	cout << "Press 's' to spin the wheel.";
	cin >> action;  
    spinValue = wh1.SpinWheel();
    prizecheck = wh1.CheckSpin();
    switch(prizecheck)
    {
    	case 0:
    		cout << endl << "Your Letter value is $" << spinValue << endl;
    		turnPrize = wh1.GetPrize();
    		cout << endl << "You can Win a " << turnPrize << endl;
    		prizevalue = wh1.GetPrizeValue();
    		cout << endl << "Worth $" << prizevalue;
    		break;
    	case 1:
    		cout << endl << "Sorry Next Player is up";
    		break;
    	case 2:
    		cout << endl << "Sorry you went bankrupt!  Next Player is up";
    	default:
    		cout << endl << "Your Letter value is $" << spinValue << endl;
    		cout << endl << "Pick a letter > ";
    }
    
    
        
    
    int matchedLetters = 1;
    
    //wh1.PrintWheel();
 
    //cout << curLetterValue << " letter value" << endl; 
    
 //turnPoints = wh1.SumTurnPoints(matchedLetters, curLetterValue );
    
  //cout << turnPoints << " Turn Points" << endl;
   
 
    
   //system("pause");
    return(0);
}
