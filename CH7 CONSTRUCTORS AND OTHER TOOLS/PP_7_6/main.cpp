#include <iostream>
#include <vector>
#include<string>

using namespace std;

class Pizza{
public:

    Pizza(char,char,int,int);
    Pizza();
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
    void setPrice();
    double getPrice();

private:
    char type, size;
    double price;
    const double PRICE_TOPPING=2.00;
    int pepTops,cheeseTops;

};

class Order{
public:
    Order();
    void setFullOrder(Pizza);
    void displayFullOrder();
    void setTotalPrice();
    double getTotalPrice();


    private:
    vector<Pizza> fullOrder;
    double totalPrice=0;

};

int main(int argc, char *argv[])
{
     Order order1;

    //vector of Pizza objects, since size will not be asked
    //the program will prompt the user for each pizza

    //made loop(works) for user input, will instead use test program
   /* char ans='\0';
    do{

         Pizza onePizza;

         order1.setFullOrder(onePizza);

         order1.displayFullOrder();

        cout<<"\nWould you like to add another pizza to the order(Enter y or Y)?";
        cin>>ans;

    }while(ans=='y'||ans=='Y');*/

     Pizza onePizza('p','s',0,0),twoPizza('d','l',10,2);
     order1.setFullOrder(onePizza);
     order1.setFullOrder(twoPizza);
     order1.displayFullOrder();

    cout<<"\nYour complete TOTAL is: $"<<order1.getTotalPrice()<<endl;

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
    cout<<getPizzaSize()<<" "<< getPizzaType()<<" PIZZA";
    cout<<"\nwith "<<getCheeseTops()<<" CHEESE topping(s) and "<<getPepTops()<<" PEPPERONI topping(s).";
    cout<<"\nYour PRICE for this PIZZA is $"<<getPrice();
    cout<<endl;

}

void Pizza::setPrice()
{
    switch (size) {
    case 's': {

        price=10.00 +2*getToppings();
        break;
    }
    case 'm': {
        price= 14.00 +2*getToppings();
        break;
    }
    case 'l':{
        price=17.00 +2*getToppings();
        break;
    }
    default:
        break;
    }


}

Pizza::Pizza():type('d'),size('s'),price(0.00),
    pepTops(0),cheeseTops(0)
{
    setPizzaSize();
    setPizzaType();
    setToppings();
    setPrice();
}

Pizza::Pizza(char ptype, char psize,int pep,int cheese)
{
    setPizzaType(ptype);
    setPizzaSize(psize);
    setToppings(cheese,pep);
    setPrice();
}

Order::Order(){}
void Order::setFullOrder(Pizza onePizza)
{
    fullOrder.push_back(onePizza);
    totalPrice+=onePizza.getPrice();
}

void Order::displayFullOrder()
{
    cout<<"Your order is:";
    for(unsigned int i=0;i<fullOrder.size();i++)
    {
         fullOrder[i].outputDescription();
    }
    cout<<"\nYour RUNNING TOTAL is: $"<<getTotalPrice();
}

double Pizza::getPrice()
{
    return price;
}


 double Order::getTotalPrice()
{
    return totalPrice;
}

