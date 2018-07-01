/*3. Workers at a particular company have won a 7.6% pay increase retroactive for six
months. Write a program that takes an employee’s previous annual salary as input
and outputs the amount of retroactive pay due the employee, the new annual
salary, and the new monthly salary. Use a variable declaration with the modifier
const to express the pay increase.*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    const double PAY_INCREASE = 0.076;
    double current_salary=0.00;
    double previous_salary=0.00;

    cout<<"Enter your previous annual salary:$ ";
    cin>>previous_salary;

    current_salary=PAY_INCREASE*previous_salary+previous_salary;
    cout<<"\nThe retroactive pay is: $ "<<(current_salary-previous_salary)/6;

    cout<<"\nThe new monthly salary is: $ "<<current_salary/12;
    cout<<"\nThe new annual salary is: $ "<<current_salary<<endl;
    return 0;
}


