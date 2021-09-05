#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int MAX_N=3e5+5;
ll N, dp[MAX_N]={}, ans[MAX_N]={};
vector<int> graph[MAX_N]={};

ll solve (int cur, int p) {
    if (dp[cur]!=-1) return dp[cur];
    dp[cur]=1;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==p) continue;
        dp[cur]+=solve(nx, cur);
    }
    ans[cur]+=N*(N-1)/2-(N-dp[cur])*(N-dp[cur]-1)/2;
    return dp[cur];
}

int main()
{
    cin >> N;
    for (int i=1; i<=N-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    fill(&dp[0], &dp[MAX_N], -1);

    solve(1, 0);

    ll answer=0;
    for (int i=2; i<=N; i++) {
        answer+=ans[i];
    }
    cout << answer;
}
