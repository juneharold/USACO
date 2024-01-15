#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> graph[100005];
ll dp[100005][2]={};
const ll MOD=1e9+7;

void dfs(int cur, int p) {
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dfs(nx, cur);
        dp[cur][0]*=dp[nx][0]+dp[nx][1];
        dp[cur][0]%=MOD;
        dp[cur][1]*=dp[nx][0];
        dp[cur][1]%=MOD;
    }
}

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N-1; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    fill(&dp[0][0], &dp[N+1][2], 1);
    dfs(1, 0);
    cout << (dp[1][0]+dp[1][1])%MOD;
}