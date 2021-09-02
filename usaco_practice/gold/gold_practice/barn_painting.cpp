#include <iostream>
#include <vector>
using namespace std;
#define ll long long

const ll MAX_N=1e5+5, MOD=1e9+7;
ll N, K, dp[MAX_N][4];
vector <ll> graph[MAX_N];

ll solve(ll cur, ll p, ll color) {
    if (dp[cur][color]!=-1) return dp[cur][color];

    dp[cur][color]=1;
    for (ll i=0; i<graph[cur].size(); i++) {
        ll nx=graph[cur][i];
        if (nx==p) continue;

        ll temp=0;
        for (ll j=1; j<=3; j++) {
            if (j==color) continue;
            temp+=solve(nx, cur, j);
        }
        dp[cur][color]*=temp;
        dp[cur][color]%=MOD;
    }
    return dp[cur][color];
}


int main()
{
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    cin >> N >> K;
    for (ll i=1; i<=N-1; i++) {
        ll a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    fill(&dp[0][0], &dp[MAX_N-1][4], -1);
    for (ll i=0; i<K; i++) {
        ll b, c; cin >> b >> c;
        for (ll j=1; j<=3; j++) {
            if (j==c) continue;
            dp[b][j]=0;
        }
    }

    cout << (solve(1, 0, 1)+solve(1, 0, 2)+solve(1, 0, 3))%MOD;
}
