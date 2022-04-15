#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define f first
#define s second

struct Point {
    int x, y;
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x<=max(p.x, r.x) && q.x>=min(p.x, r.x) &&
        q.y<=max(p.y, r.y) && q.y>=min(p.y, r.y)) return true;
    return false;
}

int orientation(Point p, Point q, Point r) {
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if (val==0) return 0; // colinear
    if (val>0) return 1; // clockwise
    else return 2; // counterclockwise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1=orientation(p1, q1, p2);
    int o2=orientation(p1, q1, q2);
    int o3=orientation(p2, q2, p1);
    int o4=orientation(p2, q2, q1);

    if (o1!=o2 && o3!=o4) return true;
    if (o1==0 && onSegment(p1, p2, q1)) return true;
    if (o2==0 && onSegment(p1, q2, q1)) return true;
    if (o3==0 && onSegment(p2, p1, q2)) return true;
    if (o4==0 && onSegment(p2, q1, q2)) return true;
    return false;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        Point spy, cam;
        int W;
        cin >> spy.x >> spy.y >> cam.x >> cam.y >> W;
        bool see=true;
        for (int i=0; i<W; i++) {
            Point start, end;
            cin >> start.x >> start.y >> end.x >> end.y;
            if (doIntersect(spy, cam, start, end)) see=false;
        }
        if (see) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
2
2 2 6 4 1
2 5 5 5
2 2 6 4 2
4 1 4 5
1 5 4 5
*/
