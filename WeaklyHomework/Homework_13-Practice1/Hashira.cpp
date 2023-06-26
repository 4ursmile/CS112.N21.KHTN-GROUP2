#include <bits/stdc++.h>
#include <cmath>
#define ll long long
#define fort(i,a,b) for(int i = a; i<=b; i++)
using namespace std;

// Structure to represent a point in 2D
struct Point {
    double x;
    double y;
    Point()
    {
        this->x = 0;
        this->y = 0;
    }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point operator+(const Point &b) 
    {
        double x = this->x+b.x;
        double y = this->y+b.y;
        return Point(x,y);
    }
    Point operator-(const Point &b) 
    {
        double x = this->x-b.x;
        double y = this->y-b.y;
        return Point(x,y);
    }
    Point operator/(double alpha)
    {
        double x = this->x/alpha;
        double y = this->y/alpha;
        return Point(x,y);
    }
    Point operator*(double alpha)
    {
        double x = this->x*alpha;
        double y = this->y*alpha;
        return Point(x,y);
    }
    double operator*(const Point &b)
    {
        double res = this->x*b.x + this->y*b.y;
        return res;
    }
    double mattidute()
    {
        return sqrt(this->x*this->x + this->y*this->y);
    }
};

// Structure to represent a straight line segment in 2D
struct LineSegment {
    Point p1;
    Point p2;
    LineSegment(Point p1, Point p2)
    {
        this->p1 = p1;
        this->p2 = p2;
    }
    LineSegment()
    {
        this->p1 = Point();
        this->p2 = Point();
    }
};

// Structure to represent a ray in 2D
struct Ray {
    Point origin;
    Point direction;
    Ray(Point origin, Point direction)
    {
        this->origin = origin;
        this->direction = direction;
    }
    Ray()
    {
        this->origin = Point();
        this->direction = Point(0,1);
    }
};
double Deg2Rad(double deg)
{
    return deg*(M_PI/180);
}
double Rad2Deg(double Rad)
{
    return Rad*(180/M_PI);
}
double Get_Angle( Point p1, Point p2)
{
    double res = (p1*p2)/(p1.mattidute()*p2.mattidute());
    return Rad2Deg(acos(res));
}
double Area(vector<Point>& points)
{
    double Res = 0;
    int n = points.size();
    for (int i = 0; i < n-1; i++)
    {
        Point p1 = points[i], p2 = points[i+1];
        Res+= p1.x*p2.y - p1.y*p2.x;
    }
    Point p1 = points[n-1], p2 = points[0];
    Res += (p1.x*p2.y - p1.y*p2.x);
    return abs(Res/2);
    
}
// Function to Rotate vector p by angle (in radian) around the origin
// and return the rotated vector
Point VectorRotate(Point p, double angle)
{
    double x = p.x*cos(angle) - p.y*sin(angle);
    double y = p.x*sin(angle) + p.y*cos(angle);
    return Point(x,y);
}
const double delta = .0000001;
// Function to calculate the intersection point of a line segment and a ray
// Returns 1 if there is an intersection point, 0 otherwise
// The intersection point is stored in the intersectionPoint parameter
bool calculateIntersection(const LineSegment& segment, const Ray& ray, Point& intersectionPoint) {
    double x1 = segment.p1.x;
    double y1 = segment.p1.y;
    double x2 = segment.p2.x;
    double y2 = segment.p2.y;

    double x3 = ray.origin.x;
    double y3 = ray.origin.y;
    double x4 = ray.origin.x + ray.direction.x;
    double y4 = ray.origin.y + ray.direction.y;

    double det = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    // Check if the line segment and ray are parallel
    if (std::abs(det) < 1e-6) {
        //std::cout << "Line segment and ray are parallel, no intersection." << std::endl;
        return 0;
    }

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / det;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / det;

    if (t >= 0-delta && t <= 1+delta && u >= 0-delta) {
        double xi = x1 + t * (x2 - x1);
        double yi = y1 + t * (y2 - y1);
        intersectionPoint = Point(xi, yi);
        return 1;
    }

    //std::cout << "No intersection point within the line segment and ray's range." << std::endl;
    return 0; // Return a default point
}

double Solve(vector<Point> &points)
{
    int n = points.size();
    Point Camere_Point = (points[1]+points[0])/2;
    Point Direction = points[1]-points[0];
    Point LeftDirection = VectorRotate(Direction, Deg2Rad(135));
    Point RightDirection = VectorRotate(Direction, Deg2Rad(45));
    // std::cout << Camere_Point.x << " " << Camere_Point.y << endl;
    // std::cout << RightDirection.x << " " << RightDirection.y << endl;
    // std::cout << LeftDirection.x << " " << LeftDirection.y << endl;
    Ray LeftRay(Camere_Point, LeftDirection);
    Ray RightRay(Camere_Point, RightDirection);
    int left = 0, right = 0;
    Point CastLeft, castRight;
    for (int i = 1; i < n-1; i++)
    {
        LineSegment segment(points[i], points[i+1]);
        Point intersectionPoint;
        if (calculateIntersection(segment, RightRay, intersectionPoint) && right == 0)
        {
            right = i+1;
            castRight = intersectionPoint;
        }
        if (calculateIntersection(segment, LeftRay, intersectionPoint) && left == 0)
        {
            left = i+1;
            CastLeft = intersectionPoint;
        }
    }
    if (left == 0 || right == 0) {
        LineSegment segment(points[n-1], points[0]);
        Point intersectionPoint;
        if (calculateIntersection(segment, RightRay, intersectionPoint))
        {
            right = n;
            castRight = intersectionPoint;
        }
        if (calculateIntersection(segment, LeftRay, intersectionPoint))
        {
            left = n;
            CastLeft = intersectionPoint;
        }
    }
    //std::cout << right << " " << left << " | (" << castRight.x << ", " << castRight.y << ") (" << CastLeft.x << ", " << CastLeft.y << ") \n";
    vector<Point> setPoint= {Camere_Point, castRight};
    for (int i = right; i < left; i++)
    {
        setPoint.push_back(points[i]);
    }
    setPoint.push_back(CastLeft);

    double Area1 = Area(setPoint);
    double Area2 = Area(points);
    double Ratio = Area1/Area2;
    
    return Ratio;
}
int main() {
    ifstream cin("in.inp");
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<Point> points(n);
        for (size_t j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            points[j] = Point(a,b);
        }
        std::cout << fixed << setprecision(10) <<Solve(points) << endl;
    }
    
    return 0;
}
