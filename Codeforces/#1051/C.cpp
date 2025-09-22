#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int u[nmax], v[nmax], x[nmax], y[nmax], p[nmax];

int mn, mx;
vector<pair<int, pii>> graph[nmax];

void dfs(int u, int parent) {
    for (auto [v, pr]: graph[u]) {
        if (v==parent) continue;

        int xx=pr.fs, yy=pr.sc;

        if (u<v && xx>yy) {
            p[v]=--mn;
        }
        else if (u<v && xx<yy) {
            p[v]=++mx;
        }
        else if (u>v && xx>yy) {
            p[v]=--mn;
        }
        else {
            p[v]=++mx;
        }
        dfs(v, u);
    }
}


void solve() {
    int n; cin >> n;
    vector<int> u(n+1), v(n+1), x(n+1), y(n+1);
    for (int i=1; i<=n-1; i++) {
        cin >> u[i] >> v[i] >> x[i] >> y[i];
        graph[u[i]].push_back({v[i], {x[i], y[i]}});
        graph[v[i]].push_back({u[i], {y[i], x[i]}});
    }

    p[1]=n;
    mn=n, mx=n;
    dfs(1, 0);

    for (int i=1; i<=n; i++) cout << p[i]-(mn-1) << ' ';
    cout << "\n";

    for (int i=1; i<=n; i++) {
        graph[i].clear();
        u[i]=v[i]=x[i]=y[i]=p[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
