/***********************************************************************
* Program:
*    Assignment 10 Date Class
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte
* Summary: 
*   Date class inherits from Time class. The program executes various functions
* to test the functionality of the Date class. 
*    
*   INCOMPLETE. NOT ALL FUNCTIONS DEFINED. DOES NOT COMPILE
*    
*    
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>


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
      Time();
      void setMinute(int theMinute);
      void setHour(int theHour);
      void setSecond(int theSecond);
      int getSecond() const {return second;}
      int getMinute() const {return minute;}
      int getHour() const {return hour;}
      void addSeconds(int seconds2Add);
      void addMinutes(int minutes2Add);
      // add hours and returns # of days of overflow
      void addHours(int hours2Add);
      // display as military time - default no seconds (hh:mm)
      void displayMilitaryTime(bool displaySeconds = false);
      // display the prompt and read data into the time object
      void promptForTime(string prompt, bool readSeconds = false);
      // add two time objects & return the resulting time object
      const Time operator + (const Time &time1) const;
      int adjustTime();
   
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

   protected:
      int hour;
      int minute;
      int second;
};


class Date:public Time
{
   public:
      Date();
      Date(int aDay, int aMonth, int aYear);   
      Date(int aDay, int aMonth, int aYear, int aHour, int aMin);
      bool isLeapYear();
      void setMonth(int aMonth);
      void setDay(int aDay);
      void setYear(int aYear);
      int getMonth() const   {return mMonth;}
      int getDay() const   {return mDay;}
      int getYear() const {return mYear;}
   void addSeconds(int seconds2Add); // redefined
   void addMinutes(int minutes2Add); // redefined
   void addHours(int hours2Add); // redefined
      void addDays(int aDay);
      void addMonth(int aMonth);
      void addYear(int aYear);
      void addTime(int aDay, int aMonth, int aYear);
      int getDaysInMonth(int aMonth);
      void adjustDateTime();
      void displayDateAndTime();
      void displayLDSDateAndTime();
      void promptForDate(string prompt);
   



   private:
      int mDay;
      int mMonth;
      int mYear;
      
};

int getInt(string prompt, string errMsg = "\nValue must be an integer!\n");

/***********************************************************************
 * Program Main for Assignment #8 - Date Class:
 *
 *****************************************************************************/
int main()
{
   int hours;
   int days;
   int minutes;
   int theMonth;
   int theDay;
   int theYear;
   
   cout << "Creating a Date object" << endl;
   Date myDate;
   
   myDate.displayDateAndTime();
   cout << endl;

   cout << "\nModify the first Date object" << endl;
   myDate.promptForDate("Enter date (mm/dd/yyyy): ");
   myDate.promptForTime("Enter time (hh:mm): ");
   myDate.displayDateAndTime();
   cout << endl;

   cout << "\nAdd time to the first Date object" << endl;
   days =  getInt("Enter days to add: ");
   myDate.addDays(days);
   myDate.displayDateAndTime();
   cout << endl;
   hours  = getInt("Enter hours to add: ");
   myDate.addHours(hours);
   myDate.displayDateAndTime();
   cout << endl;
   minutes = getInt("Enter minutes to add: ");
   myDate.addMinutes(minutes);
   myDate.displayDateAndTime();
   cout << endl;
      
   cout << "\nCreate a second Date object" << endl;
   theMonth = getInt("Enter the Month (1-12): ");
   theDay = getInt("Enter the Day (1-31): ");
   theYear = getInt("Enter the Year: ");
   Date myDate2(theMonth, theDay, theYear);
   myDate2.displayDateAndTime();
   cout << endl;
   
   cout << "\nA default third Date object is automatically created.\n";
   Date myDate3(1,1,2005,8,0);
   myDate3.displayDateAndTime();

   cout << endl;
   cout << "\nReplace the default third Date object\n";
   myDate3.promptForDate("Enter the new date (mm/dd/yyyy): ");
   myDate3.promptForTime("Enter the new time (hh:mm): ");
   myDate3.displayDateAndTime();
   cout << endl;
   cout << "\nAdd time to the third Date object" << endl;
   days =  getInt("Enter days to add: ");
   hours  = getInt("Enter hours to add: ");
   minutes = getInt("Enter minutes to add: ");
   cout << "\nThird Date before: ";
   myDate3.displayLDSDateAndTime();
   myDate3.addTime(days,hours,minutes);
   cout << "\nThird Date after:  ";
   myDate3.displayLDSDateAndTime();
   cout << endl;

   cout << "\nSet new date and time for third Date object" << endl;
   int inputYear = getInt("Change Year: ");
   myDate3.setYear(inputYear);
   int inputMonth = getInt("Change Month: ");
   myDate3.setMonth(inputMonth);
   int inputDay = getInt("Change Day: ");
   myDate3.setDay(inputDay);
   int inputHour = getInt("Change Hour: ");
   myDate3.setHour(inputHour);
   int inputMin = getInt("Change Minute: ");
   myDate3.setMinute(inputMin);
   myDate3.displayLDSDateAndTime();
   cout << endl;
   cout << "\nThe three Date objects";
   cout << "\n----------------------\n";
   myDate.displayLDSDateAndTime();
   cout << endl;
   myDate2.displayLDSDateAndTime();
   cout << endl;
   myDate3.displayLDSDateAndTime();
   cout << endl;
                
   return 0;
}

