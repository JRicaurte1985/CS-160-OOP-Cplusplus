/***********************************************************************
* Program: 
*    Assignment 02, Mortgage Monthly Payment and Amortization Calculator  
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte
* Summary:
* This program asks the user to input three values: a loan amount,
* the annual interest rate, and the loan term (in years). It then calculates
* the monthly payment and displays it, along with the three aforementioned
* user inputs . A prompt then asks the user if they want to see the
* amortization chart, expecting a user input of 'y' for yes and 'n' for no.
* Any other input besides 'y' or 'n' is invalid and results in a re-prompt. If
* the user inputs 'y', the program displays the amortization chart. The
* amortization chart consists of six columns: Payment number, Principal,
* Interest, Cumulative Principal, Cumulative Interest, and Principal balance
* remaining. The user may choose not to view the amortization chart. After the
* amortization chart has been viewed or denied by the user, he is then
* prompted to choose if he wants to continue using the program, or exit.    
************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// These are the maximum values that the program will accept for loan, apr,
//and terms
const int MAX_LOAN = 20000000;
const int MAX_APR = 20;
const int MAX_TERM = 30;


double getLoanAmt();
double getAPR();
int getLoanTerm ();
double calculateMonthlyPayment(double loan, double annualInterestRate,
                               int loanTerm);
void showReportHeader(double loan, double annualInterestRate, int loanTerm,
                      double monthlyPayment);
void showAmortizationChart(double loan, double annualInterestRate,
                           int loanTerm,double monthlyPayment);

/*************************************************************************
 * main- Necessary variables are declared. loanAmt, annualInterestRate,
 * loanTerm, and monthlyPayment all serve to store important values needed
 * by later functions. Two strings are declared for input tests. A bool
 * is declared for use at the end of a do loop. main calls three
 * 'get' functions which serve to ask the user for input and stores these
 * in the aforementioned variables, namely loanAmt, annualInterestRate, and
 * loanTerm. main then passes these three values as arguments in the
 * calculateMonthlyPayment function. calculateMonthlyPayment returns the
 * the correct monthly payment using a formula, and this is assigned to the
 * variable monthlyPayment. Finally, showReportHeader displayed these 4
 * acquired values on the screen.
 * Then there are two while loops that serve the purpose of error-proofing
 * the following user input. First, a prompt that asks the user if they want
 * to see the amortization chart. Inside the first while loop exists 3
 * possibilities of input: 'y', 'n', and anything else. 'y' will run the
 * showAmortizationChart function and then break the loop. 'n' will break the
 * loop without running the showAmortizationChart function. Anything else is
 * is treated as invalid input and causes the while loop to restart.
 * The second while loop is alike, except this time the user is asked if they
 * want to continue using the program. 'y' will set restart, a boolean
 * variable to true. 'n' sets it to false. Anything else is treated as invalid
 * input and causes the while loop to restart.
 * After both while loops handled the user input, the do loop tests to see if
 * restart is true or false. If true, essentially all of main repeats. If false
 * the program will terminate
 **************************************************************************/
