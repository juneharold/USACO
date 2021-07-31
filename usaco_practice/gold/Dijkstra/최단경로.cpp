#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int Vmax=2e4+5, Emax=3e5+5;
int v, e, k, visit[Vmax]={};
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> edge[Emax];

int main()
{
    cin >> v >> e >> k;
    for (int i=0; i<e; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    fill(&visit[0], &visit[Vmax], 1e9);

    pq.push({0, k});
    visit[k]=0;

    while (!pq.empty()) {
        int weight=-pq.top().first, cur=pq.top().second;
        pq.pop();

        if (weight>visit[cur]) continue;

        for (int i=0; i<edge[cur].size(); i++) {
            int next=edge[cur][i].first, nw=edge[cur][i].second;
            if (weight+nw<visit[next]) {
                visit[next]=weight+nw;
                pq.push({-(weight+nw), next});
            }
        }
    }

    for (int i=1; i<=v; i++) {
        if (visit[i]==1e9) cout << "INF\n";
        else cout << visit[i] << "\n";
    }
}
