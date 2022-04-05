#include <iostream>
#include <algorithm>
using namespace std;

int N, M, grid[505][505]={}, dp[505][505]={};
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};

int dfs(int x, int y) {
    if (dp[x][y]!=-1) return dp[x][y];
    dp[x][y]=0;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (grid[nx][ny]==0 || grid[nx][ny]>=grid[x][y]) continue;
        dp[x][y]+=dfs(nx, ny);
    }
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin >> grid[i][j];
    fill(&dp[0][0], &dp[N+1][M+1], -1);
    dp[N][M]=1;
    cout << dfs(1, 1);
}
