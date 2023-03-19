#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int dist[3][2005]={};
vector<pair<int, int>> graph[2005];

void dijkstra(int start, int idx) {
    dist[idx][start]=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int d=-pq.top().first, cur=pq.top().second;
        pq.pop();
        if (d>dist[idx][cur]) continue;
        for (int i=0; i<graph[cur].size(); i++) {
            int nx=graph[cur][i].first, nd=graph[cur][i].second;
            if (d+nd<dist[idx][nx]) {
                dist[idx][nx]=d+nd;
                pq.push({-(d+nd), nx});
            }
        }
    }
}

void solve() {
    int n, m, t, s, g, h; cin >> n >> m >> t >> s >> g >> h;
    for (int i=0; i<m; i++) {
        int a, b, d; cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    vector<int> ends;
    for (int i=0; i<t; i++) {
        int x; cin >> x;
        ends.push_back(x);
    }

    dijkstra(s, 0);
    dijkstra(g, 1);
    dijkstra(h, 2);

    vector<int> ans;
    for (int x: ends) {
        if (dist[0][x]==dist[0][g]+dist[1][h]+dist[2][x]) ans.push_back(x);
        else if (dist[0][x]==dist[0][h]+dist[2][g]+dist[1][x]) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    for (int a: ans) cout << a << ' ';
    cout << "\n";
}

int main()
{
    int T; cin >> T;
    while (T--) {
        fill(&dist[0][0], &dist[2][2001], 1e9);
        for (int i=0; i<2001; i++) graph[i].clear();
        solve();
    }
}

/*
1
2 1 1 
1 1 2 
1 2 2 
2

1
3 3 1
1 2 3 
1 2 1
1 3 2
2 3 1
3

1
5 7 3
1 1 2
1 2 1 
2 3 1 
1 3 2
3 4 2
1 4 4 
1 5 6 
4 5 2
3 
4 
5 
*/