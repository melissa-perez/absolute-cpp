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

    int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
    double totalCount=0.0;
    inputStream.open("backers.txt");

    while(inputStream>>strNum){
        char numberCheck = strNum[0];
        if(numberCheck=='1'){n1++;}
        else if(numberCheck=='2'){n2++;}
        else if(numberCheck=='3'){n3++;}
        else if(numberCheck=='4'){n4++;}
        else if(numberCheck=='5'){n5++;}
        else if(numberCheck=='6'){n6++;}
        else if(numberCheck=='7'){n7++;}
        else if(numberCheck=='8'){n8++;}
        else if(numberCheck=='9'){n9++;}
       }

    totalCount=n1+n2+n3+n4+n5+n6+n7+n8+n9;

    cout<<"Percentage of 1: "<<(n1/totalCount)*100.0<<"\%"<<endl;
    cout<<"Percentage of 2: "<<(n2/totalCount)*100.0<<"\%"<<endl;
    cout<<"Percentage of 3: "<<(n3/totalCount)*100.0<<"\%"<<endl;
    cout<<"Percentage of 4: "<<(n4/totalCount)*100.0<<"\%"<<endl;
    cout<<"Percentage of 5: "<<(n5/totalCount)*100.0<<"\%"<<endl;
    cout<<"Percentage of 6: "<<(n6/totalCount)*100.0<<"\%"<<endl;
    cout<<"Percentage of 7: "<<(n7/totalCount)*100.0<<"\%"<<endl;
    cout<<"Percentage of 8: "<<(n8/totalCount)*100.0<<"\%"<<endl;
    cout<<"Percentage of 9: "<<(n9/totalCount)*100.0<<"\%"<<endl;

    inputStream.close();
    return 0;
}
