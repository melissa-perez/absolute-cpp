#include <iostream>

using namespace std;


const double METER_TO_FOOT=0.3048;
const double CM_TO_M=100.0;
const double IN_TO_FT=12.0;

void inputMandCM(double& meter, double& centimeter);
bool verifyMeasurements(double meter, double centimeter);
void convertMandCM(double& feet, double& inches, double meters,double centimeter);
void displayFandIN(double feet,double inches, double meters, double centimeters);

int main(int argc, char *argv[])
{
    double feet=0, inches=0,meters=0,centimeters=0;
    char userAnswer='A';

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    do{
        inputMandCM(meters,centimeters);
        convertMandCM(feet,inches,meters,centimeters);
        displayFandIN(feet,inches,meters,centimeters);

        cout<<"Would you like to enter another value(Enter Y or y)?:";
        cin>>userAnswer;
        cout<<endl;
    }while(userAnswer=='Y'||userAnswer=='y');

    cout<<"END OF PROGRAM"<<endl;

    return 0;
}

void inputMandCM(double &meter, double &centimeter)
{
    do{
        cout<<"Please enter how many meter(s): ";
        cin>>meter;
        cout<<"and how centimeter(s): ";
        cin>>centimeter;
    }while(verifyMeasurements(meter,centimeter)==0);
}

bool verifyMeasurements(double meter, double centimeter)
{
    bool isValid= meter>=0 && centimeter>=0;

    if(isValid==0){
        cout<<"\nIncorrect measurement entry. Try again."<<endl;
    }
    return(isValid);
}

void convertMandCM(double& feet, double& inches, double meters, double centimeter)
{
    feet=meters/METER_TO_FOOT;
    inches=((centimeter/CM_TO_M)/METER_TO_FOOT)*12.0;
}

void displayFandIN(double feet, double inches,double meters, double centimeters)
{
    cout<<"Converted: "<<meters<<" m. "<<centimeters<<" cm. to"<<endl;
    cout<<feet<<" ft. "<<inches<<" in. "<<"or "<<feet+(inches/IN_TO_FT)<<" ft. "<<"or "<<(inches+(feet*IN_TO_FT))<<" in."<<endl;

}
