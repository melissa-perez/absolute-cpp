#include <iostream>
#include <cmath>
using namespace std;


double average(double const numberArray[],int size);
double stdDev(const double numberArray[],double avg,int size);
int main(int argc, char *argv[])
{
    double numberArray[50]={2,1,5,100,20,4,99,-1,2,-4,100},avg=0,std=0;
    int size =11;

    avg=average(numberArray,size);
    std=stdDev(numberArray,avg,size);

    cout<<"The array: ";
    for(int i=0;i<size;i++){cout<<numberArray[i]<<" ";}
    cout<<endl;
    cout<<"The average of the array is: "<<avg<<endl;
    cout<<"The standard deviation of the array is: "<<std<<endl;
    return 0;
}

double average(const double numberArray[], int size)
{
    double sum=0;
    for(int i=0;i<size;i++){sum+=numberArray[i];}
    return(sum/size);
}

double stdDev(const double numberArray[],double avg,int size)
{
    double sum=0;
    for(int i=0;i<size;i++) {sum+=(pow(numberArray[i]-avg,2));}

    return(sqrt(sum/size));
}
