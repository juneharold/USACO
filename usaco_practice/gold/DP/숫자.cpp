#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
#define ll long

ll A, B, K, from[4000005]={}, dp[4000005]={}, vst[4000005]={};

ll S(ll N, ll k) {
    ll ret=0;
    while (N!=0) {
        ret+=pow(N%10, k);
        N/=10;
    }
    return ret;
}

vector<ll> path;
void dfs(ll cur) {
    vst[cur]=1;
    path.push_back(cur);

    if (vst[from[cur]]==1) {
        ll idx=-1;
        for (ll j=0; j<path.size(); j++) {
            if (path[j]==from[cur]) idx=j;
        }
        if (idx!=-1) {
            ll Min=1e9;
            for (ll j=idx; j<path.size(); j++) Min=min(Min, path[j]);
            for (ll j=idx; j<path.size(); j++) dp[path[j]]=Min;
        }
    }
    else dfs(from[cur]);
}

ll solve(ll i) {
    if (dp[i]!=0) return dp[i];
    dp[i]=min(i, solve(from[i]));
    return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> K;
    for (ll i=1; i<=3188710; i++) {
        from[i]=S(i, K);
    }

    for (ll i=1; i<=3188710; i++) {
        if (vst[i]==0) {
            path.clear();
            dfs(i);
        }
    }
    
    ll ans=0;
    for (ll i=A; i<=B; i++) ans+=solve(i);
    cout << ans;
}