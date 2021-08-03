#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N=1005;
int n, m, visit[MAX_N]={}, parent[MAX_N]={};
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> edge[MAX_N];


int main()
{
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    fill(&visit[0], &visit[MAX_N], 1e9);
    pq.push({0, 1});
    visit[1]=0;
    while (!pq.empty()) {
        int dist=-pq.top().first, cur=pq.top().second;
        pq.pop();

        if (dist>visit[cur]) continue;

        for (int i=0; i<edge[cur].size(); i++) {
            int next=edge[cur][i].first, nd=edge[cur][i].second;
            if (dist+nd<visit[next]) {
                visit[next]=dist+nd;
                pq.push({-(dist+nd), next});

                parent[next]=cur;
            }
        }
    }

    cout << n-1 << "\n";
    for (int i=2; i<=n; i++) cout << i << " " << parent[i] << "\n";
}
