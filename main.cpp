#include <iostream>
#include "savings.h"
using namespace std;

int main()
{
    while (1)
    {
        //displays the initial screen and shows what kind of data the program needs from the user
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: " << endl;
        cout << "Monthly Deposit: " << endl;
        cout << "Annual Interest: " << endl;
        cout << "Number of years: " << endl;

        //pauses so user can review
        system("pause");
        cout << endl;

        //Get the inputs from user
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: $";
        double investment, monthlydeposit, interestrate;
        int years;
        cin >> investment;
        cout << "Monthly Deposit: $";
        cin >> monthlydeposit;
        cout << "Annual Interest: %";
        cin >> interestrate;
        cout << "Number of years: ";
        cin >> years;

        //pauses so user can review input data
        system("pause");

        //creates a savings sheet with the inputs from the user
        savings mysavings = savings(investment, monthlydeposit, interestrate, years);
        cout << endl;
        //calls the savings report methods with no monthly deposit
        mysavings.reportNoMonthlyDeposits();
        cout << endl;
        //calls the saving report method WITH monthly depost, but only if monthly deposit is more than 0
        if (monthlydeposit > 0)
        {
            mysavings.reportWithMonthlyDeposits();
        }
        //checks if user wants to run program again with new data
        cout << endl
             << "Run new data set? (y/n): ";
        string choice;
        cin >> choice;
        //kills loop if user decides not to run program again
        if (choice != "y")
        {
            break;
        }
        cout << endl;
    }
    return 0;
}