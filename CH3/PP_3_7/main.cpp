#include <iostream>
#include <cmath>

using namespace std;


double windChillFactor(double temperature,double windSpeed);
bool tempCheck(double temperature);

int main(int argc, char *argv[])
{
    double temperature=0.0,windSpeed=0.0, wcf=0.00;
    char userInput='A';
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    do{
        cout<<"Please enter a temperature in Celsius(t <=10 C): ";
        cin>>temperature;
        while(tempCheck(temperature)==0){
            cout<<"\nIncorrect temperature range; re-enter t, Celsius(t <=10 C): ";
            cin>>temperature;
        }

        cout<<"\nPlease enter the wind speed in m/sec: ";
        cin>>windSpeed;

        wcf=windChillFactor(temperature,windSpeed);

        cout<<"The wind chill index is: "<<wcf<<" C.";

        cout<<"\nWould you like to calculate again?(Enter Y or y): ";
        cin>>userInput;
        cout<<endl;

    }while(userInput=='Y'||userInput=='y');

    cout<<"END OF PROGRAM"<<endl;

    return 0;
}


bool tempCheck(double temperature)
{
    return (temperature<=10);
}

double windChillFactor(double temperature, double windSpeed)
{
    return((33-((10*sqrt(windSpeed)-windSpeed+10.5)*(33-temperature))/23.1));
}
