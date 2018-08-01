#include <iostream>

using namespace std;

void chooseConversion(int& userPicks);
bool checkConversion(int& userPicks);
void inputMeasurements(double& measurement1,double &measurement2,int userPicks);
bool verifyMeasurements(double measurement1,double measurement2);

void convert(double& feet, double& inches, double& meters, double& centimeter,int userPicks);
void displayConversion(double feet, double inches,double meters, double centimeters, int userPicks);

const double METER_TO_FOOT=0.3048;
const double CM_TO_M=100.0;
const double IN_TO_FT=12.0;

int main(int argc, char *argv[])
{
    char userAnswer='A';
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);


    do{
        int userPicks=0;
        double feet=0, inches=0,meters=0,centimeters=0;
        chooseConversion(userPicks);
        if(userPicks==1){
            inputMeasurements(feet,inches,userPicks);
            convert(feet,inches,meters,centimeters,userPicks);
            displayConversion(feet,inches,meters,centimeters,userPicks);
        }
        else{
            inputMeasurements(meters,centimeters,userPicks);
            convert(feet,inches,meters,centimeters,userPicks);
            displayConversion(feet,inches,meters,centimeters,userPicks);
        }
        cout<<"Would you like to enter another value(Enter Y or y)?:";
        cin>>userAnswer;
        cout<<endl;
    }while(userAnswer=='Y'||userAnswer=='y');
    cout<<"END OF PROGRAM"<<endl;
    return 0;
}

void chooseConversion(int &userPicks)
{
    do{
        cout<<"Which type of conversion would you like to do?\n"
           <<"Enter 1 for ft. and in. to m. and cm. or\n"
          <<"Enter 2 for m. and cm. to ft. and in.: ";
        cin>>userPicks;

    }while(checkConversion(userPicks)==0);
}

bool checkConversion(int &userPicks)
{
    bool toCheck= userPicks==1 || userPicks==2;
    if(toCheck==0){
        cout<<"\nIncorrect entry. Try again."<<endl;
    }
    return(toCheck);
}

void inputMeasurements(double& measurement1, double& measurement2, int userPicks)
{
       if(userPicks==1){
           do{
               cout<<"Please enter how many feet or foot: ";
               cin>>measurement1;
               cout<<"and how many inch(es): ";
               cin>>measurement2;
           }while(verifyMeasurements(measurement1,measurement2)==0);
       }
       else{
           do{
               cout<<"Please enter how many meter(s): ";
               cin>>measurement1;
               cout<<"and how centimeter(s): ";
               cin>>measurement2;
           }while(verifyMeasurements(measurement1,measurement2)==0);
       }
}

bool verifyMeasurements(double measurement1, double measurement2)
{
    bool isValid= measurement1>=0 && measurement2>=0;
    if(isValid==0){cout<<"\nIncorrect measurement entry. Try again."<<endl;}
    return(isValid);
}

void convert(double& feet, double& inches, double& meters, double& centimeter,int userPicks)
{
    if(userPicks==1){
        meters=feet*METER_TO_FOOT;
        centimeter=(inches/IN_TO_FT)*METER_TO_FOOT*CM_TO_M;
    }
    else{
        feet=meters/METER_TO_FOOT;
        inches=((centimeter/CM_TO_M)/METER_TO_FOOT)*IN_TO_FT;
    }
}

void displayConversion(double feet, double inches,double meters, double centimeters,int userPicks)
{
    if(userPicks==1){
        cout<<"Converted: "<<feet<<" ft. "<<inches<<" in. to"<<endl;
        cout<<meters<<" m. "<<centimeters<<" cm."<<" or "<<meters+(centimeters/CM_TO_M)<<" m. "<<"or "<<(meters+(centimeters/CM_TO_M))*CM_TO_M<<" cm."<<endl;
    }
    else{
        cout<<"Converted: "<<meters<<" m. "<<centimeters<<" cm. to"<<endl;
        cout<<feet<<" ft. "<<inches<<" in. "<<"or "<<feet+(inches/IN_TO_FT)<<" ft. "<<"or "<<(inches+(feet*IN_TO_FT))<<" in."<<endl;
       }
}
