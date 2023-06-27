#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, MOD=1e9+7;

ll fastpow(ll x, ll y) {
    x%=MOD;
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
ll dp[200005]={}, p[200005]={};

ll dfs(ll cur) {
    if (dp[cur]!=-1) return dp[cur];
    dp[cur]=1;
    for (ll nx: graph[cur]) {
        if (nx==p[cur]) continue;
        p[nx]=cur;
        dp[cur]+=dfs(nx);
    }
    return dp[cur];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, k; cin >> n >> k;
    for (ll i=1; i<=n-1; i++) {
        ll u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (k%2==1) {
        cout << 1;
        exit(0);
    }
    fill(&dp[0], &dp[n+1], -1);
    dfs(1);

    ll ans=0;
    for (ll i=1; i<=n; i++) {
        ll temp=n*(n-1)/2;
        for (ll adj: graph[i]) {
            if (adj==p[i]) temp-=(n-dp[i])*(n-dp[i]-1)/2;
            else temp-=dp[adj]*(dp[adj]-1)/2;
        }
        ans+=temp;
        ans%=MOD;
    }
    cout << ans*fastpow(n*(n-1)/2, MOD-2)%MOD;
}

/*
7 2
1 2
2 4
2 5
1 3
3 6
3 7

2 2
1 2
*/

