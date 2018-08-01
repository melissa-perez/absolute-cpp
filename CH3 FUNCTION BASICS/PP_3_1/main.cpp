#include <iostream>

using namespace std;

const double LITER = 0.264179;

double milesPerGallon(double litersConsumed, double milesTraveled);

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    double litersConsumed = 0.0, milesTraveled=0.0,mpg=0.0;
    char userAnswer='a';

   do{
        cout<<"Please enter the number of liters consumed by your car: ";
        cin>>litersConsumed;
        cout<<"\nPlease enter the number of miles traveled: ";
        cin>>milesTraveled;
        mpg=milesPerGallon(litersConsumed,milesTraveled);
        cout<<"MPG: "<<mpg<<endl;
        cout<<"\nWould you like to calculate again?(Enter Y or y): ";
        cin>>userAnswer;
   }while(userAnswer=='y'||userAnswer=='Y');

   cout<<"END OF PROGRAM."<<endl;
    return 0;
}

double milesPerGallon(double litersConsumed, double milesTraveled)
{
    return((litersConsumed/LITER)/milesTraveled);
}
