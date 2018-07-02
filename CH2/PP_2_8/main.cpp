#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int fahrenheit =30;
    int celsius =100;
    int formula=0;

    while(celsius>fahrenheit){
        formula=(9/5)*celsius+32;
        celsius--;
    }

    cout<<"Farenheit(F): "<<fahrenheit;
    cout<<"\nCelsius(C): "<<celsius<<endl;
    return 0;
}
