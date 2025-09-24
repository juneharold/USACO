#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<ll> graph[nmax];
ll vst[nmax]={}, dist[nmax]={}, dp[nmax]={};
ll ans=0;

void init(ll n) {
    for (ll i=1; i<=n; i++) {
        graph[i].clear();
        vst[i]=0;
        dist[i]=0;
        dp[i]=0;
    }
    ans=0;
}

void doBFS(ll n) {
    queue<ll> q;
    for (ll i=1; i<=n; i++) if (graph[i].size()==1) {
        vst[i]=1;
        q.push(i);
    }
    while (!q.empty()) {
        ll cur=q.front(); q.pop();
        for (ll nx: graph[cur]) {
            if (vst[nx]==0) {
                vst[nx]=1;
                dist[nx]=dist[cur]+1;
                q.push(nx);
            }
        }
    }

}

void computeDP(ll cur, ll p) {
    dp[cur]=0;
    if (dist[cur]>=2) dp[cur]=1;
    for (ll nx: graph[cur]) {
        if (nx==p) continue;
        computeDP(nx, cur);
        dp[cur]+=dp[nx];
    }
}

void dfs(ll cur, ll p) {
    if (dist[cur]==1) {
        //cout << cur << endl;
        vector<pii> candidates;
        ll dp_sum=0;
        for (ll nx: graph[cur]) {
            if (nx==p) continue;
            if (dist[nx]!=0) candidates.push_back({nx, dp[nx]});
            //dp_sum+=dp[nx];
        }
        if (p!=0 && dist[p]!=0) candidates.push_back({p, dp[1]-dp[cur]});
        //for (auto cand: candidates) cout << cand.fs << ' ' << cand.sc << endl;
        ll totalP=0;
        for (auto cand: candidates) totalP+=cand.sc;
        for (auto cand: candidates) ans+=totalP-cand.sc;
    }
    // continue dfs
    for (ll nx: graph[cur]) {
        if (nx==p) continue;
        dfs(nx, cur);
    }
}

void solve() {
    ll n; cin >> n;
    for (ll i=1; i<n; i++) {
        ll u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    doBFS(n);
    computeDP(1, 0);
    dfs(1, 0);
    ll cntLeaf=0;
    for (ll i=1; i<=n; i++) if (dist[i]==0) cntLeaf++;
    ans+=cntLeaf*(n-cntLeaf);
    cout << ans << "\n";
    init(n);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
