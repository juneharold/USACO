#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<int> graph[nmax];

vector<int> diameter, path;
int n, s, e, dist[nmax]={};

void dfs(int cur, int p) {
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dist[nx]=dist[cur]+1;
        dfs(nx, cur);
    }
}

void dfs2(int cur, int p) {
    path.push_back(cur);
    if (cur==e) {
        diameter=path;
        return;
    }
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dist[nx]=dist[cur]+1;
        dfs2(nx, cur);
        if (diameter.size()>0) return;
    }
    path.pop_back();
}

void reset() {
    path.clear();
    diameter.clear();
    for (int i=1; i<=n; i++) {
        dist[i]=0;
        graph[i].clear();
    }
}

void solve() {
    cin >> n;
    int u, v;
    for (int i=1; i<=n-1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    int mx=-1;
    for (int i=1; i<=n; i++) {
        if (dist[i]>mx) {
            mx=dist[i];
            s=i;
        }
    }

    dfs(s, 0);
    mx=-1;
    for (int i=1; i<=n; i++) {
        if (dist[i]>mx) {
            mx=dist[i];
            e=i;
        }
    }

    dfs2(s, 0);

    if (diameter.size()==n) {
        cout << "-1\n";
        reset();
        return;
    }

    for (int i=1; i<diameter.size()-1; i++) {
        int a=diameter[i-1], b=diameter[i];
        for (int c: graph[b]) {
            if (c!=diameter[i+1] && c!=a) {
                cout << a << ' ' << b << ' ' << c << "\n";
                reset();
                return;
            }
        }
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

/*
9
1 2
2 3
1 4
4 5
1 6
6 7
1 8
8 9
*/