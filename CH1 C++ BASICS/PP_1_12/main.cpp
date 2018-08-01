#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    double height = 5; //assume person is at least 5 feet
    double inches= 0.00;
    double body_weight=0.00;

    cout<<"Enter your height in ft: ";
    cin>>height;
    cout<<endl<<"Enter any additional inches: ";
    cin>>inches;

    if(floor(height)>5){
        height-=5;
        height*=60; //12 inches in a foot times 5
        body_weight+=110;
        body_weight+=inches*5;
        body_weight+=height;
    }
    else{
        body_weight+=110;
        body_weight+=inches*5;
}
    cout<<"Your ideal body weight is: "<< body_weight<< " lbs."<<endl;
    return 0;
}
