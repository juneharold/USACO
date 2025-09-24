#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=4e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

map<ll, int> toGraph;
map<ll, int> vst;
vector<ll> graph[nmax];
ll ans=0;

void dfs(ll cur) {
    vst[cur]=1;
    ans=max(ans, cur);
    for (ll nx: graph[toGraph[cur]]) {
        if (nx==cur) continue;
        if (vst.find(nx)==vst.end()) dfs(nx);
    }
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    int idx=0;
    for (int i=1; i<=n; i++) {
        ll aa=a[i]-(n+1-i);
        ll bb=aa+i-1;
        //cout << aa << ' ' << bb << endl;
        if (aa<0) continue;
        if (toGraph.find(aa)==toGraph.end()) toGraph[aa]=++idx;
        graph[toGraph[aa]].push_back(bb);
    }
    ans=0;
    dfs(0);
    cout << ans+n << "\n";
    for (int i=1; i<=idx; i++) {
        graph[i].clear();
    }
    toGraph.clear();
    vst.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
