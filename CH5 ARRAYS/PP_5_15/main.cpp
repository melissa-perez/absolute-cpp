#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
const int PIN_LENGTH=5;
const int ARRAY_SIZE=10;
void pinScreen(int num[ARRAY_SIZE]);
bool validatePIN(int num[ARRAY_SIZE],int pin[ARRAY_SIZE]);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int num[ARRAY_SIZE]={0};
    int pin[ARRAY_SIZE]={1,2,3,4,5}; //THE PIN IS 12345

    pinScreen(num);

    bool isCorrect=validatePIN(num,pin);
    if(isCorrect)
    {
        cout<<"\nCorrect entry."<<endl;
    }
    else cout<<"\nIncorrect entry."<<endl;
    return 0;
}


void pinScreen(int num[ARRAY_SIZE])
{
    cout<<"PIN: ";
    for(int i=0;i<ARRAY_SIZE;i++)
    {
     cout<< i<<" ";
    }
    cout<<endl;
    for(int i =0;i<ARRAY_SIZE;i++)
    {
        num[i]=1+rand()%3;
    }

    cout<<"NUM: ";
    for(int i=0;i<ARRAY_SIZE;i++)
    {
     cout<<num[i]<<" ";
    }
}


bool validatePIN(int num[], int pin[])
{
    string pinEntry="";
    bool result=false;
    cout<<"\nEnter your PIN using the NUM keys: ";
    cin>>pinEntry;
    cout<<endl;
    for(int i=0,j=pin[i];i<PIN_LENGTH;i++,j=pin[i])
    {
        if(static_cast<int>(pinEntry[i])-48==num[j])
        {
            result=true;
        }

        else result=false;
    }
    return result;
}
