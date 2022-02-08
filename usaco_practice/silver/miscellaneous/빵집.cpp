#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second

int R, C, visit[10005][505]={}, dx[3]={-1, 0, 1}, check=0;
char graph[10005][505]={};

void dfs(int x, int y) {
    visit[x][y]=1;
    if (y==C) {
        check=1;
        return;
    }
    for (int i=0; i<3; i++) {
        int nx=x+dx[i], ny=y+1;
        if (check==1) return;
        if (nx<1 || nx>R || ny<1 || ny>C) continue;
        if (graph[nx][ny]=='.' && visit[nx][ny]==0) dfs(nx, ny);
    }
}

int main()
{
    cin >> R >> C;
    for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) cin >> graph[i][j];

    int ans=0;
    for (int i=1; i<=R; i++) {
        dfs(i, 1);
        if (check==1) {
            ans++;
            check=0;
        }
    }
    cout << ans;
}
