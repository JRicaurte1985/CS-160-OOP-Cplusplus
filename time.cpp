/**************************************************************************
* Program:
*    Assignment 08, Time class
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte   
* Summary:
*    This program introduces a class called Time. Various member functions
* were written and operators were overloaded. Main tests the class to see if
* the class works properly.
****************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>


using namespace std;

#ifndef TIME_H
#define TIME_H

/*****************************************************************************
 * Class Name: Time
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
 *****************************************************************************/
class Time
{
   public:

      Time(int theHour, int theMin, int theSec);
      Time(int theHour, int theMin);
      Time(void);
      void setMinute(int theMinute);
      void setHour(int theHour);
      void setSecond(int theSecond);
      void addSeconds(int seconds2Add);
      void addMinutes(int minutes2Add);
      // add hours and returns # of days of overflow
      int  addHours(int hours2Add);
      // display as military time - default no seconds (hh:mm)
      void displayMilitaryTime(bool displaySeconds = false);
      // display the prompt and read data into the time object
      void promptForTime(string prompt, bool readSeconds = false);
      // add two time objects & return the resulting time object
      const Time operator + (const Time &time1) const;
   
      // logical operators
      bool operator < (const Time &time1) const;
      bool operator > (const Time &time1) const;
      bool operator == (const Time &time1) const;
      bool operator <= (const Time &time1) const;
      bool operator >= (const Time &time1) const;

      // displays the time object in the format "hh:mm"
      friend ostream& operator << (ostream &out, const Time &time1);
      // reads into the time object.  Expects format "hh:mm"
      friend istream& operator >> (istream &in, Time &time1);

   private:
      int hour;
      int minute;
      int second;
};
#endif

int getInt(string prompt, string errMsg = "\nValue must be an integer!\n");

/***********************************************************************
* main - various Time objects are created and its member functions used.
* main's purpose is to test to see if the Class is written properly and its
* member funcitons and overloaded operators work.
***********************************************************************/
int main (void)
{
   const bool DISPLAY_SECONDS = true;
   const bool READ_SECONDS = true;

   int hourInput;
   int minInput;
   int secInput;

   Time time1;
   cout << "\nTime1 = " << time1;
   Time time2(8,10);
   cout << "\nTime2 = " << time2; 
   time2.promptForTime("\nChange Time2 (hh:mm): ");

   Time time3(12,30,15);
   time3.promptForTime("Enter Time3 (hh:mm:ss): ",READ_SECONDS);

   Time time4;
   cout << "Enter Time4 (hh:mm): ";
   cin >> time4;

   cout << "\nTime1 = ";
   time1.displayMilitaryTime(DISPLAY_SECONDS);
   cout << "\nTime2 = ";
   time2.displayMilitaryTime(DISPLAY_SECONDS);
   cout << "\nTime3 = ";
   time3.displayMilitaryTime(DISPLAY_SECONDS);
   cout << "\nTime4 = ";
   time4.displayMilitaryTime();

   Time time5(8,0);
   cout << "\nTime5 = ";
   cout << time5;
   cout << endl << endl;
   
   cout << "Adding Time1 to Time2" << endl;
   time5 = time1 + time2;
   cout << time1 << " + " << time2 << " = " << time5 << endl;

   cout << "Adding Time3 to Time4" << endl;
   time5 = time3 + time4;
   cout << time3 << " + " << time4 << " = " << time5 << endl;

   cout << "\nTime5 = ";
   time5.displayMilitaryTime(DISPLAY_SECONDS);

   cout << "\nNow let's add to Time5\n";
   
   secInput = getInt("\nNumber of seconds to add: ","Invalid Seconds value!");
   time5.addSeconds(secInput);
   cout << "Adding " << secInput << " seconds to Time5 = ";
   time5.displayMilitaryTime(DISPLAY_SECONDS);

   minInput = getInt("\nNumber of minutes to add: ","Invalid Minutes value!");
   time5.addMinutes(minInput);
   cout << "Adding " << minInput << " minutes to Time5 = ";
   time5.displayMilitaryTime(DISPLAY_SECONDS);

   hourInput = getInt("\nNumber of hours to add: ","Invalid hours value!");
   int day = time5.addHours(hourInput);
   cout << "Adding " << hourInput << " hours to Time5 = ";
   time5.displayMilitaryTime(DISPLAY_SECONDS);
   cout << "\nDays carried over: " << day << endl;
   cout << endl;
  
   if (time1 < time2)
   {
      cout << time1 << " is less than " << time2 << endl;
   }

   if (time1 > time2)
   {
      cout << time1 << " is greater than " << time2 << endl;
   }
   
   if (time2 == time3)
   {
      cout << time2 << " is equal " << time3 << endl;
   }
   
   if (time3 <= time4)
   {
      cout << time3 << " is less or equal to " << time4 << endl;
   }
   
   if (time4 >= time5)
   {
      cout << time4 << " is greater or equal to " << time5 << endl;
   }

   Time time6(7,40,35);
   Time time7(9,20,40);
   if (time6 < time7)
   {
      time6.displayMilitaryTime(DISPLAY_SECONDS);
      cout << " is less than ";
      time7.displayMilitaryTime(DISPLAY_SECONDS);
      cout << endl;
   }
   else
   {
      time6.displayMilitaryTime(DISPLAY_SECONDS);
      cout << " is greater or equal to ";
      time7.displayMilitaryTime(DISPLAY_SECONDS);
      cout << endl;
   }

   time6 = Time(8,30,15);
   time7 = Time(8,20,15);
   if (time6 <= time7)
   {
      time6.displayMilitaryTime(DISPLAY_SECONDS);
      cout << " is less than or equal ";
      time7.displayMilitaryTime(DISPLAY_SECONDS);
      cout << endl;
   }
   else
   {
      time6.displayMilitaryTime(DISPLAY_SECONDS);
      cout << " is greater than ";
      time7.displayMilitaryTime(DISPLAY_SECONDS);
      cout << endl;
   }

   return 0;
}

