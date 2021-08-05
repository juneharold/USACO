#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N=1005;
int n, m, start, finish, visit[MAX_N]={}, parent[MAX_N]={};
vector<pair<int, int>> graph[MAX_N];
priority_queue<pair<int, int>> pq;
vector<int> path;

void find_path(int cur) {
    path.push_back(cur);
    if (parent[cur]==start) {
        path.push_back(start);
        return;
    }
    else {
        find_path(parent[cur]);
    }
}

int main()
{
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cin >> start >> finish;

    fill(&visit[0], &visit[MAX_N], 1e9);
    visit[start]=0; pq.push({0, start});
    while (!pq.empty()) {
        int cost=-pq.top().first, cur=pq.top().second;
        pq.pop();
        if (cost>visit[cur]) continue;

        for (int i=0; i<graph[cur].size(); i++) {
            int nx=graph[cur][i].first, nc=graph[cur][i].second;
            if (nc+cost<visit[nx]) {
                visit[nx]=nc+cost;
                parent[nx]=cur;
                pq.push({-(nc+cost), nx});
            }
        }
    }

    find_path(finish);

    cout << visit[finish] << "\n" << path.size() << "\n";

    for (auto it=path.end(); it>=path.begin(); it--) {
        if (it==path.end()) it--;
        cout << *it << " ";
    }
}
