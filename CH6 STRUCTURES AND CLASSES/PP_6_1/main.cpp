#include <iostream>

using namespace std;
//This program uses structs only, for this reason
//no functions are made to make a distinction between
//structs and classes.

struct StudentRecord{

    int quiz1=0,quiz2=0; //out of 10
    int midterm=0,final=0; //out of 100
    double average=0.0;
    char letterGrade='F';
};

void getStudentInfo(StudentRecord& student);
void setGrade(StudentRecord& average);

int main(int argc, char *argv[])
{
    StudentRecord student1,student2;

    cout<<"Enter the record of student 1.\n";
    getStudentInfo(student1);
    cout<<"\nEnter the record of student 2.\n";
    getStudentInfo(student2);

    student1.average=100*(0.25*((student1.quiz1+student1.quiz2)/20.0)
            +0.25*(student1.midterm/100.0)+0.50*(student1.final/100.0));

    setGrade(student1);
    student2.average=100.0*(0.25*((student2.quiz1+student2.quiz2)/20.0)
            +0.25*(student2.midterm/100.0)+0.50*(student2.final/100.0));
    setGrade(student2);


    cout<<student1.average<<" "<<student1.letterGrade<<endl;
    return 0;
}


void getStudentInfo(StudentRecord &student)
{
    cout<<"Enter the two quiz grades (Out of 10 points)\n";
    cin>>student.quiz1>>student.quiz2;
    cout<<"\nEnter the midterm exam grade (Out of 100 points): ";
    cin>>student.midterm;
    cout<<"\nEnter the final exam grades(Out of 100 points): ";
    cin>>student.final;
}


void setGrade(StudentRecord &student)
{
    if(student.average>=90.0)student.letterGrade='A';
    else if(student.average<90.0&& student.average>=80.0)student.letterGrade='B';
    else if(student.average<80.0&& student.average>=70.0)student.letterGrade='C';
    else if(student.average<70.0&& student.average>=60.0)student.letterGrade='D';
    else student.letterGrade='F';
}
