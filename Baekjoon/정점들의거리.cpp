#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> p[40005];
vector<pair<int, int>> graph[40005];
int depth[40005];

void dfs(int cur, int parent) {
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].first, dist=graph[cur][i].second;
        if (nx==parent) continue;
        p[nx]={cur, dist};
        depth[nx]=depth[cur]+1;
        dfs(nx, cur);
    }
}

int LCA(int a, int b) {
    if (depth[a]<depth[b]) swap(a, b);

    int ret=0;
    while (depth[a]!=depth[b]) {
        ret+=p[a].second;
        a=p[a].first;
    }
    while (a!=b) {
        ret+=p[a].second+p[b].second;
        a=p[a].first;
        b=p[b].first;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i=0; i<N-1; i++) {
        int u, v, d; cin >> u >> v >> d;
        graph[u].push_back(make_pair(v, d));
        graph[v].push_back(make_pair(u, d));
    }

    depth[1]=0;
    dfs(1, 0);

    int M; cin >> M;
    for (int i=0; i<M; i++) {
        int u, v; cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }
}