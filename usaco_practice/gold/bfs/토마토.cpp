#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int arr[1005][1005]={};
int visit[1005][1005]={};
queue <pair<int, int>> q;
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

int main() {
    cin >> m >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        cin >> arr[i][j]; arr[i][j]++;
        if (arr[i][j]==2) {
            q.push({i, j});
            visit[i][j]=1;
        }
    }

    while (!q.empty()) {
        int x=q.front().first, y=q.front().second;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (arr[nx][ny]==0) continue;
            if (visit[nx][ny]==0 and arr[nx][ny]==1) {
                q.push({nx, ny});
                arr[nx][ny]=2;
                visit[nx][ny]=visit[x][y]+1;
            }
        }
        q.pop();
    }

    bool ripe=true;
    int ans=0;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        if (arr[i][j]==1) ripe=false;
        ans=max(ans, visit[i][j]-1);
    }

    if (ripe==false) cout << -1;
    else cout << ans;
    return 0;
}
