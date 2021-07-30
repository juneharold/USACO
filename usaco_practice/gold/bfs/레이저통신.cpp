#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int MAX=105;
int W, H;
char graph[MAX][MAX]={};
int visit[MAX][MAX][2]={};
int dx0[2]={1, -1}, dy0[2]={0, 0}, dx1[2]={0, 0}, dy1[2]={1, -1};

struct pos {
    int x, y, dir;
};

deque<pos> dq;
pair<int, int> c1={0, 0}, c2={0, 0};

int main()
{
    cin >> W >> H;
    for (int i=1; i<=H; i++) for (int j=1; j<=W; j++) {
        cin >> graph[i][j];
        if (graph[i][j]=='C' && c1.first==0) c1={i, j};
        else if (graph[i][j]=='C') c2={i, j};
    }

    dq.push_back({c1.first, c1.second, 0}); visit[c1.first][c1.second][0]=1;
    dq.push_back({c1.first, c1.second, 1}); visit[c1.first][c1.second][1]=1;

    while (!dq.empty()) {
        int x=dq.front().x, y=dq.front().y, d=dq.front().dir;
        dq.pop_front();

        if (d==0) {
            for (int i=0; i<2; i++) {
                int nx=x+dx0[i], ny=y+dy0[i];
                if (nx<1 || nx>H || ny<1 || ny>W || graph[nx][ny]=='*') continue;
                if (visit[nx][ny][0]==0 || visit[x][y][0]<visit[nx][ny][0]) {
                    visit[nx][ny][0]=visit[x][y][0];
                    dq.push_back({nx, ny, 0});
                }
            }
            for (int i=0; i<2; i++) {
                int nx=x+dx1[i], ny=y+dy1[i];
                if (nx<1 || nx>H || ny<1 || ny>W || graph[nx][ny]=='*') continue;
                if (visit[nx][ny][1]==0 || visit[x][y][0]+1<visit[nx][ny][1]) {
                    visit[nx][ny][1]=visit[x][y][0]+1;
                    dq.push_back({nx, ny, 1});
                }
            }
        }
        if (d==1) {
            for (int i=0; i<2; i++) {
                int nx=x+dx0[i], ny=y+dy0[i];
                if (nx<1 || nx>H || ny<1 || ny>W || graph[nx][ny]=='*') continue;
                if (visit[nx][ny][0]==0 || visit[x][y][1]+1<visit[nx][ny][0]) {
                    visit[nx][ny][0]=visit[x][y][1]+1;
                    dq.push_back({nx, ny, 0});
                }
            }
            for (int i=0; i<2; i++) {
                int nx=x+dx1[i], ny=y+dy1[i];
                if (nx<1 || nx>H || ny<1 || ny>W || graph[nx][ny]=='*') continue;
                if (visit[nx][ny][1]==0 || visit[x][y][1]<visit[nx][ny][1]) {
                    visit[nx][ny][1]=visit[x][y][1];
                    dq.push_back({nx, ny, 1});
                }
            }
        }
    }

    int ans=visit[c2.first][c2.second][0];
    if (ans==0 || (visit[c2.first][c2.second][1]!=0 && visit[c2.first][c2.second][1]<ans)) ans=visit[c2.first][c2.second][1];

    cout << ans-1;
}
