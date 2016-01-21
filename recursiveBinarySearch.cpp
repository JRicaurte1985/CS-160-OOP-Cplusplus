/***********************************************************************
* Program:
*    Assignment 05, Recursive Binary Search
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte
* Summary: 
* This program is a Binary Search Program. It first reads in from a file  a
* list of names into an array of ID's (struct). It then sorts the array by
* last name, assigns a record number to the ID. The program then loops a
* prompt to the user to input a last name to search for. A binary search is
* performed and if successful, displays the full name and record number. If not
* found, it will indicate that the name was not found. If the user types 'quit'
* the loop ends and the program terminates.
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct ID
{
   string firstName;
   string lastName;
   int recordNumber;
};

void binarySearch(ID list[], int first, int last, string key,
                  bool& found, int& location);

int partition (ID list[], int left, int right);
void quickSort(ID list[], int left, int right);


/*****************************************************************************
 * main -  Main starts by declaring necessary variables. It opens a file called
 * studentList.txt and reads it into an array of ID's (a struct I created).
 * ID's consist of a first name, last name, and record number. The file
 * begins with a number that is read into an int (numStudents). This
 * determines the length of the array. The rest of the file is just a list
 * of first and last names. Once saved into the array, a quicksort algorithm is
 * performed to sort the array by last name. A record number is then assigned
 * to each ID once the array has been sorted. Then a loop occurs which prompts
 * the user to search for a last name. A binary search is performed. The full
 * name is displayed along with the record number. If the user types "quit" the
 * loop ends and the program terminates.
 ****************************************************************************/
int main()
{
   ifstream inFile;
   int numStudents;
   int finalIndex;
   int location;
   bool found;
   bool active = true;
   string userInput;
   
   inFile.open ("/home/ercanbracks/cs165-examples/assign05/studentList.txt");
   if (inFile.fail())
   {
      cout << "\nFile not found";
      return 0;
   }
   
   inFile >> numStudents;
   
   //create ID array of size numStudents
   ID studentList[numStudents];
   
   finalIndex = numStudents - 1;
   
   //populate last and first names into array
   for (int i = 0; i < numStudents; i++)
   {
      inFile >> studentList[i].lastName;
      inFile >> studentList[i].firstName;
   }
   inFile.close();

   //sort array by last name
   quickSort(studentList, 0, numStudents - 1);

   //populate record numbers into array
   for (int i = 0; i < numStudents; i++)
      studentList[i].recordNumber = i + 1;

   cout << "---------------------------------------------------------------\n"
        << "Binary Search Program - Search using last name (case sensitive)\n"
        << "---------------------------------------------------------------"
        << "\n";

   //loop begins for Binary Search Program
   do
   {
      cout << "\nSearch for: ";
      cin >> userInput;
      if (userInput == "quit")
         active = false;
      if (active)
      {
         binarySearch(studentList, 0, finalIndex, userInput, found, location);

         if (found)
         {
            string temp = studentList[location].lastName + ", " +
                          studentList[location].firstName;
            
            cout << "\n" << temp << setw(45 - temp.size())
                 << "Record Number: " << studentList[location].recordNumber
                 << "\n";
         }
         else
            cout << "\n" << userInput << " is not found!\n";
      }
   }while (active);
   return 0;
}
  
/*****************************************************************************
 * binarySearch - This is a generic binary search algorithm that has been
 * modified to work with ID's. The search is comparing lastName members of
 * ID's, so the parameter 'key' is required to be of type string. Its
 * arguments 'first' and 'last' are the first and last index of the array. If
 * the search is successful in finding the desired name, that index will be
 * assigned to 'location' and will be displayed in main as the record number+1
 * (hence the pass by reference). The same is true of the 'found' argument.
 ****************************************************************************/
void binarySearch(ID list[], int first, int last, string key,
                  bool& found, int& location)
{
   int mid;
   if (first > last)
      found = false;
   else
   {
      mid = (first + last) / 2;

      if (key == list[mid].lastName)
      {
         found = true;
         location = mid;
      }
      else if (key  < list[mid].lastName)
      {
         binarySearch(list, first, mid - 1, key, found, location);
      }
      else if (key > list[mid].lastName)
      {
         binarySearch(list, mid + 1, last, key, found, location);
      }
   }
}

/*****************************************************************************
 * partition - this function is part of the quickSort algorithm and is called
 * every time quickSort recursively calls itself. It's purpose in the algorithm
 * is to divide the array into 2 sub-arrays based on a pivot chosen. In this
 * case the pivot is not random. It is set as the midpoint of the array. Once
 * the pivot is chosen, i and j serve as indices for the beginning and end of
 * the array. i and j move along the array and through a series of comparisons
 * and swaps with the pivot and each other, the values less than the pivot
 * stay on the left and the values greater than pivot move to the right. i is
 * returned and used in the quickSort recursion to determine the starting or
 * end position of the new array to be partitioned.
 ****************************************************************************/
int partition (ID list[], int left, int right)
{
   int i = left;
   int j = right;
   ID temp;
   string pivot = list[(left + right) / 2].lastName;

   while (i <= j)
   {
      while (list[i].lastName < pivot)
         i++;
      while (list[j].lastName > pivot)
         j--;
      if (i <= j)
      {
         temp = list[i];
         list[i] = list[j];
         list[j] = temp;
         i++;
         j--;
      }
    
   }
   return i;
}

/****************************************************************************
 * quickSort - This function is the quicksort algorithm modified to take as 
 * an argument an ID array. The comparisons are done on the lastName members
 * of the ID's. The algorithm basically chooses a pivot, puts the values less
 * than the pivot to the left of it and the values greater than the pivot to
 * the right. This is done through the partition function. Recursion occurs
 * until the the whole 'less-than' sub-array is sorted and then moves on to
 * the 'greater-than' sub-array. Recursion occurs until the greater-than
 * sub-array is sorted, which finally results in the entire array being sorted.
 * As well known, this is not a stable sort, so equal values will not be
 * maintained.
 ****************************************************************************/
void quickSort(ID list[], int left, int right)
{
   int index = partition(list, left, right);
   if (left < index - 1)
      quickSort(list, left, index - 1);
   if (index < right)
      quickSort(list, index, right);
}
   
