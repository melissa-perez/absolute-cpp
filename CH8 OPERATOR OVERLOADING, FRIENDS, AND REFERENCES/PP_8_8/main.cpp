#include <iostream>

using namespace std;

// Uses my code from 6.10
// Does not sanitize input
class Temperature{
public:
    void setTempKelvin(double);
    void setTempFahrenheit(double);
    void setTempCelsius(double);
    double getTempKelvin() const;
    double getTempFahrenheit() const;
    double getTempCelsius() const;
    void displayTemperatures();
    friend ostream& operator <<(ostream&,
                            const Temperature&);
    friend istream& operator >>(istream&,
                                 Temperature&);
    friend bool operator ==(const Temperature&, const Temperature&);

private:
    double kelvin = 0.0;
};

int main(int argc, char *argv[]){

    Temperature temp1, temp2;

    cout << "Enter temperature 1 in Fahrenheit: ";
    cin >> temp1;

    cout << "Enter temperature 2 in Fahrenheit: ";
    cin >> temp2;

    cout << temp1;
    cout << temp2;

    if(temp1 == temp2)
    {
        cout << "Temp 1 equals Temp 2!" << endl;
    }
    else
    {
        cout << "Temp 1 DOES NOT equals Temp 2!" << endl;
    }

    return 0;
}

void Temperature::setTempKelvin(double K){

    if(K >= 0)
        kelvin = K;
}

void Temperature::setTempFahrenheit(double F){

    double C = 0.0;

    C = (5.0 / 9) * (F - 32);
    kelvin = C + 273.15;
}

void Temperature::setTempCelsius(double C){

    kelvin = C + 273.15;
}

double Temperature::getTempCelsius() const{

    double celsius = kelvin - 273.15;
    return celsius;
}

double Temperature::getTempFahrenheit() const{

    double fahrenheit = getTempCelsius() * (9.0 / 5.0) + 32.0;
    return fahrenheit;
}

double Temperature::getTempKelvin() const{

    return kelvin;
}

void Temperature::displayTemperatures(){

    cout << "\nTemperature in Kelvin " << getTempKelvin() << " K.\n";
    cout << "Temperature in Celsius " << getTempCelsius() << " C.\n";
    cout << "Temperature in Fahrenheit " << getTempFahrenheit() << " F." << endl << endl;

}


bool operator ==(const Temperature& temp1,
                              const Temperature& temp2){

    return (temp1.kelvin == temp2.kelvin);
}

ostream& operator <<(ostream& out, const Temperature& temp){

    out << "Temp: " << temp.getTempFahrenheit() << " F." << endl;
    return out;
}

istream& operator >>(istream& in, Temperature& temp){

    double F = 0.0;

    in >> F;
    temp.setTempFahrenheit(F);
    return in;
}
