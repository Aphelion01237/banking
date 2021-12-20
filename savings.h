#ifndef SAVINGS_H_
#define SAVINGS_H_

//declares the class and sets up
class savings{
    public:
        savings(double investment, double monthDeposit, double rate, int years);
        virtual ~savings();
        void reportNoMonthlyDeposits();
        void reportWithMonthlyDeposits();

    private:
        double initialDeposit;
        double monthlyDeposit;
        double interestRate;
        int numYears;
};

#endif
