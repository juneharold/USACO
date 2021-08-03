#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int M=1e5+5, N=1005;
int n, m, start, finish, visit[N]={};
vector<pair<int, int>> edge[N];
priority_queue<pair<int, int>> pq;

int main()
{
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    cin >> start >> finish;
    fill(&visit[0], &visit[N], 1e9);

    pq.push({0, start}); visit[start]=0;
    while (!pq.empty()) {
        int dist=-pq.top().first, cur=pq.top().second;
        pq.pop();

        if (dist>visit[cur]) continue;

        for (int i=0; i<edge[cur].size(); i++) {
            int next=edge[cur][i].first, nd=edge[cur][i].second;
            if (dist+nd<visit[next]) {
                visit[next]=dist+nd;
                pq.push({-(dist+nd), next});
            }
        }
    }

    cout << visit[finish];
}
