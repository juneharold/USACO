#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second

int N, P, K, dist[1005]={};
vector<pair<int, int>> graph[1005];

bool dijkstra(int x) {
    dist[1]=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int d=-pq.top().f, cur=pq.top().s;
        pq.pop();
        if (d>dist[cur]) continue;
        for (int i=0; i<graph[cur].size(); i++) {
            int nx=graph[cur][i].f, w=graph[cur][i].s, nd;
            if (w>x) nd=1;
            else nd=0;
            if (d+nd<dist[nx]) {
                dist[nx]=d+nd;
                pq.push({-(d+nd), nx});
            }
        }
    }

    if (dist[N]<=K) return true;
    else return false;
}

int main()
{
    cin >> N >> P >> K;
    for (int i=0; i<P; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    int lo=0, hi=1e6+1;
    while (lo<hi) {
        fill(&dist[0], &dist[N+1], 1e9);
        int mid=(lo+hi)/2;
        if (dijkstra(mid)) hi=mid;
        else lo=mid+1;
    }
    if (lo==1e6+1) cout << -1;
    else cout << lo;
}
