#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define f first
#define s second

struct Point {
    long long x, y;
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x<=max(p.x, r.x) && q.x>=min(p.x, r.x) &&
        q.y<=max(p.y, r.y) && q.y>=min(p.y, r.y)) return true;
    return false;
}

long long orientation(Point p, Point q, Point r) {
    long long val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if (val==0) return 0; // colinear
    if (val>0) return 1; // clockwise
    else return 2; // counterclockwise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    long long o1=orientation(p1, q1, p2);
    long long o2=orientation(p1, q1, q2);
    long long o3=orientation(p2, q2, p1);
    long long o4=orientation(p2, q2, q1);

    if (o1!=o2 && o3!=o4) return true;
    if (o1==0 && onSegment(p1, p2, q1)) return true;
    if (o2==0 && onSegment(p1, q2, q1)) return true;
    if (o3==0 && onSegment(p2, p1, q2)) return true;
    if (o4==0 && onSegment(p2, q1, q2)) return true;
    return false;
}

int main()
{
    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    if (doIntersect(a, b, c, d)) cout << "1";
    else cout << "0";
}
