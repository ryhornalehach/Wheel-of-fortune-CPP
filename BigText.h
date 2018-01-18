// Programmer James P. Rizzitano
// Date Dec. 11 2015
// File Name: BigText.h
// Displays strings in Large Fonts.
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Class Declaration ***********************
class BigText
{
     private:
             string lA[5]; string lAp[5]; string lB[5]; string lBo[5]; string lC[5]; 
             string lCo[5]; string lD[5]; string lDa[5]; string lE[5]; string lF[5]; 
             string lG[5]; string lH[5]; string lI[5]; string lJ[5]; string lK[5]; 
             string lL[5]; string lM[5]; string lN[5]; string lO[5]; string lP[5];
             string lQ[5]; string lR[5]; string lS[5]; string lSp[5]; string lT[5]; 
             string lU[5]; string lUl[5]; string lV[5]; string lW[5]; string lX[5]; 
             string lY[5]; string lZ[5]; string filenames[32]; int spacePosition[10];
             string curPhrase; 
			 int maxLine, slength, cntSpaces, lineBreak;
			 
                     
     public:
     		int GetPhraseLength();
     	    void LoadFonts();
            void LoadPhrase(string phrase);
            void PrintString();
            void SetLineBreaks();
             
};

void BigText::PrintString()
{
	int c;
	int plength = 0;
	if(slength > 13)
	{
		plength = (slength - lineBreak);
		slength = lineBreak; 
	}
	
	for(c=0; c<5; c++)
	{
		int i;
		for(i=0; i<slength; i++)
		{	
			if(curPhrase[i] == 'A')
				cout << setw(5) << lA[c]<< " ";
			if(curPhrase[i] == 'B')
				cout << setw(5) << lB[c]<< " ";
			if(curPhrase[i] == 'C')
				cout << setw(5) << lC[c]<< " ";
			if(curPhrase[i] == 'D')
				cout << setw(5) << lD[c]<< " ";
			if(curPhrase[i] == 'E')
				cout << setw(5) << lE[c]<< " ";
			if(curPhrase[i] == 'F')
				cout << setw(5) << lF[c]<< " ";
			if(curPhrase[i] == 'G')
				cout << setw(5) << lG[c]<< " ";
			if(curPhrase[i] == 'H')
				cout << setw(5) << lH[c]<< " ";
			if(curPhrase[i] == 'I')
				cout << setw(5) << lI[c]<< " ";
			if(curPhrase[i] == 'J')
				cout << setw(5) << lJ[c]<< " ";
			if(curPhrase[i] == 'K')
				cout << setw(5) << lK[c]<< " ";
			if(curPhrase[i] == 'L')
				cout << setw(5) << lL[c]<< " ";
			if(curPhrase[i] == 'M')
				cout << setw(5) << lM[c]<< " ";
			if(curPhrase[i] == 'N')
				cout << setw(5) << lN[c]<< " ";
			if(curPhrase[i] == 'O')
				cout << setw(5) << lO[c]<< " ";
			if(curPhrase[i] == 'P')
				cout << setw(5) << lP[c]<< " ";
			if(curPhrase[i] == 'Q')
				cout << setw(5) << lQ[c]<< " ";
			if(curPhrase[i] == 'R')
				cout << setw(5) << lR[c]<< " ";
			if(curPhrase[i] == 'S')
				cout << setw(5) << lS[c]<< " ";
			if(curPhrase[i] == 'T') 
				cout << setw(5) << lT[c]<< " ";
		 	if(curPhrase[i] == 'U')
				cout << setw(5) << lU[c]<< " ";
			if(curPhrase[i] == 'V')
				cout << setw(5) << lV[c]<< " ";
			if(curPhrase[i] == 'W')
				cout << setw(5) << lW[c]<< " ";
			if(curPhrase[i] == 'X')
				cout << setw(5) << lX[c]<< " ";
			if(curPhrase[i] == 'Y')
				cout << setw(5) << lY[c]<< " ";
			if(curPhrase[i] == 'Z')
				cout << setw(5) << lZ[c]<< " ";
			if(curPhrase[i] == ' ' )
				cout << setw(5) << lSp[c]<< " ";
			if(curPhrase[i] == ',' )
				cout << setw(5) << lCo[c]<< " ";
			if(curPhrase[i] == '-' )
				cout << setw(5) << lDa[c]<< " ";
			if(curPhrase[i] == '_' )
				cout << setw(5) << lUl[c]<< " ";
							
		}
		cout << endl;
		
	}
	cout << endl << endl; // << endl << endl;
	if (plength > 0)
	{
		for(c=0; c<5; c++)
		{
			int x, i;
			i = lineBreak+1;
			for(x=0; x < plength; x++)
			{	
				if(curPhrase[i] == 'A' || curPhrase[i] == 'a')
					cout << setw(5) << lA[c]<< " ";
				if(curPhrase[i] == 'B' || curPhrase[i] == 'b')
					cout << setw(5) << lB[c]<< " ";
				if(curPhrase[i] == 'C' || curPhrase[i] == 'c')
					cout << setw(5) << lC[c]<< " ";
				if(curPhrase[i] == 'D' || curPhrase[i] == 'd')
					cout << setw(5) << lD[c]<< " ";
				if(curPhrase[i] == 'E' || curPhrase[i] == 'e')
					cout << setw(5) << lE[c]<< " ";
				if(curPhrase[i] == 'F' || curPhrase[i] == 'f')
					cout << setw(5) << lF[c]<< " ";
				if(curPhrase[i] == 'G' || curPhrase[i] == 'g')
					cout << setw(5) << lG[c]<< " ";
				if(curPhrase[i] == 'H' || curPhrase[i] == 'h')
					cout << setw(5) << lH[c]<< " ";
				if(curPhrase[i] == 'I' || curPhrase[i] == 'i')
					cout << setw(5) << lI[c]<< " ";
				if(curPhrase[i] == 'J' || curPhrase[i] == 'j')
					cout << setw(5) << lJ[c]<< " ";
				if(curPhrase[i] == 'K' || curPhrase[i] == 'k')
					cout << setw(5) << lK[c]<< " ";
				if(curPhrase[i] == 'L' || curPhrase[i] == 'l')
					cout << setw(5) << lL[c]<< " ";
				if(curPhrase[i] == 'M' || curPhrase[i] == 'm')
					cout << setw(5) << lM[c]<< " ";
				if(curPhrase[i] == 'N' || curPhrase[i] == 'n')
					cout << setw(5) << lN[c]<< " ";
				if(curPhrase[i] == 'O' || curPhrase[i] == 'o')
					cout << setw(5) << lO[c]<< " ";
				if(curPhrase[i] == 'P' || curPhrase[i] == 'p')
					cout << setw(5) << lP[c]<< " ";
				if(curPhrase[i] == 'Q' || curPhrase[i] == 'q')
					cout << setw(5) << lQ[c]<< " ";
				if(curPhrase[i] == 'R' || curPhrase[i] == 'r')
					cout << setw(5) << lR[c]<< " ";
				if(curPhrase[i] == 'S' || curPhrase[i] == 's')
					cout << setw(5) << lS[c]<< " ";
				if(curPhrase[i] == 'T' || curPhrase[i] == 't') 
					cout << setw(5) << lT[c]<< " ";
		 		if(curPhrase[i] == 'U' || curPhrase[i] == 'u')
					cout << setw(5) << lU[c]<< " ";
				if(curPhrase[i] == 'V' || curPhrase[i] == 'v')
					cout << setw(5) << lV[c]<< " ";
				if(curPhrase[i] == 'W' || curPhrase[i] == 'w')
					cout << setw(5) << lW[c]<< " ";
				if(curPhrase[i] == 'X' || curPhrase[i] == 'x')
					cout << setw(5) << lX[c]<< " ";
				if(curPhrase[i] == 'Y' || curPhrase[i] == 'y')
					cout << setw(5) << lY[c]<< " ";
				if(curPhrase[i] == 'Z' || curPhrase[i] == 'z')
					cout << setw(5) << lZ[c]<< " ";
				if(curPhrase[i] == '*' )
					cout << setw(5) << lAp[c]<< " ";
				if(curPhrase[i] == ' ' )
					cout << setw(5) << lSp[c]<< " ";
				if(curPhrase[i] == ',' )
					cout << setw(5) << lCo[c]<< " ";
				if(curPhrase[i] == '-' )
					cout << setw(5) << lDa[c]<< " ";
				if(curPhrase[i] == '_' )
					{
						cout << setw(5) << lUl[c]<< " ";
					}
				i++;
			}
			cout << endl; 
		}
	return;
	}
}

