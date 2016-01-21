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

/**********************************************************************
 * main description
 * 
 ***********************************************************************/
int main()
{
   const bool DISPLAY_SECONDS = true;
   Time time1(10,5,45);
   time1.displayMilitaryTime(DISPLAY_SECONDS);
   cout << endl;
   Time time2(10,5,45);
   time2.displayMilitaryTime(DISPLAY_SECONDS);
   cout << endl;
   cout << "\nTime 1 + Time 2 = ";
   Time time3 = time1 + time2;
   time3.displayMilitaryTime(DISPLAY_SECONDS);
   cout << endl << endl;
   time1.displayMilitaryTime(DISPLAY_SECONDS);
   cout << endl;
   time2.displayMilitaryTime(DISPLAY_SECONDS);
   cout << endl;
   time3.addMinutes(189);
   time3.displayMilitaryTime(DISPLAY_SECONDS);

   if (time1 == time2)
      cout << "\nOperator works";

   cout << "\nTime1 is: " << time1 << "\nTime2 is: " << time2 << "\nTime3 is: "
        << time3 << endl;
   
   Time time4;
   cout << "\nTesting >> operator. Enter time in hh:mm  : ";
   cin >> time4;

   cout << "\nTime4 is: " << time4 << endl;
   time4.displayMilitaryTime(DISPLAY_SECONDS);
   
   
   return 0;
}

/*****************************************************************************
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
 *****************************************************************************/

Time::Time(int theHour, int theMin, int theSec)
{
   setHour(theHour);
   setMinute(theMin);
   setSecond(theSec);
}

/*****************************************************************************
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
 *****************************************************************************/
Time::Time(int theHour, int theMin)
      :second(0)
{
   setHour(theHour);
   setMinute(theMin);
}

/*****************************************************************************
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
 *****************************************************************************/
Time::Time()
      :hour(0), minute(0), second(0)
{/*Body intentionally empty*/}



/*****************************************************************************
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
         cout << "\nInvalid format. Input using specified format. ";
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
 *****************************************************************************/
bool Time::operator == (const Time &time1) const
{
   if (hour == time1.hour && minute == time1.minute && second == time1.second)
      return true;
   else
      return false;
}

/*****************************************************************************
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
 *****************************************************************************/ostream& operator << (ostream &out, const Time &time1)
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
 * Summary: This class contains methods for the the creation,
 *          manipulation, input, and output of time objects
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
int getInt(string prompt, string errMsg = "\nValue must be an integer!\n")
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
         cout << errMsg;
      }
      else
         break;
   }

   return input;
}
