#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define f first
#define s second 

int dist[4][805]={};
vector<pair<int, int>> graph[805];

void dijkstra(int start, int idx) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[idx][start]=0;
    while (!pq.empty()) {
        int d=-pq.top().f, cur=pq.top().s;
        pq.pop();
        if (d>dist[idx][cur]) continue;
        for (int i=0; i<graph[cur].size(); i++) {
            int nx=graph[cur][i].f, nd=graph[cur][i].s;
            if (d+nd<dist[idx][nx]) {
                dist[idx][nx]=d+nd;
                pq.push({-(d+nd), nx});
            }
        }
    }
}

int main()
{
    int N, E, v1, v2; cin >> N >> E;
    for (int i=0; i<E; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    fill(&dist[0][0], &dist[3][804], 2e9);

    dijkstra(1, 0);
    dijkstra(v1, 1);
    dijkstra(v2, 2);
    int ans=min(dist[0][v1]+dist[1][v2]+dist[2][N], dist[0][v2]+dist[2][v1]+dist[1][N]);
    if (ans>=1e9) cout << -1;
    else cout << ans;
}

