#include <iostream>

using namespace std;

class Money{
public:
    Money();
    Money(int, int);
    void setDollars();
    void setDollars(int);
    void setCents();
    void setCents(int);
    int getDollars();
    int getCents();
    double moneyAmount();
    void displayMoney();
private:
    int dollars=0, cents=0;
    double totalMoney=0;
};

int main(int argc, char *argv[])
{
    Money money1,money2,money3,money4(4,5);

    money1.setDollars();
    money1.setCents();
    money1.displayMoney();



    money2.setDollars(20);
    money2.setCents(10);
    money2.displayMoney();

    cout<<"\nInvoking the default const of 0 dollars and 0 cents."<<endl;
    money3.displayMoney();

    cout<<"\nInvoking the input const with 4 dollars and 5 cents."<<endl;
    money4.displayMoney();


    return 0;
}

Money::Money():dollars(0),cents(0){}
Money::Money(int bills,int coins):dollars(bills),cents(coins){}
void Money::setDollars()
{
    cout<<"Enter the amount of dollars $";
    cin>>dollars;
}

void Money::setDollars(int onlyDollars)
{
   dollars=onlyDollars;
}
void Money::setCents()
{
    cout<<"Enter the amount of cents .";
    cin>>cents;
}
void Money::setCents(int onlyCents)
{
   cents=onlyCents;
}

int Money::getCents()
{
    return cents;
}

int Money::getDollars()
{
    return dollars;
}

double Money::moneyAmount()
{
    return(getDollars()+(getCents()/100.0));
}

void Money::displayMoney()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"Total amount is $"<<moneyAmount()<<endl;
}
