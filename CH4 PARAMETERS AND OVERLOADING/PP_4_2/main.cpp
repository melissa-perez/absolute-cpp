#include <iostream>
#include <cmath>

using namespace std;

void sideInput(double& length1, double& length2, double& length3);
void displayAnswer(double areaH, double length1, double length2, double length3);
void triangleHeron(double length1,double length2, double length3, double& area, double& perimeter);
double trianglePerimeter(double length1, double length2, double length3);
bool checkSides(double length1, double length2, double length3);

int main(int argc, char *argv[])
{
    double length1=0,length2=0,length3=0,perimeter=0,areaH=0;
    sideInput(length1,length2,length3);
    perimeter=trianglePerimeter(length1,length2,length3);
    triangleHeron(length1,length2,length3,areaH,perimeter);
    displayAnswer(areaH,length1,length2,length3);
    return 0;
}

double trianglePerimeter(double length1, double length2, double length3)
{
    return(length1+length2+length3);
}

void sideInput(double &length1, double &length2, double &length3)
{
    do{
        cout<<"\nPlease enter the first side: a=";
        cin>>length1;
        cout<<"\nPlease enter the second side (base): b=";
        cin>>length2;
        cout<<"\nPlease enter the third side: c=";
        cin>>length3;
    }while(checkSides(length1,length2,length3));

}

void triangleHeron(double length1, double length2, double length3, double& areaH, double& perimeter)
{
    double equation=((perimeter/2.0)*((perimeter/2.0)-length1)*((perimeter/2.0)-length2)*((perimeter/2.0)-length3));
    areaH=sqrt(equation);
}

void displayAnswer(double areaH,double length1, double length2,double length3)
{
    cout<<"\nThe area of a triangle with sides "<<length1<<" , "<<length2<<" , "<<length3<<" is ";
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout<<areaH<<endl;
}

bool checkSides(double length1, double length2, double length3)
{
    if((((length1+length2)<length3)||((length2+length3)<length1)||((length1+length3)<length2))){
        cout<<endl<<"Invalid side entries. Try again. "<<endl;
    }
    return((((length1+length2)<length3)||((length2+length3)<length1)||((length1+length3<length2))));
}
