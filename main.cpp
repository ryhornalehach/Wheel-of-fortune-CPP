

#include <iostream>
#include <fstream>
#include <cstdlib>   // needed for exit()
#include <string>
using namespace std;

int main()
{
   string filename  = "wof-phrases.dat"; 
   string phrase;
   ifstream inFile;

   inFile.open(filename.c_str());

   if (inFile.fail())  // check for successful open
   {
        cout << "\nThe file was not successfully opened"
	          << "\n Please check that the file currently exists."
	          << endl;
        exit(1);
   }
  
   while ( getline(inFile, phrase) )
   { 
      cout << "Phrase is: " << phrase << endl;
   }
   
   cout << "Length of phrase is: " << phrase.length();
   
   cout << "Character at 4 is " << phrase[4]<< endl;
   inFile.close(); 

  return 0;


}