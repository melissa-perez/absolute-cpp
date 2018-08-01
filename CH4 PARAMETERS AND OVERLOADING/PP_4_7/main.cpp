#include <iostream>

using namespace std;

const double LB_TO_KG=2.2046;
const double G_TO_KG=1000.0;
const double OZ_TO_LB=16.0;

void inputLBandOZ(double& pounds, double& ounces);
bool verifyMeasurements(double pounds, double ounces);
void convertLBandOZ(double pounds, double ounces, double& kilograms,double& grams);
void displayKGandG(double pounds,double ounces, double kilograms, double grams);

int main(int argc, char *argv[])
{
    double pounds=0, ounces=0,kilograms=0,grams=0;
    char userAnswer='A';

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    do{
        inputLBandOZ(pounds,ounces);
        convertLBandOZ(pounds,ounces,kilograms,grams);
        displayKGandG(pounds,ounces,kilograms,grams);

        cout<<"Would you like to enter another value(Enter Y or y)?:";
        cin>>userAnswer;
        cout<<endl;
    }while(userAnswer=='Y'||userAnswer=='y');

    cout<<"END OF PROGRAM"<<endl;

    return 0;
}

void inputLBandOZ(double &pounds, double &ounces)
{
    do{
        cout<<"Please enter how many pound(s): ";
        cin>>pounds;
        cout<<"and how many ounce(s): ";
        cin>>ounces;
    }while(verifyMeasurements(pounds,ounces)==0);
}

bool verifyMeasurements(double pounds, double ounces)
{
    bool isValid= pounds>=0 && ounces>=0;

    if(isValid==0){
        cout<<"\nIncorrect measurement entry. Try again."<<endl;
    }
    return(isValid);
}

void convertLBandOZ(double pounds, double ounces, double &kilograms, double &grams)
{
    kilograms=pounds/LB_TO_KG;
    grams=((ounces/OZ_TO_LB)/LB_TO_KG)*G_TO_KG;
}

void displayKGandG(double pounds, double ounces,double kilograms, double grams)
{
    cout<<"Converted: "<<pounds<<" LB. "<<ounces<<" OZ. to"<<endl;
    cout<<kilograms<<" KG. "<<grams<<" G."<<" or "<<kilograms+(grams/G_TO_KG)<<" KG. "<<"or "<<(kilograms+(grams/G_TO_KG))*G_TO_KG<<" G."<<endl;

}
