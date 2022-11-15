#include<iostream>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second

int dist[1005]={};
vector<pair<int, pair<int, int>>> adj[1005];

int main()
{
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    int N, M; cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b, c, f; cin >> a >> b >> c >> f;
        adj[a].push_back({b, {c, f}});
        adj[b].push_back({a, {c, f}});
    }
    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    dist[1]=1e9;
    pq.push({{1e9, 1}, {0, 1e9}});
    while (!pq.empty()) {
        int d=pq.top().f.f, cur=pq.top().f.s, cost=pq.top().s.f, fmin=pq.top().s.s;
        pq.pop();
        if (d>dist[cur]) continue;
        for (auto nx: adj[cur]) {
            int nd=min(fmin, nx.s.s)*1000000/(cost+nx.s.f);
            if (nd>dist[nx.f]) {
                dist[nx.f]=nd;
                pq.push({{nd, nx.f}, {cost+nx.s.f, min(fmin, nx.s.s)}});
            }
        }
    }

    cout << dist[N];
}
