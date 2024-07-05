#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=998244353, INF=1e18;

ll dp[nmax][11]={}, sum[nmax][11]={};

void solve() {
    int n, m; cin >> n >> m;
    dp[0][0]=1;
    sum[0][0]=1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=m; j++) {
            dp[i+1][min(j+1, m)]+=sum[i][j];
            if (2<i+1 && i+1<n) dp[i+1][min(j+1, m)]-=dp[i-1][j];
            dp[i+1][min(j+1, m)]=(dp[i+1][min(j+1, m)]+MOD)%MOD;
            sum[i+1][j]=(sum[i][j]+dp[i+1][j])%MOD;
        }
    }
    cout << dp[n][m] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
