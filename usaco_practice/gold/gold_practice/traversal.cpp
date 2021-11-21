#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define f first
#define s second
#define ll long long
const ll MAX_N=1e5+5;

ll N, dp[MAX_N]={}, total_files=0, num_files[MAX_N]={}, ans=1e18;
pair<string, ll> node_info[MAX_N];
vector<pair<ll, ll>> tree[MAX_N];

pair<ll, ll> dfs_down (ll cur, ll p) {
    if (node_info[cur].s==0) {
        num_files[cur]=1;
        return {0, 1};
    }
    if (dp[cur]!=0) return {dp[cur], num_files[cur]};

    for (ll i=0; i<tree[cur].size(); i++) {
        ll nx=tree[cur][i].f, w=tree[cur][i].s;
        if (nx==p) continue;

        pair<ll, ll> ret=dfs_down(nx, cur);
        dp[cur]+=ret.f+w*num_files[nx];
        num_files[cur]+=ret.s;
    }

    return {dp[cur], num_files[cur]};
}

void solve(ll cur, ll p) {
    if (cur!=1) {
        dp[cur]=dp[p]+(3*(total_files-num_files[cur]))-((node_info[cur].f.size()+1)*num_files[cur]);
    }

    for (ll i=0; i<tree[cur].size(); i++) {
        ll nx=tree[cur][i].f;
        if (nx==p) continue;
        solve(nx, cur);
    }
}

int main()
{
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    cin >> N;
    for (ll i=1; i<=N; i++) {
        cin >> node_info[i].f >> node_info[i].s;
        if (node_info[i].s>0) for (ll j=1; j<=node_info[i].s; j++) {
            ll a; cin >> a;
            tree[i].push_back({a, 0});
            tree[a].push_back({i, 3}); // '../'
        }
        else total_files++;
    }

    for (ll i=1; i<=N; i++) {
        for (ll j=0; j<tree[i].size(); j++) {
            ll node=tree[i][j].f, weight=tree[i][j].s;
            if (weight==0) tree[i][j].s=(node_info[node].f).size()+1;
            if (node_info[node].s==0) tree[i][j].s--;
        }
    }

    dfs_down(1, 0);

    fill(&dp[2], &dp[N+1], 0);

    solve(1, 0);

    for (ll i=1; i<=N; i++) {
        if (node_info[i].s>0) ans=min(ans, dp[i]);
    }
    cout << ans;
}
