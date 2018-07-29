#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_INTEGER_LENGTH=20;

void enterInteger(char numberArray[MAX_INTEGER_LENGTH],int& numberUsed);
void swapValues(char& v1, char& v2);
void sum(char numberArray1[MAX_INTEGER_LENGTH],char numberArray2[MAX_INTEGER_LENGTH],int sumArray[MAX_INTEGER_LENGTH], int&numberUsed1,int&numberUsed2,int& sNumberUsed);
void fillZeros(char numberArray[],int& numberUsed1, int& numberUsed2);
void displaySum(char numberArray1[],char numberArray2[],int sumArray[],int numberUsed1,int numberUsed2,int sNumberUsed);

int main(int argc, char *argv[])
{
    char ans='a';
    do{
        char numberArray1[MAX_INTEGER_LENGTH]={0},numberArray2[MAX_INTEGER_LENGTH]={0};
        int sumArray[MAX_INTEGER_LENGTH]={0};
        int numberUsed1=0,numberUsed2=0,sNumberUsed=0;

        cout<<"Enter the first integer, one character at a time. ";
        enterInteger(numberArray1, numberUsed1);
        cout<<"Enter the second integer, one character at a time. ";
        enterInteger(numberArray2,numberUsed2);
        sum(numberArray1,numberArray2,sumArray,numberUsed1,numberUsed2,sNumberUsed);
        if(sNumberUsed<=MAX_INTEGER_LENGTH){
            displaySum(numberArray1, numberArray2, sumArray, numberUsed1, numberUsed2,sNumberUsed);
        }
        cout<<"Would you like to do another calculation(Enter y or Y)?: ";
        cin>>ans;
     }while(ans=='y'||ans=='Y');
    cout<<"END OF PROGRAM"<<endl;
    return 0;
}

void enterInteger(char numberArray[MAX_INTEGER_LENGTH],int& numberUsed)
{
        cout<<"You may enter up to "<<MAX_INTEGER_LENGTH<<" digits.\n";
        int index=0;
        char next='0',ans='y';

        while((index<MAX_INTEGER_LENGTH)&&(ans=='y'||ans=='Y'))
        {
            if(numberUsed>=1){
                cout<<"Enter a digit:";
                cin>>next;
                for(int i=0;i<=numberUsed;i++){
                    swapValues(numberArray[i],next);
                }
                index++;
                numberUsed+=1;
            }
            else{
                    cout<<"Enter a digit:";
                    cin>>next;
                    numberArray[index]=next;
                    index++;
                    numberUsed+=1;
            }
            if(numberUsed<MAX_INTEGER_LENGTH){
            cout<<"\nEnter another digit? (Key in y or Y): ";
            cin>>ans;
            }
        }
}

void swapValues(char &v1, char &v2)
{
    char temp='a';

    temp =v1;
    v1=v2;
    v2=temp;
}

void fillZeros(char numberArray[],int &numberUsed1, int &numberUsed2)
{
    if(numberUsed1<numberUsed2)
    {
       for(int i=numberUsed2-1;i>=numberUsed1;i--)
       {
           numberArray[i]='0';
       }
       numberUsed1=numberUsed2;
    }

    else if(numberUsed1>numberUsed2)
    {
       for(int i=numberUsed1-1;i>=numberUsed2;i--)
       {
           numberArray[i]='0';
       }
       numberUsed2=numberUsed1;
    }
}

void sum(char numberArray1[], char numberArray2[], int sumArray[],int& numberUsed1,int& numberUsed2,int &sNumberUsed)
{
    int carryOver=0,result=0;
    int index=0;

    if(numberUsed1<numberUsed2)
    {
        fillZeros(numberArray1,numberUsed1,numberUsed2);
    }

    else if(numberUsed2<numberUsed1)
    {
        fillZeros(numberArray2,numberUsed1,numberUsed2);
    }

    do{
        result=(((static_cast<int>(numberArray1[index])-48)+(static_cast<int>(numberArray2[index])-48))+carryOver);

        if(result>=10){
            carryOver=0;
            sumArray[index]=(result-10);
            carryOver=1;
        }
        else{
            sumArray[index]=result;
            carryOver=0;
        }
        sNumberUsed+=1;
        index+=1;

        if((carryOver==1)&&(sNumberUsed>=numberUsed1))
        {
          sumArray[index]=carryOver;
          sNumberUsed+=1;
        }

        if(sNumberUsed>MAX_INTEGER_LENGTH){
            cout<<"INTEGER OVERFLOW"<<endl;
            break;
        }
    }while (sNumberUsed<numberUsed1);
}

void displaySum(char numberArray1[],char numberArray2[],int sumArray[],int numberUsed1,int numberUsed2, int sNumberUsed)
{
    cout<<" ";
    for(int i =numberUsed1-1;i>=0;i--)cout<<setw(1)<<numberArray1[i];
    cout<<endl<<"+";
    for(int i =numberUsed2-1;i>=0;i--)cout<<setw(1)<<numberArray2[i];
    cout<<endl;
    for(int i =0;i<=sNumberUsed;i++)cout<<"-";
    cout<<endl;
    for(int i =sNumberUsed-1;i>=0;i--)cout<<sumArray[i];
    cout<<endl;
}
