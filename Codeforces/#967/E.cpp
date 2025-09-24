#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=505, sqrmax=635, MOD=1e9+7, INF=1e18;

int n, k, p;
ll dp[nmax][nmax][2]={};

ll fastpow (ll x, ll y) {
    ll ret=1;
    while (y) {
        if (y%2) {
            ret*=x;
            ret%=p;
        }
        x*=x;
        x%=p;
        y/=2;
    }
    return ret;
}

ll DP(int i, int j, int type) {
    if (dp[i][j][type]!=-1) return dp[i][j][type];
    if (i==n) return 1;
    dp[i][j][type]=0;
    if (type==0) {
        for (int x=0; x<=j; x++) {
            dp[i][j][0]+=DP(i+1, x, 0)*DP(i+1, j-x, 0);//dp[i+1][x][0]*dp[i+1][j-x][0];
            dp[i][j][0]%=p;
        }
    }
    else {
        for (int x=0; x<=j; x++) {
            if (j-x>x) {
                dp[i][j][1]+=DP(i+1, x, 0)*DP(i+1, j-x, 1);//dp[i+1][x][0]*dp[i+1][j-x][1];
                dp[i][j][1]%=p;
            }
            if (j-x<x) {
                dp[i][j][1]+=DP(i+1, x, 1)*DP(i+1, j-x, 0);//dp[i+1][x][1]*dp[i+1][j-x][0];
                dp[i][j][1]%=p;
            }
        }
    }
    dp[i][j][type]*=fastpow(2, i-1);
    dp[i][j][type]%=p;
    return dp[i][j][type];
}

void solve() {
    cin >> n >> k >> p;
    fill(&dp[0][0][0], &dp[n+1][k+1][1], -1);
    cout << DP(1, k, 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
