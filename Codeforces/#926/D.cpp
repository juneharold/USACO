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
const ll nmax=3e5+5, sqrmax=635, MOD=998244353, INF=1e18;

vector<int> graph[nmax];
ll dp[nmax]={};

void dfs(int cur, int p) {
    dp[cur]=1;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dfs(nx, cur);
        dp[cur]=dp[cur]*(dp[nx]+1)%MOD;
    }
}

void solve() {
    int n; cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    ll ans=1;
    for (int i=1; i<=n; i++) ans=(ans+dp[i])%MOD;
    cout << ans << "\n";
    fill(&dp[0], &dp[n+1], 0);
    for (int i=1; i<=n; i++) graph[i].clear();
}

/*
let the tree be rooted in node 1
condition for a good set is 
- no three nodes that are child-grandparent can coexist in a set 
dp[i]=number of non-empty good sets in subtree i such that no node is ancestor of another node 
dp[i]=(dp[u]+1)*(dp[v]+1)*...

answer is dp[i] summed over all i +1 (for empty subset)
This is because if node i is chosen, then there can be dp[i] number of sets that include i
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
