//Assume sentence ends with a period
//Line break is treated as a space aka, more than
//one "space"needs to be compressed
//First letter should be capitalized
//Everyhthing else is lower case

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100;

void stdLetters(char[]);

int main(int argc, char *argv[])
{
    char sentence[MAX_SIZE];
    int index = 0;

    cout << "Enter a sentence up to 100 characters long: ";
    cin.getline(sentence, MAX_SIZE);

    while (sentence[index] != '\0'){
        cout << sentence[index];
        index++;
    }

    cout << endl;
    return 0;
}
