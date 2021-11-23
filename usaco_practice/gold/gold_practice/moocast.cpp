#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define f first
#define s second

int N, parent[1005]={};
priority_queue<pair<int, pair<int, int>>> edges;
pair<int, int> pos[1005];

int Find (int x) {
    if (parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}

void Union (int a, int b) {
    a=Find(a);
    b=Find(b);
    if (a==b) return;
    parent[a]=b;
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> pos[i].f >> pos[i].s;
        parent[i]=i;
    }

    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            int cost=(pos[i].f-pos[j].f)*(pos[i].f-pos[j].f)+(pos[i].s-pos[j].s)*(pos[i].s-pos[j].s);
            edges.push({-cost, {i, j}});
        }
    }

    int ans=0;
    while (!edges.empty()) {
        int cost=-edges.top().f, u=edges.top().s.f, v=edges.top().s.s;
        if (Find(u)!=Find(v)) {
            Union(u, v);
            ans=cost;
        }
        edges.pop();
    }
    cout << ans;
}
