#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

// Does not take user input
using namespace std;

class BoxOfProduce{
public:
    BoxOfProduce();
    BoxOfProduce(const vector<string>);
    vector<string> GetBox() const;
    void SetBox();
    void output() const;
    void addProduce();
    friend const BoxOfProduce operator + (const BoxOfProduce&, const BoxOfProduce&);

private:
    vector<string> box;
    const static vector<string> itemChoices;
    const static int NUMBER_OF_ITEMS;
    const static int VARIETY_OF_ITEMS;
    static vector<string> CreateItemChoices();
    static void DisplayItemChoices();
    bool checkUserInput(int, vector<string>) const;

};

const vector<string> BoxOfProduce::itemChoices = CreateItemChoices();
const int BoxOfProduce::NUMBER_OF_ITEMS = 3;
const int BoxOfProduce::VARIETY_OF_ITEMS = 5;

int main(int argc, char *argv[]){

    srand(time(NULL));
    BoxOfProduce box1, box2, box3;

    box1.output();
    box1.SetBox();
    box1.output();
    box1.addProduce();
    box1.output();


    box2.output();

    box3 = box1 + box2;

    box3.output();

    return 0;
}

void BoxOfProduce::DisplayItemChoices(){

    cout << "Your bundle choices: ";
    for(size_t i = 0; i < itemChoices.size(); i++){
        cout << "[" << i + 1 << "]" << itemChoices[i];
        if(i < itemChoices.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

BoxOfProduce::BoxOfProduce(){

    for(size_t i = 0; i < NUMBER_OF_ITEMS; i++){
        box.push_back(itemChoices[rand() % VARIETY_OF_ITEMS]);
    }
}

BoxOfProduce::BoxOfProduce(const vector<string> boxToSet){

    box = boxToSet;
 }

vector<string> BoxOfProduce::CreateItemChoices(){

    vector<string> itemVec;
    string textFileName = "produce.txt", next;
    fstream wordDoc;

    wordDoc.open(textFileName, ios::in);
    if (wordDoc.fail()){
            cout << "Error in opening "
                 << textFileName << ". Ending program." << endl;
        }
        else{
            while(wordDoc >> next){
                itemVec.push_back(next);
            }
        }
    wordDoc.close();
    return itemVec;
}

vector<string> BoxOfProduce::GetBox() const{
    \
    return box;
}

void BoxOfProduce::output() const{

    cout << "Your current box contains: ";
    for(size_t i = 0; i < box.size(); i++){
        cout << "[" << i + 1 << "]" << box[i];
        if(i < box.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

void BoxOfProduce::SetBox(){

    char userAns = 'r';
    int userChoice1 = 0, userChoice2 = 0;

    cout << "Would you like to change your box selection?(Enter Y or y): ";
    cin >> userAns;

    if(userAns == 'Y' ||
            userAns == 'y'
           ){
        cout << "Enter the number for the item you wish to change: ";
        cin >> userChoice1;

        if(checkUserInput(userChoice1, this -> box)){
            DisplayItemChoices();
            cout << "Enter the number: ";

            cin >> userChoice2;
            if(checkUserInput(userChoice2, itemChoices)){
                this -> box[userChoice1 - 1] = itemChoices[userChoice2 - 1];
            }
        }
    }
}

bool BoxOfProduce::checkUserInput(int value, vector<string> vecToUse) const{

    if(value >= 1 &&
            value <= static_cast<int>(vecToUse.size()))
        return true;

    return false;
}

void BoxOfProduce::addProduce(){

    int userChoice1 = 0;
    DisplayItemChoices();
    cout << "Enter the number for the item you wish to add: ";
    cin >> userChoice1;
    if(checkUserInput(userChoice1, this -> itemChoices)){
        this -> box.push_back(itemChoices[userChoice1 - 1]);
    }

}


const BoxOfProduce operator +(const BoxOfProduce& box1, const BoxOfProduce& box2){

    vector<string> combinedBox;

    for(size_t i = 0; i < box1.box.size(); i++)
        combinedBox.push_back(box1.box[i]);

    for(size_t i = 0; i < box2.box.size(); i++)
        combinedBox.push_back(box2.box[i]);

    return BoxOfProduce(combinedBox);
}
