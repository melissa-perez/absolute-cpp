#include <iostream>
using namespace std;

class Fraction{
public:
    void setFraction();
    int getNumerator();
    int getDenominator();
    bool lowestTerms();
    void result();
    void displayResult();
    double getResult();
private:
    int numerator=0,denominator=1;
    double fracResult=0.00;
};

int main(int argc, char *argv[])
{
    char ans ='a';
    do{
        Fraction fract;

        fract.setFraction();

        if(fract.lowestTerms())
        {
            fract.displayResult();
        }
        else{
            cout<<"\nIncorrect input."<<endl;
        }
        cout<<"\nTest again?(y/n) ";
        cin>>ans;
        cout<<endl;

    }while(ans=='Y'|| ans=='y');
    cout<<"\nEND OF PROGRAM."<<endl;

    return 0;
}

void Fraction::setFraction()
{
    cout<<"Enter the numerator: ";
    cin>>numerator;
    cout<<"Enter the denominator: ";
    cin>>denominator;
}

bool Fraction::lowestTerms()
{
    int gcd=1;
    if(denominator==0){ return false;}
    for(int i=1;i<=numerator;i++){
            if((numerator%i)==0 &&((denominator%i)==0)){
                gcd=i;
            }
        }
    numerator/=gcd;
    denominator/=gcd;

    return true;
}

int Fraction::getNumerator()
{
    return numerator;
}

int Fraction::getDenominator()
{
    return denominator;
}

void Fraction::displayResult()
{
    if(getDenominator()==1){
        cout<<"In lowest terms: "<<getNumerator()<<endl;
    }
    else{
        result();
        cout<<"In lowest terms: "<<getNumerator()<<"/"<<getDenominator()<<"="<<getResult();

    }
}

void Fraction::result()
{
    fracResult=static_cast<double>(numerator)/static_cast<double>(denominator);
}

double Fraction::getResult()
{
    return fracResult;
}
