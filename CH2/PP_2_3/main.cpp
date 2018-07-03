#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    double dollarAmount=0.00;
    int numberOfBars=0;
    int numberOfCoupons=0;
    const int COUPONS_NEEDED=7;

    cout << "Enter the amount of money you have: $ ";
    cin>>dollarAmount;

    while(dollarAmount >0.00 || numberOfCoupons>=7){
        dollarAmount--;
        numberOfCoupons++;
        numberOfBars++;
        if(numberOfCoupons>=COUPONS_NEEDED){
            numberOfCoupons-=COUPONS_NEEDED;
            numberOfBars++;
            numberOfCoupons++;
        }
    }
     cout<<"The total number of chocolate bar(s) are: "<<numberOfBars<<"."<<endl;
     cout<<"You have "<<numberOfCoupons<<" coupon(s)left over."<<endl;

    return 0;
}
