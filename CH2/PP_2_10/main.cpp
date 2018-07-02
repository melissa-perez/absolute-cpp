#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string text;
    fstream inputStream;

    inputStream.open("hate.txt");

    while(inputStream>>text){
        if(text=="hate"){
            cout<<" love ";
        }
        else{
            cout<<text;
        }
    }
    cout<<endl;
    inputStream.close();
    return 0;
}
