#include <iostream>

using namespace std;


const double METER_TO_FOOT=0.3048;
const double CM_TO_M=100.0;
const double IN_TO_FT=12.0;

void inputFTandIN(double& feet, double& inches);
bool verifyMeasurements(double feet, double inches);
void convertFTandIN(double feet, double inches, double& meters,double& centimeter);
void displayMandCM(double feet,double inches, double meters, double centimeters);

int main(int argc, char *argv[])
{
    double feet=0, inches=0,meters=0,centimeters=0;
    char userAnswer='A';

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    do{
        inputFTandIN(feet,inches);
        convertFTandIN(feet,inches,meters,centimeters);
        displayMandCM(feet,inches,meters,centimeters);

        cout<<"Would you like to enter another value(Enter Y or y)?:";
        cin>>userAnswer;
        cout<<endl;
    }while(userAnswer=='Y'||userAnswer=='y');

    cout<<"END OF PROGRAM"<<endl;

    return 0;
}

void inputFTandIN(double &feet, double &inches)
{
    do{
        cout<<"Please enter how many feet: ";
        cin>>feet;
        cout<<"and how inches: ";
        cin>>inches;
    }while(verifyMeasurements(feet,inches)==0);
}

bool verifyMeasurements(double feet, double inches)
{
    bool isValid= feet>=0 && inches>=0;

    if(isValid==0){
        cout<<"\nIncorrect measurement entry. Try again."<<endl;
    }
    return(isValid);
}

void convertFTandIN(double feet, double inches, double &meters, double &centimeter)
{
    meters=feet*METER_TO_FOOT;
    centimeter=(inches/IN_TO_FT)*METER_TO_FOOT*CM_TO_M;
}

void displayMandCM(double feet, double inches,double meters, double centimeters)
{
    cout<<"Converted: "<<feet<<" ft. "<<inches<<" in. to"<<endl;
    cout<<meters<<" m. "<<centimeters<<" cm."<<" or "<<meters+(centimeters/100.0)<<" m. "<<"or "<<(meters+(centimeters/100.0))*100.0<<" cm."<<endl;

}
