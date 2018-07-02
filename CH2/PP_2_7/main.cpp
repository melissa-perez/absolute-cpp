#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    int exercise_number=0;
    double exercise_score=0.00;
    double total_score=0.00;
    double exercise_score_total=0.00;
    double total_points=0.00;

    cout<<"How many exercises to input? ";
    cin>>exercise_number;

    for(int i =1; i<= exercise_number;i++){
        cout<<"Score received for exercise "<<i<<": ";
        cin>>exercise_score;

        cout<<"Total points possible for exercise "<<i<<": ";
        cin>>exercise_score_total;

        total_points+=exercise_score;
        total_score+=exercise_score_total;
    }
    cout<<"Your total is "<<total_points<<" out of "<<total_score
       <<", or "<<(total_points/total_score)*100<<"\%."<<endl;
    return 0;
}
