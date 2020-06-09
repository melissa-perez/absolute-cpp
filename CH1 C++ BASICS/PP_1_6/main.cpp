#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double hours_worked = 0.00;
    int num_of_dep = 0;
    const double FULL_TIME = 40.0;
    double gross_pay = 0.00;
    const double WAGE = 16.78;
    const double SSTAX = 0.06;
    double ss_amount = 0.00;
    const double FIT = 0.14;
    double fit_amount = 0.00;
    const double SIT = 0.05;
    double sit_amount = 0.00;
    const double UNION_DUES = 10.0; //per week
    const double THREE_OR_MORE_DEP = 35.0;

    cout << "Enter the number of hours worked: ";
    cin >> hours_worked;
    cout << endl << "Enter the number of dependents: ";
    cin >> num_of_dep;

    if (hours_worked > FULL_TIME){
    while (hours_worked > FULL_TIME){
        hours_worked -= FULL_TIME;
        gross_pay += hours_worked * (WAGE + 1.5 * WAGE);
       }
    gross_pay += FULL_TIME * WAGE;
    }

    else{
        gross_pay += (hours_worked * WAGE);
    }

    cout << "\nThe gross pay is: $" << gross_pay
       << endl;
    ss_amount = gross_pay * SSTAX;
    fit_amount = gross_pay * FIT;

    sit_amount = gross_pay * SIT;

    gross_pay = gross_pay - ss_amount - fit_amount - sit_amount;
    gross_pay -= UNION_DUES;

    cout << "\nThe amount witheld for Social Security Tax: $" << ss_amount
        << endl;
    cout << "\nThe amount witheld for Federal Income Tax: $" << fit_amount
       << endl;
    cout << "\nThe amount witheld for State Income Tax: $" << sit_amount
       << endl;
    cout << "\nThe amount witheld for Union Dues: $" << UNION_DUES 
       << endl;

    if (num_of_dep >= 3){
        gross_pay -= THREE_OR_MORE_DEP;
    cout << "\nThe amount witheld for extra cost health insurance : $" << THREE_OR_MORE_DEP
        << endl;
    }

    cout << "\nThe net take-home pay is: $"<< gross_pay 
       << endl;
    return 0;
}
