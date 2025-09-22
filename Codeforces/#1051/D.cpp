#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=3e2+5, sqrmax=635, MOD=1e9+7, INF=9e18;

ll dp[nmax][nmax][nmax]={};

void solve() {
    int n; cin >> n;
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) cin >> v[i];

    dp[0][0][0]=1;
    for (int i=0; i<n; i++) {
        for (int a=0; a<=n; a++) {
            for (int b=0; b<=a; b++) {
                // don't pick v[i+1]
                dp[i+1][a][b]+=dp[i][a][b];
                dp[i+1][a][b]%=MOD;

                // pick v[i+1]
                if (v[i+1]>=a) {
                    dp[i+1][v[i+1]][b]+=dp[i][a][b];
                    dp[i+1][v[i+1]][b]%=MOD;
                }
                else if (v[i+1]>=b) {
                    dp[i+1][a][v[i+1]]+=dp[i][a][b];
                    dp[i+1][a][v[i+1]]%=MOD;
                }
            }
        }
    }

    ll ans=0;
    for (int a=0; a<=n; a++) {
        for (int b=0; b<=a; b++) {
            //cout << "a b: " << a << ' ' << b << ' ' << dp[n][a][b] << endl;
            ans+=dp[n][a][b];
            ans%=MOD;
        }
    }
    cout << ans << "\n";

    fill(&dp[0][0][0], &dp[n+1][n+1][n+1], 0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
