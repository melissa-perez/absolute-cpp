#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double item_cost=0.00,inflationRate=0.00;
    int numberOfyears=0;

    cout<<"Please input the cost of the items: $ ";
    cin>>item_cost;
    cout<<"\nPlease enter the number of years from now that you will purchase the item: ";
    cin>>numberOfyears;
    cout<<"Please enter the inflation rate as a percent (\%): ";
    cin>>inflationRate;

    inflationRate/=100.0;
    for(int i = 1;i<=numberOfyears;i++){
        item_cost+=item_cost*inflationRate;
    }

    cout<<"The price adjusted for inflation after "<<numberOfyears
       <<" year(s) is: $"<<item_cost<<endl;
   return 0;
}
