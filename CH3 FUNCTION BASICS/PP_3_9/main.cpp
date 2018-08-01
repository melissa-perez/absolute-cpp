//Over the long run, the probability of winning against the house and vice-versa is close to 50-50 using no seed and seed outcomes.
//Making craps + pass line bet an almost fair casino game to play and win!


#include <iostream>
#include <cstdlib>
#include <ctime> //to make the dice rolls a bit more random

using namespace std;

int diceRoll();
int sumDice(int die1,int die2);
int comeOutRoll(int diceTotal);

int main(int argc, char *argv[])
{
    int die1=0,die2=0,diceTotal=0,firstResult=0,thePoint=0;
    double wins=0,losses=0;
    //srand(time(NULL));
    srand(99); //to allow reproduceability

    cout<<"This program will simulate 10,000 runs of craps using the \"Pass Line\" bet strategy."<<endl;

    for(int i=1;i<=10000;i++){
         die1=diceRoll();
         die2=diceRoll();
         diceTotal=sumDice(die1,die2);
         firstResult=comeOutRoll(diceTotal);

         if(firstResult==1){
             wins+=1;
         }
         else if(firstResult==2){
             losses+=1;
         }

         else if(firstResult==3){
             thePoint=diceTotal;
              do{
                 die1=diceRoll();
                 die2=diceRoll();
                 diceTotal=sumDice(die1,die2);
                 if(diceTotal==7){
                     losses+=1;
                     break;
                 }
                 else if(diceTotal==thePoint){
                     wins+=1;
                     break;
                 }
             }while(diceTotal!=thePoint ||diceTotal!=7);
             }
         }
    cout<<"End of simulation."<<endl;
    cout<<"Using this betting style, there is a "<<(wins/(wins+losses))*100<<" \% win rate."<<endl;

    return 0;
}


int diceRoll()
{
    return(1+rand()%6);
}


int sumDice(int die1, int die2)
{
    return(die1+die2);
}

int comeOutRoll(int diceTotal)
{
    if(diceTotal==7||diceTotal==11) return(1);
    else if(diceTotal==2||diceTotal==3||diceTotal==12) return(2);
    else if(diceTotal==4||diceTotal==5||diceTotal==6||diceTotal==8||diceTotal==9||diceTotal==10) return(3);
}
