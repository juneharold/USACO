#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100005];
int dp[2][100005]={};

void dfs(int cur, int p, int idx) {
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dp[idx][nx]=dp[idx][cur]+1;
        dfs(nx, cur, idx);
    }
}

int main()
{
    int n; cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0, 0);
    int mx=*max_element(&dp[0][1], &dp[0][n+1]), a=-1, b=-1;
    for (int i=1; i<=n; i++) if (dp[0][i]==mx) a=i;
    fill(&dp[0][0], &dp[1][n+1], 0);
    dfs(a, 0, 0);
    mx=*max_element(&dp[0][1], &dp[0][n+1]);
    for (int i=1; i<=n; i++) if (dp[0][i]==mx) b=i;
    dfs(b, 0, 1);

    vector<int> cnt(n+1, 0);
    for (int i=1; i<=n; i++) cnt[max(dp[0][i], dp[1][i])]++;
    
    vector<int> ans(n+1, 0);
    ans[n]=n;
    for (int i=n-1; i>=1; i--) {
        ans[i]=ans[i+1]-cnt[i];
        if (ans[i+1]==n && cnt[i]!=0) ans[i]++;
    }
    for (int i=1; i<=n; i++) cout << ans[i] << ' ';
}

/*
5
1 2
2 3
3 4
3 5

*/