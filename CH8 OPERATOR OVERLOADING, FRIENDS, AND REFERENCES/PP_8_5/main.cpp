#include <iostream>

using namespace std;
 class Vector2D
 {

    public:

        Vector2D();
        void setX(int);
        void setY(int);
        int getX();
        int getY();
        friend const long operator *(const Vector2D& vec1, const Vector2D& vec2);

    private:
        int x,y;
 };

 int main( ){

    Vector2D v1, v2;

    v1.setX(5);
    v1.setY(-10);
    v2.setX(100);
    v2.setY(2);
    cout<<"Here is v1 =<"<<v1.getX()<<","<<v1.getY()<<">\n";
    cout<<"Here is v2 =<"<<v2.getX()<<","<<v2.getY()<<">\n";
    cout<<"Here is the dot product of v1 * v2 ="<<v1*v2<<"\n";
    return 0;
 }

Vector2D::Vector2D()
{
    x=0;
    y=0;
}

void Vector2D::setX(int userX)
{
    x = userX;
}

void Vector2D::setY(int userY)
{
    y = userY;
}

int Vector2D::getX()
{
    return x;
}

int Vector2D::getY()
{
    return y;
}


const long operator *(const Vector2D& vec1, const Vector2D& vec2)
{
    long dot_prod = (vec1.x * vec2.x)+ (vec2.y *vec1.y);
    return(dot_prod);
}
