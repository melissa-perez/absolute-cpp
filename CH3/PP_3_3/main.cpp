#include <iostream>

using namespace std;

double inflationRate(double priceAgo, double priceToday);
double estimatedPrice(double priceToday, double rate);
int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double priceAgo=0.0,priceToday=0,rate=0.0,priceFuture=0.0;
    char userAnswer='a';

do{
    cout<<"Please enter the price of the item one year ago: $";
    cin>>priceAgo;
    cout<<"\nPlease enter the price of the item today: $";
    cin>>priceToday;

    for(int i=1;i<=2;i++){
        rate=inflationRate(priceAgo,priceToday);
        priceFuture=estimatedPrice(priceToday,rate);
        priceAgo=priceToday;
        priceToday=priceFuture;

        if(i==1){
        cout<<"\nThe inflation rate is "<<rate*100.0<<" \%"<<endl;
        cout<<"The price in one year is estimated to be, $ "<<priceFuture<<endl;
        }
        else{
            cout<<"\nThe inflation rate is "<<rate*100.0<<" \%"<<endl;
            cout<<"The price in two years is estimated to be, $ "<<priceFuture;
        }
    }

    cout<<"\nWould you like to calculate again?(Enter Y or y): ";
    cin>>userAnswer;
    }while (userAnswer=='y'||userAnswer=='Y');


    cout<<"END OF PROGRAM."<<endl;
    return 0;
}

double inflationRate(double priceAgo, double priceToday)
{
    return((priceToday-priceAgo)/priceAgo);
}

double estimatedPrice(double priceToday, double rate)
{
    return(priceToday+(rate*priceToday));
}
