#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define f first
#define s second

int graph[501][501]={};
vector<int> from[500], dist(500, 1e9);

int dijkstra(int N, int S, int D) {
    dist[S]=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, S});
    while (!pq.empty()) {
        int d=-pq.top().f, cur=pq.top().s;
        pq.pop();
        if (d>dist[cur]) continue;
        for (int i=0; i<N; i++) {
            if (!graph[cur][i]) continue;
            int nd=graph[cur][i];
            if (d+nd<dist[i]) {
                dist[i]=d+nd;
                from[i].clear();
                from[i].push_back(cur);
                pq.push({-(d+nd), i});
            }
            else if (d+nd==dist[i]) from[i].push_back(cur);
        }
    }
    return dist[D];
}

int vst[500]={};
void delete_edge(int cur) {
	if (vst[cur]!=0) return;
	vst[cur]=1;
	for (int i=0; i<from[cur].size(); i++) {
		int prev=from[cur][i];
		if (dist[cur]==dist[prev]+graph[prev][cur]) {
            graph[prev][cur]=0;
            delete_edge(prev);
        }
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        int N, M; cin >> N >> M;
        if (!N && !M) return 0;
        int S, D; cin >> S >> D;
        for (int i=0; i<M; i++) {
            int u, v, p; cin >> u >> v >> p;
            graph[u][v]=p;
        }

        dijkstra(N, S, D);
        delete_edge(D);
        fill(&dist[0], &dist[N], 1e9);
        int ans=dijkstra(N, S, D);
        if (ans==1e9) cout << "-1\n";
        else cout << ans << "\n";

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) graph[i][j]=0;
            from[i].clear();
            dist[i]=1e9;
            vst[i]=0;
        }
    }
}
