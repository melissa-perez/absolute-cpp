#include <iostream>
#include <string>

using namespace std;


class Pizza{
public:
    void setPizzaType();
    void setPizzaSize();
    void setPizzaType(char type);
    void setPizzaSize(char size);
    void setToppings();
    void setToppings(int top1, int top2);


    string getPizzaType();
    string getPizzaSize();
    int getToppings();
    int getPepTops();
    int getCheeseTops();

    void outputDescription();
    double computePrice();


private:
    char type, size;
    double price;
    const double PRICE_TOPPING=2.00;
    int pepTops=0,cheeseTops=0;

};

int main(int argc, char *argv[])
{
    Pizza order1,order2;

    order1.setPizzaSize();
    order1.setPizzaType();
    order1.setToppings();
    order1.outputDescription();

    cout<<endl;

    order2.setPizzaSize('l');
    order2.setPizzaType('d');
    order2.setToppings(5,4);
    order2.outputDescription();
    return 0;
}

void Pizza::setPizzaType()
{
    cout<<"Enter d for deep-dish, h for hand-tossed, and"
         <<" p for pan.";
    cout<<"\nEnter the pizza type you like:";
    cin>>type;
}

void Pizza::setPizzaSize()
{
    cout<<"Enter s for small, m for medium, and "
         <<"l for large.";
    cout<<"\nEnter the pizza size you like:";
    cin>>size;
}

void Pizza::setPizzaType(char ptype)
{
    type=ptype;
}

void Pizza::setPizzaSize(char psize)
{
    size=psize;
}

void Pizza::setToppings()
{
    cout<<"\nHow many cheese topping(s) would you like? ";
    cin>>cheeseTops;
    cout<<"\nHow many pepporoni topping(s) would you like? ";
    cin>>pepTops;

}

void Pizza::setToppings(int top1, int top2)
{
    cheeseTops=top1;
    pepTops=top2;

}

string Pizza::getPizzaSize()
{
    switch (size) {
    case 's': return "SMALL";
    case 'm': return "MEDIUM";
    case 'l': return "LARGE";
    default:
        break;
    }
    return "";
}

string Pizza::getPizzaType()
{
    switch (type) {
    case 'd': return "DEEP-DISH";
    case 'h': return "HAND-TOSSED";
    case 'p': return "PAN";
    default:
        break;
    }
    return "";
}

int Pizza::getToppings(){
    return(cheeseTops+pepTops);
}

int Pizza::getPepTops(){
    return pepTops;
}

int Pizza::getCheeseTops()
{
    return cheeseTops;
}

void Pizza::outputDescription()
{
    cout<<"Your order is:"<<getPizzaSize()<<" "<< getPizzaType()<<" PIZZA";
    cout<<"\nwith "<<getCheeseTops()<<" CHEESE toppings and "<<getPepTops()<<" PEPPERONI toppings.";
    cout<<"\nYour TOTAL PRICE is $"<<computePrice();
    cout<<endl;
}

double Pizza::computePrice()
{
    switch (size) {
    case 's': return (10.00 +2*getToppings());
    case 'm': return (14.00 +2*getToppings());
    case 'l': return (17.00 +2*getToppings());
    default:
        break;
    }
    return 0;

}
