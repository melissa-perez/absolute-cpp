#include <iostream>
#include <cstdlib>

using namespace std;


class CounterType{
public:
    void input();
    void output();
    void setCount(int count);
    int getCount();
    int decreaseCount();
    int increaseCount();
private:
    int count=0;

};

int main(int argc, char *argv[])
{
   CounterType counter1,counter2;

   //Inputting a value to the class
   cout<<"CounterType Variable 1\n";
   counter1.input();
   counter1.increaseCount();
   counter1.output();
   counter1.increaseCount();
   counter1.output();

   cout<<"CounterType Variable 2\n";
   counter2.setCount(0);
   counter2.output();
   counter2.decreaseCount();
   counter2.output();

   return 0;
}


void CounterType::input()
{
    cout<<"Enter the count value you desire: ";
    cin>>count; //private members may be used in member function definitions but
    //not elsewhere
    if(count<0)
    {
        cout<<"Illegal count! Program aborted.\n";
        exit(1);
    }
}

void CounterType::setCount(int newCount) //Mutator function
{
    if(count<0)
    {
        cout<<"Illegal count! Program aborted.\n";
        exit(1);
    }
    else count=newCount;
}

void CounterType::output()//Output function
{
    cout<<"Current count is: ";
    cout<<count<<endl;
}

int CounterType::getCount()//Accessor function
{
    return count;
}


int CounterType::decreaseCount()
{
    cout<<"Decreasing count by 1...\n";
    if(--count<0)
    {
        cout<<"Illegal count! Program aborted.\n";
        exit(1);
    }
    return (count--);
}

int CounterType::increaseCount()
{
    cout<<"Increasing count by 1...\n";

    return(count++);
}
