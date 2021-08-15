#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=10005;
int V, E, p[MAX], ans=0;

struct edge {int a, b, w;};
vector<edge> edges;

bool cmp (edge a, edge b) {return a.w<b.w;}

int Find(int x) {
    if (p[x]==x) return x;
    else return p[x]=Find(p[x]);
}
void Union (int a, int b) {
    a=Find(a);
    b=Find(b);
    if (a==b) return;
    p[b]=a;
}

int main()
{
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i=1; i<=V; i++) p[i]=i;

    for (auto e: edges) {
        int cur=e.a, nx=e.b;
        if (Find(cur)==Find(nx)) continue;
        Union(cur, nx);
        ans+=e.w;
    }
    cout << ans;
}
