#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string baseNumbers(int verseNumber1,int verseNumber2);
void specialNumbers();
int main(int argc, char *argv[])
{
    string bottle =" bottle";
    string verseOne=" of beer on the wall,";
    string verseTwo=" of beer,";
    string verseThree="Take one down,pass it around,";
    string verseFour=" of beer on the wall.";
    string number="",onesPlace="";
    double fractpart=0.0,intpart=0.0;
    int verseNumber1=0,verseNumber2=0;

    for(double i=99;i>=0;i--){
        fractpart=modf(i/10.0,&intpart);
        verseNumber1=intpart;
        verseNumber2=(fractpart*10)+0.5;//compiler truncates the decimal
        number=baseNumbers(verseNumber1,verseNumber2);

        if(i==1){
            cout<<number+bottle+verseOne<<endl
                <<number+bottle+verseTwo<<endl
                <<verseThree<<endl
                <<number+bottle+verseFour<<endl<<endl;
        }

        else if(i==0){
            cout<<"Zero bottles of beer on the wall."<<endl;
            return 0;
        }
        else{
            cout<<number+bottle+"s"+verseOne<<endl
                <<number+bottle+"s"+verseTwo<<endl
                <<verseThree<<endl
                <<number+bottle+"s"+verseFour<<endl<<endl;
        }
    }
    return 0;
}

string baseNumbers(int verseNumber1,int verseNumber2)
{
    string a="",b="";

    switch (verseNumber1) {
    case 1:
        a="teen";
        break;
    case 2:
        a= "Twenty";
        break;
    case 3:
        a= "Thirty";
        break;
    case 4:
        a= "Forty";
        break;
    case 5:
        a= "Fifty";
        break;
    case 6:
        a= "Sixty";
        break;
    case 7:
        a= "Seventy";
        break;
    case 8:
        a= "Eighty";
        break;
    case 9:
        a= "Ninety";
        break;
    default:
        break;
    }

    switch (verseNumber2) {
    case 1:
        b="one";
        if(a=="teen")
        {
          return("Eleven");
        }
        break;
    case 2:
        b="two";
        if(a=="teen")
        {
          return("Twelve");
        }
        break;
    case 3:
        b="three";
        if(a=="teen")
        {
          return("Thirteen");
        }
        break;
    case 4:
        b="four";
        break;
    case 5:
        b="five";
        if(a=="teen")
        {
          return("Fifteen");
        }
        break;
    case 6:
        b="six";
        break;
    case 7:
        b="seven";
        break;
    case 8:
        b="eight";
        if(a=="teen")
        {
          return("Eighteen");
        }
        break;
    case 9:
        b="nine";
        break;
    case 0:
        if(a=="teen")
        {
          return("Ten");
        }
        if(verseNumber2==0){
            return(a+b);
        }
    }

    if(verseNumber1==1){
        b[0]=toupper(b[0]);
        return(b+a);
    }
    else if(verseNumber1==0){
        b[0]=toupper(b[0]);
        return b;
    }

    return(a+"-"+b);
}