/*****************************************************************************
 * Summary: Setter function for 'minute' variable. Appropriate data validation
 * used.
 *****************************************************************************/
void Time::setMinute(int theMinute)
{
   if (theMinute > 59 || theMinute < 0)
   {
      cerr << "\nError creating Time object. Minutes must be between 0 and";
      cerr << "59";
      exit(1);
   }
   else
      minute = theMinute;
}

/*****************************************************************************
 * Summary: Setter function for 'hour' variable. Appropriate data validation
 * used.
 *****************************************************************************/
void Time::setHour(int theHour)
{
   if (theHour > 23 || theHour < 0)
   {
      cerr << "\nError creating Time Object. Hour must be between 0 and 23";
      exit(1);
   }
   else
      hour = theHour;
}

/*****************************************************************************
 * Summary: Setter function for 'second' variable. Appropriate data validation
 * used.
 *****************************************************************************/
void Time::setSecond(int theSec)
{
   if (theSec > 59 || theSec < 0)
   {
      cerr << "\nError creating Time object. Seconds must be between 0 and 59";
      exit(1);
   }
   else
      second = theSec;
}
/*****************************************************************************
 * Summary: Alternate constructor for a Time object. Takes arguments for hour,
 * minute, and second. Uses setter functions to validate data.
 *****************************************************************************/

Time::Time(int theHour, int theMin, int theSec)
{
   setHour(theHour);
   setMinute(theMin);
   setSecond(theSec);
}

/*****************************************************************************
 * Summary: Alternate constructor for a Time object. Takes arguments for hour
 * and minute and uses appropriate setter functions to validate data. second
 * assigned to zero.
 *****************************************************************************/
Time::Time(int theHour, int theMin)
      :second(0)
{
   setHour(theHour);
   setMinute(theMin);
}

/*****************************************************************************
 * Summary: Default constructor of a Time object. All private variables set to
 * zero.
 *****************************************************************************/
Time::Time()
      :hour(0), minute(0), second(0)
{/*Body intentionally empty*/}



/*****************************************************************************
 * Summary: adds to the second variable of a Time object. Accounts for possible
 * rollover.
 *****************************************************************************/
void Time::addSeconds(int seconds2Add)
{
   if (seconds2Add < 0)
      cerr << "\nError adding seconds. Cannot add negative seconds";

   else if ((seconds2Add + second) < 60)
      second += seconds2Add;
   else 
   {
      second += seconds2Add;
      minute += second / 60;
      second = second % 60;
      if (minute >= 60)
      {
         hour += minute / 60;
         minute = minute % 60;
         if (hour >= 24)
            hour = hour % 24;
          
      }
   }
}    

/*****************************************************************************
 * Summary: adds to the minute variable of a Time object. Accounts for possible
 * rollover.
 *****************************************************************************/
