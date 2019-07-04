#include <iostream>
#include <cmath>

using namespace std;

// Takes no input, problem sets 1 as default value
// for default construtor

class PrimeNumber{

    public:
        PrimeNumber(){prime = 1;}
        PrimeNumber(int);
        int GetPrimeNumber(){return prime;}
        PrimeNumber operator++(); //prefix
        PrimeNumber operator++(int); //postfix
        PrimeNumber operator--(); //prefix
        PrimeNumber operator--(int); //postfix
        friend ostream& operator <<(ostream&,
                                    const PrimeNumber&);

    private:
        int prime;
        bool isPrime(int);
        void ChangePrime(int,bool);
};

int main()
{
    PrimeNumber a;
    cout << "Default constructor PrimeNumber, a: " << a;
    cout << "Using prefix -- on a: " << --a;

    PrimeNumber b(13);
    cout << "Overloaded constructor PrimeNumber with a prime, b: " << b;

    PrimeNumber c(9);
    cout << "Overloaded constructor PrimeNumber without a prime entered, c: " << c;

    cout << "Using prefix ++ operator on b: " << ++b;
    cout << "Using prefix ++ operator on c: " << ++c;

    cout << "Using postfix ++ operator on a: " << a++;
    cout << "Using postfix ++ operator on c: " << c++;

    cout << "The values on a: " << a.GetPrimeNumber()
         << ", c: " << c.GetPrimeNumber() << " after evaluation." << endl;

    cout << "Creating d, setting it to b++..." << endl;
    PrimeNumber d(b++);
    cout << "The value of d is b before the increase: " << d;
    cout << "The new value of b: " << b;

    PrimeNumber e;
    cout << "Using prefix -- on d: " << --d;
    cout << "Using prefix -- on e: " << --e;

    cout << "If a value is 1 because of the default constructor, then it's value is not decreased."
         << endl;

    cout << "Using postfix -- on d: " << d--;
    cout << "Using postfix -- on e: " << e--;
    cout << "Using postfix -- on b: " << b--;

    cout << "The values on d: " << d.GetPrimeNumber()
         << ", e: " << e.GetPrimeNumber() << ", b: "
         << b.GetPrimeNumber() << " after evaluation." << endl;
    return 0;
}


PrimeNumber::PrimeNumber(int num){
    if(isPrime(num)){
        prime = num;
    }
    else{
        prime = 2;
    }
}

PrimeNumber PrimeNumber::operator++(){

    int temp = prime + 1;
    while(!isPrime(temp)){
        temp += 1;
    }    
    prime = temp;
    return PrimeNumber(temp);
}


PrimeNumber PrimeNumber::operator++(int num){

    int orig_prime = prime, next_number = prime + 1;
    while(!isPrime(next_number)){
        next_number += 1;
    }
    prime = next_number;
    return PrimeNumber(orig_prime);
}

PrimeNumber PrimeNumber::operator--(){

    int orig_prime = prime, temp = prime - 1;

    if(orig_prime == 1){
       return PrimeNumber();
    }

    while(!isPrime(temp) && temp > 1){
        temp -= 1;
    }
    prime = temp;
    return PrimeNumber(temp);
}


PrimeNumber PrimeNumber::operator--(int num){

    int orig_prime = prime, temp = prime - 1;

    if(orig_prime == 1){
       return PrimeNumber();
    }

    while(!isPrime(temp) && temp > 1){
        temp -= 1;
    }
    prime = temp;
    return PrimeNumber(orig_prime);
}

bool PrimeNumber::isPrime(int num){

    int temp = 2;
    bool pFlag = true;

    if(num < 2){
        pFlag = false;
    }
    else{
        while(temp <= floor(sqrt(num)) && num > 1){
            if(num % temp == 0){
                pFlag = false;
                break;
            }
            temp +=1;
        }
    }
    return pFlag;
}

ostream& operator <<(ostream& out, const PrimeNumber& num){

    out << num.prime << endl;
    return out;
}
