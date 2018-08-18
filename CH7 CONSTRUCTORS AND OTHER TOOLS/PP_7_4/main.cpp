#include <iostream>

using namespace std;

class HotDogStand{
public:
    HotDogStand(int number, int sold);//const for priv. variables
    HotDogStand();//default constructor
    void justSold();//increases number sold by stand by 1
    void setInfo();//checks user input in const
    int getCurrentId();//returns stands id number
    int getNumberSold(); //returns hot dogs sold by stand
    void display();//displays current info
    void tally();//reuseable function for total, due to test program structure

    static void updateTotalSold();//shared variable that gathers total hot dogs sold
    static int getTotalSold();//return total sold
private:
    int id,numberSold;
    static int totalSold;
};

int HotDogStand::totalSold=0;
int main(int argc, char *argv[])
{
    HotDogStand stand1,stand2(3,10),stand3;

    stand1.display();
    stand1.justSold();
    stand1.tally();
    stand1.display();

    stand2.display();
    stand2.tally();


    stand3.display();
    stand3.justSold();
    stand3.justSold();
    stand3.display();
    stand3.tally();

    cout<<"TOTAL hot dogs sold from all stands: "<<HotDogStand::getTotalSold()<<endl;
    return 0;
}

HotDogStand::HotDogStand(int number, int sold):
    id(number),numberSold(sold){}
HotDogStand::HotDogStand():id(0),numberSold(0){
    setInfo();
}

void HotDogStand::setInfo()
{
    int standid=-1,sold=-1;

    while(standid<0){
        cout<<"Enter stand I.D number(starts at 0 and beyond): ";
        cin>>standid;
    }

    id=standid;
    while(sold<0){
        cout<<"Enter number of hot dogs SOLD today by STAND "<<standid<<": ";
        cin>>sold;
    }
    numberSold=sold;
}

void HotDogStand::justSold()
{
    cout<<"SOLD"<<endl;
    numberSold+=1;
}

int HotDogStand::getNumberSold()
{
    return numberSold;
}

int HotDogStand::getCurrentId()
{
    return id;
}

void HotDogStand::updateTotalSold()
{
    totalSold+=1;
}

int HotDogStand::getTotalSold()
{
    return totalSold;

}

void HotDogStand::display()
{
    cout<<"STAND "<<id<<endl;
    cout<<"Hot dogs SOLD: "<<numberSold<<endl;
}

void HotDogStand::tally()
{
    for(int i=0;i<numberSold;i++)
    {
        HotDogStand::updateTotalSold();
    }
}
