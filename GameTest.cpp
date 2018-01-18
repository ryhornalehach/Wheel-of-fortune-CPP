#include <cstdlib>
#include <iostream>
#include "Wheel.h"
#include "BigText.h"



using namespace std;

//Prototypes
//void printWelcome();
// void addPlayers(int&, int&, string[] );


int main()
{
	string turnPrize, phrase;
	int prizecheck, prizevalue, turnPoints, spinValue, plength, numPlayers, 
	pNum, turnNo, trnMax, maxChars;
	trnMax = 40; turnNo = 0; maxChars = 26;
	char action, curChar;
	char pickedChars[maxChars];
	int i = 0;
    Wheel wh1;
    wh1.FillWheel();
    wh1.FillPrizes();
    wh1.FillPrizeValues();
    for(i=0 ; i<100 ; i++)
	cout << endl;
	BigText bt1;
	bt1.LoadFonts();
	phrase = "WELCOME TO";
    bt1.LoadPhrase(phrase);
    bt1.GetPhraseLength();
    bt1.PrintString();
    phrase = "THE WHEEL";
    bt1.LoadPhrase(phrase);
    bt1.PrintString();
    phrase = "OF FORTUNE";
    bt1.LoadPhrase(phrase);
    bt1.PrintString();
    
   
    string playerName[4];
    cout << "\n\nHow many Players 1-4 >  ";
    cin >> numPlayers;
    int pn;
    for(pn = 0; pn < numPlayers; pn++)
    {
    	cout << "\nEnter Player " << pn+1 << "'s Name >  ";
    	cin >> playerName[pn];
    }
    i=0;
    
    while(i<maxChars )
    {
	     for(pNum = 0; pNum < numPlayers; pNum++) 
		 {
		    int picks = 0;
    		cout << "\nPlayer " << playerName[pNum] << " is up." << endl;  
			cout << "Press 's' to spin the wheel > ";
			cin >> action;  
    		spinValue = wh1.SpinWheel();
    		prizecheck = wh1.CheckSpin();
    		
			 if(prizecheck == 0){
    				cout << endl << "Your Letter value is $" << spinValue << endl;
    				turnPrize = wh1.GetPrize();
    				cout << endl << "You can Win a " << turnPrize << endl;
    				prizevalue = wh1.GetPrizeValue();
    				cout << endl << "Worth $" << prizevalue;
    				cout << endl << "Pick a letter > ";
    				cin >> curChar;
    				pickedChars[i] = curChar;
    				i++;
    				}
    			if(prizecheck == 1){
    				phrase = "LOSE TURN";
    				bt1.LoadPhrase(phrase);
    				bt1.GetPhraseLength();
    				bt1.PrintString();
    				cout << endl << "\n\nSorry Next Player is up";
    				}
    			if(prizecheck == 2){
    				phrase = "BANKRUPT";
    				bt1.LoadPhrase(phrase);
    				bt1.GetPhraseLength();
    				bt1.PrintString();
    				cout << endl << "\n\nSorry you went bankrupt!  Next Player is up";
    				}
    			if(prizecheck > 2){
    				cout << endl << "Your Letter value is $" << spinValue << endl;
    				cout << endl << "Pick a letter > ";
    				cin >> curChar;
    				pickedChars[i] = curChar;
    				i++;
    			}
    				
    		
   		 }
	}
	
					
					
	
    // int matchedLetters = 1;
    

    return(0);
}


