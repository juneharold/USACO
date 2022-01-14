#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define f first
#define s second

const int MAX=105;
int N, M, visit[MAX][MAX], dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
char graph[MAX][MAX];
pair<int, int> start;
queue<pair<int, int>> q;

bool cameras_exist (int x, int y) {
    if (graph[x][y]=='L' || graph[x][y]=='R' || graph[x][y]=='D' || graph[x][y]=='U') return false;
    int cx=x, cy=y;

    bool ret=false;
    while (cx<=N) {
        if (graph[cx][cy]=='W') break;
        if (graph[cx][cy]=='C') ret=true;
        cx+=1;
    }

    cx=x; cy=y;
    while (cx>=1) {
        if (graph[cx][cy]=='W') break;
        if (graph[cx][cy]=='C') ret=true;
        cx-=1;
    }

    cx=x; cy=y;
    while (cy<=M) {
        if (graph[cx][cy]=='W') break;
        if (graph[cx][cy]=='C') ret=true;
        cy+=1;
    }

    cx=x; cy=y;
    while (cy>=1) {
        if (graph[cx][cy]=='W') break;
        if (graph[cx][cy]=='C') ret=true;
        cy-=1;
    }

    return ret;
}

int main()
{
    cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        cin >> graph[i][j];
        if (graph[i][j]=='S') start=make_pair(i, j);
    }

    fill(&visit[0][0], &visit[MAX-1][MAX], 1e9);

    if (!cameras_exist(start.f, start.s)) {
        q.push(start); visit[start.f][start.s]=0;
    }
    while (!q.empty()) {
        int x=q.front().f, y=q.front().s;
        q.pop();

        if (graph[x][y]=='S' || graph[x][y]=='.') {
            for (int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if (graph[nx][ny]=='W') continue;
                if (!cameras_exist(nx, ny) && visit[x][y]+1<visit[nx][ny]) {
                    visit[nx][ny]=visit[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
        if (graph[x][y]=='R') {
            int nx=x, ny=y+1;
            if (graph[nx][ny]=='W') continue;
            if (!cameras_exist(nx, ny) && visit[x][y]<visit[nx][ny]) {
                visit[nx][ny]=visit[x][y];
                q.push({nx, ny});
            }
        }
        if (graph[x][y]=='L') {
            int nx=x, ny=y-1;
            if (graph[nx][ny]=='W') continue;
            if (!cameras_exist(nx, ny) && visit[x][y]<visit[nx][ny]) {
                visit[nx][ny]=visit[x][y];
                q.push({nx, ny});
            }
        }
        if (graph[x][y]=='U') {
            int nx=x-1, ny=y;
            if (graph[nx][ny]=='W') continue;
            if (!cameras_exist(nx, ny) && visit[x][y]<visit[nx][ny]) {
                visit[nx][ny]=visit[x][y];
                q.push({nx, ny});
            }
        }
        if (graph[x][y]=='D') {
            int nx=x+1, ny=y;
            if (graph[nx][ny]=='W') continue;
            if (!cameras_exist(nx, ny) && visit[x][y]<visit[nx][ny]) {
                visit[nx][ny]=visit[x][y];
                q.push({nx, ny});
            }
        }
    }


    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        if (graph[i][j]=='.') {
            if (visit[i][j]!=1e9) cout << visit[i][j] << "\n";
            else cout << -1 << "\n";
        }
    }
}
/*
5 7
WWWWWWW
WD.L.RW
W.WCU.W
WWWCS.W
WWWWWWW
*/
