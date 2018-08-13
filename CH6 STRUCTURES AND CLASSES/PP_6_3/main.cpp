#include <iostream>

using namespace std;

const int MAX=4; // make four points
class Point{
public:
    void set(double x,double y);
    double inspectX() const;
    double inspectY() const;
    void output();
    void translate(double moveX,double moveY);
    void rotate();

private:
    double x=0,y=0;
};

void inputPoints(double pointsEntered[MAX][2]);

int main(int argc, char *argv[])
{
    double pointsArray[MAX][2]={0};
    Point point1,point2, point3,point4;

    inputPoints(pointsArray);
    point1.set(pointsArray[0][0],pointsArray[0][1]);
    point2.set(pointsArray[1][0],pointsArray[1][1]);
    point3.set(pointsArray[2][0],pointsArray[2][1]);
    point4.set(pointsArray[3][0],pointsArray[3][1]);

    point1.output();

    point2.output();
    point2.translate(10,20);
    point2.output();

    point3.output();
    cout<<point3.inspectX();
    cout<<endl;
    cout<<point3.inspectY();
    cout<<endl;

    point4.output();
    point4.rotate();
    point4.output();
    cout<<endl;

    return 0;
}


//Instructions are vague on when to create the instance of the object.
//Ideally I would create and set the private members not after.
//Pre-condition:Takes any numeric value
//Returns a column matrix of coordinates, MAX size can be changed
void inputPoints(double pointsEntered[MAX][2])
{
    int i=0,j=0;
    double x=0,y=0;

    cout<<"Enter up to "<<MAX<<" points. Each point is made up of an x and y coordinate.\n";

    while(i<MAX)
    {
        cout<<"Enter the "<<i+1<<" point.\n";
        cout<<"x: ";
        cin>>x;
        cout<<endl;
        pointsEntered[i][j]=x;
        while(j<1)
        {
            j+=1;

            cout<<"y: ";
            cin>>y;
            cout<<endl;
            pointsEntered[i][j]=y;
        }
        j=0;
        i+=1;
    }
}


//Sets the private data of the created object.
void Point::set(double newx,double newy)
{
   x=newx;
   y=newy;
}


//Returns the current x coordinate of the object without mutation
double Point::inspectX() const
{
    return x;
}

//Returns the current y coordinate of the object without mutation
double Point::inspectY() const
{
    return y;
}

//Displays the member variables of the object Point: x, y
void Point::output()
{
    cout<<"("<<x<<","<<y<<")"<<endl;
}


//Pre-condition:Takes any numeric variable that will be added to the coordinates
//in order to move the point horizontally or vertically

void Point::translate(double moveX,double moveY)
{
    x+=moveX;
    y+=moveY;

}

//Rotates the object 90 deg clockwise
//by the formula: switch x and y, while multiplying the new y coordinate with a negative sign
void Point::rotate()
{
    double temp =-1.0*x;
    x=y;
    y=temp;
}