void Time::addMinutes(int minutes2Add)
{
   if (minutes2Add < 0)
      cerr << "\nError adding minutes. Cannot add negative minutes";

   else if ((minutes2Add + minute) < 60)
      minute += minutes2Add;
   else 
   {
      minute += minutes2Add;
      hour += minute / 60;
      minute = minute % 60;

      if (hour >= 24)
         hour = hour % 24;
   }
}

/*****************************************************************************
 * Summary: adds to the hour variable of a Time object. If the sum is 24 or
 * more, it will keep track of how many days it overflowed and return it.
 *****************************************************************************/
int  Time::addHours(int hours2Add)
{
   int dayOverflow = 0;
   if (hours2Add < 0)
      cerr << "\nError adding hours. Cannot add negative hours";
   else if ((hours2Add + hour) < 24)
      hour += hours2Add;
   else
   {
      hour += hours2Add;
      dayOverflow = hour / 24;
      hour = hour % 24;
   }
   return dayOverflow;
}

/*****************************************************************************
 * Summary: displays the time in military format. If displaySeconds is true,
 * it will display in format hh:mm:ss. Otherwise it will display as hh:mm.
 *****************************************************************************/
void Time::displayMilitaryTime(bool displaySeconds)
{
   if (hour < 10)
      cout << setw(2) << setfill('0') << hour;
   else
      cout << hour;
   
   cout << ":";
   
   if (minute < 10)
      cout << setw(2) << setfill('0') << minute;
   else
      cout << minute;

   if (displaySeconds == true)
   {
      if (second < 10)
         cout << ":" << setw(2) << setfill('0') << second;
      else
         cout << ":" << second;
   }
}

/*****************************************************************************
 * Summary: This function prompts the user for the time, specified by the
 * prompt argument. readSeconds is defaulted to false. It reads the time
 * in as a string and performs all possible checks to ensure that the user
 * input the time in the proper format specified by the prompt.      
 *****************************************************************************/
void Time::promptForTime(string prompt, bool readSeconds)
{
   bool goodInput = true;
   string sTime;
   int tempHour = 0;
   int tempMin = 0;
   int tempSec = 0;
   string subHour;
   string subMin;
   string subSec;
   do 
   {
      if (!goodInput)
      {
         cin.clear();
         cin.ignore(80, '\n');
         cerr << "\nInvalid format. Input using specified format. ";
      }
      goodInput = true;
      cout << prompt;
      cin >> sTime;
      
      if ((readSeconds == false && sTime.length() != 5) ||
          (readSeconds == true && sTime.length() != 8))
      {
         goodInput = false;
         continue;
      }
         
      if (!isdigit(sTime[0]) || !isdigit(sTime[1]) || !isdigit(sTime[3]) || 
          !isdigit(sTime[4]) || sTime[2] != ':')
      {
         goodInput = false;
         continue;
      }
      subHour = sTime.substr(0,2);
      subMin = sTime.substr(3,2);
      tempHour = atoi(subHour.c_str());
      tempMin = atoi(subMin.c_str());
      
      if (sTime.length() == 8)
      {
         if (!isdigit(sTime[6]) || !isdigit(sTime[7]) ||
             sTime[5] != ':')
         {
            goodInput = false;
            continue;
         }
         subSec = sTime.substr(6,2);
         tempSec = atoi(subSec.c_str());
      }
      
      if (tempHour >= 0 && tempHour < 24 || tempMin >= 0 && tempMin < 60 &&
          tempSec >= 0 && tempSec < 60)
         {   
            hour = tempHour;
            minute = tempMin;
            second = tempSec;
         }
      else 
         goodInput = false;
      
   } while (!goodInput);

}

/*****************************************************************************
 * Summary: Overloads the addition operator to handle the addition of Time
 * objects.
 *****************************************************************************/
const Time Time::operator + (const Time &time1) const
{
   int totalHours = hour + time1.hour;
   int totalMinutes = minute + time1.minute;
   int totalSeconds = second + time1.second;

   if (totalSeconds > 59)
   {
      totalMinutes += totalSeconds / 60;
      totalSeconds = totalSeconds % 60;
   }

   if (totalMinutes > 59)
   {
      totalHours += totalMinutes / 60;
      totalMinutes = totalMinutes % 60;
   }

   if (totalHours > 23)
      totalHours = totalHours % 24;

   return Time (totalHours, totalMinutes, totalSeconds);
}

