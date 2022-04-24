#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int V, visit[100005]={};
vector<pair<int, int>> graph[100005];

void dfs(int cur, int w) {
    visit[cur]=w;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].f, nw=graph[cur][i].s;
        if (visit[nx]==-1) dfs(nx, w+nw);
    }
}

int main()
{
    cin >> V;
    for (int i=1; i<=V; i++) {
        int node; cin >> node;
        while (true) {
            int a, b; cin >> a;
            if (a==-1) break;
            else cin >> b;
            graph[node].push_back({a, b});
        }
    }

    fill(&visit[1], &visit[V+1], -1);
    dfs(1, 0);

    int temp=0, from;
    for (int i=1; i<=V; i++) {
        if (visit[i]>temp) {
            temp=visit[i];
            from=i;
        }
        visit[i]=-1;
    }

    dfs(from, 0);

    int ans=0;
    for (int i=1; i<=V; i++) ans=max(ans, visit[i]);
    cout << ans;
}
