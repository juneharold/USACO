#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int N, visit[10005]={};
vector<pair<int, int>> graph[10005];

void dfs(int cur, int w) {
    visit[cur]=w;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].f, nw=graph[cur][i].s;
        if (visit[nx]==-1) dfs(nx, w+nw);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i=1; i<=N-1; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    fill(&visit[1], &visit[N+1], -1);
    dfs(1, 0);

    int temp=0, from=0;
    for (int i=1; i<=N; i++) {
        if (visit[i]>temp) {
            temp=visit[i];
            from=i;
        }
        visit[i]=-1;
    }

    dfs(from, 0);

    int ans=0;
    for (int i=1; i<=N; i++) ans=max(ans, visit[i]);
    cout << ans;
}
