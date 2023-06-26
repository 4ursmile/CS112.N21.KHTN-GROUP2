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
struct Rectangle
{
    double orientation;
    Point center;
    double width;
    double height;
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
Point VectorRotateCCW(Point p, double angle)
{
    double x = p.x*cos(angle) - p.y*sin(angle);
    double y = p.x*sin(angle) + p.y*cos(angle);
    return Point(x,y);
}
Point VectorRotateCW(Point p, double angle)
{
    double x = p.x*cos(angle) + p.y*sin(angle);
    double y = -p.x*sin(angle) + p.y*cos(angle);
    return Point(x,y);
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; 	 // colinear
    return (val > 0)? 1: 2; 	// clock or counterclock wise
}
int orientationCCW(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; 	 // colinear
    return (val > 0)? 2: 1; 	// clock or counterclock wise
}
vector<Point> convexHull(vector<Point> &points, int n)
{
    // There must be at least 3 points
    if (n <= 3) return points;
    sort(points.begin(), points.end(), [](Point &a, Point &b){
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    auto it = unique(points.begin(), points.end(), [](Point &a, Point &b){
        return a.x == b.x && a.y == b.y;
    });
    points.resize(distance(points.begin(),it));
    // Initialize Result
    vector<Point> hull;
    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);
        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           // If i is more counterclockwise than current q, then
           // update q
           if (orientationCCW(points[p], points[i], points[q]) == 2)
               q = i;
        }
        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;
    } while (p != l);  // While we don't come to first point
    return hull;
}

double RectangleArea(vector<Rectangle> &rects)
{
    double sum = 0;
    for (size_t i = 0; i < rects.size(); i++)
    {
        sum += rects[i].width*rects[i].height;
    }
    return sum;
}
vector<Point> findFourCorner(Rectangle rec)
{
    vector<Point> res(4);
    
    Point p1 = rec.center + VectorRotateCW(Point(-rec.width/2, rec.height/2), Deg2Rad(rec.orientation));
    Point p2 = rec.center + VectorRotateCW(Point(rec.width/2, rec.height/2), Deg2Rad(rec.orientation));
    Point p3 = rec.center + VectorRotateCW(Point(rec.width/2, -rec.height/2), Deg2Rad(rec.orientation));
    Point p4 = rec.center + VectorRotateCW(Point(-rec.width/2, -rec.height/2), Deg2Rad(rec.orientation));
    res[0] = p1;
    res[1] = p2;
    res[2] = p3;
    res[3] = p4;
    return res;
}
double Solve(vector<Rectangle> &recs)
{
    if (recs.size() == 0)
        return 0;
    if (recs.size() == 1)
        return 100;
    vector<Point> points;
    for(auto &rec: recs)
    {
        vector<Point> tmp = findFourCorner(rec);
        points.insert(points.end(), tmp.begin(), tmp.end());
    }
    vector<Point> hull = convexHull(points, points.size());
    double hullArea = Area(hull);
    double recArea = RectangleArea(recs);
    return recArea/hullArea*100;
}
int main() {
    //ifstream cin("in.inp");
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<Rectangle> recs(n);
        for (size_t j = 0; j < n; j++)
        {
            cin >> recs[j].center.x >> recs[j].center.y >> recs[j].width >> recs[j].height >> recs[j].orientation;
        }
        std::cout << fixed << setprecision(2) <<Solve(recs) << endl;
    }
    
    return 0;
}
