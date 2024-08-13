#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<int> graph[nmax];

void solve() {
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    for (int i=0; i<m; i++) {
        cin >> u[i] >> v[i];
        graph[u[i]].push_back(v[i]);
    }
    for (int i=1; i<=n-1; i++) graph[i].push_back(i+1);

    vector<int> dist(n+1, 1e9);
    priority_queue<pii> pq;
    dist[1]=0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int d=-pq.top().fs, cur=pq.top().sc;
        pq.pop();
        if (d>dist[cur]) continue;
        for (int nx: graph[cur]) {
            if (dist[nx]>dist[cur]+1) {
                dist[nx]=dist[cur]+1;
                pq.push({-dist[nx], nx});
            }
        }
    }

    vector<int> mark(n+1, 0);
    for (int i=0; i<m; i++) {
        // dist[u[i]]+1<v[i]-x --> u[i]+1<=x<v[i]-(dist[u[i]]+1)
        if (u[i]+1<=v[i]-(dist[u[i]]+1)-1) {
            mark[u[i]+1]++;
            mark[v[i]-(dist[u[i]]+1)]--;
        }
    }
    for (int i=1; i<=n; i++) mark[i]+=mark[i-1];

    vector<int> ans(n+1, 1);
    for (int i=1; i<=n; i++) if (mark[i]>0) ans[i]=0;
    for (int i=1; i<=n-1; i++) cout << ans[i];
    cout << "\n";
    
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