void BigText::SetLineBreaks()
{
	int i;
	
	for(i = 12; i >= 0 ; i--)
	{
		if(curPhrase[i]==' ')
		 {
		 	lineBreak = i;
		 	return;
		 }
	}
	return;
}

void BigText::LoadPhrase(string phrase)
{
	curPhrase = phrase;
}

int BigText::GetPhraseLength()
{
    std::string testString(curPhrase);
    slength = (testString.length());
    return(slength);
}
  
void BigText::LoadFonts()
{
     int size = 5;
     int i;
     string phrase;
          
     string filename = "letterA.txt";
     ifstream inFile;
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lA[i] = phrase;
     }
     inFile.close();
     
     filename = "letterApostraphy.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lAp[i] = phrase;
     }
     inFile.close();
     
     filename = "letterB.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lB[i] = phrase;
     }
     inFile.close();
          
     filename = "letterBox.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lBo[i] = phrase;
     }
     inFile.close();
          
     filename = "letterC.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lC[i] = phrase;
     }
     inFile.close();
          
     filename = "letterComma.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lCo[i] = phrase;
     }
     inFile.close();
          
     filename = "letterD.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lD[i] = phrase;
     }
     inFile.close();
          
     filename = "letterDash.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lDa[i] = phrase;
     }
     inFile.close();
          
     filename = "letterE.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lE[i] = phrase;
     }
     inFile.close();
          
     filename = "letterF.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lF[i] = phrase;
     }
     inFile.close();
          
     filename = "letterG.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lG[i] = phrase;
     }
     inFile.close();
          
     filename = "letterH.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lH[i] = phrase;
     }
     inFile.close();
          
     filename = "letterI.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lI[i] = phrase;
     }
     inFile.close();
          
     filename = "letterJ.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lJ[i] = phrase;
     }
     inFile.close();
          
     filename = "letterK.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lK[i] = phrase;
     }
     inFile.close();
          
     filename = "letterL.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lL[i] = phrase;
     }
     inFile.close();
          
     filename = "letterM.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lM[i] = phrase;
     }
     inFile.close();
          
     filename = "letterN.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lN[i] = phrase;
     }
     inFile.close();
          
     filename = "letterO.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lO[i] = phrase;
     }
     inFile.close();
          
     filename = "letterP.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lP[i] = phrase;
     }
     inFile.close();
          
     filename = "letterQ.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lQ[i] = phrase;
     }
     inFile.close();
          
     filename = "letterR.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lR[i] = phrase;
     }
     inFile.close();
          
     filename = "letterS.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lS[i] = phrase;
     }
     inFile.close();
          
     filename = "letterSpace.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lSp[i] = phrase;
     }
     inFile.close();
          
     filename = "letterT.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lT[i] = phrase;
     }
     inFile.close();
          
     filename = "letterU.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lU[i] = phrase;
     }
     inFile.close();
          
     filename = "letterUline.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lUl[i] = phrase;
     }
     inFile.close();
          
     filename = "letterV.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lV[i] = phrase;
     }
     inFile.close();
          
     filename = "letterW.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lW[i] = phrase;
     }
     inFile.close();
          
     filename = "letterX.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lX[i] = phrase;
     }
     inFile.close();
          
     filename = "letterY.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lY[i] = phrase;
     }
     inFile.close();
          
     filename = "letterZ.txt";
     inFile.open(filename.c_str());
     if(inFile.fail())
     {
                      cout << "\nThe file fontfiles.txt was not successfully opened"
                           << "\n Please check that the file currently exists"
                           << endl;
                           exit(1);
     }
     for (i = 0 ; i < size ; i++) 
     {
           getline(inFile, phrase);
           lZ[i] = phrase;
     }
     inFile.close();
          
         
     return;                     
}

