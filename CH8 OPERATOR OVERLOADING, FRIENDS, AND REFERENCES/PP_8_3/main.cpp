#include <iostream>

using namespace std;

class Complex
{
    public:
        Complex();
        Complex(double,double);
        Complex(double realPart);
        double getReal();
        double getIma();

        friend bool operator == (const Complex& number1, const Complex& number2);
        friend const Complex operator + (const Complex& number1, const Complex& number2);
        friend const Complex operator - (const Complex& number1, const Complex& number2);
        friend const Complex operator * (const Complex& number1, const Complex& number2);
        friend ostream& operator <<(ostream& outputStream,const Complex& number);
        friend istream& operator >>(istream& inputStream, Complex& number);

    private:
        double real,imaginary;
};

const Complex i (0,1);


int main()
{
    /*Testing the constructors*/
    Complex first, second(10,20), third(2),fourth,fifth;

    cout<<"\nDefault constructor complex: "<< first.getReal()<<" "<<first.getIma()<<endl;

    cout<<"\nTwo double constructor complex: "<<second.getReal()<<" "<<second.getIma()<<endl;
    cout<<"\nOne double constructor complex: "<<third.getReal()<<" "<<third.getIma()<<endl;

    /*Testing the overloaded operators*/
    fourth = second+third;
    cout<<"\nAdding second and third complex: "<<fourth.getReal()<<" "<<fourth.getIma()<<endl;
    fourth = second-third;
    cout<<"\nSubtracting second and third complex: "<<fourth.getReal()<<" "<<fourth.getIma()<<endl;
    fourth = second*third;
    cout<<"\nMultiplying second and third complex: "<<fourth.getReal()<<" "<<fourth.getIma()<<endl;

    cout<<"\nDisplaying complex numbers with cout: "<<endl<<first<<endl<<second<<endl<<third<<endl<<fourth;
    cout<<endl<<Complex(10,-10);

    cout<<"\nEnter a complex number: ";
    cin>>fifth;

    cout<<"\nYou entered: "<<fifth<<endl;

     cout<<"\nThis is i: "<<i<<endl;

    if(fifth==fifth)
    {
        cout<<"\nThis prints if the two are equal and "<<fifth<<" is equal to "<<fifth<<endl;
    }

    return 0;
}

Complex::Complex()
{
    real = 0;
    imaginary=0;
}

Complex::Complex(double r, double i)
{
    real = r;
    imaginary=i;
}

Complex::Complex(double realPart)
{
    real = realPart;
    imaginary=0;
}
double Complex::getReal()
{
    return real;
}

double Complex::getIma()
{
    return imaginary;
}

bool operator == (const Complex& number1, const Complex& number2)
{
    return(number1.real == number2.real && number1.imaginary == number2.imaginary);
}

const Complex operator + (const Complex& number1, const Complex& number2)
{
    double realPart = number1.real+number2.real,
    imaginaryPart= number2.imaginary+number1.imaginary;

    return Complex(realPart,imaginaryPart);
}

const Complex operator - (const Complex& number1, const Complex& number2)
{
    double realPart = number1.real-number2.real,
    imaginaryPart= number2.imaginary-number1.imaginary;

    return Complex(realPart,imaginaryPart);
}

const Complex operator * (const Complex& number1, const Complex& number2)
{
    double firstTerm = number1.real*number2.real - number1.imaginary*number2.imaginary,
    secondTerm = (number1.real*number2.imaginary + number2.real*number1.imaginary)*i.imaginary;


    return Complex(firstTerm,secondTerm);
}

ostream& operator <<(ostream& outputStream, const Complex& number)
{
    if(number.imaginary>=0)
    {
        outputStream<<number.real<<"+"<<number.imaginary<<"i";
    }
    else
     outputStream<<number.real<<number.imaginary<<"i";

    return outputStream;
}


istream& operator >>(istream& inputStream, Complex& number)
 {
    char sign,i;

    inputStream >> number.real>>sign;

    if (sign == '+' || sign == '-')
    {
        inputStream>>number.imaginary;
        if(sign == '-')
            number.imaginary*=-1;

    }
    else
    {
        cout<<"No sign detected.";
        exit(1);
    }
    inputStream>>i;
    if(i != 'i')
    {
        cout<<"No i detected.";
        exit(1);
    }

    return inputStream;
 }



