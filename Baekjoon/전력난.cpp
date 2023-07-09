#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[200005]={}, sz[200005]={};

struct edge{
    int u, v, w;
};
bool cmp(edge a, edge b) {
    return a.w<b.w;
}
vector<edge> road;

int Find(int x) {
    if (p[x]==x) return x;
    return p[x]=Find(p[x]);
}

void Union(int a, int b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    p[a]=b;
    sz[b]+=sz[a];
}

vector<int> out;

int main()
{
    while (true) {
        int m, n; cin >> m >> n;
        if (m==0 && n==0) break;
        for (int i=0; i<m; i++) p[i]=i, sz[i]=1;
        road.clear();
        int ans=0;
        for (int i=0; i<n; i++) {
            int u, v, w; cin >> u >> v >> w;
            road.push_back({u, v, w});
            ans+=w;
        }
        sort(road.begin(), road.end(), cmp);

        for (int i=0; i<n; i++) {
            int u=road[i].u, v=road[i].v, w=road[i].w;
            if (Find(u)!=Find(v)) {
                Union(u, v);
                ans-=w;
            }
        }
        out.push_back(ans);

        fill(&p[0], &p[m], 0);
        fill(&sz[0], &sz[m], 0);
    }
    for (int x: out) cout << x << "\n";
}