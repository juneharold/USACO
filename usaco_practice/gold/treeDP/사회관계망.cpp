#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, dp[1000005][2]={};
vector<int> graph[1000005];

void solve(int cur, int p) {
    dp[cur][1]=1;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        solve(nx, cur);

        dp[cur][0]+=dp[nx][1];
        dp[cur][1]+=min(dp[nx][0], dp[nx][1]);
    }
}

int main()
{
    cin >> N;
    for (int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);
    cout << min(dp[1][0], dp[1][1]);
}
