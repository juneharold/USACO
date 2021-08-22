#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N=2e5+5;
int dp[MAX_N][2]={}, w[MAX_N], N;
vector<int> graph[MAX_N]={};
set<int> s[MAX_N][2]={};

void solve (int cur, int parent) {
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==parent) continue;
        solve(nx, cur);
        if (dp[nx][0]>=dp[nx][1]) {
            dp[cur][0]+=dp[nx][0];
            s[cur][0].insert(s[nx][0].begin(), s[nx][0].end());
        }
        else {
            dp[cur][0]+=dp[nx][1];
            s[cur][0].insert(s[nx][1].begin(), s[nx][1].end());
        }
        //dp[cur][0]+=max(dp[nx][0], dp[nx][1]);
    }

    dp[cur][1]=w[cur]; s[cur][1].insert(cur);
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==parent) continue;
        dp[cur][1]+=dp[nx][0];
        s[cur][1].insert(s[nx][0].begin(), s[nx][0].end());
    }
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> w[i];
    for (int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1, 0);
    if (dp[1][0]>=dp[1][1]) {
        cout << dp[1][0] << "\n";
        for (auto e: s[1][0]) cout << e << " ";
    }
    else {
        cout << dp[1][1] << "\n";
        for (auto e: s[1][1]) cout << e << " ";
    }
    //cout << max(dp[1][0], dp[1][1]);

    /*
    for (int i=1; i<=N; i++) {
        for (int j=0; j<2; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
}
