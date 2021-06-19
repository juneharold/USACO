#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int r, c;
char map[55][55]={};
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

queue <pair<int, int>> qw;
int vw[55][55]={}; //visit water

queue <pair<int, int>> qs;
int vs[55][55]={}; //visit 고슴도치


int main()
{
    cin >> r >> c;
    for (int i=1; i<=r; i++) for (int j=1; j<=c; j++) {
        cin >> map[i][j];
        if (map[i][j]=='*') {
            qw.push({i, j});
            vw[i][j]=1;
        }
        if (map[i][j]=='S') {
            qs.push({i, j});
            vs[i][j]=1;
        }
    }

    while (!qw.empty()) {
        int x=qw.front().first, y=qs.front().second;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (map[nx][ny]==NULL) continue;

            if (vw[nx][ny]==0 && map[nx][ny]=='.') {
                qw.push({nx, ny});
                vw[nx][ny]=vw[x][y]+1;
            }
        }
        qw.pop();
    }

    int ans=1e9;
    while (!qs.empty()) {
        int x=qs.front().first, y=qs.front().second;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (map[nx][ny]==NULL) continue;

            if (vs[nx][ny]==0 && map[nx][ny]!='X' && (vs[x][y]+1<vw[nx][ny] || vw[nx][ny]==0)) {
                qs.push({nx, ny});
                vs[nx][ny]=vs[x][y]+1;
                if (map[nx][ny]=='D') ans=min(ans, vs[nx][ny]-1);
            }
        }
        qs.pop();
    }
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            cout << vw[i][j] << " ";
        }
        cout << "\n";
    }
    if (ans==1e9) cout << "KAKTUS";
    else cout << ans;
}
