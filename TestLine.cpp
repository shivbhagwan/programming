#include <iostream>
using namespace std;
#include "PointUG201310030.cpp"
#include "LineUG201310030.cpp"

void TestLine()
{
    cout << "\nTest Line and Point Type" << endl;
    // Define two things within Point class
    Point One;
    Point Two;
    Line MyLine;

   //Set these points into different x and y values=
   Two.SetXCoordinate(4);
   Two.SetYCoordinate(4);
   MyLine.SetStart(One);
   MyLine.SetEnd(Two);

   //Print out the points
   cout << "Starting Point = " << One << endl;
   cout << "End Point = " << Two << endl;

   //Calculate the distance between the two points
   cout << "Distance between " << One << " and " << Two << " is = " << One.CalculateDistance(Two)<< endl;
    cout << "Equation of my first line = " << MyLine << endl;

    Point Three(0,-2);
    Point Four(3,2);
    Line MyLine1(Three, Four);
    cout << "Equation of my second line = " << MyLine1 << endl;

    Point Five(1,-2);
    Point Six(-3,0);
    Line MyLine2(Five,Six);
    cout << "Equation of my third line = " << MyLine2 << endl;
    MyLine2 = MyLine2 + 5;
    cout << "Equation of my third line after translation= " << MyLine2 << endl;

    Point Seven(1,1);
    Point Eight(3,3);
    Line MyLine3(Seven,Eight);
    cout << "Before rotation" << endl;
    cout << "Equation of my Fourth line = " << MyLine3 << endl;
    MyLine3.rotate(90,Seven);
    cout << "After rotation" << endl;
    cout << "Start point = " << MyLine3.GetStart() << endl;
    cout << "End point = " << MyLine3.GetEnd() << endl;
    cout << "Equation of my Fourth line after Rotation= " << MyLine3 << endl;

    Line MyLine4(Point(0,3),Point(3,-2));
    Point Nine(2,2);
    cout << "Distance from " << MyLine4 << " and " << Nine << " is = " << MyLine4.CalculateDistance(Nine) << endl;

    Line MyLine5(MyLine4);
    cout << "Equation of my Sixth line = " << MyLine5 << endl;
    return;
}
