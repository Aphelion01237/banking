#include <iomanip>
#include <iostream>
#include "savings.h"
using namespace std;

//constructor
//sets up the values for the variables
savings::savings(double investment, double monthDeposit,
    double rate, int years){
     this->initialDeposit = investment;
     this->monthlyDeposit = monthDeposit;
     this->interestRate = rate;
     this->numYears = years;
}

//destructor
savings::~savings(){
}

//function to print the montly report without deposits
void savings::reportNoMonthlyDeposits(){
    cout << "   Balance and Interest without additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;
    cout << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(35) << "Year End Earned Interest Rate" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    //runs through the number of years and calculates interest, then prints each year
    int currentyear = 1;
    double yearendBalance = this->initialDeposit;
    while(currentyear <= this->numYears){
        double interestearned = yearendBalance * this->interestRate / 100;
        yearendBalance += interestearned;
        cout << right << setw(10) << currentyear << fixed << setprecision(2)
             << setw(20) << yearendBalance
            << setw(35) << interestearned << endl;
        currentyear++;
    }
}

//function to print the montly report without deposits
void savings::reportWithMonthlyDeposits(){
    cout << "   Balance and Interest without additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;
    cout << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(35) << "Year End Earned Interest Rate" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    //runs through the number of years and calculates interest, then prints each year
    int currentyear = 1;
    double yearendBalance = this->initialDeposit;
    while(currentyear <= this->numYears){
        int month = 1;
        double interestearned = 0.0;
        double monthendbalance = yearendBalance;
        while(month <= 12){
            monthendbalance += this->monthlyDeposit;
            double monthlyinterest = monthendbalance * this->interestRate / (100*12);
            interestearned += monthlyinterest;
            monthendbalance += monthlyinterest;
            month++;
        }
        yearendBalance = monthendbalance;
        cout << right << setw(10) << currentyear << fixed << setprecision(2)
            << setw(20) << yearendBalance
            << setw(35) << interestearned << endl;
        currentyear++;
    }
}
