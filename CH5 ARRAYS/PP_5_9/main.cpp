#include <iostream>
#include <string>
using namespace std;

void selectOrder(char& player1, char& player2);
void displayBoard(char position[9]);
void playerTurn(char position[9],char marker, bool& noWinner,string& playerMoves,int& numberUsed);
void checkWinner(bool& noWinner,string playerMoves,int numberUsed);
bool checkOrder(char input);
bool checkInput(char input);
void displayWinner(char marker);
int indexOfSmallest(string moves, int startIndex, int numberUsed);
void swapValues(char &v1, char &v2);
void sort(string& moves, int numberUsed);

int main(int argc, char *argv[])
{
    char ans='a';

    do{
        bool noWinner=true,isDraw=false;
        char player1='a',player2='a';
        char position[9]={'1','2','3','4','5','6','7','8','9'};
        string player1Moves="", player2Moves="";
        int numberUsed1=0,numberUsed2=0;

        selectOrder(player1,player2);
        while(noWinner)
        {
            displayBoard(position);
            playerTurn(position,player1,noWinner,player1Moves,numberUsed1);
            for(int i=0;i<8;i++)
            {
                if(position[i]=='X'||position[i]=='O')
                {
                    isDraw=true;
                }
                else
                {
                    isDraw=false;
                }
            }

            if(isDraw==true)
            {
                cout<<"Game is a DRAW.\n";
                break;
            }
            if(noWinner==false)
            {
                displayBoard(position);
                displayWinner(player1);
                break;
            }
            displayBoard(position);
            playerTurn(position,player2,noWinner,player2Moves,numberUsed2);
            if(noWinner==false)
            {
                displayBoard(position);
                displayWinner(player2);
                break;
            }
        }


        cout<<"\nPlay another game?(Enter y or Y): ";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
    cout<<"END OF PROGRAM.\n";
    return 0;
}

bool checkOrder(char input)
{
    if(input == 'X'|| input =='x'|| input == 'o'|| input =='O')
    {
         return true;
    }
    else{

        cout<<"Incorrect entry.\n";
        return false;
    }
}
void selectOrder(char& player1, char& player2)
{
    char selection='a';
    do{
            cout<<"Player 1 selects either X or O, Player 2 will default to the other marker: ";
            cin>>selection;
    }while(checkOrder(selection)==false);

    switch (selection) {
    case 'x':
        player1='X';
        player2='O';
        break;
    case 'X':
        player1='X';
        player2='O';
        break;
    case 'o':
        player1='O';
        player2='X';
        break;
    case 'O':
        player1='O';
        player2='X';
        break;
    default:
        break;
    }
}

void displayBoard(char position[9])
{
    int count=0;
    cout<<"Current game board: "<<endl;
    for(int i=0;i<9;i++)
    {
        cout<<position[i]<<" ";
        count+=1;
        if(count==3){
            cout<<endl;
            count=0;
        }
    }
}

void playerTurn(char position[9],char marker,bool& noWinner, string &playerMoves,int & numberUsed)
{
    char input='0';

    do{
        cout<<"Enter a position for "<<marker<<":";
        cin>>input;

        if(position[(static_cast<int>(input)-48)-1]=='X'||position[(static_cast<int>(input)-48)-1]=='O')
        {
            input='0';
        }
    }while(checkInput(input)==false);

    position[(static_cast<int>(input)-48)-1]=marker;
    playerMoves+=input;
    numberUsed+=1;
    sort(playerMoves,numberUsed);
    checkWinner(noWinner,playerMoves,numberUsed);
}

bool checkInput(char input)
{
    if((input< '1'|| input>'9'))
    {
        cout<<"Incorrect entry.\n";
        return false;
    }
    return true;
}

void sort(string& moves, int numberUsed)
{
    int indexOfNextLargest=0;

    for(int index=0;index<numberUsed;index++)
    {
        indexOfNextLargest=indexOfSmallest(moves,index,numberUsed);
        swapValues(moves[index],moves[indexOfNextLargest]);

    }
}


void swapValues(char &v1, char &v2)
{
    char temp='a';

    temp =v1;
    v1=v2;
    v2=temp;
}



int indexOfSmallest(string moves, int startIndex, int numberUsed)
{
    char min=moves[startIndex];
    int indexOfSmall=startIndex;

    for(int index=startIndex+1;index<numberUsed;index++){
        if(moves[index]<min){
            min= moves[index];
            indexOfSmall=index;
        }
    }
   return indexOfSmall;
}


void checkWinner(bool& noWinner,string playerMoves,int numberUsed)
{
   string winCombos[8]={"123","456","147","159","789",
                         "369","357","258"};
   int index=0;
   string move="";


   while(index<numberUsed-2 && numberUsed>=3)
   {
       move+=playerMoves[index];
       move+=playerMoves[index+1];
       move+=playerMoves[index+2];
       for(int i=0;i<8;i++)
       {
          if(move==winCombos[i])
          {
            noWinner=false;
            break;
          }
       }
       if(noWinner==false)
       {
           break;
       }
       move="";
       index+=1;
   }
}

void displayWinner(char marker)
{
    cout<<"\nPlayer "<<marker<<" wins!"<<endl;
}
