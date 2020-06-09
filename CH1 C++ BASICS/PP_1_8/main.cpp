#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    double n = 0.00;
    double guess = 0.00;
    double r = 0.00;
    double prev_guess = 0.00;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Babylonian Algorithm\n"
       << "Take the square root of what number? "
      << endl;
    cin >> n;
    guess = n/2;
    do{
        prev_guess = guess;
        r = n / guess;
        guess = (guess + r) / 2;
   }while(prev_guess - guess >= 0.01 * prev_guess);

    cout << "The square root of " << n << " is " << guess << endl;
    return 0;
}
