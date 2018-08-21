#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int TOTAL_DIGITS=25;
const int GROUP_OF_FIVE=5;
class ZipCode{
public:
    ZipCode(int);
    ZipCode(string);

    int getZipCodeNumber(int);
    string getZipCodeString();

private:
    string code;
    int value[GROUP_OF_FIVE]={7,4,2,1,0};
    void convertToString(int);
    int convertToInt();
};

int main(int argc, char *argv[])
{
    //no user input needed, no default constructor asked
    //added first and last 1's during display. not specified to add into return value

    ZipCode code1(99504);
    cout<<"1"+code1.getZipCodeString()+"1"<<endl;

    ZipCode code2(92627);
    cout<<"1"+code2.getZipCodeString()+"1"<<endl;

    ZipCode code3("1010010100010101100001001");
    cout<<endl;

    ZipCode code4("0101000101011000010110001");
    cout<<endl;

    ZipCode code5(12345);
    cout<<"1"+code5.getZipCodeString()+"1"<<endl;

    ZipCode code6(00000);
    cout<<"1"+code6.getZipCodeString()+"1"<<endl;


    return 0;
}

ZipCode::ZipCode(int input)
{
    cout<<"ZIP CODE: "<<input<<endl;
    convertToString(input);
}

ZipCode::ZipCode(string input):code(input)
{
    cout<<"POST NET CODE: "<<"1"+input+"1"<<endl;
    cout<<getZipCodeNumber(convertToInt());
}

void ZipCode::convertToString(int input)
{
    int brokenZipCode[GROUP_OF_FIVE]={0};
    int remainder=0;
    char stringOfLines[TOTAL_DIGITS];
    int index=0;
    bool flag=false;

    for(int i=0;i<GROUP_OF_FIVE;i++)
    {
        remainder=input%static_cast<int>(pow(10,(GROUP_OF_FIVE-1)-i));
        brokenZipCode[i]=input/(pow(10,(GROUP_OF_FIVE-1)-i));
        input=remainder;
    }

    int carryOn=0;

    while(index<GROUP_OF_FIVE)
       {
           for(int i=0;i<GROUP_OF_FIVE;i++)
           {
               for(int j=i+1;j<GROUP_OF_FIVE;j++)
               {
                   if((value[i]+value[j]==brokenZipCode[index])||((value[i]+value[j]==11)&&brokenZipCode[index]==0))
                   {
                       stringOfLines[i+carryOn]='1';
                       stringOfLines[j+carryOn]='1';
                       flag=true;
                       break;
                   }
               }
               if(flag==true)break;
           }
           flag=false;

          for(int i=0;i<GROUP_OF_FIVE;i++)
           {
               if(stringOfLines[i+carryOn]!='1')stringOfLines[i+carryOn]='0';
           }
           index+=1;
           carryOn+=GROUP_OF_FIVE;
       }

    for(int i=0;i<TOTAL_DIGITS;i++)
    {
       code+=stringOfLines[i];
    }
}


int ZipCode::convertToInt()
{
    int decode=0, toAdd=0;
    for(int i=0,k=0;i<TOTAL_DIGITS;i+=5,k++)
    {   for(int j=0;j<GROUP_OF_FIVE;j++)
        {
            if(code[i+j]=='1'){
               toAdd+=value[j];
            }
            if(toAdd==11)toAdd=0;
        }
       decode+=toAdd*pow(10,(GROUP_OF_FIVE-1)-k);
       toAdd=0;
     }
    return decode;
}


string ZipCode::getZipCodeString()
{
    cout<<"The zip code encoded is: ";
    return code;
}


int ZipCode::getZipCodeNumber(int decodedString)
{
    cout<<"The zip code decoded is: ";
    return decodedString;
}