/*****************************************************************************
 * Summary: Default constructor of a Time object. All private variables set to
 * zero.
 *****************************************************************************/
Time::Time()
      :hour(0), minute(0), second(0)
{/*Body intentionally empty*/}

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
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
int Time::adjustTime()
{
   int dayOverflow = 0;
   if (second > 59)
   {
      minute += second / 60;
      second %= 60;
   }
   if (minute > 59)
   {
      hour += minute / 60;
      minute %= 60;
   }
   if (hour > 23)
   {
      dayOverflow = hour / 24;
      hour %= 24;
   }
   return dayOverflow;
}

/*****************************************************************************
 * Summary: adds to the second variable of a Time object. Accounts for possible
 * rollover.
 *****************************************************************************/
void Time::addSeconds(int seconds2Add)
{
   if (seconds2Add < 0)
      cerr << "\nError adding seconds. Cannot add negative seconds";

   else 
      second += seconds2Add;

   if (second > 59)
      adjustTime();
}

/*****************************************************************************
 * Summary: adds to the minute variable of a Time object. Accounts for possible
 * rollover.
 *****************************************************************************/
void Time::addMinutes(int minutes2Add)
{
   if (minutes2Add < 0)
      cerr << "\nError adding minutes. Cannot add negative minutes";

   else 
      minute += minutes2Add;
   
   if (minute > 59)
      adjustTime();
}

/*****************************************************************************
 * Summary: adds to the hour variable of a Time object. If the sum is 24 or
 * more, it will keep track of how many days it overflowed and return it.
 *****************************************************************************/
