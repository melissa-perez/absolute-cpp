#include <iostream>

using namespace std;

int heightOfChild(char genderOfChild, int motherHeight,int fatherHeight);

int main(int argc, char *argv[])
{
    char genderOfChild='a',userAnswer='b';
    int feet=0,inches=0,motherHeight=0,fatherHeight=0,childHeight=0;

    do{
        cout << "Please enter the gender of the child(M for male or F for female): ";
        cin>>genderOfChild;
        cout<<"\nPlease enter the height of of the mother(feet only): ";
        cin>>feet;
        cout<<"\nPlease enter the height of of the mother(inches only): ";
        cin>>inches;

        motherHeight=12*feet+inches;
        cout<<"\nMother's height: "<<feet<<"\' and "<<inches<<"\" or "<<motherHeight<<" inches";

        cout<<"\nPlease enter the height of of the father(feet only): ";
        cin>>feet;
        cout<<"\nPlease enter the height of of the father(inches only): ";
        cin>>inches;

        fatherHeight=12*feet+inches;
        cout<<"\nFather's height: "<<feet<<"\' and "<<inches<<"\" or "<<fatherHeight<<" inches";

        childHeight=heightOfChild(genderOfChild,motherHeight,fatherHeight);
        if(childHeight!=1){
            cout<<"\nThe height of the child will be "<<childHeight<<" inches or "<<childHeight/12<<" \'"<<childHeight%12<<" \"."<<endl;
        }


        cout<<"\nWould you like to calculate again?(Enter Y or y): ";
        cin>>userAnswer;
    }while(userAnswer=='y'||userAnswer=='Y');

    cout<<"END OF PROGRAM."<<endl;

    return 0;
}


int heightOfChild(char genderOfChild, int motherHeight, int fatherHeight)
{
    if(genderOfChild=='M'||genderOfChild=='m')
    {
        return((motherHeight*(13/12)+fatherHeight)/2);
    }
    else if(genderOfChild=='F'||genderOfChild=='f')
    {
        return(((fatherHeight*12)/13+motherHeight)/2);
    }

    else{
        cout<<"\nIncorrect gender entry."<<endl;
        return 1;
    }
}
