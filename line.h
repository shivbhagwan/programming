using namespace std;
class Line
{
    private:
	  Point startP;
	  Point endP;
    public:

	  //constructors and destructor
	  Line();
	  Line(Point p1, Point p2);
	  Line(const Line &OtherLine);
	  ~Line();

	  //getters and setters
	  void SetStart (const Point SomePoint);
	  void SetEnd (const Point SomePoint);
	  Point GetStart() const;
	  Point GetEnd() const;
	  double GetSlope() const;
	  double GetIntercept() const;

	  //other useful methods
	  Line operator+(double);
	  void rotate(double,Point);
	  double CalculateDistance (Point SomePoint) const;

	  // Overloaded stream operators
	  friend ostream& operator<<(ostream&, const Line&);
};
