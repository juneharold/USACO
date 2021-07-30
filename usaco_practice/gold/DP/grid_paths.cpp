#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N=1005, mod=1e9+7;
long long dp[MAX_N][MAX_N]={};
char graph[MAX_N][MAX_N]={};
queue<pair<int, int>> q;
int dx[2]={1, 0}, dy[2]={0, 1};
int n;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> graph[i][j];

    if (graph[1][1]!='*') {
        q.push({1, 1});
        dp[1][1]=1;
    }

    while (!q.empty()) {
        int x=q.front().first, y=q.front().second;
        q.pop();
        for (int i=0; i<2; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1 || nx>n || ny<1 || ny>n || graph[nx][ny]=='*') continue;

            if (dp[nx][ny]==0) {
                dp[nx][ny]=dp[nx-1][ny]+dp[nx][ny-1];
                dp[nx][ny]%=mod;
                q.push({nx, ny});
            }
        }
    }
    cout << dp[n][n];
}
