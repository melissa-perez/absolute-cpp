#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    double weight =0.00; //in lbs.
    double radius =0.00; //in ft
    const double GAMMA = 62.4; //lb/ft^3 water weight
    double volume = 0.00;
    double force_b=0.00;

    cout<<"Please enter the weight of the object(in lbs.): ";
    cin>> weight;
    cout<<"\nPlease enter the radius of the object(in ft.): ";
    cin>>radius;
    cout<<endl;

    volume=(4.0/3.0)*M_PI*pow(radius,3);
    cout<<volume<<endl;
    force_b=volume*GAMMA;
    cout<<force_b<<endl;
    cout<<weight;

    if(force_b>=weight){
        cout<<"The object will float.\n";
    }
    else{
        cout<<"The object will sink.\n";
    }
    return 0;
}
