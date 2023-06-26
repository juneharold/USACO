#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;
typedef long long ll;

vector<ll> graph1[500005];
ll cash1[500005]={}, vst[500005]={}, group[500005]={}, restaurant[500005]={}, cash2[500005]={};
ll idx=0, groupnum=0;
stack<ll> s;

ll dfs(ll cur) {
    vst[cur]=++idx;
    s.push(cur);
    ll parent=vst[cur];
    for (ll nx: graph1[cur]) {
        if (vst[nx]==0) parent=min(parent, dfs(nx));
        else if (group[nx]==0) parent=min(parent, vst[nx]);
    }

    if (parent==vst[cur]) {
        groupnum++;
        ll sum=0;
        while (!s.empty()) {
            ll temp=s.top();
            group[s.top()]=groupnum;
            sum+=cash1[s.top()];
            s.pop();
            if (temp==cur) break;
        }
        cash2[groupnum]=sum;
    }
    return parent;
}

vector<ll> graph2[500005]; // dp를 위한 SCC를 연결한 그래프 (그래프 방향은 반대)
ll dp[500005]={};

ll find_dp(ll cur) {
    if (dp[cur]!=-1e18) return dp[cur];
    dp[cur]=0;
    for (ll bef: graph2[cur]) {
        dp[cur]=max(dp[cur], find_dp(bef)+cash2[cur]);
    }
    return dp[cur];
}

int main()
{
    ll N, M; cin >> N >> M;
    for (ll i=0; i<M; i++) {
        ll u, v; cin >> u >> v;
        graph1[u].push_back(v);
    }
    for (ll i=1; i<=N; i++) cin >> cash1[i];
    ll S, P; cin >> S >> P;
    for (ll i=0; i<P; i++) {
        ll x; cin >> x;
        restaurant[x]=1;
    }

    dfs(S);

    // dp
    for (ll i=1; i<=N; i++) {
        for (ll nx: graph1[i]) {
            if (group[i]!=group[nx]) graph2[group[nx]].push_back(group[i]);
        }
    }

    ll start=group[S], ans=0;
    fill(&dp[0], &dp[groupnum+1], -1e18);
    dp[start]=cash2[start];
    for (ll i=1; i<=N; i++) {
        if (restaurant[i]) {
            ans=max(ans, find_dp(group[i]));
        }
    }
    cout << ans;
}