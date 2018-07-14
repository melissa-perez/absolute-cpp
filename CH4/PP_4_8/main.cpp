#include <iostream>

using namespace std;

const double LB_TO_KG=2.2046;
const double G_TO_KG=1000.0;
const double OZ_TO_LB=16.0;

void inputKGandG(double& kilograms, double& grams);
bool verifyMeasurements(double kilograms, double grams);
void convertKGandG(double& pounds, double& ounces, double kilograms,double grams);
void displayLBandOZ(double pounds,double ounces, double kilograms, double grams);

int main(int argc, char *argv[])
{
    double pounds=0, ounces=0,kilograms=0,grams=0;
    char userAnswer='A';

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    do{
        inputKGandG(kilograms,grams);
        convertKGandG(pounds,ounces,kilograms,grams);
        displayLBandOZ(pounds,ounces,kilograms,grams);

        cout<<"Would you like to enter another value(Enter Y or y)?:";
        cin>>userAnswer;
        cout<<endl;
    }while(userAnswer=='Y'||userAnswer=='y');

    cout<<"END OF PROGRAM"<<endl;

    return 0;
}

void inputKGandG(double &kilograms, double &grams)
{
    do{
        cout<<"Please enter how many kilogram(s): ";
        cin>>kilograms;
        cout<<"and how many gram(s): ";
        cin>>grams;
    }while(verifyMeasurements(kilograms,grams)==0);
}

bool verifyMeasurements(double kilograms, double grams)
{
    bool isValid= kilograms>=0 && grams>=0;

    if(isValid==0){
        cout<<"\nIncorrect measurement entry. Try again."<<endl;
    }
    return(isValid);
}

void convertKGandG(double& pounds, double& ounces, double kilograms, double grams)
{
    pounds=kilograms*LB_TO_KG;
    ounces=((grams/G_TO_KG)*LB_TO_KG)*OZ_TO_LB;
}

void displayLBandOZ(double pounds, double ounces,double kilograms, double grams)
{
    cout<<"Converted: "<<kilograms<<" KG. "<<grams<<" G. to"<<endl;
    cout<<pounds<<" LB. "<<ounces<<" OZ."<<" or "<<pounds+(ounces/OZ_TO_LB)<<" LB. "<<"or "<<(pounds+(ounces/OZ_TO_LB))*OZ_TO_LB<<" OZ."<<endl;

}
