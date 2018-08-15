#include <iostream>
#include <cmath>
using namespace std;

class Money{
public:
    void setDollars();
    void setDollars(double);
    void setCents();
    void setCents(double);
    void setMoneyAmount();
    void setMoneyAmount(double);
    double getDollars();
    double getCents();
    double getMoneyAmount();
    void displayMoney();
private:
    double totalMoney=0;
};

int main(int argc, char *argv[])
{
    Money money1,money2,money3;


    money1.setDollars();
    money1.setCents();
    money1.displayMoney();



    money2.setDollars(4.55);
    money2.setDollars(13);
    money2.displayMoney();

    money3.setCents();
    money3.displayMoney();

    money3.setCents(110);
    money3.displayMoney();
    return 0;
}


void Money::setDollars()
{
    double dollars;

    cout<<"Enter the amount of dollars $";
    cin>>dollars;
    totalMoney=(totalMoney-floor(totalMoney))+dollars;
}

void Money::setDollars(double dollars)
{
    totalMoney=(totalMoney-floor(totalMoney))+dollars;
}
void Money::setCents()
{
    double cents;
    cout<<"Enter the amount of cents .";
    cin>>cents;
    totalMoney=(totalMoney-getCents())+(cents/100.0);

}
void Money::setCents(double cents)
{
    totalMoney=(totalMoney-getCents())+(cents/100.00);
}

double Money::getCents()
{
    return (totalMoney-floor(totalMoney));
}

double Money::getDollars()
{
    return (totalMoney-getCents());
}

double Money::getMoneyAmount()
{
    return(getDollars()+(getCents()));
}

void Money::setMoneyAmount()
{
    cout<<"Enter the total amount of money $";
    cin>>totalMoney;
}


void Money::setMoneyAmount(double allMoney)
{
    totalMoney=allMoney;
}

void Money::displayMoney()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"Total amount is $"<<getMoneyAmount()<<endl;
}

