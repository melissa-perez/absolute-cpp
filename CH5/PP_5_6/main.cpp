#include <iostream>

using namespace std;

const int MAX_INTEGER_LENGTH=7;
const float MODIFIER=0.6;

void enterScores(float scoreArray[MAX_INTEGER_LENGTH]);
void enterDive(float& diveLevel);
void indexOfLargest(float scoreArray[MAX_INTEGER_LENGTH],int& max);
void indexOfSmallest(float scoreArray[MAX_INTEGER_LENGTH],int& min);
void totalScore(float& sum,float scoreArray[MAX_INTEGER_LENGTH],int max,int min,float& diveLevel);

int main(int argc, char *argv[])
{
    float diveLevel=0,sum=0;
    int max=0,min=0;
    float scoreArray[MAX_INTEGER_LENGTH]={0};

    enterScores(scoreArray);
    enterDive(diveLevel);
    indexOfLargest(scoreArray,max);
    indexOfSmallest(scoreArray,min);
    totalScore(sum,scoreArray,max,min,diveLevel);

    cout<<"The "<<MAX_INTEGER_LENGTH<<" scores: ";
    for(int i=0; i<MAX_INTEGER_LENGTH;i++)cout<<scoreArray[i]<<" ";
    cout<<endl<<"The dive difficulty: "<<diveLevel;
    cout<<endl<<"The final score: "<<sum<<endl;

    return 0;
}


void enterScores(float scoreArray[MAX_INTEGER_LENGTH])
{
        cout<<"You may enter up to "<<MAX_INTEGER_LENGTH<<" scores.\n";
        int index=0;
        float score=0;

        cout<<"Please enter a score between 0 to 10. "<<endl;

        while((index<MAX_INTEGER_LENGTH))
        {
            cout<<"Please enter the "<<index+1<<" score: ";
            cin>>score;
            if(score<0||score>10)
            {
                cout<<"Incorrect score entry."<<endl;
            }
            else
            {
               scoreArray[index]=score;
               index++;
            }
        }
}

void enterDive(float& diveLevel)
{
    while(diveLevel<1.2||diveLevel>3.8)
    {
        cout<<"Please enter a difficulty level for the dive. "<<endl
           <<"Level ranges from 1.2 to 3.8: ";
        cin>>diveLevel;
    }
}

void indexOfLargest(float scoreArray[], int& startIndex)
{
        int max=scoreArray[startIndex],indexOfLarge=startIndex;
        for(int index=startIndex+1;index<=MAX_INTEGER_LENGTH;index++){
            if(scoreArray[index]>max){
                max= scoreArray[index];
                indexOfLarge=index;
            }
        }
        startIndex=indexOfLarge;
}


void indexOfSmallest(float scoreArray[], int& startIndex)
{
        int min=scoreArray[startIndex],indexOfSmallest=startIndex;

        for(int index=startIndex+1;index<=MAX_INTEGER_LENGTH;index++){
            if(scoreArray[index]<min){
                min= scoreArray[index];
                indexOfSmallest=index;
            }
        }
        startIndex=indexOfSmallest;
}

void totalScore(float& sum,float scoreArray[], int max, int min,float& diveLevel)
{
    int i=0,count=0;

    while((count<(MAX_INTEGER_LENGTH-2))){
        if(i==max||i==min);
        else{
            sum=sum+scoreArray[i];
            count++;
        }
        i++;
    }
    sum=(sum*diveLevel*0.6);
}
