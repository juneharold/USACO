#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, depth[50005]={}, parent[50005][20]={};
vector<int> graph[50005];

void dfs(int cur, int p) {
    depth[cur]=depth[p]+1;
    for (int i=1; i<20; i++) {
        if ((1<<i)>depth[cur]) break;
        parent[cur][i]=parent[parent[cur][i-1]][i-1];
    }
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        parent[nx][0]=cur;
        dfs(nx, cur);
    }
}

int LCA(int a, int b) {
    if (depth[b]>depth[a]) swap(a, b);
    for (int i=19; i>=0; i--) {
        if (parent[a][i]==-1) continue;
        if (depth[b]<=depth[parent[a][i]]) a=parent[a][i];
    }
    if (a==b) return a;
    for (int i=19; i>=0; i--) {
        if (parent[a][i]!=parent[b][i]) {
            a=parent[a][i];
            b=parent[b][i];
        }
    }
    return parent[a][0];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    fill(&depth[0], &depth[N+1], -1);
    fill(&parent[0][0], &parent[N][20], -1);
    dfs(1, 0);

    int Q; cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}
