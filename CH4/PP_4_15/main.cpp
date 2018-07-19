#include <iostream>
#include <cassert>
#define NDEBUG

using namespace std;

bool convertToLowestTerms(int &numerator, int& denominator);

int main(int argc, char *argv[])
{
    int numerator =0,denominator=1;
    char ans ='a';
    do{
        cout<<"Enter the numerator: ";
        cin>>numerator;
        cout<<"Enter the denominator: ";
        cin>>denominator;
        cout<<"\nThe fraction "<<numerator<<"/"<<denominator<<endl;
        if(convertToLowestTerms(numerator,denominator))
        {
            if(denominator==1){
                cout<<"In lowest terms: "<<numerator<<endl;
            }
            else{
                cout<<"In lowest terms: "<<numerator<<"/"<<denominator;
            }
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

bool convertToLowestTerms(int &numerator, int &denominator)
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
