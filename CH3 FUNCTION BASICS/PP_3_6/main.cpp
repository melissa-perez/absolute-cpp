#include <iostream>
#include <cmath>
using namespace std;

double scoreAverage(double s1, double s2, double s3, double s4);
double scoreVariance(double s1, double s2, double s3, double s4, double average);
double scoreSD(double s1,double s2, double s3, double s4, double average, double variance);

const int N =4;


int main(int argc, char *argv[])
{
    double s1=0.0,s2=0.0,s3=0.0,s4=0.0,avg=0.0,var=0.0,sd=0.0;
    char userInput ='a';

    do{
        cout<<"Please enter the first score: ";
        cin>>s1;
        cout<<"\nPlease enter the second score: ";
        cin>>s2;
        cout<<"\nPlease enter the third score: ";
        cin>>s3;
        cout<<"\nPlease enter the fourth score: ";
        cin>>s4;

        sd=scoreSD(s1,s2,s3,s4,avg,var);

        cout<<"\nThe standard deviation of the four score is: "<<sd;


        cout<<"\nWould you like to calculate again?(Enter Y or y): ";
        cin>>userInput;
        cout<<endl;

    }while(userInput=='Y'||userInput=='y');

    cout<<"END OF PROGRAM"<<endl;

    return 0;
}


double scoreAverage(double s1, double s2, double s3, double s4)
{
    return((s1+s2+s3+s4)/N);
}


double scoreVariance(double s1, double s2, double s3, double s4, double average)
{
    return(((pow(s1,2)+pow(s2,2)+pow(s3,2)+pow(s4,2))/N) - pow(average,2));
}

double scoreSD(double s1, double s2, double s3, double s4, double average, double variance)
{
    average=scoreAverage(s1,s2,s3,s4);
    cout<<"\nThe average of the four scores is: "<<average;
    variance=scoreVariance(s1,s2,s3,s4,average);
    return(sqrt(variance));

}

