#include <iostream>

using namespace std;

const int ARBITRARY_NUMBER=10; //change this to add or lower the amount
//of grades entered
const int SCORE_RANGE=6;


void enterGrade(int hist[]);
void histogram (int hist[],int score);
void displayHist(int hist[]);

int main(int argc, char *argv[])
{
    int hist[SCORE_RANGE]={0};
    enterGrade(hist);
    displayHist(hist);
    return 0;
}

void histogram(int hist[],int score)
{
    for(int j=0;j<SCORE_RANGE;j++){
            if(score==j){
                hist[j]+=1;
            }
        }
}

void enterGrade(int hist[])
{
    cout<<"Enter "<<ARBITRARY_NUMBER<<" quiz scores."<<endl
       <<"The grades range from 0 to 5.";
    int grade=-1,index=0;

    while(index<ARBITRARY_NUMBER){
        cout<<"\nEnter the "<<index+1<<" grade: ";
        cin>>grade;

        if(grade<0 || grade>5){
            cout<<"Incorrect entry."<<endl;
        }
        else{
            histogram(hist,grade);
            index++;
        }
    }
}



void displayHist(int hist[])
{
    cout<<"QUIZ RESULTS OF "<<ARBITRARY_NUMBER<<" STUDENTS"<<endl;
    for(int i=0;i<SCORE_RANGE;i++)cout<<hist[i]<<" grade(s) of "<<i<<endl;
}
