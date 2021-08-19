#include <iostream>
#include <vector>
using namespace std;

const int MAX_N=2e5+5;
int dp[MAX_N][2]={}, N;
vector<int> graph[MAX_N]={};

void solve (int cur, int parent) {
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==parent) continue;
        solve(nx, cur);
        dp[cur][0]+=max(dp[nx][0], dp[nx][1]);
    }

    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==parent) continue;
        dp[cur][1]=max(dp[cur][1], dp[cur][0]-max(dp[nx][0], dp[nx][1])+dp[nx][0]+1);
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
    cout << max(dp[1][0], dp[1][1]);
}
