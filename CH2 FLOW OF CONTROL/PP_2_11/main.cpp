#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string firstName,lastName,text;
    double height=0.00,inches=0.00;
    fstream inputStream;
    double body_weight=0.00;

    inputStream.open("height.txt");

    while(inputStream>>text){
        firstName=text;
        inputStream>>lastName>>height>>inches;

    if(height>5){
        height-=5;
        height*=60; //12 inches in a foot times 5
        body_weight+=110;
        body_weight+=inches*5;
        body_weight+=height;
    }
    else{
        body_weight=0;
        body_weight+=110;
        body_weight+=inches*5;
    }

    cout<<"Ideal body weight for "<<firstName<<" "
       <<lastName<<" is "<< body_weight<< " lbs."<<endl;
    }

    inputStream.close();
    return 0;
}
