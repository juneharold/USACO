#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define f first
#define s second

int p[1005]={}, sz[1005]={};
int Find(int x) {
    if (p[x]==x) return x;
    else return p[x]=Find(p[x]);
}
void Union(int a, int b) {
    int A=Find(a), B=Find(b);
    if (A==B) return;
    if (sz[A]>sz[B]) swap(A, B);
    p[A]=B;
    sz[B]+=sz[A];
}

double dist(double x1, double y1, double x2, double y2) {
    double a=(x1-x2)*(x1-x2);
    double b=(y1-y2)*(y1-y2);
    return sqrt(a+b);
}

pair<double, double> point[1005];
pair<double, pair<int, int>> edge[1000005];

int main()
{
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> point[i].f >> point[i].s;

    for (int i=1; i<=1000; i++) {
        p[i]=i;
        sz[i]=1;
    }
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        Union(a, b);
    }

    int idx=1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i==j) continue;
            double d=dist(point[i].f, point[i].s, point[j].f, point[j].s);
            edge[idx]={d, {i, j}};
            idx++;
        }
    }

    sort(&edge[1], &edge[idx]);

    double cost=0;
    for (int i=1; i<idx; i++) {
        int a=edge[i].s.f, b=edge[i].s.s;
        if (Find(a)!=Find(b)) {
            Union(a, b);
            cost+=edge[i].f;
        }
    }

    //cost-=0.005;
    printf("%.2lf", cost);
}
