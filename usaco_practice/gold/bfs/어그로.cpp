#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define f first
#define s second

char graph[1505][1505];
int visit[1505][1505]={}, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    queue<pair<int, int>> q;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        cin >> graph[i][j];
        if (graph[i][j]=='0') q.push({i, j});
        else visit[i][j]=1e9;
    }

    while (!q.empty()) {
        int x=q.front().f, y=q.front().s;
        q.pop();
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1 || nx>N || ny<1 || ny>M) continue;
            if (visit[nx][ny]==1e9 && graph[nx][ny]=='1') {
                visit[nx][ny]=visit[x][y]+1;
                q.push({nx, ny});
            }
        }
    }

    int ans=0, cnt=0;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        if (visit[i][j]!=1e9) {
            cnt++;
            ans=max(ans, visit[i][j]-1);
        }
    }

    cout << ans << " " << cnt;
}

/*
2 2
10
10
*/
