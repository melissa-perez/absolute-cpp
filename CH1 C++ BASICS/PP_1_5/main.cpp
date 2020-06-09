#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int max_room_cap = 0;
    int number_of_people = 0;

    cout << "What is the maximum room capacity?\n";
    cin >> max_room_cap;
    cout << "How many people are attending?" << endl;
    cin >> number_of_people;

    int diff = max_room_cap - number_of_people;

    if (number_of_people < max_room_cap){
        cout << "It is LEGAL to hold the meeting per fire law regulations." << endl;
        
        if(diff == 1)
            cout << "You are allowed " << diff << " additional person." << endl;
        else
            cout << "You are allowed " << diff << " additional people." << endl;
    }
    else{
        cout << "It is not LEGAL to hold the meeting per fire law regulations." << endl;
        
        if (-1 * diff == 1)
           cout << "You must exclude " << -1 * diff << " person." << endl;
        else
           cout << "You must exclude " << -1 * diff << " people."<<endl;
    }
    return 0;
}
