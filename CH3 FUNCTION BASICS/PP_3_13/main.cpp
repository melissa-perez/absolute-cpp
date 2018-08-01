#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int finalistSelected();
void displayWinners(int selected1,int selected2,int selected3,int selected4);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int selected1=0,selected2=0,selected3=0,selected4=0;

     selected1=finalistSelected();
     do{selected2=finalistSelected();}while(selected2==selected1);
     do{selected3=finalistSelected();}while(selected3==selected1||selected3==selected2);
     do{selected4=finalistSelected();}while(selected4==selected1||selected4==selected2||selected4==selected3);
     displayWinners(selected1,selected2,selected3,selected4);


    return 0;
}


int finalistSelected()
{
   return(1+rand()%25);
}

void displayWinners(int selected1,int selected2,int selected3,int selected4)
{
    cout<<"The selected finalists of the four prizes are: "<<selected1<<" "<<selected2<<" "<<selected3<<" "<<selected4<<endl;
}
