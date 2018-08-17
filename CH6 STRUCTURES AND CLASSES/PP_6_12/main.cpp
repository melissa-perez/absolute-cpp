#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

const int NUMBER_OF_ITEMS=3;
const int VARIETY_OF_ITEMS=5;
class BoxOfProduce{
public:
    void initBox(string[],BoxOfProduce[]);
    void output(BoxOfProduce toDeliver[]);
    void setBox(BoxOfProduce[],string[]);

private:
    string bundle="";
};

void readProduce(string[]);
void displayList(string []);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    BoxOfProduce box[NUMBER_OF_ITEMS];
    string selection[VARIETY_OF_ITEMS];
    char ans='\0';

    readProduce(selection);
    box[NUMBER_OF_ITEMS].initBox(selection,box);

    do{
        box[NUMBER_OF_ITEMS].output(box);

        box[NUMBER_OF_ITEMS].setBox(box,selection);
        box[NUMBER_OF_ITEMS].output(box);
        cout<<"Would you like to change the contents of the box? (Enter Y or y): ";
        cin>>ans;
        cout<<endl;

    }while(ans=='y'||ans=='Y');

    cout<<"Your final order is...";
    box[NUMBER_OF_ITEMS].output(box);
    cout<<"ORDER PENDING.\n";
    return 0;
}


void readProduce(string fileToRead[VARIETY_OF_ITEMS]){
    fstream inputStream;
    string text="";
    int numberUsed=0;
    inputStream.open("produce.txt");

    while(inputStream>>text)
    {
        fileToRead[numberUsed]=text;
        numberUsed+=1;
    }
}

void displayList(string fileToRead[VARIETY_OF_ITEMS])
{
    for(int i=0;i<VARIETY_OF_ITEMS;i++){
    cout<<fileToRead[i];
    cout<<":"<<i<<" ";
    cout<<endl;
    }
}

void BoxOfProduce::initBox(string fileRead[VARIETY_OF_ITEMS], BoxOfProduce toShip[NUMBER_OF_ITEMS])
{
    for(int i=0;i<NUMBER_OF_ITEMS;i++)
    {
        toShip[i].bundle=fileRead[rand()%(VARIETY_OF_ITEMS-1)];
    }
}

void BoxOfProduce::output(BoxOfProduce toDeliver[])
{
    cout<<"Your box currently contains: ";
    for(int i=0;i<NUMBER_OF_ITEMS;i++)
    {
        cout<<toDeliver[i].bundle;
        cout<<":"<<i<<" ";
    }
    cout<<endl;
}

void BoxOfProduce::setBox(BoxOfProduce box[], string selection[])
{
    int toChange=0,changeWith=0;
    cout<<"\nTo switch out an item, enter the number that it corresponds to: ";
    cin>>toChange;
    if(toChange>=5 || toChange<0)
    {
        cout<<"\nIllegal entry."<<endl;
        exit(1);
    }
    displayList(selection);
    cout<<"\nChange with?: ";
    cin>>changeWith;
    switch (changeWith) {
    case 0:
        box[toChange].bundle=selection[changeWith];

        break;
    case 1:
        box[toChange].bundle=selection[changeWith];
        break;
    case 2:
        box[toChange].bundle=selection[changeWith];

        break;
    case 3:
        box[toChange].bundle=selection[changeWith];

        break;
    case 4:
        box[toChange].bundle=selection[changeWith];

        break;
    default:
        cout<<"\nNo change entered.\n";
        break;
    }
}
