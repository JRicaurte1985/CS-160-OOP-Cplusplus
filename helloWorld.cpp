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
using namespace std;

/**********************************************************************
 * main description
 * 
 ***********************************************************************/
int main()
{
   int numberOfLanguages;
   
   cout << "Hello world\n"
        << "Welcome to C++.\n";

   cout <<"How many programming languages have you used? ";
   cin >> numberOfLanguages;

   if (numberOfLanguages < 1)
      cout << "Read the preface. You may prefer\n"
           << "a more elementary book by the same author.\n";
   else
      cout << "Enjoy the book.\n";
         
   return 0;
}
