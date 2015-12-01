#include<iostream>
#include "line.h"

using namespace std;
Line::Line()
{
    startP;
    endP;
}

	 Line:: Line(Point p1, Point p2)
	  {
	      startP(p1);
	      endP(p2);
	  }
	  Line::Line(const Line &OtherLine)
	  {
	      startP=OtherLine.startP;
	      endP=OtherLine.endP;
	  }
	 Line:: ~Line()
	  {

	  }
	  void Line:: SetStart (const Point SomePoint)
	  {
	      startP.Xcoord=SomePoint.Xcoord;
	      startP.Ycoord=SomePoint.Ycoord;

	  }
	  void Line::SetEnd (const Point SomePoint)
	  {
	      endP.Xcoord=SomePoint.Xcoord;
	      endP.Ycoord=SomePoint.Ycoord;
	  }
	  Point Line::GetStart() const
	  {
	      return startP;
	  }
	  Point Line::GetEnd() const
	  {
	      return endP;
	  }
	  double Line::GetSlope() const
	  {
	      double a=endP.Xcoord-startP.Xcoord;
	      double b=endP.Ycoord-startP.Ycoord;
	      return b/a;
	  }
	  double Line::GetIntercept() const
	  {
          return startP.Ycoord-GetSlope()*startP.Xcoord;
	  }
	  Line Line::operator+(double d1)
	  {
           startP=startP-d1;
           endP=endP-d1;
           return this;
	  }
	  void Line::rotate(double d1,Point p1)
	  {
	      double a=p1.Xcoord;
	      double b=p1.Ycoord;
	      startP=startP-a;
          endP=endP-b;
          startP.rotatePoint(d1);
	      endP.rotatePoint(d1);
	      startP=startP+a;
          endP=endP+b;
	  }
	  double Line::CalculateDistance (Point SomePoint) const
	  {
	      double d1=((endP.Ycoord-startP.Ycoord)*SomePoint.Xcoord-(endP.Xcoord-startP.Xcoord)*SomePoint.Ycoord+endP.Xcoord*startP.Ycoord-endP.Ycoord*startP.Xcoord);
        float d2=startP.CalculateDistance(endP);
        if(d1>=0&&d2!=0)
            return d1/d2;
        else if(d1<0&&d2!=0)
            return -(d1/d2);
        else
        {
            cout<<"not defined"<<endl;
            return 0;
        }
	  }
     ostream& operator<<(ostream& dout, const Line& l1)
     {
         dout<<"y="<<GetSlope()<<"x +"<<GetIntercept()<<endl;
     }
