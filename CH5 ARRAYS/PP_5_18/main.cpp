#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int TOP_THREE=3;
void getHighScore(string player[TOP_THREE], int score[TOP_THREE]);
void swapValues(string &v1, string &v2);
void swapValues(int &v1, int &v2);
int indexOfLargest(int score[TOP_THREE],int startIndex);
void sort(string player[TOP_THREE],int score[TOP_THREE]);

int main(int argc, char *argv[])
{
    string player[TOP_THREE]={""};
    int score[TOP_THREE]={0};

    getHighScore(player,score);

    for(int i=0;i<TOP_THREE;i++)
    {
        cout<<"Player: "<<player[i]<<endl
       <<"High Score: "<<score[i]<<endl;
    }
    return 0;
}

void getHighScore(string player[TOP_THREE], int score[TOP_THREE])
{
    fstream inputStream;
    string checkPlayer="",text="";
    int checkScore=0;
    int numberUsed=0;
    inputStream.open("scores.txt");

    while(inputStream >> text)
    {
        int index=0,j=TOP_THREE-1;
        checkPlayer=text;
        inputStream>>checkScore;
        if(numberUsed<3)
       {
         player[numberUsed]=checkPlayer;
         score[numberUsed]=checkScore;
         numberUsed+=1;
        }
        else{
            sort(player,score);
            while(j>-1)
            {
                if(checkScore<score[j]&&j==2)break;
                else if(checkScore>score[j])
                {
                    index=j;
                    if(index==0)
                   {
                       swapValues(score[index+1],score[index+2]);
                       swapValues(player[index+1],player[index+2]);
                       swapValues(score[index+1],score[index]);
                       swapValues(player[index+1],player[index]);
                       player[index]=checkPlayer;
                       score[index]=checkScore;
                   }
                }
                else
                {
                    if(index==1)
                    {
                        swapValues(score[index],score[index+1]);
                        swapValues(player[index],player[index+1]);
                        player[index]=checkPlayer;
                        score[index]=checkScore;
                    }

                    else if(index==2)
                    {
                        player[index]=checkPlayer;
                        score[index]=checkScore;
                    }
                    break;
                }
                j--;
            }
        }
    }

    inputStream.close();
}


void swapValues(string &v1, string &v2)
{
    string temp="";

    temp =v1;
    v1=v2;
    v2=temp;
}

void swapValues(int &v1, int &v2)
{
    int temp=0;

    temp =v1;
    v1=v2;
    v2=temp;
}

int indexOfLargest(int score[TOP_THREE], int startIndex)
{
    int max=score[startIndex],indexOfLarge=startIndex;
    for(int index=startIndex+1;index<TOP_THREE;index++){
        if(score[index]>max){
            max=score[index];
            indexOfLarge=index;
        }
    }

    return indexOfLarge;
}

void sort(string player[TOP_THREE],int score[TOP_THREE])
{
    int indexOfNextLargest=0;

    for(int index=0;index<TOP_THREE;index++){
        indexOfNextLargest=indexOfLargest(score,index);
        swapValues(score[index],score[indexOfNextLargest]);
        swapValues(player[index],player[indexOfNextLargest]);
    }
}
