#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll n, a[nmax]={}, dp[nmax]={};
vector<int> graph[nmax];

void dfs(int cur) {
    if (graph[cur].size()==0) {
        dp[cur]=a[cur];
        return;
    }
    ll mn=INF;
    for (int nx: graph[cur]) {
        dfs(nx);
        mn=min(mn, dp[nx]);
    }
    if (mn!=INF && a[cur]<mn) {
        dp[cur]=(mn+a[cur])/2;
    }
    else dp[cur]=mn;
}


void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=2; i<=n; i++) {
        int p; cin >> p;
        graph[p].push_back(i);
    }
    dfs(1);

    ll ans=a[1], mn=INF;
    for (int nx: graph[1]) {
        mn=min(mn, dp[nx]);
    }
    if (mn!=INF) ans+=mn;
    cout << ans << "\n";

    for (int i=1; i<=n; i++) {
        graph[i].clear();
        dp[i]=0;
        a[i]=0;
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
