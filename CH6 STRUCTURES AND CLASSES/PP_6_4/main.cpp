#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>

using namespace std;


class GasPump{
public:
    void pumpGallons();
    void displayAmount();
    void setGallons();
    void displayCPG();
    void displayGallons();

private:
    double amountCharged=0.00;
    double const COST_PER_GALLON=3.50;
    double gallons=0.00;

};

int main(int argc, char *argv[])
{
    char ans='\0';
    do{
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        GasPump pump;
        pump.setGallons();
        pump.pumpGallons();
        pump.displayGallons();
        pump.displayAmount();
        cout<<"\nComputer another purchase?(Enter Y or y): ";
        cin>>ans;
        system("cls");

    }while(ans=='y'||ans=='Y');
    cout<<"\nEND OF PROGRAM."<<endl;
    return 0;
}

void GasPump::setGallons()
{
    gallons=0.00;
    amountCharged=0.00;
}

void GasPump::displayAmount()
{
    cout<<"\nAmount charged is $"<<COST_PER_GALLON*gallons<<endl;
}

void GasPump::displayCPG()
{
    cout<<"\nThe cost per gallon is $"<<COST_PER_GALLON<<endl;
}

void GasPump::pumpGallons()
{
    char c ;
    double i=0.00;

    while(1){
        cout<<"Hold the enter button to pump gas, press ESC to stop. "<<endl;
        displayCPG();
        displayAmount();
        displayGallons();
        i+=0.01;

        cout<<"Gas pumping....\n";
        Sleep(40);

        c=getch();
        system("cls");

        if (c==27)break;
        gallons=i;


    }

    system("cls");

}

void GasPump::displayGallons()
{
    cout<<gallons<<" gallons"<<endl;

}
