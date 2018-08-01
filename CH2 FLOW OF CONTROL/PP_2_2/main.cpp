#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double debt=1000.0,totalInterest=0.0;
    double const MONTHLY_PAYMENT = 50.0;
    double const interestRate= 0.015; //1.5% per month; 18% per year
    int monthsNeeded=0;

    while(debt >0){
        totalInterest+=debt*interestRate;
        debt=debt-(MONTHLY_PAYMENT-debt*interestRate);
        monthsNeeded++;
    }

    cout<<"You will need "<<monthsNeeded<<" month(s) to pay off the debt in full."<<endl
       <<"You will pay a total of $"<<totalInterest
      <<" in interest.\n";
    return 0;
}
