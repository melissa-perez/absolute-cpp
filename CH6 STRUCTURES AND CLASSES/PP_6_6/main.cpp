#include <iostream>

using namespace std;

class Odometer{
public:
    void setOdometer();
    void setFuelEfficiency();
    void milesDriven();
    void setFuelEfficiency(double);
    void milesDriven(double);
    double getGallons();
    void gallonsUsed();
    void outputGallons();
private:
    double miles, fuelEfficiency,gallons;
};

int main(int argc, char *argv[])
{

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    Odometer meter,meter2;

    //meter 1
    meter.setOdometer();
    meter.setFuelEfficiency();
    meter.milesDriven();
    meter.gallonsUsed();
    meter.outputGallons();


    cout<<endl;

    //meter 2

    meter2.setOdometer();
    meter2.setFuelEfficiency(30);
    meter2.milesDriven(500);
    meter2.gallonsUsed();
    meter2.outputGallons();


    cout<<endl;
    return 0;
}

//Sets the Odometer to 0.
//No user input nor output.
void Odometer::setOdometer()
{
    miles=0.00;
}

//Allows user to enter fuel efficiency
void Odometer::setFuelEfficiency()
{
    cout<<"\nEnter fuel efficiency of car in miles per gallon: ";
    cin>>fuelEfficiency;
}


//Allows user to enter miles driven
void Odometer::milesDriven()
{    
    cout<<"Enter miles driven for a trip: ";
    cin>>miles;
}


//Allows setting fuel efficiency by function call
void Odometer::setFuelEfficiency(double fuelEf)
{
    fuelEfficiency=fuelEf;
}

//Allows setting fuel efficiency by function call

void Odometer::milesDriven(double mileage)
{
    miles=mileage;

}

//Calculates gallons used by dividing miles driven from formula: FE= miles/gallons
void Odometer::gallonsUsed()
{
    gallons=miles/fuelEfficiency;
}


//Returns gallons amount
double Odometer::getGallons()
{
    return gallons;
}


//Displays total gallons
void Odometer::outputGallons()
{
    cout<<"\nSince last odometer reset you have"
       <<" used "<<getGallons()<<" gallons.\n";
}
