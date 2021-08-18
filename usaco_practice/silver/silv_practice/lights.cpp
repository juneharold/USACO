#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int n, m;
struct light_switch {
    int x, y, a, b;
};
light_switch light[20005]={};
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1}, visit[105][105]={}, open[105][105]={}; //불켜짐.
queue<pair<int, int>> q;

int main()
{
    //freopen("lightson.in", "r", stdin);
    //freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for (int i=0; i<m; i++) cin >> light[i].x >> light[i].y >> light[i].a >> light[i].b;

    q.push({1, 1});
    visit[1][1]=1; open[1][1]=1;

    while(!q.empty()) {
        int cx=q.front().first, cy=q.front().second;
        q.pop();

        for (int i=0; i<m; i++) {
            if (light[i].x==cx && light[i].y==cy && open[light[i].a][light[i].b]==0) {
                open[light[i].a][light[i].b]=1;
            }
        }

        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (nx<=0 || nx>n || ny<=0 || ny>n) continue;
            if (visit[nx][ny]==0 && open[nx][ny]==1) {
                q.push({nx, ny});
                visit[nx][ny]=1;
            }
        }

        for (int i=0; i<m; i++) {
            if (light[i].x==cx && light[i].y==cy && open[light[i].a][light[i].b]==1) {
                for (int j=0; j<4; j++) {
                    int nx=light[i].a+dx[j], ny=light[i].b+dy[j];
                    if (nx<=0 || nx>n || ny<=0 || ny>n) continue;
                    if (visit[nx][ny]==1 && visit[light[i].a][light[i].b]==0) {
                        q.push({light[i].a, light[i].b});
                        visit[light[i].a][light[i].b]=1;
                    }
                }
            }
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (open[i][j]==1) ans++;
        }
    }
    cout << ans;
}
