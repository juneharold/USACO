#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll dp[nmax*2]={};
map<ll, ll> ktoidx;
map<ll, vector<ll>> graph;

void dfs(ll cur) {
    //cout << "cur: " << cur << endl;
    dp[ktoidx[cur]]=cur;
    if (graph.find(cur)==graph.end()) return;
    for (ll nx: graph[cur]) {
        //cout << nx << ' ' << ktoidx[nx] << ' ';
        if (dp[ktoidx[nx]]==-1) dfs(nx);
        dp[ktoidx[cur]]=max(dp[ktoidx[cur]], dp[ktoidx[nx]]);
    }
    //cout << endl;
}

void solve() {
    ll n, m; cin >> n >> m;
    ll idx=0;
    for (ll i=1; i<=n; i++) {
        ll l; cin >> l;
        set<ll> s;
        for (ll j=0; j<l; j++) {
            ll x; cin >> x;
            s.insert(x);
        }
        ll cnt=0, u=-1, v=-1;
        for (ll j=0; j<nmax; j++) {
            if (s.find(j)==s.end()) cnt++;
            //cout << j << ' '<< cnt << endl;
            if (cnt==1 && u==-1) {
                u=j;
            }
            if (cnt==2 && v==-1) {
                v=j;
                break;
            }
        }
        if (ktoidx.find(u)==ktoidx.end()) ktoidx[u]=++idx;
        if (ktoidx.find(v)==ktoidx.end()) ktoidx[v]=++idx;
        graph[u].push_back(v);
        //cout << "u v: " << u << ' ' << v << endl;
    }

    fill(&dp[0], &dp[idx+1], -1);
    for (auto g: graph) {
        if (dp[ktoidx[g.fs]]==-1) dfs(g.fs);
        //cout << g.fs << ' ' << dp[ktoidx[g.fs]] << endl;
    }
    //cout << endl;

    ll mxdp=0;
    for (auto g: graph) {
        mxdp=max(mxdp, g.fs);
        if (g.sc.size()>1) {
            for (ll j=0; j<g.sc.size(); j++) {
                mxdp=max(mxdp, dp[ktoidx[g.sc[j]]]);
            }
        }
    }
    //cout << mxdp << endl;
    // cnt+1 ~ m 

    ll ans=0, cnt1=0, cnt2=0;
    for (auto g: graph) {
        if (g.fs>m || dp[ktoidx[g.fs]]<=mxdp) continue;
        ans+=dp[ktoidx[g.fs]];
        if (g.fs>mxdp) cnt1+=g.fs;
        if (g.fs<=mxdp) cnt2++;
        //cout << g.fs << ' ' << g.sc.size() << endl;
    }
    //cout << ans << ' ' << mxdp << ' ' << cnt1 << ' ' << cnt2 << endl;

    if (mxdp<=m) ans+=mxdp*(mxdp+1-cnt2)+m*(m+1)/2-mxdp*(mxdp+1)/2-cnt1;
    else ans+=(m+1-cnt2)*mxdp-cnt1;
    cout << ans << "\n";

    for (ll i=1; i<=idx+5; i++) {
        dp[i]=0;
    }
    ktoidx.clear();
    graph.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}