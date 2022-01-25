#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define ll long long

const int MAX=1005;
int H, W, grid[MAX][MAX]={}, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1}, visit[MAX][MAX]={}; //물이 모일 수 있는 곳 저장

int dfs(int x, int y) {
    if (visit[x][y]!=0) return visit[x][y];

    visit[x][y]=grid[x][y];
    bool diff=false;
    int prev=-1;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (grid[nx][ny]<grid[x][y] && 1<=nx && nx<=H && 1<=ny && ny<=W) {
            if (prev!=-1 && prev!=dfs(nx, ny)) diff=true;
            if (dfs(nx, ny)==1e9) diff=true;
            prev=dfs(nx, ny);
            if (visit[x][y]!=1e9) visit[x][y]=min(dfs(nx, ny), visit[nx][ny]);
            if (visit[x][y]==0) visit[x][y]=dfs(nx, ny);
        }
    }
    if (diff) visit[x][y]=1e9;
    return visit[x][y];
}

int main()
{
    cin >> H >> W;
    fill(&grid[0][0], &grid[MAX-1][MAX-1], 1e9);
    for (int i=1; i<=H; i++) for (int j=1; j<=W; j++) cin >> grid[i][j];

    int ans=0;
    for (int i=1; i<=H; i++) for (int j=1; j<=W; j++) {
        if (visit[i][j]==0) dfs(i, j);
        if (visit[i][j]==1e9) ans++;
    }

    cout << ans;
}
