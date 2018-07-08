#include <iostream>

using namespace std;


double inflationRate(double priceAgo, double priceToday);
int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double priceAgo=0.0,priceToday=0,rate=0.0;
    char userAnswer='a';

do{
    cout<<"Please enter the price of the item one year ago: $";
    cin>>priceAgo;
    cout<<"\nPlease enter the price of the item today: $";
    cin>>priceToday;

    rate=inflationRate(priceAgo,priceToday);
    cout<<"\nThe inflation rate is "<<rate<<" \%"<<endl;
    cout<<"\nWould you like to calculate again?(Enter Y or y): ";
    cin>>userAnswer;
    }while (userAnswer=='y'||userAnswer=='Y');


    cout<<"END OF PROGRAM."<<endl;
    return 0;
}

double inflationRate(double priceAgo, double priceToday)
{
    return(100.0*((priceToday-priceAgo)/priceAgo));
}
