/*Chapter 1: Programming Project 1
 * Author: Melissa Marie Perez
 * Date: June 23, 2017
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    const double METRIC_TON=35273.92;
    double weight_cereal_box=0.0;

    cout<<"Please enter the weight of the cereal box in ounces: ";
    cin>>weight_cereal_box;
    cout<<"\nThe weight of the cereal box in metric tons is: "<<
          weight_cereal_box/METRIC_TON<<" ton(s).";
    cout<<"\nYou need " <<ceil(METRIC_TON/weight_cereal_box)<<" boxes to yield a "
       <<"metric ton."<<endl;
    return 0;
}


