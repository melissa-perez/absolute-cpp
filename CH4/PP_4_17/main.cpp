#include <iostream>

using namespace std;

void sort(int& a, int& b,int& c);
int main(int argc, char *argv[])
{
    int a=0,b=0,c=0;


    cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Enter the second number: ";
    cin>>b;
    cout<<"Enter the third number: ";
    cin>>c;


    sort(a,b,c);

    cout<<"\nIn order: "<<a<<" , "<<b<<" , "<<c<<endl;
    return 0;
}

void sort(int &a, int &b, int &c)
{
    int temp=0;

    if(a>b){
        temp=b;
        b=a;
        a=temp;
    }
    if(b>c){
        temp=b;
        b=c;
        c=temp;
    }

    if(b<a){
        temp=b;
        b=a;
        a=temp;
    }
}
