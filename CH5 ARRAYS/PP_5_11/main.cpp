#include <iostream>
#include <cmath>
#include <iomanip>

//CODE borrowed from DISPLAY 5.4
//added vertical bar plot
using namespace std;
const int NUMBER_OF_PLANTS=4;

void inputData(int a[NUMBER_OF_PLANTS],int lastPlantNumber);
void scale(int a[NUMBER_OF_PLANTS],int size);
void getTotal(int &sum);
void getMax(const int a[],int& max);
void setAsterisks(const int a[NUMBER_OF_PLANTS],char asteriskCount[][NUMBER_OF_PLANTS],int max);
void graph(const char asteriskCount[][NUMBER_OF_PLANTS],int max);


int main(int argc, char *argv[])
{
    int max=0;
    int production[NUMBER_OF_PLANTS];

    cout<<"The program displays a graph showing\n"
       <<"production for each plant in the company.\n";
    inputData(production,NUMBER_OF_PLANTS);
    scale(production,NUMBER_OF_PLANTS);
    getMax(production,max);

    char asteriskCount[max-1][NUMBER_OF_PLANTS]= {'*'};
    setAsterisks(production,asteriskCount,max);
    graph(asteriskCount,max);

    return 0;
}

void inputData(int a[NUMBER_OF_PLANTS], int lastPlantNumber)
{
    for(int plantNumber=1;plantNumber<=lastPlantNumber;plantNumber++)
    {
        cout<<endl
           <<"Enter production data for plant number "
          <<plantNumber<<endl;
        getTotal(a[plantNumber-1]);
    }
}

void getTotal(int &sum){
    cout<<"Enter number of units produced by each department.\n"
       <<"Append a negative number to the end of the list.\n";
    sum=0;
    int next;
    cin>>next;
    while(next>=0)
    {
        sum=sum+next;
        cin>>next;
    }
    cout<<"Total = "<<sum<<endl;
}

void scale(int a[NUMBER_OF_PLANTS], int size)
{
    for(int index=0;index<size;index++){
        a[index]=round(a[index]/1000.0);
    }
}

void getMax(const int a[], int& max)
{
    for(int i =0;i<NUMBER_OF_PLANTS;i++)
    {
        if(a[i]>max)max=a[i];
    }
}

void setAsterisks(const int a[NUMBER_OF_PLANTS],char asteriskCount[][NUMBER_OF_PLANTS],int max)
{
    for(int i=0;i<NUMBER_OF_PLANTS;i++)
    {
        for(int j=0;j<(max);j++)
        {
            if(j<a[i])
            {
                asteriskCount[j][i]='*';
            }
            else asteriskCount[j][i]='\0';
        }
    }
}

void graph(const char asteriskCount[][NUMBER_OF_PLANTS], int max)
{
    cout<<"\nUnits produced in thousands of units:\n\n";
    for(int plantNumber=1;plantNumber<=NUMBER_OF_PLANTS;plantNumber++)
    {
        cout<<setw(10)<<"Plant #"<<plantNumber<<" ";
    }
        cout<<endl;

    for(int i=max-1;i>=0;i--)
    {
        for(int j=0;j<NUMBER_OF_PLANTS;j++)
        {
            cout<<setw(9)<<" "<<asteriskCount[i][j];
        }
        cout<<endl;
    }
}

