#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_LIMIT=9999;
class Counter{
public:
    Counter(int limit);//custom const followed by setCounter*
    Counter(); //default const*

    void setCounter(int limit);//checks the max entered by user and sets it correctly*
    void reset();//resets counter to 0*
    void incr1();//increase the rightmost of the counter
    void incr10();//increase the second rightmost of counter
    void incr100();//increase the second leftmost of counter
    void incr1000();//increase the leftmost of the counter
    bool overflow(); //will declare overflow if the amount goes over the max
    int getMax(); //returns max entered by user or set by const *
    int getCounter();//returns current number *
    void menu();
private:
        int max_count;//maximum to reach
        int counter; //keeps tally
        char last_selection;
};

int main(int argc, char *argv[])
{
    Counter littleRedCounter;
    littleRedCounter.reset();

    while(littleRedCounter.overflow()==0)
    {
        littleRedCounter.menu();

    }
    return 0;
}

bool Counter::overflow()
{
    if(counter>max_count||last_selection=='o')
    {

        cout<<"OVERFLOW"<<endl;
        return true;
    }

    else return false;
}


Counter::Counter(int limit):max_count(limit),counter(0),last_selection('\0'){}
Counter::Counter():max_count(MAX_LIMIT),counter(0),last_selection('\0')
{
    char tensDollars,Dollars,tensCents,cents,point;

    cout<<"Enter the limit for your counter(in dollar and cent format)): $";
    cin>>tensDollars>>Dollars>>point>>tensCents>>cents;
    int limit=static_cast<int>(tensDollars-'0')*1000+static_cast<int>(Dollars-'0')*100
            +static_cast<int>(tensCents-'0')*10+static_cast<int>(cents-'0');
    setCounter(limit);
}
void Counter::setCounter(int limit)
{
    if(limit<0 ||limit>MAX_LIMIT){
        cout<<"\nIncorrect max setting. Default to $99.99.\n";
        max_count=MAX_LIMIT;
    }

    else max_count=limit;
}
void Counter::reset()
{
    counter=0;
}
int Counter::getMax()
{
    return max_count;
}
int Counter::getCounter()
{
    return counter;
}

void Counter::menu()
{
    char choice='\0';
    cout<<"Current counter: $"<<(getCounter()/1000)
       <<(((getCounter()%1000)/100))<<"."<<(((getCounter()%1000)%100)/10)<<(((getCounter()%1000)%100)%10)<<endl;
    cout<<"Limit set: $"<<(getMax()/1000)
       <<(((getMax()%1000)/100))<<"."<<(((getMax()%1000)%100)/10)<<(((getMax()%1000)%100)%10)<<endl;
    cout<<"Enter a to increase cents.\n";
    cout<<"Enter s to increase dimes.\n";
    cout<<"Enter d to increase dollars.\n";
    cout<<"Enter f to increase tens of dollars.\n";
    cout<<"Enter o to request overflow and exit.\n";
    cout<<"Selection: ";
    cin>>choice;
    switch (choice) {
    case 'a':
        incr1();
        last_selection=choice;
        break;
    case 's':
        incr10();
        last_selection=choice;
        break;
    case 'd':
        incr100();
        last_selection=choice;
        break;
    case 'f':
        incr1000();
        last_selection=choice;
        break;
    case 'o':
        last_selection=choice;
        cout<<"\nOverflow selected."<<endl;
    }
}

void Counter::incr1()
{
    int cents=0;
    while(cents<1 || cents>9){
        cout<<"\nEnter how many cents to add (from 1-9): ";
        cin>>cents;
    }
     counter+=cents;
}


void Counter::incr10()
{
    int tens=0;
    while(tens<1 || tens>9){
        cout<<"\nEnter how many tens of cents to add (from 1-9): ";
        cin>>tens;
    }
     counter+=(tens*10);
}

void Counter::incr100()
{
    int huns=0;
    while(huns<1 || huns>9){
        cout<<"\nEnter how many dollars to add (from 1-9): ";
        cin>>huns;
    }
     counter+=(huns*100);
}

void Counter::incr1000()
{
    int thou=0;
    while(thou<1 || thou>9){
        cout<<"\nEnter how many tens of dollars to add (from 1-9): ";
        cin>>thou;
    }
     counter+=(thou*1000);
}
