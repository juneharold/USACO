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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e3+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll dp[nmax][20005]={};

void solve() {
    int N; cin >> N;
    vector<int> a(N+1);
    for (int i=1; i<=N; i++) cin >> a[i];
    //dp[0][0]=1;
    for (int i=1; i<=N; i++) {
        for (int j=-10000; j<=10000; j++) {
            int jj=j+10000;
            if (jj-a[i]>=0) dp[i][jj]+=dp[i-1][jj-a[i]];
            if (jj+a[i]<=20000) dp[i][jj]+=dp[i-1][jj+a[i]];
            if (j-a[i]==0 || j+a[i]==0) dp[i][jj]++;
            dp[i][jj]%=MOD;
        }
    }
    ll ans=0;
    for (int i=1; i<=N; i++) ans=(ans+dp[i][10000])%MOD;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
