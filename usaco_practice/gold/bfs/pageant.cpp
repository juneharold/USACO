#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int arr[55][55]={};
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};
int visit[55][55]={};
queue <pair<int, int>> q;

void dfs(int x, int y) {
    visit[x][y]=1;
    q.push({x, y});
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<1 or nx>n or ny<1 or ny>m) continue;
        if (visit[nx][ny]==0 and arr[nx][ny]==1) dfs(nx, ny);
    }
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        char a; cin >> a;
        if (a=='X') arr[i][j]=1;
        else arr[i][j]=0;
    }

    int x1, y1;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        if (arr[i][j]==1) {
            x1=i;
            y1=j;
            break;
        }
    }
    dfs(x1, y1);

    int ans=1e9;
    while(!q.empty()) {
        int x=q.front().first, y=q.front().second;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1 or nx>n or ny<1 or ny>m) continue;
            if (visit[nx][ny]==0 and arr[nx][ny]==1) {
                q.push({nx, ny});
                visit[nx][ny]=visit[x][y]+1;
                ans=min(ans, visit[nx][ny]-2);
            }
            else {
                q.push({nx, ny});
                visit[nx][ny]=visit[x][y]+1;
            }
        }
        q.pop();
    }
    cout << ans;
}