/*****************************************************************************
 * Summary: Overloads the less-than operator to handle the Time class.
 *****************************************************************************/
bool Time::operator < (const Time &time1) const
{
   if (hour < time1.hour)
      return true;
   else if (hour == time1.hour && minute < time1.minute)
      return true;
   else if (hour == time1.hour && minute == time1.minute &&
            second < time1.second)
      return true;
   else
      return false;
}

/*****************************************************************************
 * Summary: Overloads the greater-than operator to handle the Time Class.
 *****************************************************************************/
bool Time::operator > (const Time &time1) const
{
   if (hour > time1.hour)
      return true;
   else if (hour == time1.hour && minute > time1.minute)
      return true;
   else if (hour == time1.hour && minute == time1.minute &&
            second > time1.second)
      return true;
   else
      return false;
}

/*****************************************************************************
 * Summary: Overloads the 'equals' operator to handle the Time class.
 *****************************************************************************/
bool Time::operator == (const Time &time1) const
{
   if (hour == time1.hour && minute == time1.minute && second == time1.second)
      return true;
   else
      return false;
}

/*****************************************************************************
 * Summary: Overloads the less-than-or-equal-to operator to handle the Time
 * class.
 *****************************************************************************/
bool Time::operator <= (const Time &time1) const
{
   if (hour < time1.hour)
      return true;
   else if (hour == time1.hour && minute < time1.minute)
      return true;
   else if (hour == time1.hour && minute == time1.minute &&
            second < time1.second)
      return true;
   else if (hour == time1.hour && minute == time1.minute &&
            second == time1.second)
      return true;
   else
      return false;
}

/*****************************************************************************
 * Summary: Overloads the greater-than-or-equal-to operator to handle the Time
 * class.
 *****************************************************************************/
bool Time::operator >= (const Time &time1) const
{
   if (hour > time1.hour)
      return true;
   else if (hour == time1.hour && minute > time1.minute)
      return true;
   else if (hour == time1.hour && minute == time1.minute &&
            second > time1.second)
      return true;
   else if (hour == time1.hour && minute == time1.minute &&
            second == time1.second)
      return true;
   else
      return false;
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
ostream& operator << (ostream &out, const Time &time1)
{
   if (time1.hour >= 10)
      out << time1.hour;
   else
      out << '0' << time1.hour;

   out << ':';

   if (time1.minute >= 10)
      out << time1.minute;
   else
      out << '0' << time1.minute;

   return out;
}

/*****************************************************************************
 * Summary: Overloads the extraction operator. Stores input as a string,
 * performs error checks, converts to int, then assigns to the time1 hour
 * and minute variables.
 *****************************************************************************/
istream& operator >> (istream &in, Time &time1)
{
   string input;
   string sHours;
   string sMinutes;
   int tempHour;
   int tempMin;
   in >> input;

   if (!isdigit(input[0]) || !isdigit(input[1]) || input[2] != ':' ||
       !isdigit(input[3]) || !isdigit(input[4]) || input.length() != 5)
   {
      cerr << "\nInvalid entry. Use hh:mm format";
      exit(1);
   }
   
   sHours = input.substr(0,2);
   sMinutes = input.substr(3,2);
 
   tempHour = atoi(sHours.c_str());
   tempMin = atoi(sMinutes.c_str());
   
   if (tempHour < 0 || tempHour > 23 || tempMin < 0 || tempMin > 59)
   {
      cerr << "\nInvalid entry. Hour must be between 0-23. "
           << "Minutes must be between 0-59";
      exit(1);
   }
   else
   {
      time1.hour = tempHour;
      time1.minute = tempMin;
   }

   return in;
}

/************************************************************************
 *  int getInt(string prompt, string errMsg)
 *
 *  Desc: Error safe - read integer routine
 *        On error, this function will re-prompt for the integer
 *        until there is no input error.
 *
 *  Inputs:  prompt - string used to prompt for the integer
 *           errMsg - error message you wish displayed if you get an error.
 *  Outputs: none
 *  return:  integer - read from the console
 **************************************************************************/
int getInt(string prompt, string errMsg)
{
   int input = 0;

   while (true)
   {
      cout << prompt;
      cin >> input;

      if (input < 0 || cin.fail())
      {
         cin.clear();
         cin.ignore(80,'\n');
         cerr << errMsg;
      }
      else
         break;
   }

   return input;
}


               
