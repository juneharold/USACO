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
const ll nmax=15, sqrmax=635, MOD=9901, INF=1e18;

int n, m, dp[nmax*nmax][(1<<nmax)]={};

int DP(int pos, int state) {
    if (pos==n*m+1) return state==0;
    if (dp[pos][state]!=-1) return dp[pos][state];
    dp[pos][state]=0;
    if (state&1) {
        dp[pos][state]+=DP(pos+1, state>>1);
    }
    else {
        if ((state&2)==0 && pos%m!=0) {
            dp[pos][state]+=DP(pos+1, (state>>1)+1);
        }
        dp[pos][state]+=DP(pos+1, (state>>1)+(1<<(m-1)));
    }
    dp[pos][state]%=MOD;
    return dp[pos][state];
}

void solve() {
    cin >> n >> m;
    fill(&dp[0][0], &dp[n*m+1][(1<<m)], -1);
    cout << DP(1, 0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
