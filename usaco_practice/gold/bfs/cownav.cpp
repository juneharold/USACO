#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long

ll N, visit[22][22][6][22][22][6]={};
char graph[21][21];
struct twocows {
    ll a1, a2, ad, b1, b2, bd;
};
queue<twocows> q;

int main()
{
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
    cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> graph[i][j];

    fill(&visit[0][0][0][0][0][0], &visit[21][21][5][21][21][5], 1e18);

    q.push({N, 1, 1, N, 1, 2});
    visit[N][1][1][N][1][2]=0;

    while (!q.empty()) {
        int x1=q.front().a1, x2=q.front().a2, xd=q.front().ad;
        int y1=q.front().b1, y2=q.front().b2, yd=q.front().bd;
        q.pop();

        int nx1=x1, nx2=x2, nxd=xd, ny1=y1, ny2=y2, nyd=yd;
        //moving forward
        if (xd==1) nx1--;
        if (xd==2) nx2++;
        if (xd==3) nx1++;
        if (xd==4) nx2--;

        if (yd==1) ny1--;
        if (yd==2) ny2++;
        if (yd==3) ny1++;
        if (yd==4) ny2--;

        if (graph[nx1][nx2]=='H' || nx1<1 || nx1>N || nx2<1 || nx2>N) {
            nx1=x1; nx2=x2;
        }
        if (graph[ny1][ny2]=='H' || ny1<1 || ny1>N || ny2<1 || ny2>N) {
            ny1=y1; ny2=y2;
        }

        if (x1==1 && x2==N) {
            nx1=1; nx2=N;
        }
        if (y1==1 && y2==N) {
            ny1=1; ny2=N;
        }

        if (visit[nx1][nx2][nxd][ny1][ny2][nyd]==1e18) {
            q.push({nx1, nx2, nxd, ny1, ny2, nyd});
            visit[nx1][nx2][nxd][ny1][ny2][nyd]=visit[x1][x2][xd][y1][y2][yd]+1;
        }

        //turn right
        nx1=x1; nx2=x2; nxd=xd; ny1=y1; ny2=y2; nyd=yd;
        nxd++; nyd++;
        if (nxd>4) nxd-=4;
        if (nyd>4) nyd-=4;

        if (visit[nx1][nx2][nxd][ny1][ny2][nyd]==1e18) {
            q.push({nx1, nx2, nxd, ny1, ny2, nyd});
            visit[nx1][nx2][nxd][ny1][ny2][nyd]=visit[x1][x2][xd][y1][y2][yd]+1;
        }

        //turn left
        nx1=x1; nx2=x2; nxd=xd; ny1=y1; ny2=y2; nyd=yd;
        nxd--; nyd--;
        if (nxd<1) nxd+=4;
        if (nyd<1) nyd+=4;

        if (visit[nx1][nx2][nxd][ny1][ny2][nyd]==1e18) {
            q.push({nx1, nx2, nxd, ny1, ny2, nyd});
            visit[nx1][nx2][nxd][ny1][ny2][nyd]=visit[x1][x2][xd][y1][y2][yd]+1;
        }

    }

    ll ans=1e18;
    for (int i=1; i<=4; i++) for (int j=1; j<=4; j++) {
        ans=min(ans, visit[1][N][i][1][N][j]);
    }

    cout << ans;
}

//010-4856-6184
