#include <iostream>
#include <string>
#include <iomanip> //to make pretty table,not used
#include <cmath>
using namespace std;

const int MONTHS_IN_YEAR=12;
void askMonth(int& monthNumber);
void getMonth(const string months[],int monthNumber,string& currentMonth,int& currentIndex);
void averageRainfall(const string months[],double avgRF[]);
void actualRainfall(const string months[], double actRF[],int currentIndex);
void printAsterisks(int n);
void graph(const string months[],const double avgRF[],const double actRF[]);
void displayTable(const string months[],const double avgRF[],const double actRF[]);
void userInput(const string months[],double avgRainfall[],double actRainfall[],
               int& monthNumber,string& currentMonth, int&currentIndex);
bool verifyInput(int choice);
void chooseInput(int &userPicks);
void display(int choice, const string months[],const double avgRF[],const double actRF[]);



int main(int argc, char *argv[])
{
    const string months[MONTHS_IN_YEAR]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug",
                      "Sep","Oct","Nov","Dec"};
    double avgRF[MONTHS_IN_YEAR], actRF[MONTHS_IN_YEAR];
    int monthNumber=0,currentIndex=0;;
    string currentMonth="";
    char ans='a';

    userInput(months,avgRF,actRF,monthNumber,currentMonth,currentIndex);

    do{
        int userChoice=0;

        chooseInput(userChoice);
        display(userChoice,months,avgRF,actRF);

        cout<<"Would you like to see the graph or table again(Enter Y or y)?:";
        cin>>ans;
        cout<<endl;

    }while(ans=='Y'||ans=='y');

    cout<<"END OF PROGRAM"<<endl;
    return 0;
}

void userInput(const string months[],double avgRainfall[],double actRainfall[],int& monthNumber,string& currentMonth, int&currentIndex)
{
    averageRainfall(months,avgRainfall);
    askMonth(monthNumber);
    getMonth(months,monthNumber,currentMonth,currentIndex);
    actualRainfall(months,actRainfall,currentIndex);
}

void averageRainfall(const string months[],double avgRF[])
{
    cout<<"Enter the average rainfall for all the months."<<endl;

    for(int i=0;i<MONTHS_IN_YEAR;i++){
        cout<<"For "<<months[i]<<": ";
        cin>>avgRF[i];
    }
}

void askMonth(int& monthNumber)
{
    cout<<"Enter the current month's number(Eg. 3 for March or 12 for December): ";
    cin>>monthNumber;
}

void getMonth(const string months[],int monthNumber,string& currentMonth,int& currentIndex)
{
    for(int i=1;i<(MONTHS_IN_YEAR+1);i++){
       if( monthNumber==i){
           currentMonth=months[i-1];
           currentIndex=i-1;
       }
    }
    cout<<"\nThe current month entered is "<<currentMonth<<"."<<endl;
}

void actualRainfall(const string months[],double actRF[],int currentIndex)
{
    int countForMonths=0;

    cout<<"Enter the actual rainfall for the previous months."<<endl;
    for(int i=(currentIndex-1);countForMonths<MONTHS_IN_YEAR;countForMonths++,i--){
        if(i==-1){i=11;}
        cout<<"For "<<months[i]<<": ";
        cin>>actRF[i];
    }
}

void chooseInput(int &userPicks){
    do{
        cout<<"\nWould you like to see the table or the bar graph?(Enter 1 for table or 2 for graph): ";
        cin>>userPicks;
    }while(verifyInput(userPicks)==0);

}

bool verifyInput(int choice)
{
    bool isValid= choice==1 || choice==2;
    if(isValid==0){cout<<"\nIncorrect entry. Try again."<<endl;}
    return(isValid);
}

void displayTable(const string months[],const double avgRF[],const double actRF[])
{
    cout<<"\nRainfall Information"<<endl;
    cout<<"Month"<<setw(5)<<" Actual "<<setw(5)<<" Difference "<<endl;
    for(int i=0;i<MONTHS_IN_YEAR;i++){
       cout<<months[i]<<setw(5)<<actRF[i]<<setw(10)<<actRF[i]-avgRF[i]<<endl;
    }
}

void printAsterisks(int n)
{
    for(int count=1;count<=n;count++){cout<<"*";}
}

void graph(const string months[], const double avgRF[],const double actRF[])
{
    cout<<"\nUnits of rainfall(by single digits).\n\n";
    cout<<"Average rainfall for each previous month:\n";
    for(int monthNumber=1;monthNumber<=MONTHS_IN_YEAR;monthNumber++){
        cout<<months[monthNumber-1]<<" ";
        printAsterisks(round(avgRF[monthNumber-1]));
        cout<<endl;
    }
    cout<<"\nActual rainfall for each previous month:\n";
    for(int monthNumber=1;monthNumber<=MONTHS_IN_YEAR;monthNumber++){
        cout<<months[monthNumber-1]<<" ";
        printAsterisks(round(actRF[monthNumber-1]));
        cout<<endl;
    }
}

void display(int choice, const string months[],const double avgRF[],const double actRF[])
{
    if(choice==1){displayTable(months,avgRF,actRF);}
    else{graph(months,avgRF,actRF);}
}
