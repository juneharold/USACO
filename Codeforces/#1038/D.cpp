#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<uint16_t, uint16_t> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<uint16_t> graph[5005];
uint16_t dist[5005][15005];

void solve() {
    int n, m; cin >> n >> m;
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    fill(&dist[0][0], &dist[n+1][3*n+1], 15001);
    dist[1][0]=0;
    deque<pair<pii,uint16_t>> dq;
    dq.push_front({{0, 0}, 1});
    pii ans={15001, 15001};
    while (!dq.empty()) {
        pii d=dq.front().fs;
        int cur=dq.front().sc;
        dq.pop_front();

        if (d.fs>ans.fs) continue;

        if (cur==n) {
            if (d.fs<ans.fs || (d.fs==ans.fs && d.sc<ans.sc)) ans=d;
            continue;
        }

        if (d.fs>3*n || dist[cur][d.fs]<d.sc) continue;

        int sz=graph[cur].size();
        if (sz==0) continue;
        int node=graph[cur][d.fs%sz];
        pii nx1={node, d.fs+1};
        if (d.sc<dist[node][d.fs+1]) {
            dist[node][d.fs+1]=d.sc;
            dq.push_front({{d.fs+1, d.sc}, node});
        }

        pii nx2={cur, d.fs+1};
        if (d.sc+1<dist[cur][d.fs+1]) {
            dist[cur][d.fs+1]=d.sc+1;
            dq.push_back({{d.fs+1, d.sc+1}, cur});
        }
    }
    cout << ans.fs << ' ' << ans.sc << "\n";
    for (int i=1; i<=n; i++) graph[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
/*
4 4
1 2
2 3
3 4
1 4

6 6
1 2 
2 3
3 4
4 6
5 6
1 5

4 3
1 2
2 3
2 4

*/