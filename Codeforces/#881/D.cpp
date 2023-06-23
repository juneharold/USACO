#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

ll fastpow (ll x, ll y) {
    ll exponent=y, ret=1;
    while (exponent) {
        if (exponent%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        exponent/=2;
    }
    return ret;
}

vector<ll> graph[nmax];
ll dp[nmax]={};

void dfs(ll cur, ll p) {
    if (graph[cur].size()==1 && graph[cur][0]==p) {
        dp[cur]=1;
        return;
    }
    for (ll i=0; i<graph[cur].size(); i++) {
        ll nx=graph[cur][i];
        if (nx==p) continue;
        dfs(nx, cur);
        dp[cur]+=dp[nx];
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    vector<ll> out;
    while (T--) {
        ll n; cin >> n;
        for (ll i=0; i<n-1; i++) {
            ll u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, 0);
        ll q; cin >> q;
        for (ll i=0; i<q; i++) {
            ll x, y; cin >> x >> y;
            out.push_back(dp[x]*dp[y]);
        }

        for (ll i=0; i<=n; i++) {
            graph[i].clear();
            dp[i]=0;
        }
    }
    for (ll x: out) cout << x << "\n";
}
