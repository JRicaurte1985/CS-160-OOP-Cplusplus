/***********************************************************************
* Program:
*    Assignment  
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte
* Summary: 
*   
*    
*   
*    
*    
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * main description
 * 
 ***********************************************************************/
int main()
{
   string prompt = "Enter a Date: ";
   int month, day, year;
   char slash;
   cout << prompt << endl;
   cin >> month >> slash>> day >> slash >> year;
   cout << month << day << year;
   return 0;
}
