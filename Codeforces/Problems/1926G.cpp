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
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<int> graph[nmax];
char a[nmax];
int dp[nmax][3]={};

void dfs(int cur, int p) {
    if (a[cur]=='P') dp[cur][0]=dp[cur][2]=1e9;
    if (a[cur]=='S') dp[cur][0]=dp[cur][1]=1e9;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dfs(nx, cur);
        if (a[cur]=='C') {
            dp[cur][0]+=min({dp[nx][0], dp[nx][1]+1, dp[nx][2]+1});
            dp[cur][1]+=min({dp[nx][0], dp[nx][1], dp[nx][2]+1});
            dp[cur][2]+=min({dp[nx][0], dp[nx][1]+1, dp[nx][2]});
        }
        if (a[cur]=='P') dp[cur][1]+=min({dp[nx][0], dp[nx][1], dp[nx][2]+1});
        if (a[cur]=='S') dp[cur][2]+=min({dp[nx][0], dp[nx][1]+1, dp[nx][2]});
    }
}

void solve() {
    int n; cin >> n;
    for (int i=2; i<=n; i++) {
        int j; cin >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    for (int i=1; i<=n; i++) cin >> a[i];

    dfs(1, 0);
    cout << min({dp[1][0], dp[1][1], dp[1][2]}) << "\n";

    for (int i=1; i<=n; i++) {
        dp[i][0]=dp[i][1]=dp[i][2]=0;
        graph[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
