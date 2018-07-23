#include <iostream>
//we can assume all letters are lower case
//the empty char is \0
using namespace std;

void deleteRepeats(char a[], int& size);
void swapValues(char& v1, char& v2);

int main(int argc, char *argv[])
{
    char a[20]={'e','i','o','u','t','o', 'm','e','i','u','p','m','e','z','e','i','m'};
    int size=17;

    cout<<"Before deleteRepeats function:";

    for(int i =0;i<20;i++) cout<<a[i];

    cout<<endl<<"Size of array: "<<size<<endl;

    deleteRepeats(a,size);

    cout<<"After deleteRepeats function:";

    for(int i =0;i<20;i++) cout<<a[i];

    cout<<endl<<"Size of new array: "<<size<<endl;

    return 0;
}

void deleteRepeats(char a[], int &size)
{
    for(int i=0;i<size;i++){
        int countOfNull=0;

        for(int j =i+1;j<size;j++){
            if(a[i]==a[j]){
                a[j]='\0';
                countOfNull+=1;
            }   
        }
      for(int k=1;k<size;k++){
          //cout<<k<<" Pre:";
          //for(int i =0;i<20;i++) cout<<a[i];
          //cout<<endl;
          if(a[k]=='\0'){
              swapValues(a[k],a[k+1]);
          }
          if (a[k-1]=='\0'){
              swapValues(a[k-1],a[k]);
          }
          //cout<<k<<" Post:";
          //for(int i =0;i<20;i++) cout<<a[i];
          //cout<<endl;
      }
      size-=countOfNull;
    }
}


void swapValues(char &v1, char &v2)
{
    char temp='a';
    temp=v2;
    v2=v1;
    v1=temp;
}
