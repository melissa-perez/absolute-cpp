#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int SIZE=4;
void shuffle(char deckOfCards[SIZE][SIZE],int count[8]);
bool allTaken(char cards[SIZE][SIZE],char toCheck);
void initializeBoard(char cardState[SIZE][SIZE]);
void displayBoard(char cardState[SIZE][SIZE]);
void enterPosition(char cardState[SIZE][SIZE],int& row, int& col);
bool checkCoordinates(char cardState[SIZE][SIZE],int row, int col);
void flipCard(char& previousNumber,char deckOfCards[SIZE][SIZE],char cardState[SIZE][SIZE],int row, int col,int& prevRow,int& prevCol);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    char deckOfCards[SIZE][SIZE]={'\0'};
    char cardState[SIZE][SIZE]={'\0'};
    int count[8]={0},previousRow=0,previousCol=0;
    char previousNumber='\0';

    shuffle(deckOfCards,count);
    initializeBoard(cardState);
    //displayBoard(deckOfCards);
    //cout<<endl;
    while(!allTaken(cardState,'*'))
    {
        int row=0,col=0;

        displayBoard(cardState);
        enterPosition(cardState,row,col);
        flipCard(previousNumber,deckOfCards,cardState,row,col,previousRow,previousCol);
    }
    cout<<endl;
    displayBoard(cardState);
    cout<<"\nYou matched all the cards!"<<endl;
    return 0;
}


void shuffle(char deckOfCards[SIZE][SIZE],int count[])
{
        while(!allTaken(deckOfCards,'\0'))
        {
            for(int row=0;row<SIZE;row++)
            {
                for(int col =0;col<SIZE;col++)
                {
                    int i=1+rand()%8;
                    if((count[i-1]<2)&& (deckOfCards[row][col]=='\0'))
                    {
                        deckOfCards[row][col]=static_cast<char>(i)+48;
                        count[i-1]+=1;
                    }
                }
            }
        }
}

bool allTaken(char deckOfCards[SIZE][SIZE],char toCheck)
{
    bool cardTaken=false;


    for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                if(deckOfCards[i][j]!=toCheck)
                {
                    cardTaken=true;
                }
                else{
                    cardTaken=false;
                    break;
                }

            }
            if(cardTaken==false)break;

        }
    return cardTaken;
}

void initializeBoard(char cardState[SIZE][SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
         cardState[i][j]='*';
        }
    }
}

void displayBoard(char cardState[SIZE][SIZE])
{

    cout<<setw(4)<<"|";
    for(int i=1;i<5;i++)
    {
        cout<<setw(4)<<i;
    }
    cout<<endl;
    for(int i=0;i<12;i++)cout<<"--";
    cout<<endl;
    for(int i=0;i<SIZE;i++)
    {
        cout<<setw(3)<<i+1<<"|";
        for(int j=0;j<SIZE;j++)
        {
            cout<<setw(4)<<cardState[i][j];
        }
        cout<<endl;
    }
}
void enterPosition(char cardState[SIZE][SIZE],int& row, int& col)
{
    do{
        cout<<"\nEnter the row number: ";
        cin>>row;
        row-=1;
        cout<<"\nEnter the col number: ";
        cin>>col;
        col-=1;
    }while(!checkCoordinates(cardState,row,col));

}

bool checkCoordinates(char cardState[SIZE][SIZE],int row, int col)
{
    if((row>=SIZE)||(row<0)||(col>=SIZE)||(col<0)||cardState[row][col]!='*')
    {
        cout<<"\nIncorrect position.\n";
        return false;
    }
    else return true;
}

void flipCard(char& prevNum,char deckOfCards[SIZE][SIZE], char cardState[SIZE][SIZE], int row, int col,int& prevRow,int& prevCol)
{
    if(prevNum=='\0')
    {
        cardState[row][col]=deckOfCards[row][col];
        prevNum=cardState[row][col];
        prevRow=row;
        prevCol=col;
    }
    else
    {
        if(deckOfCards[row][col]==prevNum)
        {
            cardState[row][col]=deckOfCards[row][col];
            prevNum='\0';
            prevRow=0;
            prevCol=0;
        }
        else
        {
           cardState[row][col]='*';
           cardState[prevRow][prevCol]='*';
           prevNum='\0';
           prevRow=0;
           prevCol=0;
        }
    }
}
