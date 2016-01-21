/***********************************************************************
* Program:
*    Assignment 11 Bank Program  
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte
* Summary: 
* This program processes various bank transactions. The transaction list is
* read from a file and the appropriate objects are created and updated.
* A parent Account class allows three derived classes to be created. The
* derived classes are used appropriately.
************************************************************************/

#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Account
{
public:
   Account(int aActNum, string aName);
   Account(int aActNum, string aName, double aBalance);
   string getName() const             {return mName;}
   int getActNum() const           {return mActNum;}
   double getBalance() const          {return mBalance;}
   void setName(string aName)         {mName = aName;}
   void setActNum(int aActNum)     {mActNum = aActNum;}
   void setBalance(double aBalance)   {mBalance = aBalance;}
   virtual void transaction(double modification) = 0;
   virtual void update() = 0;  
   virtual void  printBalanceInfo(ostream &out) const = 0;
   
private:
   string mName;
   int mActNum;
   double mBalance;
};


class Savings:public Account
{
public:
   Savings(int aActNum, string aName);
   Savings(int aActNum, string aName, double aBalance, double aIntRate);
   double getIntRate() const   {return mIntRate;}
   void setIntRate(double aIntRate)   {mIntRate = aIntRate;}
   virtual void transaction(double modification);
   virtual void update();
   virtual void printBalanceInfo(ostream &out) const;

private:
   double mIntRate;
};


class Checking:public Account
{
public:
   Checking(int aActNum, string aName);
   Checking(int aActNum, string aName, double aBalance, double aCheckFee);
   double getCheckFee() const   {return mCheckFee;}
   int getNumChecks() const   {return mNumChecks;}
   double getBounceFee() const   {return mBounceFee;}
   double getCheckFeeTotal() const   {return mNumChecks * mCheckFee;}
   void setCheckFee(double aCheckFee)   {mCheckFee = aCheckFee;}
   void setNumChecks(int aNumChecks)   {mNumChecks = aNumChecks;}
   void setBounceFee(double aBounceFee)   {mBounceFee = aBounceFee;}
   void addCheck()   {mNumChecks++;}
   virtual void transaction(double modification);
   virtual void update();
   virtual void printBalanceInfo(ostream &out) const; 
private:
   double mBounceFee;
   double mCheckFee;
   int mNumChecks;
};
   

class Loan:public Account
{
public:
   Loan(int aActNum, string aName);
   Loan(int aActNum, string aName, double aBalance, double aIntRate);
   double getIntRate() const   {return mIntRate;}
   void setIntRate(double aIntRate)   {mIntRate = aIntRate;}
   virtual void transaction(double modification);
   virtual void update();
   virtual void printBalanceInfo(ostream &out) const;

private:
   double mIntRate;
};

ostream& operator << (ostream &out, const Account &acc1);

/**********************************************************************
 * main description - Main begins by opening a bank.txt file and then reads in
 * instructions. The file provides the instructions for what transactions and
 * updates to perform. When complete, the file is closed.
 * 
 ***********************************************************************/
int main()
{
   ifstream fin;
   string fileName = "/home/ercanbracks/cs165-examples/assign11-bank/bank.txt";
   char action;
   string name;
   double balance;
   int actNum;
   double intRate;
   double checkFee;
   double mod;
   Account *client[10];

   fin.open(fileName.c_str());
   if (fin.fail())
   {
      cout << "\n" << fileName << " NOT FOUND";
      return 0;
   }
   
   while (fin >> action)
   {
      if (action == 's')
      {
         fin >> actNum >> name >> balance >> intRate;
         client[actNum] = new Savings(actNum, name, balance, intRate);
         cout << "new account...\n" << *client[actNum] << endl;
      }

      if (action == 'c')
      {
         fin >> actNum >> name >> balance >> checkFee;
         client[actNum] = new Checking(actNum, name, balance, checkFee);
         cout << "new account...\n" << *client[actNum] << endl;
      }

      if (action == 'l')
      {
         fin >> actNum >> name >> balance >> intRate;
         client[actNum] = new Loan(actNum, name, balance, intRate);
         cout << "new account...\n" << *client[actNum] << endl;
      }

      if (action == 't')
      {
         fin >> actNum >> mod;
         client[actNum]->transaction(mod);
         cout << *client[actNum] << endl;
      }

      if (action == 'u')
      {
         fin >> actNum;
         client[actNum]->update();
         cout << *client[actNum] << endl;
      }
   
   }

   fin.close(); 
   return 0;
}

/***************************************************************************
 * Primary constructor - actNum and aName must be given as arguments.
 * Balance defaults to zero.
 ***************************************************************************/
Account::Account(int aActNum, string aName)
      :mActNum(aActNum), mName(aName), mBalance(0)
{/*Body intentionally empty*/}

/***************************************************************************
 * Secondary constructor - Same as primary, except mBalance is assigned
 * aBalance.
 ***************************************************************************/
Account::Account(int aActNum, string aName, double aBalance)
      :mActNum(aActNum), mName(aName), mBalance(aBalance)
{/*Body intentionally empty*/}

/***************************************************************************
 * Primary constructor - calls Account primary constructor. mIntRate set to
 * zero.
 ***************************************************************************/
Savings::Savings(int aActNum, string aName)
      :Account(aActNum, aName), mIntRate(0)
{/*Body intentionally empty*/}

/***************************************************************************
 * Secondary constructor - Secondary Account constructor called. mIntRate is 
 * assigned aIntRate.
 ***************************************************************************/
Savings::Savings(int aActNum, string aName, double aBalance, double aIntRate)
      :Account(aActNum, aName, aBalance), mIntRate(aIntRate)
{/*Body intentionally empty*/}

