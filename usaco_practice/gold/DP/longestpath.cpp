#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, dp[100005]={};
vector<int> graph[100005];

int solve(int cur) {
    if (dp[cur]!=-1) return dp[cur];
    dp[cur]=0;
    for (int nx: graph[cur]) {
        int nxt=solve(nx);
        if (nxt>=dp[cur]) {
            dp[cur]=nxt+1;
        }
    }
    return dp[cur];
}

int main()
{
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        graph[b].push_back(a);
    }

    fill(dp, dp+N+3, -1);
    int ans=0;
    for (int i=1; i<=N; i++) {
        if (dp[i]==-1) ans=max(ans, solve(i));
    }
    cout << ans;
}