int main()
{  
   double loanAmt;
   double annualInterestRate;
   int loanTerm;
   double monthlyPayment;
   
   string amortizationDecision;
   string restartDecision;
   bool restart;
   
   do
   {
      loanAmt = getLoanAmt();
      annualInterestRate = getAPR();
      loanTerm = getLoanTerm();

      monthlyPayment = calculateMonthlyPayment(loanAmt, annualInterestRate,
                                               loanTerm);
      showReportHeader(loanAmt, annualInterestRate, loanTerm, monthlyPayment);
      // The following while loop test for either a 'y' or 'n' input.
      // Anything else is treated as invalid input and restarts the loop.
      while (true)
      {
         cout << "\n\nDo you want to see the Amortization chart?(y/n): ";
         cin >> amortizationDecision;
      
         if (amortizationDecision.size() == 1 &&
             amortizationDecision[0] == 'y')
         {
            showAmortizationChart(loanAmt, annualInterestRate, loanTerm,
                                  monthlyPayment);
            break;
         }

         if (amortizationDecision.size() == 1 &&
             amortizationDecision[0] == 'n')
            break;
         
         else
         {
            cout << "\nInvalid input";
            cin.clear();
            cin.ignore(80,'\n');
         }
      }
      //Like the while loop above it, this tests for either a 'y' or 'n' input
      //Anything else is invalid input and while loop restarts.
      while (true)
      {
         cout << "\nDo you want to continue? (y/n): ";
         cin >> restartDecision;

         if (restartDecision.size() == 1 && restartDecision[0] == 'y')
         {
            restart = true;
            break;
         }

         if (restartDecision.size() == 1 && restartDecision[0] == 'n')
         {
            restart = false;
            break;
         }

         else
         {
            cout << "\nInvalid input";
            cin.clear();
            cin.ignore(80,'\n');
         }
      }
      
   }while (restart == true);

   return 0;
}
      
/**************************************************************************
*getLoanAmt - A function of type double that asks the user for the loan
*amount, stores it in loanAmt, then returns loanAmt. A while loop tests for
*proper input. A test is included to make sure the user does not input a
*value that exceeds tha maximum loan amout defined by the global constant
*MAX_LOAN.
****************************************************************************/


double getLoanAmt()
{
   double loanAmt;
   while (true)
   {
      cout << "\nPlease enter loan amount: ";
      cin >> loanAmt;

      if (loanAmt > MAX_LOAN)
         cout << "\nMaximum loan limit exceeded\n";

      else if (cin.fail())
      {
         cin.clear();
         cin.ignore(80,'\n');
         cout << "\nInvalid Input\n";
      }
      else
         break;
   }
      
   return loanAmt;
}

/**************************************************************************
*getAPR - A function of type double that asks the user for the annual
*interest rate, stores it in annualInterestRate, then returns
*annualInterestRate. A while loop tests for proper input. A test is included
*to make sure the user does not input a value that exceeds the maximum APR
*amount defined by the global constant MAX_APR.
***************************************************************************/
double getAPR()
{
   double annualInterestRate;

   while (true)
   {
      cout << "\nPlease enter Annual Interest Rate: ";
      cin >> annualInterestRate;

      if (annualInterestRate > MAX_APR)
         cout << "\nMaximum Interest Rate exceeded\n";

      else if (cin.fail())
      {
         cin.clear();
         cin.ignore(80,'\n');
         cout << "\nInvalid Input\n";
      }

      else
         break;
   }

   return annualInterestRate;
}

/**************************************************************************
*getLoanTerm - A simple function of type int that asks the user for the loan
*term, stores it in the int loanTerm, then returns loanTerm.
*A while loop tests for proper input. A test is included to make sure the
*user does not input a value that exceeds the maximum loan term defined by
*the global constant MAX_TERM.
***************************************************************************/

int getLoanTerm()
{
   int loanTerm;

   while (true)
   {
      cout << "\nPlease enter Loan term (in years): ";
      cin >> loanTerm;

      if (loanTerm > MAX_TERM)
         cout << "\nMaximum loan term exceeded\n";

      else if (cin.fail())
      {
         cin.clear();
         cin.ignore(80,'\n');
         cout << "\nInvalid Input\n";
      }

      else
         break;
   }

   return loanTerm;
}

/**************************************************************************
*calculateMonthlyPayment - A function of type double that takes three
*arguments: loan, annualInterestRate, and loanTerm. It uses a mathematical
*formula to calculate the monthly payment. A double variable called
*monthlyPayment is declared and assigned the result of this formula. It is
*then returned.
***************************************************************************/

