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

int n, c, k, dp[1<<18]; 
char s[(1<<18)+10];

int DP(int i) {
    if (dp[i]!=-1) return dp[i];
    dp[i]=1;
    for (int j=0; j<c; j++) {
        if (i&(1<<j)) continue;
        if (DP(i+(1<<j))==0) {
            dp[i]=0;
            break;
        }
    }
    return dp[i];
}

int cntbits(int x) {
    int ret=0;
    while (x) {
        if (x%2) ret++;
        x/=2;
    }
    return ret;
}

void solve() {
    cin >> n >> c >> k;
    for (int i=1; i<=n; i++) cin >> s[i];

    vector<vector<int>> pfs(n+1, vector<int>(c+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=0; j<c; j++) {
            if (s[i]-'A'==j) pfs[i][j]=pfs[i-1][j]+1;
            else pfs[i][j]=pfs[i-1][j];
        }
    }

    fill(&dp[0], &dp[1<<c], -1);

    for (int i=k; i<=n; i++) {
        int idx=0;
        for (int j=0; j<c; j++) {
            //cout << j << endl;
            if (pfs[i][j]!=pfs[i-k][j]) idx+=(1<<j);
        }
        //cout << (1<<c)-1-idx << endl;
        dp[(1<<c)-1-idx]=0;
        //cout << idx << endl;
    }

    //cout << "here\n";

    int ans=c;
    for (int i=1; i<(1<<c); i++) {
        //cout << i << ' ' << DP(i) << endl;
        if (DP(i) && (i&(1<<(s[n]-'A')))) ans=min(ans, cntbits(i));
    }
    cout << ans << "\n";
}
/*
dp[i]=0 
if j <= i then dp[j]=0
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
