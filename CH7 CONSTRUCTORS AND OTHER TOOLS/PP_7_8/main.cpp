#include <iostream>
#include <vector>

using namespace std;

const int SENTINEL_VALUE=-1;
void histogram(vector<int> hist);

int main(int argc, char *argv[])
{
    vector<int> grades;
    int max=0;
    int grade=0;

    cout<<"Enter quiz scores,"
       <<"when you are finished enter -1."<<endl;
    while(grade>SENTINEL_VALUE){
            cout<<"\nEnter the quiz grade: ";
            cin>>grade;
            grades.push_back(grade);
    }

    grades.resize(grades.size()-1);

    for(unsigned int i=0;i<grades.size();i++)
    {
        if(grades[i]>max)max=grades[i];
    }

    vector<int> hist(max+1);

    for(unsigned int i=0;i<grades.size();i++)
    {
        hist[grades[i]]+=1;

    }

    cout<<"QUIZ RESULTS OF "<<grades.size()<<" STUDENTS"<<endl;
    cout<<"The MAXIMUM grade is "<<max<<endl;
    for(unsigned int i=0;i<hist.size();i++)cout<<hist[i]<<" grade(s) of "<<i<<endl;

    return 0;
}
