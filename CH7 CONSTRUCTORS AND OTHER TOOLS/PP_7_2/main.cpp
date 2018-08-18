#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


class Month{
public:
    Month(char letter1,char letter2, char letter3);
    //construct with 3 letters as the priv. member
    Month(int monthNumber); //construct with 1 number
    Month(); //empty constructor

    void setMonth(char letter1, char letter2, char letter3);
    void setMonth(int monthNumber);

    void setMonth();
    void setMonthAbv();

    void outputMonthNumber();
    void outputMonthLetters();

    Month nextMonth();
private:
    char mletter1,mletter2,mletter3;
};

int main(int argc, char *argv[])
{
    Month mth1('D','e','c'), mth2(12),mth3,mth4,mth5,mth6;
    mth1.outputMonthNumber();
    mth2.outputMonthNumber();
    mth2.outputMonthLetters();
    mth3.setMonth(2);
    mth3.outputMonthLetters();
    mth3.outputMonthNumber();
    mth4=mth1.nextMonth();
    mth4.outputMonthLetters();
    mth4.outputMonthNumber();
    mth5.setMonth();
    mth5.outputMonthLetters();
    mth6.setMonthAbv();
    mth6.outputMonthNumber();
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
            mletter1=letter1;
            mletter2=letter2;
            mletter3=letter3;
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

    string months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul",
                      "Aug","Sep","Oct","Nov","Dec"};
    for(int i =0;i<12;i++)
    {
        if(i+1==monthNumber)
        {
                mletter1=months[i][0];
                mletter2=months[i][1];
                mletter3=months[i][2];
                break;
        }
    }
}

Month::Month():mletter1('J'),mletter2('a'),mletter3('n'){}

void Month::setMonth()
{
    int monthNumber;
    cout<<"Enter the month number(Ex. 5 for May) :";
    cin>>monthNumber;
    setMonth(monthNumber);
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
    string months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul",
                      "Aug","Sep","Oct","Nov","Dec"};
    string abv="";
    abv+=mletter1;
    abv+=mletter2;
    abv+=mletter3;

    cout<<abv<<endl;

    for(int i =0;i<12;i++)
    {
        if(abv==months[i])
        {
            cout<<"Month number is "<< i+1<<endl;
            break;
        }
    }
 }

void Month::outputMonthLetters()
{
    cout<<"Month abv. is "<<mletter1<<mletter2<<mletter3<<endl;
}

Month Month::nextMonth()
{
    Month next;
    string months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul",
                      "Aug","Sep","Oct","Nov","Dec"};
    string abv="";
    abv+=mletter1;
    abv+=mletter2;
    abv+=mletter3;

    for(int i =0;i<12;i++)
    {
        if(abv==months[i])
        {
            if(i==11) {
                next.mletter1=months[0][0];
                next.mletter2=months[0][1];
                next.mletter3=months[0][2];
                break;
            }
            else {
                next.mletter1=months[i+1][0];
                next.mletter2=months[i+1][1];
                next.mletter3=months[i+1][2];
                break;
            }
        }
    }
    return next;
}
