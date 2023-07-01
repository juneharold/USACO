/*
dp[i]=maximum path length from an arbitary node to get to node i. 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[100005];
int dp[100005];

int dfs(int cur) {
    if (dp[cur]!=-1) return dp[cur];
    dp[cur]=0;
    for (int nx: graph[cur]) {
        dp[cur]=max(dp[cur], dfs(nx)+1);
    }
    return dp[cur];
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        graph[v].push_back(u);
    }
    fill(&dp[1], &dp[n+1], -1);

    int ans=-1e9;
    for (int i=1; i<=n; i++) {
        ans=max(ans, dfs(i));
    }
    cout << ans;
}