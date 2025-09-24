#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=5e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int n, c[nmax];
vector<int> graph[nmax];

ll dp[nmax]={};
int sz[nmax];
void dfs(int cur, int p) {
    vector<pair<pii, int>> next_dp;
    sz[cur]=1;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dfs(nx, cur);
        sz[cur]+=sz[nx];
        next_dp.push_back({{sz[nx], dp[nx]}, nx});
    }

    sort(next_dp.begin(), next_dp.end());
    dp[cur]=0;
    ll t=0;
    for (int i=0; i<next_dp.size(); i++) {
        int s=next_dp[i].fs.fs, d=next_dp[i].fs.sc, nx=next_dp[i].sc;
        t++;
        dp[cur]=max(dp[cur], max(c[nx], d)+t);
        t+=2*s-1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> c[i];
    int u, v; 
    for (int i=1; i<=n-1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    // for (int i=1; i<=n; i++) cout << dp[i] << ' ';
    // cout << endl;
    cout << max(dp[1], (ll)2*(sz[1]-1)+c[1]);
}
/*
6
1 8 9 6 10 2
1 3
2 3
3 4
4 5
4 6
ans: 15
*/