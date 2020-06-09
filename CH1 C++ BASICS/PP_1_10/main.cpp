/*
10. Write a program that allows the user to enter a
time in seconds and then outputs
how far an object would drop if it is in freefall
for that length of time. Assume no
friction or resistance from air and
a constant acceleration of 32 feet per second due
to gravity. Use the equation
Distance = 1/2* acceleration * time^2
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    double time = 0.00; //in seconds
    const double ACCELERATION = 32.0; //feet per second
    double distance = 0.00;

    cout << "Enter time in seconds: ";
    cin >> time;
    distance = (0.5) * ACCELERATION * pow(time,2.00);

    cout << "An object in freefall for " << time << " secs will go a distance of " << distance
       << " ft. \n";

    return 0;
}
