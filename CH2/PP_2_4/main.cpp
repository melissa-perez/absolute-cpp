#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int prime=0;
    for(int n=3;n<=100;n++){
        for(int i=2;i<=n-1;i++){
            if(n%i==0){
                prime=0;
                break;
            }
            else{
                prime=n;
            }
        }
        if(prime!=0){
            cout<<prime<<endl;
            prime=0;
        }
    }
    return 0;
}
