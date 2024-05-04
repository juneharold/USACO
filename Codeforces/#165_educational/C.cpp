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
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(k+1, INF));
    dp[0][0]=0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            dp[i][j]=min(dp[i][j], dp[i-1][j]+a[i]);
            ll mn=a[i];
            for (ll x=1; x<=k+1; x++) {
                if (i-x<1) break;
                mn=min(mn, a[i-x]);
                if (j-x>=0) dp[i][j]=min(dp[i][j], dp[i-x-1][j-x]+mn*(x+1));
                /*if (i==n && j==k) {
                    cout << i-x-1 << ' ' << j-x << ' ' << mn << ' ' << x << endl;
                }*/
            }
        }
    }
    /*for (int i=1; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/

    ll ans=INF;
    for (int j=0; j<=k; j++) ans=min(ans, dp[n][j]);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
