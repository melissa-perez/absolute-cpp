#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int TRIAL_COUNT=5000;
const int SIZE=50;

void assignBirthdays(int birthDays[SIZE][SIZE][2],int const months[12],const int days[12]);
void checkBirthDays(int  birthDays[SIZE][SIZE][2], int sameBirthDays[SIZE]);
void displayProb(int count[SIZE]);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int days[12]={31,28,31,31,
               31,30,31,31,
               30,31,30,31};
    int months[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    int count[SIZE]={0};

    for(int i=0;i<TRIAL_COUNT;i++)
    {
        int birthDays[SIZE][SIZE][2]={0};

        assignBirthdays(birthDays,months,days);
        checkBirthDays(birthDays,count);
    }
    displayProb(count);
    return 0;
}

void assignBirthdays(int birthDays[SIZE][SIZE][2], int const months[12], int const days[12])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(k==0){
                    birthDays[i][j][k]=(months[rand()%12]);
                }
               else if(k==1)
                {
                    int target=birthDays[i][j][k-1],index=0;
                    while((target-1)!=index && index<12)
                    {
                        if((target-1)==index){break;}
                        index+=1;
                    }
                    birthDays[i][j][k]=1+(rand()%days[index]);
                }
             }
         }
    }

}

void checkBirthDays(int  birthDays[SIZE][SIZE][2], int count[SIZE])
{
        for(int i=0;i<SIZE;i++)
        {
            int index1=0;
            bool found=false;
            while(index1<i)
            {
                int index2=index1+1;
                while(index2<=i)
                {
                    if((birthDays[i][index1][0]==birthDays[i][index2][0])&&(birthDays[i][index1][1]==birthDays[i][index2][1]))
                    {
                        found=true;
                        count[i]+=1;
                        break;
                    }
                    else
                    {
                        index2+=1;
                    }
                }

                if(found==true)
                {
                    found=false;
                    break;
                }
                else
                {
                   index1++;
                }
            }
       }
}

void displayProb(int count[SIZE])
{

    for(int i =1;i<SIZE;i++)
    {
        cout<<"For "<<i+1<<" people, the probability of two birthdays is about "
           <<static_cast<double>(count[i])/TRIAL_COUNT;
        cout<<endl;
    }
    cout<<endl;
}
