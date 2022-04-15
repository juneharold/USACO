#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll, ll> pll;

bool onSegment(pll p, pll q, pll r) {
    if (q.f<=max(p.f, r.f) && q.f>=min(p.f, r.f) &&
        q.s<=max(p.s, r.s) && q.s>=min(p.s, r.s)) return true;
    return false;
}

double orientation(pll p, pll q, pll r) {
    double val=(q.s-p.s)*(r.f-q.f)-(q.f-p.f)*(r.s-q.s);
    if (val==0) return 0; // colinear
    if (val>0) return 1; // clockwise
    else return 2; // counterclockwise
}

bool doIntersect(pll p1, pll q1, pll p2, pll q2) {
    double o1=orientation(p1, q1, p2);
    double o2=orientation(p1, q1, q2);
    double o3=orientation(p2, q2, p1);
    double o4=orientation(p2, q2, q1);

    if (o1!=o2 && o3!=o4) return true;
    if (o1==0 && onSegment(p1, p2, q1)) return true;
    if (o2==0 && onSegment(p1, q2, q1)) return true;
    if (o3==0 && onSegment(p2, p1, q2)) return true;
    if (o4==0 && onSegment(p2, q1, q2)) return true;
    return false;
}

int main()
{
    pll a, b, c, d;
    cin >> a.f >> a.s >> b.f >> b.s >> c.f >> c.s >> d.f >> d.s;
    if (a>b) swap(a, b);
    if (c>d) swap(c, d);

    if (doIntersect(a, b, c, d)) {
        cout << "1\n";
        double a1=b.s-a.s;
        double b1=a.f-b.f;
        double c1=a1*(a.f)+b1*(a.s);

        double a2=d.s-c.s;
        double b2=c.f-d.f;
        double c2=a2*(c.f)+b2*(c.s);

        double det=a1*b2-a2*b1;
        if (det!=0) {
            double x=(b2*c1-b1*c2)/det;
            double y=(a1*c2-a2*c1)/det;
            cout << fixed << setprecision(10) << x << " " << y;
        }
        else {
            if (c.f==d.f && c.s==d.s) {
                cout << c.f << " " << c.s;
            }
            else if (a==d) {
                cout << a.f << " " << a.s;
            }
            else if (b==c) {
                cout << b.f << " " << b.s;
            }
        }
    }
    else cout << "0";
}
