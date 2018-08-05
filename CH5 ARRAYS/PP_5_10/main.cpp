#include <iostream>
#include <string>

using namespace std;

void createPlane(char planeSeats[7][4]);
void chooseSeats(char planeSeats[7][4],int& rowNumber, char& seatChair);
void displayPlane(char planeSeats[7][4]);
bool checkRowNumber(int rowNumber);
bool checkSeatChair(char seatChair);
bool allTaken(char planeSeats[7][4]);
int convert(char c);

int main(int argc, char *argv[])
{
    char planeSeats[7][4]={'0'}, ans ='a';
    int rowNumber=0;
    char seatChair='Z';
    createPlane(planeSeats);

    do{
        displayPlane(planeSeats);
        chooseSeats(planeSeats,rowNumber,seatChair);
        if(allTaken(planeSeats))
        {
            displayPlane(planeSeats);
            cout<<"\nAll seats are TAKEN.";
            break;
        }
        cout<<"\nContinue choosing more seats?(Enter Y or y): ";
        cin>>ans;
    }while(ans=='y' || ans=='Y');
    cout<<"\nFinal seat configuration.\n";
    displayPlane(planeSeats);
    cout<<"END OF PROGRAM."<<endl;
    return 0;
}

void createPlane(char planeSeats[7][4])
{
    string seats="ABCD";
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<4;j++)
        {
            planeSeats[i][j]=seats[j];
        }
    }
}

void displayPlane(char planeSeats[7][4])
{
    for(int i=0;i<7;i++)
    {
        cout<<i+1<<" ";
        for(int j=0;j<4;j++)
        {
            cout<<planeSeats[i][j]<< " ";
        }
        cout<<"\n"<<endl;
    }
}

void chooseSeats(char planeSeats[7][4],int& rowNumber,char& seatLetter)
{
    bool isTaken=false;
    int seatNum=0;

    do{
        do{
            cout<<"Enter row number: ";
            cin>>rowNumber;
        }while(!checkRowNumber(rowNumber));

        do{
            cout<<"Enter chair letter: ";
            cin>>seatLetter;
        }while(!checkSeatChair(seatLetter));

        seatNum=convert(seatLetter);

        if(planeSeats[rowNumber-1][seatNum]=='X')
        {
            cout<<"SEAT is TAKEN!"<<endl;
            isTaken=true;
        }
        else{

            planeSeats[rowNumber-1][seatNum]='X';
            isTaken=false;
        }

    }while(isTaken==true);
}

bool checkRowNumber(int rowNumber)
{
    if(rowNumber>7 || rowNumber<1){
        cout<<"Incorrect row number.\n";
        return false;
    }
    return true;
}

bool checkSeatChair(char seatChair)
{
    if(seatChair=='A' || seatChair=='B'|| seatChair=='C'||seatChair=='D')
    {
        return true;
    }

    cout<<"Incorrect chair location.\n";
    return false;
}

bool allTaken(char planeSeats[7][4])
{
    bool seatTaken=false;

    for(int i=0;i<7;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(planeSeats[i][j]=='X')
                {
                    seatTaken=true;
                }

                else{
                    seatTaken=false;
                }
            }
        }
    return seatTaken;
}


int convert(char c)
{
    int rtn=0;
    switch (c)
    {
    case 'A':
        rtn = 0;
        break;
    case 'B':
        rtn = 1;
        break;
    case 'C':
        rtn = 2;
        break;
    case 'D':
        rtn = 3;
        break;
    }

    return rtn;
}
