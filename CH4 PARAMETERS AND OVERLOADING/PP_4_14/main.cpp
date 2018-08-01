#include <iostream>

using namespace std;

void enterTime(int& hours, int& minutes);
int differenceMin(int& shours, int& sminutes,int& ehours, int& eminutes);
bool checkEndTime(int shours, int sminutes,int ehours, int eminutes);

int main(int argc, char *argv[])
{
    int shours=0,sminutes=0, ehours=0,eminutes=0;
    char ans='a';

    do{
        cout<<"Enter the start time."<<endl;
        enterTime(shours,sminutes);
        cout<<"Enter the end time."<<endl;
        enterTime(ehours,eminutes);


        cout<<"\nYou have travelled "<<differenceMin(shours,sminutes,ehours,eminutes)
           <<" minute(s) into the future."<<endl;

        cout<<"Test again?(y/n) ";
        cin>>ans;
        cout<<endl;

    }while(ans=='Y'||ans=='y');

    cout<<"\nEND OF DRIVER PROGRAM."<<endl;

    return 0;
}

void enterTime(int &hours, int &minutes)
{
    cout<<"Please enter the hour(s) in military notation (E.g. 0 or 23): ";
    cin>>hours;
    cout<<"Please enter the minute(s) (E.g. 10 or 50): ";
    cin>>minutes;
}

int differenceMin(int &shours, int &sminutes, int &ehours, int &eminutes)
{
    const int MINSINDAY=1440, MINSINHOUR=60;
    int mins1=0,mins2=0;
    if(shours>ehours){
       mins1= MINSINDAY-((MINSINHOUR*shours)+sminutes);
       mins2=(MINSINHOUR*ehours)+eminutes;
       return(mins1+mins2);
    }
    else if(shours<=ehours){
        mins1=((MINSINHOUR*shours)+sminutes);
        mins2=(MINSINHOUR*ehours)+eminutes;
        return(mins2-mins1);
     }

    return 0;
}