/***************************************************************************
 * Primary constructor - Primary Account constructor called. mNumChecks set to 
 * zero. mBounceFee set to 25.
 ***************************************************************************/
Checking::Checking(int aActNum, string aName)
      :Account(aActNum, aName), mCheckFee(0), mNumChecks(0), mBounceFee(25)
{/*Body intentionally empty*/}

/***************************************************************************
 * Secondary constructor - Secondary Account constructor called. mCheckFee is
 * assigned aCheckFee. mNumChecks set to zero. mBounceFee set to 25.
 ***************************************************************************/
Checking::Checking(int aActNum, string aName, double aBalance,
                   double aCheckFee)
      :Account(aActNum, aName, aBalance), mCheckFee(aCheckFee), mNumChecks(0),
       mBounceFee(25)
{/*Body intentionally empty*/}

/***************************************************************************
 * Primary constructor - Primary Account constructor called. mIntRate set to
 * zero.
 ***************************************************************************/
Loan::Loan(int aActNum, string aName)
      :Account(aActNum, aName), mIntRate(0)
{/*Body intentionally empty*/}

/***************************************************************************
 * Secondary constructor - Secondary Account constructor called. mIntRate is
 * assigned aIntRate.
 ***************************************************************************/
Loan::Loan(int aActNum, string aName, double aBalance, double aIntRate)
      :Account(aActNum, aName, aBalance), mIntRate(aIntRate)
{/*Body intentionally empty*/}


/***************************************************************************
 * Savigns transaction - If the modification plus the balance results in a
 * negative balance, user will receive msg of "insufficient funds" and there is
 * no change to balance. Else, the modification is added to the balance.
 ***************************************************************************/
void Savings::transaction(double modification)
{
   cout << "transaction...\n";
   
   if ((getBalance() + modification) < 0)
      cout << "$" << modification << " rejected (insufficient funds)\n";
   else
   {
      setBalance(getBalance() + modification);
   
      cout << getName() << " (savings):  " << "$" << setprecision(2)
           << fixed << modification << " applied to account\n";
   }   
}

/***************************************************************************
 * Checking transaction - Keeps track of written checks. If a check is written
 * that would cause the balance to go negative, user gets msg and the bounce
 * fee is applied to the account. Deposits are handled appropriately.
 ***************************************************************************/
void Checking::transaction(double modification)
{
   cout << "transaction...\n";
   if (modification < 0)
      addCheck();
   
   if ((getBalance() + modification) < 0)
   {
      cout << getName() << " (checking):  " << "$" << modification
           << " rejected (insufficient funds)\n";
      cout << getName() << " (checking):  $-" << getBounceFee()
           << " applied to account\n";
      setBalance(getBalance() - getBounceFee());
      
   }
   else
   {  
      setBalance(getBalance() + modification);
   
      cout << getName() << " (checking):  " << "$" << setprecision(2)
           << fixed << modification << " applied to account\n";
   }
 
}

/***************************************************************************
 * Loan transaction - takes loan payments and computes into overall loan
 * balance.
 ***************************************************************************/
void Loan::transaction(double modification)
{
   setBalance(getBalance() - modification);
 
   cout << "transaction...\n" << getName() << " (loan):  "
        << "$" << setprecision(2) << fixed << modification
        << " applied to account\n";   
}

/***************************************************************************
 * Savings update - computes the interest on the current balance and adds it
 * to the balance. Displays update info to the user.
 ***************************************************************************/
void Savings::update()
{
   double interest = getBalance() * getIntRate();
   setBalance(getBalance()+ interest);
   
   cout << "update...\n" << getName() << " (savings):  "
        << "$" << setprecision(2) << fixed << interest
        << " applied to account\n";   
}

/***************************************************************************
 * Checking update - computes the check fees based on the number of checks
 * written thus far and subtracts from the balance. Resets the number of checks
 * written to zero. Displays update info to the user. 
 ***************************************************************************/
void Checking::update()
{
   setBalance(getBalance() - getCheckFeeTotal());
   
   cout << "update...\n" << getName() << " (checking):  "
        << "$-" << setprecision(2) << fixed << getCheckFeeTotal()
        << " applied to account\n";
   setNumChecks(0);
   
}

/***************************************************************************
 * Loan update - calculates the interest and adds it to the loan balance.
 * Displays the update info.
 ***************************************************************************/
void Loan::update()
{
   double interest = getBalance() * getIntRate();
   setBalance(getBalance() + interest);
   
   cout << "update...\n" << getName() << " (loan):  "
        << "$-" << setprecision(2) << fixed << interest
        << " applied to account\n";
}

/*****************************************************************************
 * Savings printBalanceInfo - writes the current balance information to the
 * output stream
 *****************************************************************************/
void Savings::printBalanceInfo(ostream &out) const
{
   out << getName() << " (savings):  balance is $" << setprecision(2)
        << fixed << getBalance() << endl;
}

/*****************************************************************************
 * Checking printBalanceInfo - writes the current balance information to the
 * output stream
 *****************************************************************************/
void Checking::printBalanceInfo(ostream &out) const
{
   out << getName() << " (checking):  balance is $"
        << setprecision(2) << fixed << getBalance() << endl;
}

/*****************************************************************************
 * Loan printBalanceInfo - writes the current balance information to the output
 * stream
 *****************************************************************************/
void Loan::printBalanceInfo(ostream &out) const
{
   out << getName() << " (loan):  balance is $-"
        << setprecision(2) << fixed << getBalance() << endl;
}

/*****************************************************************************
 * Summary: Overloads the insertion operator to handle the Account class. Calls
 * the Account's derived classes' printBalanceInfo function (virtual) because
 * it is abstract in the Account class.
 *****************************************************************************/
ostream& operator << (ostream &out, const Account &acc1)
{
   acc1.printBalanceInfo(out);
   return out;
}
