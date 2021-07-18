#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N=505;
int dp[MAX_N][MAX_N]={};
int graph[MAX_N][MAX_N];
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n;
int ans=0;

int dfs(int x, int y) {

    if (dp[x][y]!=0) return dp[x][y];
    dp[x][y]=1;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<1 || nx>n || ny<1 || ny>n) continue;
        if (graph[x][y]<graph[nx][ny]) dp[x][y]=max(dp[x][y], dfs(nx, ny)+1);
    }
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> graph[i][j];

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ans=max(ans, dfs(i, j));
        }
    }
    cout << ans;
}
