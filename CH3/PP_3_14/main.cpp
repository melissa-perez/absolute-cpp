#include <iostream>

using namespace std;

double babylonian(double n);

int main(int argc, char *argv[])
{
    double n =0.00;
    char userAnswer='A';
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout<<"Babylonian Algorithm\n";
    do{
       cout<<"\nTake the square root of what number? ";
    cin>>n;

    cout<<"The square root of "<<n<< " is "<<babylonian(n)<<endl;

    cout<<"\nWould you like to calculate again?(Enter Y or y): ";
    cin>>userAnswer;

    }while(userAnswer=='y'||userAnswer=='Y');

    cout<<"END OF PROGRAM."<<endl;

    return 0;
}

double babylonian(double n){
    double guess = 0.00;
    double r =0.00;
    double prev_guess=0.00;

    guess=n/2;
    do{
        prev_guess=guess;
        r = n/guess;
        guess=(guess+r)/2;

   }while(prev_guess-guess >= 0.01*prev_guess);

    return guess;
}
