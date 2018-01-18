// Programmer: John J. Drugan
// Date: 12/1/2015
// File: Utility.hpp

//#include "stdafx.h"   // needed for MS C++ Express 2010 programs


#include <iostream>
#include <iomanip>  // needed for formatting


using namespace std;

#ifndef __Utility
#define __Utility
//class declaration section
class Utility
{
  private: 
	
  public:
      Utility(int = 10);
      
      int Random(int max);  // Returns a Random value between 0 and max
      int Random(int numDie, int dieSide);
};

//  class implementation section
Utility::Utility(int max)
{
   srand(time(0));
}

int Utility::Random(int max)
{
      
	return (rand() % max );
   
} // end Random()

int Utility::Random(int numDie, int dieSide)
{
   int sum = 0;
   
   for ( int i = 0; i < numDie; i++ )
	{
      sum += (rand() % dieSide) + 1 ;
   }
   return sum;
    
   
} // end Random()

#endif