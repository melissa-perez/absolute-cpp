#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int ticket_count=0;
    const int gball=3;
    const int cbar=10;
    int gball_count=0;
    int cbar_count=0;

    cout<<"Enter how many tickets you have: ";
    cin>>ticket_count;

    while(ticket_count>=10){
        cbar_count+=1;
        ticket_count-=cbar;
    }

    while(ticket_count>=3){
        gball_count+=1;
        ticket_count-=gball;
    }

    cout<<endl<<"You have enough tickets for "<<cbar_count<<" candy bar(s) and "
       <<gball_count<<" gumball(s)."<<endl;
    return 0;
}
