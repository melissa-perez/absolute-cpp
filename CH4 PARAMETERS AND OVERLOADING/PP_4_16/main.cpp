#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void getHighScore(string& player, int& score);
int main(int argc, char *argv[])
{
    string player="";
    int score=0;

    getHighScore(player,score);
    cout<<"Player: "<<player<<endl
       <<"High Score: "<<score<<endl;
    return 0;
}

void getHighScore(string &player, int &score)
{
    fstream inputStream;
    string checkPlayer="",text="";
    int checkScore=0;

    inputStream.open("scores.txt");

    while(inputStream >> text){

        checkPlayer=text;
        inputStream>>checkScore;

        if(checkScore>score){
            score=checkScore;
            player=checkPlayer;
        }
    }
    inputStream.close();
}
