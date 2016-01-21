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
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

// finds b^n % m
//based on Applied Cryptography by Bruce Schneier
int modExp(int b, int n, int m)
{
   int ans = 1;
   while (n > 0)
   {
      if (n % 2  == 1)
         ans = (ans * b) % m;
      n = n >> 1;
      cout << "\nN equals " << n;
      b = (b * b) % m;
   }
   return ans;
}
/**********************************************************************
 * main description
 * 
 ***********************************************************************/
int main()
{
   modExp(4,3,3);
   cout << "\nDone";
   return 0;
}
