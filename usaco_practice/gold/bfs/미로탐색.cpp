#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int maze[105][105]={};
int visit[105][105]={};
queue <pair<int, int>> q;
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

int main()
{
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char a; cin >> a;
            maze[i][j]=a-48;
        }
    }

    q.push({1, 1});
    visit[q.front().first][q.front().second]=1;
    while (!q.empty()) {
        int x=q.front().first, y=q.front().second;
        for (int i=0; i<4; i++) {
            if (maze[x+dx[i]][y+dy[i]]==1 and visit[x+dx[i]][y+dy[i]]==0) {
                q.push({x+dx[i], y+dy[i]});
                visit[x+dx[i]][y+dy[i]]=visit[x][y]+1;
            }
        }
        q.pop();
    }
    cout << visit[n][m];
}
