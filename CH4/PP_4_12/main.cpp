//Over the 10000 duels, Bob wins the most, followed by Aaron.
//Charlie has the lowest win percentage.
//This is using the attack the deadliest opponent strategy.
/*Sample Output:

Aaron won 3692/10000 duels or 36.92 %
Bob won 4055/10000 duels or 40.55 %
Charlie won 2252/10000 duels or 22.52 %
Press <RETURN> to close this window...

*/

//Now using the strategy where Aaron misses intentionally.
//Over 10000 duels, Aaron wins the most, followed by Charlie.
//Bob has the lowest win percentage.
/*Sample Output:
Aaron won 4197/10000 duels or 41.97 %
Bob won 2528/10000 duels or 25.28 %
Charlie won 3274/10000 duels or 32.74 %
Press <RETURN> to close this window...
 */
//Therefore the better strategy for Aaron is to miss his shot in order
//to have the highest percentage in winning.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const double AARON_HIT= (1.0/3.0);
const double BOB_HIT=(1.0/2.0);
const double CHARLIE_HIT=1.0;
const double DUEL_COUNT=10000;

void aaronTurn(bool& bobAlive,bool&charlieAlive, bool aaronAlive);
void bobTurn(bool& aaronAlive,bool& charlieAlive,bool bobAlive);
void charlieTurn(bool& aaronAlive, bool& bobAlive,bool charlieAlive);
void tallyWinner(bool bobAlive, bool aaronAlive, bool charlieAlive,double& aaronWins,double& bobWins,double& charlieWins);
void displayWinner(double aaronWins, double bobWins, double charlieWins);

int main(int argc, char *argv[])
{
    double aaronWins=0, bobWins=0,charlieWins=0;
    srand(time(NULL));

    for(int i =1;i<=DUEL_COUNT;i++){
        bool aaronAlive=1, bobAlive=1,charlieAlive=1;
        do{
            aaronTurn(bobAlive,charlieAlive,aaronAlive);
            if((aaronAlive+bobAlive+charlieAlive)==1){break;}
            bobTurn(aaronAlive,charlieAlive,bobAlive);
            if((aaronAlive+bobAlive+charlieAlive)==1){break;}
            charlieTurn(aaronAlive,bobAlive,charlieAlive);
            if((aaronAlive+bobAlive+charlieAlive)==1){break;}
        }while((aaronAlive+bobAlive+charlieAlive)>1);
        tallyWinner(bobAlive, aaronAlive, charlieAlive,aaronWins,bobWins,charlieWins);
    }
    displayWinner(aaronWins,bobWins,charlieWins);
    return 0;
}

void aaronTurn(bool&  bobAlive,bool& charlieAlive, bool aaronAlive)
{
    double hitChance=(RAND_MAX - rand( ))/ static_cast < double >(RAND_MAX);
    double maxHitter=(( charlieAlive==1 )? CHARLIE_HIT:BOB_HIT);

    //to have the first strategy remove the second condition in the following statement
    if(aaronAlive==1 &&((bobAlive+charlieAlive+aaronAlive)<3)){
        if((charlieAlive==1)&&(maxHitter==CHARLIE_HIT))
        {
            if(hitChance<AARON_HIT){charlieAlive=0;}
        }
        else if((bobAlive==1)&&(maxHitter==BOB_HIT))
        {
            if(hitChance<AARON_HIT){bobAlive=0;}
        }
    }
}

void bobTurn(bool&  aaronAlive,bool& charlieAlive, bool bobAlive)
{
    double hitChance=(RAND_MAX - rand( ))/ static_cast < double >(RAND_MAX);
    double maxHitter=(charlieAlive==1)?CHARLIE_HIT:AARON_HIT;

    if(bobAlive==1){
        if((charlieAlive==1)&&(maxHitter==CHARLIE_HIT))
        {
            if(hitChance<BOB_HIT){charlieAlive=0;}
        }
        else if((aaronAlive==1)&&(maxHitter==AARON_HIT))
        {
            if(hitChance<BOB_HIT){aaronAlive=0;}
        }
    }
}

void charlieTurn(bool&  aaronAlive,bool& bobAlive, bool charlieAlive)
{
    double hitChance= (RAND_MAX - rand( ))/ static_cast < double >(RAND_MAX);
    double maxHitter=(bobAlive==1)?BOB_HIT:AARON_HIT;

    if(charlieAlive==1){
            if((aaronAlive==1)&&(maxHitter==AARON_HIT))
        {

            if(hitChance<CHARLIE_HIT){aaronAlive=0;}
        }
        else if((bobAlive==1)&&(maxHitter==BOB_HIT))
        {
                if(hitChance<CHARLIE_HIT){bobAlive=0;}
        }
    }
}

void tallyWinner(bool bobAlive, bool aaronAlive, bool charlieAlive,double& aaronWins,double& bobWins,double& charlieWins)
{
    if(bobAlive==1){bobWins+=1;}
    else if (aaronAlive==1) {aaronWins+=1;}
    else if (charlieAlive==1) {charlieWins+=1;}
}

void displayWinner(double aaronWins, double bobWins, double charlieWins)
{
    cout<<"Aaron won "<<aaronWins<<"/"<<DUEL_COUNT<<" duels or "<<(aaronWins/DUEL_COUNT)*100.0<<" \%"<<endl;
    cout<<"Bob won "<<bobWins<<"/"<<DUEL_COUNT<<" duels or "<<(bobWins/DUEL_COUNT)*100.0<<" \%"<<endl;
    cout<<"Charlie won "<<charlieWins<<"/"<<DUEL_COUNT<<" duels or "<<(charlieWins/DUEL_COUNT)*100.0<<" \%"<<endl;

}
