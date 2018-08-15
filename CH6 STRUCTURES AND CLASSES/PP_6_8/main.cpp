#include <iostream>

using namespace std;

class Money{
public:
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
    Money money1,money2;


    money1.setDollars();
    money1.setCents();
    money1.displayMoney();



    money2.setDollars(20);
    money2.setCents(10);
    money2.displayMoney();
    return 0;
}


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
