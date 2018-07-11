#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
int numberOfDay(int day,int monthValue, int centuryValue,int yearValue);
string theWeekDay(int dayNumber);

int main(int argc, char *argv[])
{

    int month=0,day=0,year=0,monthValue=0,centuryValue=0,yearValue=0;


    cout<<"Enter the month's number(1 to 12): ";
    cin>>month;
    cout<<endl<<"Enter the day's number(1 to 31): ";
    cin>>day;
    cout<<endl<<"Enter the year: ";
    cin>>year;

    monthValue=getMonthValue(month,year);
    centuryValue=getCenturyValue(year);
    yearValue=getYearValue(year);

    cout<<endl<<"The day of week on the date ("<<month<<"\\"<<day<<"\\"<<year<<") is "
       <<theWeekDay(numberOfDay(day,monthValue,centuryValue,yearValue))<<"."<<endl;

    return 0;
}

bool isLeapYear(int year)
{
    return((year%400==0)||((year%4==0)&&(year%100!=0)));
}

int getCenturyValue(int year)
{
    double century=0;
    century=year/100;
    year=static_cast<int>(century);
    year%=4;
    year=3-year;
    return(year*2);
}

int getYearValue(int year)
{
    double century=0;
    int years_passed=0;
    century=(year/100)*100;
    years_passed=year-static_cast<int>(century);
    return(years_passed+(years_passed/4));
}

int getMonthValue(int month, int year)
{
    switch (month) {
    case 1:
        if(isLeapYear(year)){return 6;}
        return 0;
    case 2:
        if(isLeapYear(year)){return 2;}
        return 3;
    case 3:
        return 3;
    case 4:

        return 6;
    case 5:

        return 1;
    case 6:

        return 4;
    case 7:

        return 6;
    case 8:

        return 2;
    case 9:

        return 5;
    case 10:

        return 0;
    case 11:

        return 3;
    case 12:

        return 5;
    default:
        cout<<"\nIncorrect month entry.\n";
        break;
    }
}


int numberOfDay (int day,int monthValue, int centuryValue, int yearValue)
{
    return((day+monthValue+centuryValue+yearValue)%7);
}


string theWeekDay(int dayNumber)
{
    switch (dayNumber) {
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
       return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    case 0:
        return "Sunday";
    }
    return "";
}
