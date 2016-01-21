/***********************************************************************
* Program:
*    Assignment 06, OO Address Book  
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte
* Summary: 
*    This program prompts uses to fill out their contact information. It then
* populates another Contact object through "setter" functions. Then it
* populates an array of 5 contact objects by reading the information from a
* file. It then displays the information of all 7 Contact objects.
************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

/*************************************************************************
 * Contact - Consists of 6 private variables, appropriate getter and
 * setter funcitons, a prompt function, and a display function. Has a default
 * and secondary constructor.
 ***********************************************************************/
class Contact
{
public:
   Contact();
   Contact(string name, string address, string city, string state, string zip,
           string phone);
   // get and set functions are inline
   string getName()  const  { return mName; }
   string getAddress()  const  { return mAddress; }
   string getCity()  const  { return mCity; }
   string getState()   const { return mState; }
   string getZip()  const { return mZip; }
   string getPhone()  const { return mPhone; }
   void setName(string name)   {mName = name;}
   void setAddress(string address)   {mAddress = address;}
   void setCity(string city)   {mCity = city;}
   void setState(string state)   {mState = state;}
   void setZip(string zip)   {mZip = zip;}
   void setPhone(string phone)   {mPhone = phone;}
   void promptForContactInfo();
   void showContactInfo();
private:
   string mName;
   string mAddress;
   string mCity;
   string mState;
   string mZip;
   string mPhone;
};

/**********************************************************************
 * main description
 * Variables are declared, including 2 unique Contact objects and an array
 * of 5 more Contact objects. prof is populated through its setter function.
 * me is populated through the promptForContactInfo memeber function. list
 * is populated by reading in from contactlist.txt. The showContactInfo
 * function is then called for all 7 Contact objects.
 ***********************************************************************/
int main()
{
   string name;
   string address;
   string city;
   string state;
   string zip;
   string phone;
   ifstream inFile;
   Contact prof;
   Contact me;
   Contact list[5];

   prof.setName("Brother Ercanbrack");
   prof.setAddress("AUS 217");
   prof.setCity("Rexburg");
   prof.setState("ID");
   prof.setZip("83460");
   prof.setPhone("496-7606");

   me.promptForContactInfo();
   
   // Open file. Exit program if fail to open
   inFile.open("/home/ercanbracks/cs165-examples/assign06/contactlist.txt");
   if (inFile.fail())
   {
      cout << "\nFile not found";
      exit(1);
   }
   //populate list array through temp object
   for (int i = 0; i < 5; i++)
   {
      getline(inFile, name);
      getline(inFile, address);
      getline(inFile, city);
      getline(inFile, state);
      getline(inFile, zip);
      getline(inFile, phone);

      Contact temp(name, address, city, state, zip, phone);
      list[i] = temp;
   }
   
   // display info for all objects
   prof.showContactInfo();
   me.showContactInfo();
   for (int i = 0; i < 5; i++)
      list[i].showContactInfo();

   inFile.close();
      
   return 0;
}

/***************************************************************************
 * Default constructor - private variables initialized to the null string.
 ***************************************************************************/
Contact::Contact()
 :mName(""), mAddress(""), mCity(""), mState(""), mZip(""),
   mPhone("")
{/*Body intentionally empty*/}

/***************************************************************************
 * Secondary constructor - takes 6 string arguments for assignment to private
 * variables.
 **************************************************************************/
Contact::Contact(string name, string address, string city, string state,
                 string zip, string phone)
{
   mName = name;
   mAddress = address;
   mCity = city;
   mState = state;
   mZip = zip;
   mPhone = phone;
}
/**************************************************************************
 * showContactInfo - displays to the screen the name, address, city, state,
 * zip code, and phone number. Essentially displays all the private variables
 * of a Contact object in address label format.
 *************************************************************************/
void Contact::showContactInfo()
{
   cout << "\n"
        << "     " << mName << "\n"
        << "     " << mAddress << "\n"
        << "     " << mCity << ", " << mState << "  " << mZip << "\n"
        << "     " << mPhone << "\n";
}
/*****************************************************************************
 * promptForContactInfo - prompts the user to input their name, address, city,
 * state, zip code, and phone number. Assigns input to the private variables of
 * a Contact object.
 **************************************************************************/
void Contact::promptForContactInfo()
{
  
   cout << "\nName: ";
   getline(cin, mName);
   
   cout << "Address: ";
   getline(cin, mAddress);
   
   cout << "City: ";
   getline(cin, mCity);
   
   cout << "State: ";
   getline(cin, mState);
   
   cout << "Zip: ";
   getline(cin, mZip);
   
   cout << "Phone: ";
   getline(cin, mPhone);
}
