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
const ll nmax=1e4+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int N, W, a[nmax][3]={}, dp[nmax][3]={}, type;
vector<int> v;

void fill_dp() {
    for (int i=2; i<=N; i++) {
        dp[i][2]=min(dp[i][2], dp[i-1][0]+1);
        if (((type!=2 && type!=0) || i>2) && a[i-1][2]+a[i][2]<=W) dp[i][2]=min(dp[i][2], dp[i-1][1]+1);

        dp[i][1]=min(dp[i][1], dp[i-1][0]+1);
        if (((type!=1 && type!=0)|| i>2) && a[i-1][1]+a[i][1]<=W) dp[i][1]=min(dp[i][1], dp[i-1][2]+1);

        dp[i][0]=min({dp[i][0], dp[i][1]+1, dp[i][2]+1});
        if (a[i][1]+a[i][2]<=W) dp[i][0]=min(dp[i][0], dp[i-1][0]+1);
        if ((type==3 || i>2) && a[i][1]+a[i-1][1]<=W && a[i-1][2]+a[i][2]<=W) dp[i][0]=min(dp[i][0], dp[i-2][0]+2);
    }
}

void solve() {
    cin >> N >> W;
    for (int i=1; i<=N; i++) cin >> a[i][1];
    for (int i=1; i<=N; i++) cin >> a[i][2];

    if (N==1) {
        if (a[1][1]+a[1][2]<=W) cout << "1\n";
        else cout << "2\n";
        return;
    }

    int ans=1e9;
    fill(&dp[1][0], &dp[N+1][2], 1e9);
    dp[1][1]=1, dp[1][2]=1, dp[1][0]=2;
    if (a[1][1]+a[1][2]<=W) dp[1][0]=1;
    type=3;
    fill_dp();
    ans=min(ans, dp[N][0]);
    
    fill(&dp[1][0], &dp[N+1][2], 1e9);
    dp[1][1]=1, dp[1][2]=1, dp[1][0]=2;
    type=1;
    fill_dp();
    ans=min(ans, dp[N][0]);
    if (a[1][1]+a[N][1]<=W) ans=min(ans, dp[N][2]);

    fill(&dp[1][0], &dp[N+1][2], 1e9);
    dp[1][1]=1, dp[1][2]=1, dp[1][0]=2;
    type=2;
    fill_dp();
    ans=min(ans, dp[N][0]);
    if (a[1][2]+a[N][2]<=W) ans=min(ans, dp[N][1]);

    fill(&dp[1][0], &dp[N+1][2], 1e9);
    dp[1][1]=1, dp[1][2]=1, dp[1][0]=2;
    type=0;
    fill_dp();
    ans=min(ans, dp[N][0]);
    if (a[1][1]+a[N][1]<=W && a[1][2]+a[N][2]<=W) ans=min(ans, dp[N-1][0]);
    
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
