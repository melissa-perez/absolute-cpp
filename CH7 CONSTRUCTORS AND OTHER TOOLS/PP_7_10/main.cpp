#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class BoxOfProduce{
public:

    BoxOfProduce();
    static int salsaFlyer;
    static void subtractSalsaFlyer();
    static int getSalsaFlyer();
    void readProduce();
    void displayList();
    void setBox();
    void changeBox();
    void displaySelection();
    void checkTomatillo();
    bool getTomatillo();

private:

    string box[3];
    string boxSelection[5];
    bool hasTomatillo=false;

};
int BoxOfProduce::salsaFlyer=5;
void menu();

int main(int argc, char *argv[])
{
    srand(time(NULL));
    menu();

    cout<<"END OF PROGRAM.\n";

    return 0;
}

void BoxOfProduce::subtractSalsaFlyer()
{
    salsaFlyer-=1;
}

int BoxOfProduce::getSalsaFlyer()
{
    return salsaFlyer;
}

BoxOfProduce::BoxOfProduce()
{
    readProduce();
    setBox();
    checkTomatillo();
}

void BoxOfProduce::readProduce(){
    fstream inputStream;
    string text="";
    int numberUsed=0;
    inputStream.open("produce.txt");

    while(inputStream>>text)
    {
        boxSelection[numberUsed]=text;
        numberUsed+=1;
    }
}

void BoxOfProduce::displayList()
{
    for(int i=0;i<3;i++){
    cout<<box[i];
    cout<<":"<<i<<" ";
    cout<<endl;
    }

    if(getTomatillo()&&BoxOfProduce::getSalsaFlyer()>0)
    {
        cout<<"\nAdded: salsa verde recipe\n";
    }
}



void BoxOfProduce::displaySelection()
{
    for(int i=0;i<5;i++){
    cout<<boxSelection[i];
    cout<<":"<<i<<" ";
    cout<<endl;
    }
}
void BoxOfProduce::setBox()
{
    for(int i=0;i<3;i++)
    {
        box[i]=boxSelection[rand()%5];
    }

    checkTomatillo();
}


void menu()
{
    int choice=0;
    char ans='\0';
    BoxOfProduce box1;

    cout<<"Welcome to Community Supported Agriculture(CSA)"<<endl;
    do{

        cout<<"ENTER 1 to CREATE a new BOX."<<endl;
        cout<<"ENTER 2 to SWITCH items from CURRENT BOX."<<endl;
        cout<<"ENTER 3 to STOP creating BOXES."<<endl;

        cout<<"\nCURRENT BOX: "<<endl;
        box1.displayList();
        cout<<"\nSELECTION: ";
        cin>>choice;
        switch (choice) {

        case 1:
            cout<<"\nFINAL BOX: "<<endl;
            box1.displayList();
            cout<<"\nORDER PENDING....\n";

            if(box1.getTomatillo()) BoxOfProduce::subtractSalsaFlyer();
            cout<<"NEW BOX"<<endl;
            box1.setBox();
            box1.displayList();
            break;
        case 2:
            cout<<"\nCURRENT BOX: "<<endl;
            box1.displayList();
            box1.changeBox();
            box1.checkTomatillo();
            box1.displayList();
            break;
        case 3:
            cout<<"\nFINAL BOX: "<<endl;
            box1.displayList();
            cout<<"\nORDER PENDING....\n";
            ans='n';
            break;
        default:
            break;
        }

        if(choice !=3)
        {
            cout<<"\nWould you like to access other features from the menu?(Enter Y or y):";
            cin>>ans;
        }

    }while(ans=='y'||ans=='Y');

    BoxOfProduce::subtractSalsaFlyer();
    cout<<"\nFINAL BOX: "<<endl;
    box1.displayList();
    cout<<"\nORDER PENDING....\n";
}


void BoxOfProduce::changeBox()
{
    int toChange=0,changeWith=0;
    cout<<"\nTo switch out an item, enter the number that it corresponds to: ";
    cin>>toChange;
    if(toChange>=5 || toChange<0)
    {
        cout<<"\nIllegal entry."<<endl;
        exit(1);
    }
    displaySelection();
    cout<<"\nChange with?: ";
    cin>>changeWith;
    switch (changeWith) {
    case 0:
        box[toChange]=boxSelection[changeWith];

        break;
    case 1:
        box[toChange]=boxSelection[changeWith];
        break;
    case 2:
        box[toChange]=boxSelection[changeWith];

        break;
    case 3:
        box[toChange]=boxSelection[changeWith];

        break;
    case 4:
        box[toChange]=boxSelection[changeWith];

        break;
    default:
        cout<<"\nNo change entered.\n";
        break;
    }
}


void BoxOfProduce::checkTomatillo()
{
    bool toSet=false;
    for(int i=0;i<3;i++)
    {
        if(box[i]=="Tomatillo")
        {
            toSet=true;
        }
    }

    hasTomatillo=toSet;
}


bool BoxOfProduce::getTomatillo()
{
    return hasTomatillo;
}
