#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


class Month{
public:
    Month(char letter1,char letter2, char letter3);
    Month(int monthNumber);
    Month();

    void setMonth(char letter1, char letter2, char letter3);
    void setMonth(int monthNumber);

    void setMonth();
    void setMonthAbv();

    void outputMonthNumber();
    void outputMonthLetters();

    Month nextMonth();
private:
    int month;
};

int main(int argc, char *argv[])
{
    Month mth1('J','a','n'), mth2,mth3(4),mth4;
    mth1.outputMonthNumber();
    mth2.setMonthAbv();
    mth2.outputMonthNumber();
    mth2.outputMonthLetters();
    mth3.outputMonthLetters();
    mth4=mth1.nextMonth();
    mth4.outputMonthLetters();
    mth4.outputMonthNumber();
    return 0;
}

Month::Month(char letter1, char letter2, char letter3)
{
    setMonth(letter1,letter2,letter3);
}

void Month::setMonth(char letter1, char letter2, char letter3)
{
    string months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul",
                      "Aug","Sep","Oct","Nov","Dec"};
    string abv="";
    abv+=letter1;
    abv+=letter2;
    abv+=letter3;

    for(int i =0;i<12;i++)
    {
        if(abv==months[i])
        {
            month=i+1;
            break;
        }
    }
}

Month::Month(int monthNumber)
{
    setMonth(monthNumber);
}

void Month::setMonth(int monthNumber)
{
    month=monthNumber;
}

Month::Month():month(1){}

void Month::setMonth()
{
    cout<<"Enter the month number(Ex. 5 for May) :";
    cin>>month;
}

void Month::setMonthAbv()
{
    char letter1,letter2,letter3;
    cout<<"Enter the first three letters of the month(Ex. Jan for January) :";
    cin>>letter1>>letter2>>letter3;
    setMonth(letter1,letter2,letter3);
}

void Month::outputMonthNumber()
{
    cout<<"Month number is "<<month<<endl;
}

void Month::outputMonthLetters()
{

    string months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul",
                      "Aug","Sep","Oct","Nov","Dec"};

    for(int i =0;i<12;i++)
    {
        if(month==i)
        {
            cout<<"Month abv. is "<<months[i-1]<<endl;
            break;
        }
    }
}

Month Month::nextMonth()
{
    if(month==12) return 1;
    else return month+1;
}
