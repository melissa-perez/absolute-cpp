#include <iostream>

using namespace std;


class Temperature{
public:
    void setTempKelvin();
    void setTempFahrenheit();
    void setTempCelsius();
    void setTempKelvin(double);
    void setTempFahrenheit(double);
    void setTempCelsius(double);
    double getTempKelvin();
    double getTempFahrenheit();
    double getTempCelsius();
    void displayTemperatures();

private:
    double kelvin=0,celsius=0,fahrenheit=0;
};
int main(int argc, char *argv[])
{
    Temperature temp1,temp2,temp3;


    temp1.setTempCelsius(32.0);
    temp1.displayTemperatures();

    temp2.setTempKelvin();
    temp2.displayTemperatures();

    temp3.setTempFahrenheit(98);
    temp3.displayTemperatures();

    return 0;
}

void Temperature::setTempKelvin(){
    cout<<"Enter the temperature in Kelvin: ";
    cin>>kelvin;
    celsius=getTempKelvin()-273.15;
    fahrenheit=getTempCelsius()*(9.0/5.0)+32.0;
}

void Temperature::setTempFahrenheit(){
    cout<<"Enter the temperature in Fahrenheit: ";
    cin>>fahrenheit;
    celsius=(5/9)*(getTempFahrenheit()-32);
    kelvin=getTempCelsius()+273.15;
}

void Temperature::setTempCelsius(){
    cout<<"Enter the temperature in Celsius: ";
    cin>>celsius;
    kelvin=getTempCelsius()+273.15;
    fahrenheit=getTempCelsius()*(9.0/5.0)+32.0;
}

void Temperature::setTempKelvin(double kelvinTemp){
    kelvin=kelvinTemp;
    celsius=getTempKelvin()-273.15;
    fahrenheit=getTempCelsius()*(9.0/5.0)+32.0;
}

void Temperature::setTempFahrenheit(double fahrenTemp){
    fahrenheit=fahrenTemp;
    celsius=(5.0/9.0)*(getTempFahrenheit()-32.0);
    kelvin=getTempCelsius()+273.15;
}

void Temperature::setTempCelsius(double celsiusTemp){
    celsius=celsiusTemp;
    kelvin=getTempCelsius()+273.15;
    fahrenheit=getTempCelsius()*(9.0/5.0)+32.0;
}

double Temperature::getTempCelsius()
{
    return celsius;
}

double Temperature::getTempFahrenheit()
{
    return fahrenheit;
}

double Temperature::getTempKelvin()
{
    return kelvin;
}

void Temperature::displayTemperatures()
{
    cout<<"\nTemperature in Kelvin "<<getTempKelvin()<<"K.\n";
    cout<<"Temperature in Celsius "<<getTempCelsius()<<"C.\n";
    cout<<"Temperature in Fahrenheit "<<getTempFahrenheit()<<"F.\n";

}
