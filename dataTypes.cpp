/***********************************************************************
* Program:
*    Assignment 01, Data Types Program  
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte
* Summary:
*    This program prompts the user for a number and stores it in an unsigned
*    long long. It then assigns that value to new variables of various
*    data types used to store numbers. A chart is then displayed showing
*    various properties of the data types and how they handled the assignment.
*    
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void showDataTypeChart(unsigned long long input);

/**********************************************************************
 * main - 
 *
 * This function is essentially an infinite while loop that prompts the
 * user for a number, checks for proper input, then runs the
 * showDataTypeChart function using the number the user typed in as its
 * argument. If the user types q, the loop breaks and the program ends.
 * If the user types anything other than q or a valid number (not larger
 * than an unsigned long long), the program will clear the fail bit, ignore
 * what's in the buffer(up to 80 characters or the next line character)
 * and restart the loop, prompting for input once again.
 ***********************************************************************/
int main()
{
   unsigned long long originalNumber;
   string s;
   while (true)
   {
      cout << "\nEnter a number (q to quit): ";
      cin >> originalNumber;
     
      if (cin.fail())
      {
         /* Here I am identifying the input error. I clear the failbit
            and assign whatever is in the buffer to the string s. I then
            test to see if the size of the string is 1 AND that the
            character is q. If true, it is because the user typed q. 
            Therefore, the loop breaks and the program ends. If the test
            does not pass, it will notify the user of invalid input, ignore
            what is in the buffer, and loop back to the beginning, asking
            for input once again.
         */
         cin.clear();
         cin >> s;
         
         if (s.size() == 1 && s[0] == 'q')
            break;
         
         cout << "\nInvalid Input!\n";
         cin.ignore(80,'\n');
      }
      else
         showDataTypeChart(originalNumber);
      
   }
   return 0;
}


/***********************************************************************
* showDataTypeChart -
*
* This function takes an unsigned long long argument called input. It 
* then assigns input to local variables of various data types. A chart is
* then displayed that shows how each data type handled the assignment.
* The chart includes the data type name, the number of bytes of memory
* required for the data type, the value of each variable in decimal and
* hexadecimal, and if the original number overflowed the data type.
***********************************************************************/
void showDataTypeChart (unsigned long long input)
{
   bool a = static_cast<bool>(input);
   char b = static_cast<char>(input);
   unsigned char c = static_cast<unsigned char>(input);
   short d = static_cast<short>(input);
   unsigned short e = static_cast<unsigned short>(input);
   int f = static_cast<int>(input);
   unsigned int g = static_cast<unsigned int>(input);
   long h = static_cast<long>(input);
   unsigned long i = static_cast<unsigned long>(input);
   long long j = static_cast<long long>(input);
   unsigned long long k = static_cast<unsigned long long>(input);
   float l = static_cast<float>(input);
   double m = static_cast<double>(input);
   long double n = static_cast<long double>(input);

   

   cout << "\nOriginal input value: " << input << "\n\n";
   cout << setw(12) << "Data Type" << setw(12) << "Bytes" << setw(17)
        << "Value (Dec)" << setw(22) << "Value (Hex)" << setw(16)
        << "Overflow\n";
   
   cout << "------------------ " << "-----  " << "--------------------  "
        << "--------------------  " << "--------\n";

   cout << "bool" << setw(18) << sizeof(bool) << setw(24) << a
        << setw(22) << hex << a << dec <<  setw(10) << "N/A\n";
   
   cout << "char" << setw(18) << sizeof(char) << setw(24);
   
   if (isprint(b))
      cout << b << setw(22) << hex << static_cast<int>(b) << dec << setw(8);
   else   
   {
      cout << static_cast<int>(b) << setw(22) << hex
           << static_cast<int>(b) << dec << setw(8);
   }   
   if ( b != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "unsigned char" << setw(9) << sizeof(unsigned char) << setw(24);

   if (isprint(c))
      cout << c << setw(22) << hex << static_cast<int>(c) << dec << setw(8);
   else
   {
      cout << static_cast<int>(c) << setw(22) << hex
           << static_cast<int>(c) << dec << setw(8);
   }
   if (c != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "short" << setw(17) << sizeof(short) << setw(24) << d << setw(22)
        << hex << d << dec << setw(8);
   
   if (d != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "unsigned short" << setw(8) << sizeof(unsigned short) << setw(24)
        << e << setw(22) << hex << e << dec << setw(8);
   
   if (e != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "int" << setw(19) << sizeof(int) << setw(24) << f << setw(22)
        << hex << f << dec << setw(8);
   
   if (f != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "unsigned int" << setw(10) << sizeof(unsigned int) << setw(24)
        << g << setw(22) << hex << g << dec << setw(8);
   
   if (g != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "long" << setw(18) << sizeof(long) << setw(24) << h << setw(22)
        << hex << h << dec << setw(8);
   
   if (h != input || h < 0)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "unsigned long" << setw(9) << sizeof(unsigned long) << setw(24)
        << i << setw(22) << hex << i << dec << setw(8);
   
   if (i != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "long long" << setw(13) << sizeof(long long) << setw(24)
        << j << setw(22) << hex << j << dec << setw(8);
   
   if (j != input || j < 0)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "unsigned long long" << setw(4) << sizeof(unsigned long long)
        << setw(24) << k << setw(22) << hex << k << dec << setw(8);
   
   if (k != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "float" << setw(17) << sizeof(float) << setw(24) 
        << setprecision(0) << fixed << l << setprecision(5) << setw(22)
        << scientific << l << fixed <<setw(8);
   
   if (static_cast<unsigned long long>(l) != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "double" << setw(16) << sizeof(double) << setw(24)
        << setprecision(0) << m << setprecision(5) << setw (22)
        << scientific << m << fixed << setw(8);
   
   if (static_cast<unsigned long long>(m) != input)
      cout << "T\n";
   else
      cout << "F\n";

   cout << "long double" << setw(11) << sizeof(long double) << setw(24)
        << setprecision(0) << n << setprecision(5) << setw(22)
        << scientific << n <<  fixed << setw(8);
   
   if (static_cast<unsigned long long>(n) != input)
      cout << "T\n";
   else
      cout << "F\n";    
}
