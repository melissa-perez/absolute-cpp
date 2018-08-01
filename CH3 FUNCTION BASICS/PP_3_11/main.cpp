#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);
int diceRoll();
void pigIntroduction();
void pigDirections();
void playerPrompt();
void currentScore(int score);
void possibleScore(int score);
void displayWinner(int playerScore,int computerScore);

int main()
{
    srand(time(NULL));

    char userAnswer='A';

    do{
        int humanTotalScore=0,computerTotalScore=0;
        pigIntroduction();
        do{
            humanTotalScore=humanTurn(humanTotalScore);
            if(humanTotalScore>=100)break;
            computerTotalScore=computerTurn(computerTotalScore);
            if(computerTotalScore>=100)break;

        }while(humanTotalScore<100||computerTotalScore<100);//

        displayWinner(humanTotalScore,computerTotalScore);
        cout<<"\nWould you like play again?(Enter Y or y): ";
        cin>>userAnswer;



    }while(userAnswer=='y'||userAnswer=='Y');
    cout<<"\nEND OF PROGRAM."<<endl;

    return 0;
}

void pigIntroduction()
{
    char userAnswer='A';

    cout<<"Welcome to the Game of Pig"<<endl;

    do{
        cout<<"\nRead directions(Enter Y or y)?: ";
        cin>>userAnswer;
        if(userAnswer=='y'||userAnswer=='Y'){
            pigDirections();
            userAnswer='A';
        }


    }while(userAnswer=='y'||userAnswer=='Y');
}

void pigDirections()
{
   cout<<"\nPig is a TWO-PLAYER dice game in which the first player"<<endl
      <<"to reach 100 or more points wins!"<<endl;
   cout<<"Enter r to roll again for a chance to earn more points,\n"
      <<"or h to hold and add the points earned and end your turn.\n"<<endl;
   cout<<"If you roll a 1, your turn ends. BE CAREFUL!"<<endl;
}

void playerPrompt()
{
    cout<<"Enter r to roll again or h to hold: ";

}

void currentScore(int score)
{
   cout<<"Your current score: "<<score<<endl;
}

void possibleScore(int score)
{
    cout<<"Current possible points to add: "<<score<<endl;
}

int diceRoll()
{
    int currentRoll=0;
    currentRoll=1+rand()%6;

    cout<<"You rolled a "<<currentRoll<<endl;

    return(currentRoll);
}
int humanTurn(int humanTotalScore)
{
    char humanInput ='r';
    int currentRoll=0,cmlPts=0;

    cout<<endl<<"BEGIN PLAYER's TURN"<<endl;
    currentScore(humanTotalScore);


    do{
       currentRoll= diceRoll();
       if(currentRoll==1){
           cmlPts=0;
           possibleScore(cmlPts);
           currentScore(humanTotalScore);
           cout<<"\nEND OF TURN. NO POINTS AWARDED.\n";
           return(humanTotalScore);
       }
       else if(currentRoll>=2&&currentRoll<=6){
           cmlPts+=currentRoll;
           possibleScore(cmlPts);
           currentScore(humanTotalScore);
           playerPrompt();
           cin>>humanInput;


           if(humanInput=='H'||humanInput=='h'){
               humanTotalScore+=cmlPts;
               cout<<"Points added: "<< cmlPts<<endl;
               currentScore(humanTotalScore);

               cout<<endl<<"END PLAYER's TURN"<<endl;
               return(humanTotalScore);
           }
       }

       }while(humanInput=='R'||humanInput=='r');


    cout<<endl<<"END PLAYER's TURN"<<endl;
    return cmlPts;
}

int computerTurn(int computerTotalScore)
{
    int currentRoll=0,cmlPts=0;

    cout<<endl<<"BEGIN COMPUTER's TURN"<<endl;
    currentScore(computerTotalScore);

    do{
       currentRoll= diceRoll();
       if(currentRoll==1){
           currentScore(computerTotalScore);
           cmlPts=0;
           possibleScore(cmlPts);
           cout<<"\nEND OF TURN. NO POINTS AWARDED.\n";
           return(computerTotalScore);
       }
       else if(currentRoll>=2&&currentRoll<=6){
            cmlPts+=currentRoll;
           }

       }while(cmlPts<20);

    computerTotalScore+=cmlPts;
    cout<<"Points added: "<< cmlPts<<endl;
    currentScore(computerTotalScore);
    cout<<endl<<"END COMPUTER's TURN"<<endl;
    return computerTotalScore;
}



void displayWinner(int playerScore, int computerScore)
{
    if(playerScore>computerScore){
        cout<<"\nPLAYER IS THE WINNER WITH "<<playerScore<<" points."<<endl;

    }
    else{
        cout<<"\nCOMPUTER IS THE WINNER WITH "<<computerScore<<" points."<<endl;
    }
}
