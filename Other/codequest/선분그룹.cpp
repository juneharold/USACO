#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

pair<Point, Point> line[3005];
int group[3005]={}, sz[3005]={};

int Find (int x) {
    if (group[x]==x) return x;
    else return group[x]=Find(group[x]);
}

void Union (int a, int b) {
    a=Find(a);
    b=Find(b);
    if (a==b) return;
    if (sz[a] > sz[b]) swap(a, b);
    group[a] = b;
    sz[b]+=sz[a];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> line[i].f.x >> line[i].f.y >> line[i].s.x >> line[i].s.y;

    for (int i=1; i<=N; i++) {
        group[i]=i;
        sz[i]=1;
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (Find(i)==Find(j)) continue;
            if (doIntersect(line[i].f, line[i].s, line[j].f, line[j].s)) {
                Union(i, j);
            }
        }
    }

    set<int> s;
    int max_sz=0;
    for (int i=1; i<=N; i++) {
        max_sz=max(max_sz, sz[i]);
        s.insert(group[i]);
    }
    cout << s.size() << "\n" << max_sz;
}
