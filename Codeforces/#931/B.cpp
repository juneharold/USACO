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

int dp[nmax]={}, a[5]={1, 3, 6, 10, 15};

void solve() {
    int n; cin >> n;
    int ans=0;
    if (n>2e5) {
        int q=(n-2e5)/15;
        ans+=q;
        n-=q*15;
        if (n>2e5) n-=15, ans++;
    }
    cout << ans+dp[n] << "\n";
}

int main()
{
    dp[0]=0;
    for (int i=1; i<=2e5; i++) {
        dp[i]=1e9;
        for (int j=0; j<5; j++) {
            if (i-a[j]>=0) dp[i]=min(dp[i], dp[i-a[j]]+1);
        }
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
