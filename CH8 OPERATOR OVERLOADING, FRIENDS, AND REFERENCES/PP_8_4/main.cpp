#include <iostream>
#include <cstdlib>
using namespace std;
 class CharPair{

    public:
        //Commented out code is previous code
        //CharPair( ){ /*Body intentionally empty*/ }
        //CharPair( char firstValue, char secondValue):
        //first(firstValue), second(secondValue){ /*Body intentionally empty*/}

        CharPair();
        CharPair(int);
        CharPair(int, char[]);
        int getSize(){return size;}
        char& operator[](int index);

    private:
        //char first;
        //char second;
        char charArray[100];
        int size;
 };

 int main( ){
    CharPair a;

    cout<<"The size of a is "<<a.getSize()<<endl;
    cout<<"The contents in a before changing the 3rd element: ";
    for(int i =0;i<a.getSize();i++)
    {
        cout<<a[i]<<" ";
    }
    a[2]='m';
    cout<<"\nThe contents in a after changing the 3rd element: ";
    for(int i =0;i<a.getSize();i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<"\nTrying to change with a bad index: \n";
    a[-1]='<';

    cout<<"The contents in a after correcting the bad index: ";
    for(int i =0;i<a.getSize();i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<"\nCreating a new CharPair object and setting the first 40 values to \'#\': ";

    CharPair b(40);
    cout<<"\n";
    for(int i =0;i<b.getSize();i++)
    {
        cout<<b[i]<<" ";
    }

    cout<<"\nCreating a char array object of size 8 to pass into constructor: ";

    int size = 8;
    char outsideArr[size];
    for(int i =0 ; i <size; i++)
    {
        outsideArr[i]= 48 +i;
    }

    for(int i =0;i<size;i++)
    {
        cout<<outsideArr[i]<<" ";
    }

    cout<<"\nCreating a new CharPair object and setting the first 8 values to outsideArr: ";
    CharPair c(size,outsideArr);

    for(int i =0;i<c.getSize();i++)
    {
        cout<<c[i]<<" ";
    }

    /*a[1] = 'A';
    a[2] = 'B';

    cout << "a[1] and a[2] are:\n";
    cout << a[1] << a[2] << endl;
    cout << "Enter two letters (no spaces):\n";
    cin >> a[1] >> a[2];
    cout << "You entered:\n";
    cout << a[1] << a[2] << endl;*/

    return 0;
 }

CharPair::CharPair()
{
    size =10;
    for(int i =0;i<size;i++)
    {
        charArray[i]='#';
    }
}

CharPair::CharPair(int sz)
{
    size =sz;
    for(int i =0;i<size;i++)
    {
        charArray[i]='#';
    }
}

CharPair::CharPair(int sz, char otherArr[])
{
    size =sz;
    for(int i =0;i<size;i++)
    {
        charArray[i]=otherArr[i];
    }
}
 //Uses iostream and cstdlib:
 char& CharPair:: operator[](int index){

    while(index>=size || index < 0)
    {
        cout<<"Index entered is invalid.\nValid ranges are from 0 - "<<size-1<<"\n";
        cout<<"Please enter another index: ";
        cin>>index;
    }
        return charArray[index];
 }
