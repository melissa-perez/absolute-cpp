#include <iostream>

using namespace std;

double hatSize(double userWeight, double userHeight);
double jacketSize(double userHeight, double userWeight, int userAge);
double waistSize(double userWeight, int userAge);

int main(int argc, char *argv[])
{
    double userHeight=0.0,userWeight=0.0,hat=0.0,jacket=0.0,waist=0.0;
    int userAge=0;
    char userInput='a';


    do{
        cout<<"Please enter your height in inches: ";
        cin>>userHeight;
        cout<<"\nPlease enter your weight in lbs.: ";
        cin>>userWeight;
        cout<<"\nPlease enter your age: ";
        cin>>userAge;

        hat=hatSize(userWeight,userHeight);
        jacket=jacketSize(userHeight,userWeight,userAge);
        waist=waistSize(userWeight,userAge);

        cout<<"\nYour hat size is : "<<hat<<endl;
        cout<<"\nYour jacket size is : "<<jacket<<endl;
        cout<<"\nYour waist size is : "<<waist<<endl;

        cout<<"\nWould you like to calculate again?(Enter Y or y): ";
        cin>>userInput;

    }while(userInput=='Y'||userInput=='y');

    cout<<"END OF PROGRAM"<<endl;
    return 0;
}


double hatSize(double userWeight, double userHeight)
{
    return(2.9*(userWeight/userHeight));
}

double jacketSize(double userHeight, double userWeight, int userAge)
{
    double adjustment=0.0;

    if(userAge>30 && userAge%10==0){
        while(userAge>30){
            adjustment+=0.125;
            userAge-=10;
        }
    }
    return(((userHeight*userWeight)/288)+adjustment);
}

double waistSize(double userWeight, int userAge)
{
    double adjustment=0.0;

    if(userAge>28 && userAge%2==0){
        while(userAge>28){
            adjustment+=0.1;
            userAge-=2;
        }
    }

    return((userWeight/5.7)+adjustment);
}
