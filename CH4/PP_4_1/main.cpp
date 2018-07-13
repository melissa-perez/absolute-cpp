#include <iostream>

using namespace std;

void enterTime(int& hours, int& minutes);
void timeConversion(int& hours, char& timeOfDay);
void userResponse(char& userAnswer);
void displayTime(int hours, int minutes, char timeOfDay);
int main(int argc, char *argv[])
{
    char timeOfDay='a',userAnswer='a';
    int hours=0,minutes=0;

    do{
        enterTime(hours, minutes);
        timeConversion(hours,timeOfDay);
        displayTime(hours,minutes,timeOfDay);
        userResponse(userAnswer);

    }while(userAnswer =='y'||userAnswer=='Y');
    cout<<endl<<"END OF PROGRAM"<<endl;
    return 0;
}

void userResponse(char& userAnswer){
    cout<<"\nWould you like to calculate another time(Enter y or Y)?: ";
    cin>>userAnswer;
}

void enterTime(int& hours, int& minutes)
{
    cout<<"Please enter the current hour: ";
    cin>>hours;

    cout<<"\nPlease enter the current minutes: ";
    cin>>minutes;

}

void timeConversion(int& hours, char& timeOfDay)
{
    if(hours>=0 && hours<=11)
    {
        if(hours==0){
            hours+=12;
        }
        timeOfDay='A';
    }
    else{
        if(hours > 12){
            hours-=12;
        }
        timeOfDay='P';
    }

}

void displayTime(int hours, int minutes, char timeOfDay){

    if(minutes==0){
        cout<<"\nThe 12-hour notation is "<<hours<<":"<<minutes<<"0 "<<timeOfDay<<".M."<<endl;
    }
    else{
        cout<<"\nThe 12-hour notation is "<<hours<<":"<<minutes<<" "<<timeOfDay<<".M."<<endl;
    }
}
