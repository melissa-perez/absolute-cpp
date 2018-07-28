#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE =50;
//may assume that the size is smaller than 50

void fillArray(int a[],int& numberUsed);
bool search(int countArray[],int numberUsed, int target, int& targetIndex);
void getUnique(const int a[],int countArray[][2],int numberUsed, int& uniqueEntry);
void sort(int countArray[][2],int uniqueEntry);
void swapValues(int& v1, int& v2);
int indexOfLargest(int countArray[][2],int startIndex, int uniqueEntry);


int main(int argc, char *argv[])
{
    int numberUsed=0,uniqueEntry=0;
    int a[SIZE]={0};

    fillArray(a,numberUsed);

    int countArray[numberUsed][2]={0};

    getUnique(a,countArray,numberUsed,uniqueEntry);
    sort(countArray,uniqueEntry);

   for(int i=0;i<uniqueEntry;i++){
         for(int j=0;j<2;j++){
             cout<<setw(5);
             cout<<countArray[i][j];
         }
         cout<<endl;
    }
    return 0;
}

void fillArray(int a[],int &numberUsed)
{
    cout<<"You may enter up to "<<SIZE<<" numbers.\n";
    int next=0,index=0;
    char ans='y';

    while((index<SIZE)&&(ans=='y'||ans=='Y'))
    {
        cout<<"Enter a number:";
        cin>>next;
        a[index]=next;
        index++;
        numberUsed+=1;
        cout<<"\nEnter another number? (Key in y or Y): ";
        cin>>ans;
    }
}

bool search(int countArray[][2], int numberUsed, int target, int& targetIndex)
{
    int index=0;
    bool found=false;
    while((!found)&&(index<numberUsed)){
        if(target==countArray[index][0]){
            found=true;
            targetIndex=index;
        }
        else index++;
    }
    return found;
}

void getUnique(const int a[],int countArray[][2],int numberUsed,int& uniqueEntry)
{
    int index=0,i=0;
    bool flagZero=false;
    while(i<numberUsed)
    {
        int targetIndex=0;
        if((search(countArray,numberUsed,a[i],targetIndex)==0))
        {
            countArray[index][0]=a[i];
            countArray[index][1]+=1;
            index++;
            uniqueEntry+=1;

        }
        else if(search(countArray,numberUsed,a[i],targetIndex)==1)
        {
            if((a[i]==0) && (flagZero==false)){
                flagZero=true;
                 countArray[targetIndex][1]+=1;
                 index++;
                 uniqueEntry+=1;
            }
            else{countArray[targetIndex][1]+=1;}
        }
        i++;
    }
}


void sort(int countArray[][2], int uniqueEntry)
{
    int indexOfNextLargest=0;

    for(int index=0;index<uniqueEntry;index++){
        indexOfNextLargest=indexOfLargest(countArray,index,uniqueEntry);
        swapValues(countArray[index][0],countArray[indexOfNextLargest][0]);
         swapValues(countArray[index][1],countArray[indexOfNextLargest][1]);
    }
}

void swapValues(int &v1, int &v2)
{
    int temp;

    temp =v1;
    v1=v2;
    v2=temp;
}


int indexOfLargest(int countArray[][2], int startIndex, int uniqueEntry)
{
    int max=countArray[startIndex][0],indexOfLarge=startIndex;
    for(int index=startIndex+1;index<uniqueEntry;index++){
        if(countArray[index][0]>max){
            max= countArray[index][0];
            indexOfLarge=index;
        }
    }

    return indexOfLarge;
}
