#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define f first
#define s second

const int MAX_N=105, MAX_T=1e6+5;
int n, t, graph[MAX_N][MAX_N]={}, visit[MAX_N][MAX_N][3]={};
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
priority_queue<pair<pair<int, int>, pair<int, int>>> pq; // ff: dist, fs: cnt, sf:x_loc, ss:y_loc

int main()
{
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);
    cin >> n >> t;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> graph[i][j];

    fill(&visit[0][0][0], &visit[MAX_N-1][MAX_N-1][3], 1e9);

    pq.push({{0, 0}, {1, 1}});
    visit[1][1][0]=0;
    while (!pq.empty()) {
        int dist=-pq.top().f.f, cnt=pq.top().f.s, x=pq.top().s.f, y=pq.top().s.s;
        pq.pop();

        if (dist>visit[x][y][cnt]) continue;

        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1 || nx>n || ny<1 || ny>n) continue;

            if (cnt==2) {
                if (dist+t+graph[nx][ny]<visit[nx][ny][0]) {
                    visit[nx][ny][0]=dist+t+graph[nx][ny];
                    pq.push({{-(dist+t+graph[nx][ny]), 0}, {nx, ny}});
                }
            }
            else if (cnt==1){
                if (dist+t<visit[nx][ny][2]) {
                    visit[nx][ny][2]=dist+t;
                    pq.push({{-(dist+t), 2}, {nx, ny}});
                }
            }
            else if (cnt==0){
                if (dist+t<visit[nx][ny][1]) {
                    visit[nx][ny][1]=dist+t;
                    pq.push({{-(dist+t), 1}, {nx, ny}});
                }
            }
        }
    }

    int ans=1e9;
    for (int i=0; i<3; i++) ans=min(ans, visit[n][n][i]);
    cout << ans;
}
