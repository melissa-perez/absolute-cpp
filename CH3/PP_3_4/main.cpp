#include <iostream>
#include <cmath>
using namespace std;

double const UNIVERSAL_GRAVITY= 6.673*pow(10,-8);

double gravitational_force(double mass1,double mass2, double distance);
int main(int argc, char *argv[])
{
    double mass1=0.0,mass2=0.0,distance=0.0,force=0.0;
    char userInput='a';

do{
    cout<<"Please enter the first mass: ";
    cin>>mass1;
    cout<<"\nPlease enter the second mass: ";
    cin>>mass2;
    cout<<"\nPlease enter the distance between the masses: ";
    cin>>distance;

    force=gravitational_force(mass1,mass2,distance);

    cout<<"The gravitational force between these objects is "<<force<<" dyne(s)."<<endl;

    cout<<"\nWould you like to calculate again?(Enter Y or y): ";
    cin>>userInput;
    }while(userInput=='y'||userInput=='Y');

    cout<<"END OF PROGRAM."<<endl;
    return 0;
}

double gravitational_force(double mass1, double mass2, double distance)
{
    return((UNIVERSAL_GRAVITY*mass1*mass2)/pow(distance,2));
}
