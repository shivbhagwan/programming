#include<iostream>
#include<math.h>
#include "point.h"
using namespace std;
Point::Point(double d1=0.0,double d2=0.0)
{
    Xcoord=d1;
    Ycoord=d2;
}
Point::Point(const Point &OtherPoint)
{
    Xcoord=OtherPoint.Xcoord;
    Ycoord=OtherPoint.Ycoord;

}
Point::~Point()
{

}
        void Point::SetXCoordinate(const double Value)
        {
            Xcoord=Value;
        }
        void Point::SetYCoordinate(const double Value)
        {
            Ycoord=Value;
        }
        double Point::GetXCoordinate() const
        {
            return Xcoord;
        }
        double Point::GetYCoordinate() const
        {
            return Ycoord;
        }
        void Point::rotatePoint(double d1)
        {
            Xcoord=Xcoord*cos((d1*3.14)/180)-Ycoord*sin((d1*3.14)/180);
            Ycoord=Xcoord*sin((d1*3.14)/180)+Ycoord*cos((d1*3.14)/180);
        }
        float Point::CalculateDistance(const Point OtherPoint) const
        {
            float a=(Xcoord-OtherPoint.Xcoord)*(Xcoord-OtherPoint.Xcoord);
            float b=(Ycoord-OtherPoint.Ycoord)*(Ycoord-OtherPoint.Ycoord);
            return sqrt(a+b);
        }
        Point& Point::operator+(double d1)
        {
            Xcoord=Xcoord+d1;
            Ycoord=Ycoord+d1;
            return *this;
        }
//         Point& Point::operator-(double d1)
//        {
//            Xcoord=Xcoord-d1;
//            Ycoord=Ycoord-d1;
//            return *this;
//        }
        ostream& operator<<(ostream& dout, const Point& p0)
        {
            dout<<"(X , Y) = ("<<p0.Xcoord<<" , "<<p0.Ycoord<<")"<<endl;
        }
