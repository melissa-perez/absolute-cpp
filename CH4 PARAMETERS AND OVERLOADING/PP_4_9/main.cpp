#include <iostream>

using namespace std;

void chooseConversion(int& userPicks);
bool checkConversion(int& userPicks);
void inputWeight(double& weight1,double &weight2,int userPicks);
bool verifyWeight(double weight1,double weight2);

void convert(double& pounds, double& ounces, double& kilograms, double& grams,int userPicks);
void displayConversion(double pounds, double ounces,double kilograms, double grams, int userPicks);


const double LB_TO_KG=2.2046;
const double G_TO_KG=1000.0;
const double OZ_TO_LB=16.0;

int main(int argc, char *argv[])
{
    char userAnswer='A';
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    do{
        int userPicks=0;
        double pounds=0, ounces=0,kilograms=0,grams=0;
        chooseConversion(userPicks);
        if(userPicks==1){
            inputWeight(pounds,ounces,userPicks);
            convert(pounds,ounces,kilograms,grams,userPicks);
            displayConversion(pounds,ounces,kilograms,grams,userPicks);
        }
        else{
            inputWeight(kilograms,grams,userPicks);
            convert(pounds,ounces,kilograms,grams,userPicks);
            displayConversion(pounds,ounces,kilograms,grams,userPicks);
        }
        cout<<"Would you like to enter another value(Enter Y or y)?:";
        cin>>userAnswer;
        cout<<endl;
    }while(userAnswer=='Y'||userAnswer=='y');
    cout<<"END OF PROGRAM"<<endl;
    return 0;
}

void chooseConversion(int &userPicks)
{
    do{
        cout<<"Which type of conversion would you like to do?\n"
           <<"Enter 1 for lb. and oz. to kg. and g. or\n"
          <<"Enter 2 for kg. and g. to lb. and oz.: ";
        cin>>userPicks;

    }while(checkConversion(userPicks)==0);
}

bool checkConversion(int &userPicks)
{
    bool toCheck= userPicks==1 || userPicks==2;
    if(toCheck==0){
        cout<<"\nIncorrect entry. Try again."<<endl;
    }
    return(toCheck);
}

void inputWeight(double& weight1, double& weight2, int userPicks)
{
       if(userPicks==1){
           do{
               cout<<"Please enter how many lb. or lbs.: ";
               cin>>weight1;
               cout<<"and how many ounce(s): ";
               cin>>weight2;
           }while(verifyWeight(weight1,weight2)==0);
       }
       else{
           do{
               cout<<"Please enter how many kilogram(s): ";
               cin>>weight1;
               cout<<"and how gram(s): ";
               cin>>weight2;
           }while(verifyWeight(weight1,weight2)==0);
       }
}

bool verifyWeight(double weight1, double weight2)
{
    bool isValid= weight1>=0 && weight2>=0;
    if(isValid==0){cout<<"\nIncorrect measurement entry. Try again."<<endl;}
    return(isValid);
}

void convert(double& pounds, double& ounces, double& kilograms, double& grams,int userPicks)
{
    if(userPicks==1){
        kilograms=pounds/LB_TO_KG;
        grams=((ounces/OZ_TO_LB)/LB_TO_KG)*G_TO_KG;
    }
    else{
        pounds=kilograms*LB_TO_KG;
        ounces=((grams/G_TO_KG)*LB_TO_KG)*OZ_TO_LB;
    }
}

void displayConversion(double pounds, double ounces,double kilograms, double grams,int userPicks)
{
    if(userPicks==1){
        cout<<"Converted: "<<pounds<<" LB. "<<ounces<<" OZ. to"<<endl;
        cout<<kilograms<<" KG. "<<grams<<" G."<<" or "<<kilograms+(grams/G_TO_KG)<<" KG. "<<"or "<<(kilograms+(grams/G_TO_KG))*G_TO_KG<<" G."<<endl;
    }
    else{
        cout<<"Converted: "<<kilograms<<" KG. "<<grams<<" G. to"<<endl;
        cout<<pounds<<" LB. "<<ounces<<" OZ."<<" or "<<pounds+(ounces/OZ_TO_LB)<<" LB. "<<"or "<<(pounds+(ounces/OZ_TO_LB))*OZ_TO_LB<<" OZ."<<endl;
       }
}
