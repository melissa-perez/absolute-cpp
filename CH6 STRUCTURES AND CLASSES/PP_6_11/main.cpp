#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int TOP_THREE=3;

class Player{
public:
    void setHighScore(Player top_scores[TOP_THREE]);
    void displayHighScore(Player top_scores[TOP_THREE]);
    void sort(Player top_scores[TOP_THREE]);
    void swapValues(int &v1, int &v2);
    void swapValues(string &v1, string &v2);
    int indexOfLargest(Player top_scores[TOP_THREE], int startIndex);

private:
    string player="";
    int score=0;
};

int main(int argc, char *argv[])
{
    Player top_scores[TOP_THREE];


    top_scores[TOP_THREE].setHighScore(top_scores);


    top_scores[TOP_THREE].displayHighScore(top_scores);



    return 0;
}



void Player::setHighScore(Player top_scores[TOP_THREE])
{
    fstream inputStream;
    int checkScore=0;
    string checkPlayer="",text="";
    int numberUsed=0;

    inputStream.open("scores.txt");

    while(inputStream>>text)
    {
        int index=0,j=TOP_THREE-1;
        checkPlayer=text;
        inputStream>>checkScore;

        if(numberUsed<TOP_THREE)
        {
            top_scores[numberUsed].player=text;
            top_scores[numberUsed].score=checkScore;
            numberUsed+=1;
        }
        else{
                sort(top_scores);
                while(j>-1)
                {
                    if(checkScore<top_scores[j].score&&j==2)break;
                    else if(checkScore>top_scores[j].score)
                    {
                        index=j;
                        if(index==0)
                       {
                           swapValues(top_scores[index+1].score,top_scores[index+2].score);
                           swapValues(top_scores[index+1].player,top_scores[index+2].player);
                           swapValues(top_scores[index+1].score,top_scores[index].score);
                           swapValues(top_scores[index+1].player,top_scores[index].player);
                           top_scores[index].player=checkPlayer;
                           top_scores[index].score=checkScore;
                       }
                    }
                    else
                    {
                        if(index==1)
                        {
                            swapValues(top_scores[index].score,top_scores[index+1].score);
                            swapValues(top_scores[index].player,top_scores[index+1].player);
                            top_scores[index].player=checkPlayer;
                            top_scores[index].score=checkScore;
                        }

                        else if(index==2)
                        {
                            top_scores[index].player=checkPlayer;
                            top_scores[index].score=checkScore;
                        }
                        break;
                    }
                    j--;
                }
            }
        }

    inputStream.close();
}


void Player::displayHighScore(Player top_scores[TOP_THREE])
{
    for(int i=0;i<TOP_THREE;i++)
        {
            cout<<"Player: "<<top_scores[i].player<<endl
           <<"Score: "<<top_scores[i].score<<endl;
    }
}


void Player::sort(Player top_scores[TOP_THREE])
{
    int indexOfNextLargest=0;

    for(int index=0;index<TOP_THREE;index++){
        indexOfNextLargest=indexOfLargest(top_scores,index);
        swapValues(top_scores[index].score,top_scores[indexOfNextLargest].score);
        swapValues(top_scores[index].player,top_scores[indexOfNextLargest].player);
    }
}


int Player::indexOfLargest(Player top_scores[TOP_THREE], int startIndex)
{
    int max=top_scores[startIndex].score,indexOfLarge=startIndex;
    for(int index=startIndex+1;index<TOP_THREE;index++){
        if(top_scores[index].score>max){
            max=top_scores[index].score;
            indexOfLarge=index;
        }
    }

    return indexOfLarge;
}
void Player::swapValues(string &v1, string &v2)
{
    string temp="";

    temp =v1;
    v1=v2;
    v2=temp;
}

void Player::swapValues(int &v1, int &v2)
{
    int temp=0;

    temp =v1;
    v1=v2;
    v2=temp;
}
