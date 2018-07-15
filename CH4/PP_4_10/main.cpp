#include <iostream>

using namespace std;

void chooseConversion(int& userPicks, int& userPicks2);
bool checkConversion(int& userPicks);
void inputData(double& value1,double &value2,int userPicks, int userPicks2);
bool verifyData(double value1,double value2);
void convert(double& value1, double& value2, double& value3, double& value4,int userPicks,int userPicks2);
void displayConversion(double value1, double value2,double value3, double value4,int userPicks, int userPicks2);

const double METER_TO_FOOT=0.3048;
const double CM_TO_M=100.0;
const double IN_TO_FT=12.0;

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
           int userPicks=0,userPicks2=0;
           double value1=0, value2=0,value3=0,value4=0;
           chooseConversion(userPicks,userPicks2);

           if(userPicks==1){
               inputData(value1,value2,userPicks,userPicks2);
               convert(value1,value2,value3,value4,userPicks,userPicks2);
               displayConversion(value1,value2,value3,value4,userPicks,userPicks2);
           }
           else{
               inputData(value1,value2,userPicks,userPicks2);
               convert(value1,value2,value3,value4,userPicks,userPicks2);
               displayConversion(value1,value2,value3,value4,userPicks,userPicks2);
           }
           cout<<"Would you like to enter another value(Enter Y or y)?:";
           cin>>userAnswer;
           cout<<endl;
       }while(userAnswer=='Y'||userAnswer=='y');
   cout<<"END OF PROGRAM"<<endl;
    return 0;
}


void chooseConversion(int &userPicks,int &userPicks2)
{
    do{
        cout<<"Which type of conversion would you like to do?\n"
           <<"Enter 1 for weights or\n"
          <<"Enter 2 for lengths: ";
        cin>>userPicks;

    }while(checkConversion(userPicks)==0);

    if(userPicks==1){

        do{
            cout<<"Which type of conversion would you like to do?\n"
               <<"Enter 1 for lb. and oz. to kg. and g. or\n"
              <<"Enter 2 for kg. and g. to lb. and oz.: ";
            cin>>userPicks2;

        }while(checkConversion(userPicks2)==0);
    }

    else{
        do{
            cout<<"Which type of conversion would you like to do?\n"
                  <<"Enter 1 for ft. and in. to m. and cm. or\n"
                  <<"Enter 2 for m. and cm. to ft. and in.: ";
            cin>>userPicks2;
        }while(checkConversion(userPicks2)==0);
    }
}

bool checkConversion(int &userPicks)
{
    bool toCheck= userPicks==1 || userPicks==2;
    if(toCheck==0){
        cout<<"\nIncorrect entry. Try again."<<endl;
    }
    return(toCheck);
}

void inputData(double& value1, double& value2, int userPicks, int userPicks2)
{
       if(userPicks==1){
           if(userPicks2==1){
                do{
                    cout<<"Please enter how many lb. or lbs.: ";
                    cin>>value1;
                    cout<<"and how many ounce(s): ";
                    cin>>value2;
                }while(verifyData(value1,value2)==0);
            }
            else{
                do{
                    cout<<"Please enter how many kilogram(s): ";
                    cin>>value1;
                    cout<<"and how gram(s): ";
                    cin>>value2;
                }while(verifyData(value1,value2)==0);
            }
       }
       else{
           if(userPicks2==1){
           do{
               cout<<"Please enter how many feet or foot: ";
               cin>>value1;
               cout<<"and how many inch(es): ";
               cin>>value2;
            }while(verifyData(value1,value2)==0);
           }

            else{
                do{
                    cout<<"Please enter how many meter(s): ";
                    cin>>value1;
                    cout<<"and how centimeter(s): ";
                    cin>>value2;
                }while(verifyData(value1,value2)==0);
           }

       }
}

bool verifyData(double value1, double value2)
{
    bool isValid= value1>=0 && value2>=0;
    if(isValid==0){cout<<"\nIncorrect measurement entry. Try again."<<endl;}
    return(isValid);
}


void convert(double& value1, double& value2, double& value3, double& value4,int userPicks,int userPicks2)
{
    if(userPicks==1){
        if(userPicks2==1){
            value3=value1/LB_TO_KG;
            value4=((value2/OZ_TO_LB)/LB_TO_KG)*G_TO_KG;
        }
        else{
            value3=value1*LB_TO_KG;
            value4=((value2/G_TO_KG)*LB_TO_KG)*OZ_TO_LB;
        }
    }
    else{
        if(userPicks2==1){
            value3=value1*METER_TO_FOOT;
            value4=(value2/IN_TO_FT)*METER_TO_FOOT*CM_TO_M;
        }
        else{
            value3=value1/METER_TO_FOOT;
            value4=((value2/CM_TO_M)/METER_TO_FOOT)*IN_TO_FT;
        }
    }
}

void displayConversion(double value1, double value2,double value3, double value4,int userPicks,int userPicks2)
{
    if(userPicks==1){
        if(userPicks2==1){
        cout<<"Converted: "<<value1<<" LB. "<<value2<<" OZ. to"<<endl;
        cout<<value3<<" KG. "<<value4<<" G."<<" or "<<value3+(value4/G_TO_KG)<<" KG. "<<"or "<<(value3+(value4/G_TO_KG))*G_TO_KG<<" G."<<endl;
    }

    else{
        cout<<"Converted: "<<value1<<" KG. "<<value2<<" G. to"<<endl;
        cout<<value3<<" LB. "<<value4<<" OZ."<<" or "<<value3+(value4/OZ_TO_LB)<<" LB. "<<"or "<<(value3+(value4/OZ_TO_LB))*OZ_TO_LB<<" OZ."<<endl;
       }
    }

    else{
        if(userPicks2==1){
                cout<<"Converted: "<<value1<<" ft. "<<value2<<" in. to"<<endl;
                cout<<value3<<" m. "<<value4<<" cm."<<" or "<<value3+(value4/CM_TO_M)<<" m. "<<"or "<<(value3+(value4/CM_TO_M))*CM_TO_M<<" cm."<<endl;
        }
        else{
                cout<<"Converted: "<<value1<<" m. "<<value2<<" cm. to"<<endl;
                cout<<value3<<" ft. "<<value4<<" in. "<<"or "<<value3+(value4/IN_TO_FT)<<" ft. "<<"or "<<(value4+(value3*IN_TO_FT))<<" in."<<endl;
        }

    }
}
