/***********************************************************************
* Program:
*    Assignment 07, Team Class  
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte
* Summary: 
*   This program creates 4 Team objects and prompts the user to input the team
* and coach information. It then displays a team report of all 4 objects, which
* includes the team name, team seed, and all the coach information in address-
* label format.
************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Contact
{
public:
   Contact();
   Contact(string name, string address, string city, string state, string zip,
           string phone);
   // get and set functions are inline
   string getName() const            {return mName;}
   string getAddress() const         {return mAddress;}
   string getCity() const            {return mCity;}
   string getState() const           {return mState;}
   string getZip() const             {return mZip;}
   string getPhone() const           {return mPhone;}
   void setName(string name)         {mName = name;}
   void setAddress(string address)   {mAddress = address;}
   void setCity(string city)         {mCity = city;}
   void setState(string state)       {mState = state;}
   void setZip(string zip)           {mZip = zip;}
   void setPhone(string phone)       {mPhone = phone;}
   void promptForContactInfo();
   void displayContactInfo() const;
private:
   string mName;
   string mAddress;
   string mCity;
   string mState;
   string mZip;
   string mPhone;
};

class Team
{
public:
   Team();
   string getName() const                    {return mName;}
   string getDescription() const             {return mDescription;}
   string getSeed() const                    {return mSeed;}
   void setName(string name)                 {mName = name;}
   void setDescription(string description)   {mDescription = description;}
   void setSeed(string seed)                 {mSeed = seed;}
   void promptForTeamInfo(int &count);
   void displayTeamInfo() const;
private:
   string mName;
   string mDescription;
   string mSeed;
   Contact mCoach;
};

/**********************************************************************
 * main description - creates an array of NUM_TEAMS length and a counter called
 * teamCount. promptForTeamInfo, a member function of the Team class, is called
 * for each object in the array with the argument teamCount. This makes it so
 * that the prompt properly displays the team number the user is inputting for.
 * Once all the objects have been filled with data, a team report is displayed
 * using a for loop to call each objects displayTeamInfo function.
 ***********************************************************************/
int main()
{
   const int NUM_TEAMS = 4;
   int teamCount = 1;
   Team teamList[NUM_TEAMS];

   for (int i = 0; i < NUM_TEAMS; i++)
   {
      teamList[i].promptForTeamInfo(teamCount);
      teamCount++;
   }

   cout << "\nTeams Report" << endl
        << "------------\n";

   for (int i = 0; i < NUM_TEAMS; i++)
   {
      teamList[i].displayTeamInfo();
   }
   
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
      :mName(name), mAddress(address), mCity(city), mState(state), mZip(zip),
       mPhone(phone)
{/*Body intentionally empty*/}

/**************************************************************************
 * displayContactInfo - displays to the screen the name, address, city, state,
 * zip code, and phone number. Essentially displays all the private variables
 * of a Contact object in address label format.
 *************************************************************************/
void Contact::displayContactInfo() const
{
   cout << "\n"
        << "     " << mName << "\n"
        << "     " << mAddress << "\n"
        << "     " << mCity << ", " << mState << "  " << mZip << "\n"
        << "     " << mPhone << "\n\n";
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

/***************************************************************************
 * Default constructor - private string variables assigned to null, Contact
 * variable mCoach uses its own default constructor.
 ***************************************************************************/
Team::Team()
     :mName(""), mSeed(""), mDescription("")
{/*Body intentionally empty*/}

/*****************************************************************************
 * promptForTeamInfo - prompts the user to input the team name, team seed, and
 * team description, followed by a call to mCoach's promptForContactInfo
 * function, which includes his name, address, city, state, zip code, and
 * phone number. An int counter is passed by reference so main can keep a count
 * when inputting multiple team info.
 **************************************************************************/
void Team::promptForTeamInfo(int &count)
{
   cout << "\nTeam #" << count << " Information\n";
   
   cout << "\nTeam Name: ";
   getline(cin, mName);

   cout << "Team Seed: ";
   getline(cin, mSeed);
   
   cout << "Team Desc: ";
   getline(cin, mDescription);

   cout << "\nTeam #" << count << " Coach\n";
   mCoach.promptForContactInfo();
   
}

/**************************************************************************
 * displayTeamInfo - displays to the screen the team name, seed, and the
 * mCoach info, which includes the name, address, city, state, zip, and phone
 * number in address label format. The mCoach info is called by the Contact
 * class's  member function called showContactInfo.
 *************************************************************************/
void Team::displayTeamInfo() const
{
   cout << mName << " " << "(" << mSeed << ")\n";
   mCoach.displayContactInfo();
}
   
