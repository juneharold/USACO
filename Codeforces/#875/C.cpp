#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long
#define MOD 1000000007

vector<pair<int, int>> graph[200005]={};
int dp[200005]={};

void dfs(int cur, int p, int edge_num) {
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].f; 
        if (nx==p) continue;
        if (graph[cur][i].s>edge_num) {
            dp[nx]=dp[cur];
            dfs(nx, cur, graph[cur][i].s);
        }
        else {
            dp[nx]=dp[cur]+1;
            dfs(nx, cur, graph[cur][i].s);
        }
    }
}

int main()
{
    int T; cin >> T;
    while (T--) {
        int n;  cin >> n;
        for (int i=1; i<=n-1; i++) {
            int u, v; cin >> u >> v;
            graph[u].push_back(make_pair(v, i));
            graph[v].push_back(make_pair(u, i));
        }

        dp[1]=1;
        dfs(1, 0, 0);
        int ans=0;
        for (int i=1; i<=n; i++) {
            ans=max(ans, dp[i]);
        }
        cout << ans << "\n";

        for (int i=1; i<=n; i++) {
            graph[i].clear();
            dp[i]=0;
        }
    }
}
