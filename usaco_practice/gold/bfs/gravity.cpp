#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int MAX_NM=505;
int visit[MAX_NM][MAX_NM][2]={}; //0 is down, 1 is up
char graph[MAX_NM][MAX_NM]={};
int dx[2]={0, 0}, dy[2]={1, -1};
int N, M;
pair<int, int> cap, doc;

struct pos {
    int x, y, gd;
};
deque<pos> dq;

int main()
{
    cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        cin >> graph[i][j];
        if (graph[i][j]=='C') cap={i, j};
        if (graph[i][j]=='D') doc={i, j};
    }

    dq.push_back({cap.first, cap.second, 0});
    visit[cap.first][cap.second][0]=1;

    while (!dq.empty()) {
        int x=dq.front().x, y=dq.front().y, grav=dq.front().gd;
        dq.pop_front();

        //edge인지 확인.
        if (grav==0 && x>=N) continue;
        else if (grav==1 && x<=1) continue;

        //gravity 방향으로 떨어지는지 확인.
        if (grav==0 && graph[x+1][y]!='#') {
            int nx=x+1, ny=y;
            if (nx<1 || nx>N || ny<1 || ny>M || graph[nx][ny]=='#') continue;
            if (visit[nx][ny][0]==0 || visit[x][y][0]<visit[nx][ny][0]) {
                visit[nx][ny][0]=visit[x][y][0];
                dq.push_back({nx, ny, 0});
            }
            continue;
        }
        else if (grav==1 && graph[x-1][y]!='#') {
            int nx=x-1, ny=y;
            if (nx<1 || nx>N || ny<1 || ny>M || graph[nx][ny]=='#') continue;
            if (visit[nx][ny][1]==0 || visit[x][y][1]<visit[nx][ny][1]) {
                visit[nx][ny][1]=visit[x][y][1];
                dq.push_back({nx, ny, 1});
            }
            continue;
        }

        //좌우로 이동.
        for (int i=0; i<2; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1 || nx>N || ny<1 || ny>M || graph[nx][ny]=='#') continue;
            if (visit[nx][ny][grav]==0 || visit[x][y][grav]<visit[nx][ny][grav]) {
                visit[nx][ny][grav]=visit[x][y][grav];
                dq.push_back({nx, ny, grav});
            }
        }
        // gravity 방향 전환.
        if (grav==0 && graph[x-1][y]!='#')  {
            int nx=x-1, ny=y;
            if (visit[nx][ny][1]==0 || visit[x][y][0]+1<visit[nx][ny][1]) {
                visit[nx][ny][1]=visit[x][y][0]+1;
                dq.push_back({nx, ny, 1});
            }
        }
        else if (grav==1 && graph[x+1][y]!='#')  {
            int nx=x+1, ny=y;
            if (visit[nx][ny][0]==0 || visit[x][y][1]+1<visit[nx][ny][0]) {
                visit[nx][ny][0]=visit[x][y][1]+1;
                dq.push_back({nx, ny, 0});
            }
        }
    }

    if (visit[doc.first][doc.second][0]==0 && visit[doc.first][doc.second][1]==0) {
        cout << -1;
        return 0;
    }
    else {
        int ans=visit[doc.first][doc.second][0];
        if (ans==0 || (visit[doc.first][doc.second][1]!=0 && visit[doc.first][doc.second][1]<ans)) ans=visit[doc.first][doc.second][1];
        cout << ans-1;
        return 0;
    }
}
