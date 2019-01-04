#include <iostream>

using namespace std;

class Rational
{
    public:
        Rational();
        Rational(int);
        Rational(int, int);
        int getNum() const;
        int getDen() const;
        friend ostream& operator <<(ostream& outs,
        const Rational& fraction);
        friend istream& operator >>(istream& ins,
         Rational& fraction);
        friend bool operator == (const Rational& number1, const Rational& number2);
        friend bool operator < (const Rational& number1, const Rational& number2);
        friend bool operator <= (const Rational& number1, const Rational& number2);
        friend bool operator > (const Rational& number1, const Rational& number2);
        friend bool operator >= (const Rational& number1, const Rational& number2);
        friend operator +(const Rational& number1, const Rational& number2);
    private:
        int numerator, denominator;       
        void normalize();


};

Rational input()
{
    int num1 = 1, num2=0;
    while(num2 ==0)
    {
        cout<<"Enter the numerator: ";
        cin >>num1;
        cout<<endl<<"Enter the denominator: ";
        cin>>num2;

        if(num2==0)
        {
          cout<<endl<<"Not a valid denominator."<<endl;
        }
    }

    return Rational(num1,num2);
}

int main(int argc, char *argv[])
{
    /*Testing out the constructors*/
    cout<<"Here we are creating a Rational object by using the input function, the constructor that takes two arguments. "<<endl;
    Rational frac1= input();
    cout<<frac1<<endl;


    cout<<"Here we created a Rational object with the default constructor. "<<endl;
    Rational frac2;

    cout<<frac2<<endl;
\

    cout<<"Here we created a Rational object with the  constructor that takes 1 argument. "<<endl;

    Rational frac3(3);
    cout<<frac3<<endl;

    cout<<"Here we enter a Rational object and save it into the frac1 variable. "<<endl;

    cin>>frac1;
    cout<<"New frac1: "<<frac1<<endl;


     cout<<"Here we compare two Rational objects. "<<endl;
     cout<<frac1 <<" == "<<frac2<<" = "<<(frac1 ==frac2 ? "true":"false")<<endl;

     cout<<frac1 <<" < "<<frac2<<" = "<<(frac1 <frac2 ? "true":"false")<<endl;
     cout<<frac1 <<" <= "<<frac2<<" = "<<(frac1 <=frac2 ? "true":"false")<<endl;
     cout<<frac1 <<" > "<<frac2<<" = "<<(frac1 >frac2 ? "true":"false")<<endl;
     cout<<frac1 <<" >= "<<frac2<<" = "<<(frac1 >=frac2 ? "true":"false")<<endl;
    return 0;
}

Rational::Rational()
{
    numerator=0;
    denominator=1;
}

Rational::Rational(int input1, int input2)
{
    numerator = input1;
    denominator= input2;

    normalize();
}

Rational::Rational(int wholeNumber)
{
    numerator = wholeNumber;
    denominator=1;
}


int Rational::getNum() const
{
    return numerator;
}


int Rational::getDen() const
{
    return denominator;
}

void Rational::normalize()
{
    int r, p = numerator, q=denominator;

    while(r = p%q)
    {
       p = q;
       q = r;
    }
    numerator/=q;
    denominator/=q;

    cout<<numerator<<" "<<denominator<<endl;
    if(numerator < 0 && denominator <0 ||denominator<0)
    {
        numerator*=-1;
        denominator*=-1;
    }
}

ostream& operator <<(ostream& outs,
const Rational& fraction)
{
    outs<<fraction.numerator<<"/"<<fraction.denominator;
    return outs;
}

istream& operator >>(istream& ins,
 Rational& fraction)
{
    char divide;


    ins>>fraction.numerator;

    ins>>divide;
    if(divide != '/')
    {
        cout<<"ERROR: Missing forward slash.\n";
        exit(1);
    }


    ins>>fraction.denominator;

    if(fraction.denominator == 0)
    {
        cout<<"ERROR: Division by 0.\n";
        exit(1);
    }

    fraction.normalize();
    return ins;
}

bool operator == (const Rational& number1, const Rational& number2)
{
    return(number1.numerator *number2.denominator==number2.numerator *number1.denominator );

}

bool operator < (const Rational& number1, const Rational& number2)
 {
    int a = number1.numerator*number2.denominator, b = number2.numerator*number1.denominator;

    return(a<b);

 }

bool operator <= (const Rational& number1, const Rational& number2)
{
    int a = number1.numerator*number2.denominator, b = number2.numerator*number1.denominator;

    return(a<=b);
}

bool operator > (const Rational& number1, const Rational& number2)
{
    int a = number1.numerator*number2.denominator, b = number2.numerator*number1.denominator;
    return(a>b);
}

bool operator >= (const Rational& number1, const Rational& number2)
 {
    int a = number1.numerator*number2.denominator, b = number2.numerator*number1.denominator;
    return(a>=b);
}