double calculateMonthlyPayment (double loan, double annualInterestRate,
                                int loanTerm)
{
   double monthlyPayment;

   /* We will now assign all the arguments to variables of the same type, only
      with single letter variable names. This is so that the formula used to
      calculate the monthly payment is more understandable.*/

   double l = loan;
   // multiply loanTerm by 12 to convert from years to months.
   int n = loanTerm * 12;
   /* divide annual interest rate by 100 to get to decimal format, then divide
      by 12 to get monthly rate.*/
   double c = annualInterestRate / 1200;
   // use formula for monthly payment and assign to monthlyPayment.
   monthlyPayment =   l * (c * pow(1 + c, n)) / ((pow(1 + c,n) - 1));

   return monthlyPayment;
}

/**************************************************************************
*showReportHeader - a simple void function that takes four arguments and
*then displays them on the screen. The four values are: loan amount,
*annual interest rate, loan term, and monthly payment.
***************************************************************************/

void showReportHeader(double loan, double annualInterestRate, int loanTerm,
                      double monthlyPayment)
{
   cout << setprecision(0) << fixed << "\nLoan Amount = " << loan
        << setprecision(2) << fixed << "\nAnnual Interest Rate = "
        << annualInterestRate
        << "\nLoan Term = " << loanTerm << " years"
        << "\n\nMonthly Payment is " << monthlyPayment;
}

/**************************************************************************
*showAmortizationChart - a void funciton whose main purpose is to display
*an amortization chart. Takes four arguments: loan, annualInterestRate,
*loanTerm, and monthlyPayment. Local variables are declared in order to
*facilitate the creation of the chart. annualInterestRate is divided by 1200
*(first divide by 100 to get decimal form, then by 12 to get monthly
*interest) and assigned to monthlyInterest. loanTerm is multiplied by 12
*to get the term in months. The amortization chart consists of six columns:
*payment number, principal, interest, cumulative principle, cumulative
*interest, and remaining principal balance. Local variables are created
*for each column to simplify the understanding of the code and mathematics.
*Further explanation of the math is in the code itself. Proper display
*is used and the amortization chart is displayed.
****************************************************************************/

void showAmortizationChart(double loan, double annualInterestRate,
                           int loanTerm,double monthlyPayment)
{
   double monthlyInterest = annualInterestRate / 1200;
   int loanTermMonths = loanTerm * 12;
   
   int paymentNumber = 0;
   double toPrincipal;
   double toInterest;
   double cumPrin = 0;
   double cumInt = 0;
   double prinBal = loan;
   
   cout << "\n\nPmt" << setw(13) << "Principal" << setw(13) << "Interest"
        << setw(14) << "Cum Prin" << setw(14) << "Cum Int" << setw(16)
        << " Prin Bal";
   cout << "\n----" << setw(12) << "---------" << setw(13) << "--------"
        << setw(15) << "---------" << setw(14) << "--------" << setw(16)
        << "---------\n";
   /*This for loop uses the loan term in months to determine how many times it
   will run, thus producing the correct number of loan payments. The code
   inside the for loop produces the remaining data needed to display the
   amortization chart*/
   for (int i = 0; i < loanTermMonths; i++)
   {
      /*We start by knowing only the monthly payment,loan amount, monthly
        interest, and the term in months.
        First we can obtain the amount of the monthly payment that goes
        to interest by the formula (prinBal * monthlyInterest). Next we can
        subtract that amount from the monthly payment to know how much of
        the monthly payment goes to principal. Cumulative tallies of principal
        and interest can be kept by adding the previous months cumulative
        amount to the current months principal/interest. Finally, the
        remaining principal balance can be obtained by subtracting the current
        month's principal from the previous month's remaining principal
        balance.
      */
      paymentNumber++;
      toPrincipal = monthlyPayment - (prinBal * monthlyInterest);
      toInterest = prinBal * monthlyInterest;
      cumPrin = toPrincipal + cumPrin;
      cumInt = toInterest + cumInt;
      prinBal = prinBal - toPrincipal;
         
      cout << setw(3) << paymentNumber << setw(13) << setprecision(2) << fixed 
           << toPrincipal << setw(13) << toInterest << setw(15)
           << cumPrin << setw(14) << cumInt << setw(15) << prinBal
           << "\n";
   }

   cout << "\n";
      
   
}
   
