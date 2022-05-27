#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define f first
#define s second

char graph[1505][1505];
int R, C, ice[1505][1505]={}, visit[1505][1505]={};
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    queue<pair<int, int>> q;
    pair<int, int> S={1e9, 1e9}, D={1e9, 1e9};
    for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) {
        cin >> graph[i][j];
        if (graph[i][j]!='X') q.push({i, j});
        else ice[i][j]=1e9;
        if (graph[i][j]=='L') {
            if (S.f==1e9) S={i, j};
            else D={i, j};
        }
    }

    while (!q.empty()) {
        int x=q.front().f, y=q.front().s;
        q.pop();
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1 || nx>R || ny<1 || ny>C) continue;
            if (ice[nx][ny]==1e9) {
                ice[nx][ny]=ice[x][y]+1;
                q.push({nx, ny});
            }
        }
    }

    fill(&visit[0][0], &visit[R+1][C+1], 1e9);
    priority_queue<pair<int, pair<int, int>>> pq;
    visit[S.f][S.s]=0;
    pq.push({0, S});
    while (!pq.empty()) {
        int w=-pq.top().f, x=pq.top().s.f, y=pq.top().s.s;
        pq.pop();
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1 || nx>R || ny<1 || ny>C) continue;
            int nw=max(w, ice[nx][ny]);
            if (nw<visit[nx][ny]) {
                pq.push({-nw, {nx, ny}});
                visit[nx][ny]=nw;
            }
        }
    }

    cout << visit[D.f][D.s];
}

/*
4 4
LXXX
XXXX
XXXX
XXXL
*/
