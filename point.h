using namespace std;
class Point {
    private:
        double Xcoord;
        double Ycoord;
    public:
        //constructors and destructor
        Point(double, double);
        Point(const Point &OtherPoint);
        ~Point();

        // getters and setters
        void SetXCoordinate(const double Value);
        void SetYCoordinate(const double Value);
        double GetXCoordinate() const;
        double GetYCoordinate() const;

        //other useful methods
        void rotatePoint(double);
        float CalculateDistance(const Point OtherPoint) const;
        Point& operator+(double);

        // Overloaded stream operators
        friend ostream& operator<<(ostream&, const Point&);
};