void Time::addHours(int hours2Add)
{
   int dayOverflow = 0;
   if (hours2Add < 0)
      cerr << "\nError adding hours. Cannot add negative hours";
   else 
      hour += hours2Add;
   
   if (hour > 23)
   {
      adjustTime();
   }
      
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
 ****************************************************************************/ ostream& operator << (ostream &out, const Time &time1)
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

/*****************************************************************************
 * Summary: Default constructor for Date class. Private variables assigned to
 * zero. Calls default constructor of Time class, which assigns its inherited
 * variables to zero as well.
 *****************************************************************************/
Date::Date()
      :mMonth(0), mDay(0), mYear(0), Time()
{/*Body intentionally empty*/}
   


 /*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
Date::Date(int aMonth, int aDay, int aYear)
      :Time()
{
   setYear(aYear);
   setMonth(aMonth);
   setDay(aDay);
}

 /*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
Date::Date(int aDay, int aMonth, int aYear, int aHour, int aMin)
{
   setYear(aYear);
   setMonth(aMonth);
   setDay(aDay);
   setHour(aHour);
   setMinute(aMin);
}

 /*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::setMonth(int aMonth)
{
   if (aMonth > 0 && aMonth < 13)
      mMonth = aMonth;
   else
   {
      cerr << "\nInvalid month assignment. Terminating program.\n";
      exit(1);
   }
}

 /*****************************************************************************
  * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date:: setDay(int aDay)
{
   bool badDate = false;
   if (aDay <= 0 || aDay > 31)
   {
      cerr << "Invalid day assignment. Terminating program.\n";
      exit(1);
   }
   if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11)
   {
      if (aDay == 31)
         badDate = true;
   }

   if  (mMonth == 2)
   {
      if (isLeapYear())
      {
         if (aDay > 29)
            badDate = true;
      }
      else
      {
         if (aDay > 28)
            badDate = true;
      }
   }

   if (!badDate)
      mDay = aDay;
   else
   {
      cerr << "Invalid day assignment. Terminating program\n";
      exit(1);
   }
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::setYear(int aYear)
{
   if (aYear < 0 || aYear > 9999)
   {
      cerr << "Invalid year assignment. Terminating program\n";
      exit(1);
   }
   else
      mYear = aYear;
}






/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
bool Date::isLeapYear()
{
   bool isLeapYr = false;

   if (mYear % 4 == 0)
   {
      isLeapYr = true;
      if (mYear % 100 == 0)
      {
         if (mYear % 400 == 0)
            isLeapYr = true;
         else
            isLeapYr = false;
      }
   }
   
   return isLeapYr;
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::displayDateAndTime()
{
   if (mMonth < 10)
      cout << setw(2) << setfill('0') << mMonth;
   else
      cout << mMonth;

   cout << '/';

   if (mDay < 10)
      cout << setw(2) << setfill('0') << mDay;
   else
      cout << mDay;

   cout << '/' << setw(4) << setfill('0') << mYear << " ";

   displayMilitaryTime();
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
int Date::getDaysInMonth(int aMonth)
{
   int daysInMonth;
   int tempMonth = mMonth;

   if (tempMonth > 12)
      tempMonth = tempMonth % 12;
   
   if (tempMonth == 0)
      tempMonth = 12;   
   
   if (tempMonth == 4 || tempMonth == 6 || tempMonth == 9 || tempMonth == 11)
   {
      daysInMonth = 30;
   }

   else if  (tempMonth == 2)
   {
      if (isLeapYear())
      {
         daysInMonth = 29;
      }
      else
      {
         daysInMonth = 28;
      }
   }

   else
   {
      daysInMonth = 31;
   }

   return daysInMonth;
}

/*****************************************************************************
 * Summary: adds to the minute variable of a Time object. Accounts for possible
 * rollover.
 *****************************************************************************/
void Date::addSeconds(int seconds2Add)
{
   if (seconds2Add < 0)
      cerr << "\nError adding seconds. Cannot add negative seconds";

   else 
      second += seconds2Add;

   if (getSecond() > 59)
      adjustDateTime();
}

/*****************************************************************************
 * Summary: adds to the minute variable of a Time object. Accounts for possible
 * rollover.
 *****************************************************************************/
void Date::addMinutes(int minutes2Add)
{
   if (minutes2Add < 0)
      cerr << "\nError adding minutes. Cannot add negative minutes";

   else
      minute += minutes2Add;
   
   if (minute > 59)
      adjustDateTime();
}

/*****************************************************************************
 * Summary: adds to the hour variable of a Time object. If the sum is 24 or
 * more, it will keep track of how many days it overflowed and return it.
 *****************************************************************************/
void Date::addHours(int hours2Add)
{
   if (hours2Add < 0)
      cerr << "\nError adding hours. Cannot add negative hours";
   else
      hour += hours2Add;

   if (hour > 23)
      adjustDateTime();      
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::addTime(int aDay, int aMonth, int aYear)
{
   mDay += aDay;
   mMonth += aMonth;
   mYear += aYear;

   adjustDateTime();
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::adjustDateTime()
{
   mDay += Time::adjustTime();

   if (mMonth > 12)
   {
      mYear += mMonth / 12;
      mMonth %= 12;
   
      if (mMonth == 0)
         mMonth = 12;
   }
   
   while (mDay > getDaysInMonth(mMonth))
   {
      mDay -= getDaysInMonth(mMonth);
      mMonth += 1;
      if (mMonth > 12)
      {
         mYear += 1;
         mMonth = 1;
      }    
   }
        
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::addDays(int aDay)
{
   if (aDay < 0)
   {
      cerr << "Day to add must be positive\n";
   }

   else
   {
      mDay += aDay;
      if (mDay > getDaysInMonth(mMonth))
      {
         adjustDateTime();
      }
   }
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::addMonth(int aMonth)
{
   if (aMonth < 0)
   {
      cerr << "Month to add must be positive.\n";
   }

   else
   {
      mMonth += aMonth;
      if (mMonth > 12)
      {
         adjustDateTime();
      }
   }
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::addYear(int aYear)
{
   if (aYear < 0)
   {
      cerr << "Year to add must be positive.\n";
   }

   else
   {
      mYear += aYear;
   }
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::promptForDate(string prompt)
{
   int day, month, year;
   char slash1, slash2;
   
   
   while (true)
   {
      cout << prompt << endl;
      cin >> month >> slash1 >> day >> slash2 >> year;

      if (!cin.fail())
      {
         if (month <=  12 || month >= 1)
         {
            if (day <= getDaysInMonth(month) || day > 0)
            {
               if (slash1 == '/' && slash2 == '/')
               {
                  break;
               }
            }
         }
      }

      else
      {
         cin.clear();
         cin.ignore(80,'\n');
         cerr << "Invalid Date\n";
      }
   }

   mMonth = month;
   mDay = day;
   mYear = year;
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Time class. Does
 * proper formatting.
 *****************************************************************************/
void Date::displayLDSDateAndTime()
{
   string month;

   switch(mMonth)
   {
      case 1:
         month = "Jan";
         break;
         
      case 2:
         month = "Feb";
         break;

      case 3:
         month = "Mar";
         break;

      case 4:
         month = "Apr";
         break;

      case 5:
         month = "May";
         break;

      case 6:
         month = "Jun";
         break;

      case 7:
         month = "Jul";
         break;

      case 8:
         month = "Aug";
         break;

      case 9:
         month = "Sep";
         break;

      case 10:
         month = "Oct";
         break;

      case 11:
         month = "Nov";
         break;

      case 12:
         month = "Dec";
         break;
   }
         
   cout << setw(2) << setfill('0') << mDay;
   cout << " " << month << " " << mYear;
   displayMilitaryTime();
}

   
   
      

      
         
      
      
