#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e6+5, sqrmax=635, MOD=1e9+7, INF=9e18;

ll leader[nmax], sz[nmax];
ll Find(ll x) {
    if (leader[x]==x) return x;
    return leader[x]=Find(leader[x]);
}
void Union (ll a, ll b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    leader[a]=b;
    sz[b]+=sz[a];
}

ll n, m, degree[nmax]={};
ll l[nmax]={}, r[nmax]={}, wval[nmax]={}, f[nmax]={}, cnt[nmax]={};

ll ans=0;
void dfs(ll cur, ll mn=2e9) {
    if (cur==0) return;
    mn=min(mn, wval[cur]);
    f[cur]=mn;
    dfs(l[cur], mn);
    dfs(r[cur], mn);

    if (cur<=n && degree[cur]%2) cnt[cur]=1;
    cnt[cur]+=cnt[l[cur]]+cnt[r[cur]];
    ans+=(cnt[cur]/2)*f[cur];
    cnt[cur]%=2;
}

void solve() {
    cin >> n >> m;
    ll u, v, w;
    vector<pair<ll, pii>> edges;
    for (ll i=1; i<=m; i++) {
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    vector<ll> root(2*n+5, 0);
    for (ll i=1; i<=n; i++) {
        leader[i]=i;
        sz[i]=1;
        root[i]=i;
    }

    ll idx=n;
    for (auto e: edges) {
        degree[e.sc.fs]++;
        degree[e.sc.sc]++;
        ans+=e.fs;
        ll u=Find(e.sc.fs), v=Find(e.sc.sc);
        if (u!=v) {
            idx++;
            wval[idx]=e.fs;
            l[idx]=root[u];
            r[idx]=root[v];
            Union(u, v);
            root[Find(u)]=idx;
        }
        else {
            ll c=root[u];
            wval[c]=min(wval[c], e.fs);
        }
    }
    
    dfs(idx);

    cout << ans << "\n";

    for (ll i=1; i<=2*n; i++) {
        leader[i]=0;
        sz[i]=0;
        l[i]=0;
        r[i]=0;
        wval[i]=0;
        f[i]=0;
        degree[i]=0;
        cnt[i]=0;
    }
    ans=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
