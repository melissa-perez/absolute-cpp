//The win rate is around 66% when you switch doors instead of staying. To
//optimize winning the player should switch doors. Although keeping the same door, might seem to work in smaller trials, it does not optimize winning.


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int GAME_SIM =10000;
void setPrizes(int& door1, int& door2, int& door3);
void doorPicked(int& doorChosen);
void checkDoor(int doorChosen, int door1,int door2,int door3, int& winStay, int& winSwitch);
void displayWinRate(int winStay, int winSwitch);

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int winSwitch=0,winStay=0;

    for(int i =0;i<GAME_SIM;i++){
        int door1=0,door2=0,door3=0,doorChosen=0;
        setPrizes(door1,door2,door3);
        doorPicked(doorChosen);
       // cout<<door1<<" "<<door2<<" "<<door3<<endl;
        checkDoor(doorChosen,door1,door2,door3,winStay,winSwitch);
    }
    displayWinRate(winStay,winSwitch);
    return 0;
}

void setPrizes(int &door1, int &door2, int &door3)
{
    int temp1=0,temp2=0,temp3=0;
    while(temp1 == temp2||temp2==temp3||temp1==temp3){
        temp1=rand()%101;
        temp2=rand()%101;
        temp3=rand()%101;
    }
    door1= (temp1>max(temp2,temp3))?1:0;
    door2= (temp2>max(temp1,temp3))?1:0;
    door3= (temp3>max(temp2,temp1))?1:0;
}

void doorPicked(int &doorChosen)
{
    doorChosen=1+rand()%3;
}

void checkDoor(int doorChosen, int door1,int door2,int door3,int& winStay, int& winSwitch)
{
    //cout<<doorChosen<<"hi"<<endl;
    switch (doorChosen) {
    case 1:
        if(door2==0 && door3==0){
                winStay++;
        }
        else {
            winSwitch++;
        }
        break;
    case 2:
        if(door1==0 && door3==0){
                winStay++;
        }
        else {
            winSwitch++;
        }
        break;
    case 3:
        if(door1==0&& door2==0){
                winStay++;
        }
        else {
            winSwitch++;
        }
        break;
    }
}


void displayWinRate(int winStay, int winSwitch)
{
    cout<<"For "<<GAME_SIM<<" game simulations: "<<endl;
    cout<<"Your win rate when you stay is "<<(winStay*100.0)/GAME_SIM<<"\%."<<endl;
    cout<<"Your win rate when you switch is "<<(winSwitch*100.0)/GAME_SIM<<"\%."<<endl;

}
