#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    const double FORMULA_C= 0.0175;
    const double LB_TO_KG=1.0/2.2;
    double user_weight=0.00;
    double METS =0.00;
    double mins=0.00;
    double calories_per_min=0.00;

    cout<<"Enter your weight in lbs.: ";
    cin>>user_weight;
    cout<<endl<<"Enter your activity METS: ";
    cin>>METS;
    cout<<"Enter the minutes spent on the activity: ";
    cin>>mins;

    calories_per_min=FORMULA_C*METS*(user_weight*LB_TO_KG)*mins;

    cout<<"Estimated calories burned: "<< calories_per_min<<endl;

    return 0;
}
