#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string strNum="";
    fstream inputStream;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    int count[9]={0};
    double totalCount=0.0;
    inputStream.open("backers.txt");

    while(inputStream>>strNum){
        char numberCheck = strNum[0];
        if(numberCheck=='1'){count[0]++;}
        else if(numberCheck=='2'){count[1]++;}
        else if(numberCheck=='3'){count[2]++;}
        else if(numberCheck=='4'){count[3]++;}
        else if(numberCheck=='5'){count[4]++;}
        else if(numberCheck=='6'){count[5]++;}
        else if(numberCheck=='7'){count[6]++;}
        else if(numberCheck=='8'){count[7]++;}
        else if(numberCheck=='9'){count[8]++;}
       }

    for(int i =0;i<9;i++)
    {
        totalCount+=count[i];
    }

    for(int i =0;i<9;i++)
    {
        cout<<"Percentage of "<<i+1<<": "<<(count[i]/totalCount)*100.0<<"\%"<<endl;
    }

    inputStream.close();
    return 0;
}
