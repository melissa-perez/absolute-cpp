#include <iostream>

using namespace std;

void enterCoins(int& coinsEntered,int& amountLeft);
void computeCoins(int coinsValue,int& number, int& amountLeft);
bool checkCoins(int coinsEntered);
void displayCoins(int coinsEntered,int number, int amountLeft);


const int QUARTER=25;
const int DIME=10;
const int PENNY=1;

int main(int argc, char *argv[])
{
    char userAnswer='A';

   do{
        int coinsEntered=0,number=0,amountLeft=0;

        enterCoins(coinsEntered,amountLeft);
        displayCoins(coinsEntered,number,amountLeft);

        cout<<"\nWould you like to compute a new entry(Enter Y or y): ";
        cin>>userAnswer;

    }while(userAnswer=='y'||userAnswer=='Y');
    cout<<"END OF PROGRAM"<<endl;
    return 0;
}

void enterCoins(int& coinsEntered,int& amountLeft)
{
    do{
        cout<<"Please enter the amount of cents you have (between 1 to 99, not inclusive): ";
        cin>>coinsEntered;
    }while(checkCoins(coinsEntered)==0);
    amountLeft=coinsEntered;
}

bool checkCoins(int coinsEntered)
{
    bool equation= coinsEntered>0 && coinsEntered<100;
    if(equation==0){
        cout<<"\nIncorrect amount of coins, enter another value."<<endl;
    }
    return(equation);
}

void computeCoins(int coinValue, int &number, int &amountLeft)
{
    number= amountLeft/coinValue;
    cout<<number;
    amountLeft=amountLeft%coinValue;
    //cout<<amountLeft;
}

void displayCoins(int coinsEntered,int number, int amountLeft)
{
    cout<<coinsEntered<<" cents can be given as ";
          computeCoins(QUARTER,number,amountLeft);
          cout<<" quarter(s), ";
         computeCoins(DIME,number,amountLeft);
         cout<<" dime(s), and ";
      computeCoins(PENNY,number,amountLeft);
      cout<<" penny(pennies)."<<endl;
}
