#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int n, m;

struct light_switch {
    int x, y, a, b;
};
light_switch light[20005];

bool cmp (light_switch p, light_switch q) {
    if (p.x==q.x) return p.y<q.y;
    return p.x<q.x;
}

int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int visit[105][105]={};
int open[105][105]={}; //불켜짐.

void dfs(int cur_x, int cur_y) {
    visit[cur_x][cur_y]=1;
    open[cur_x][cur_y]=1;
    //불 키기
    for (int i=0; i<m; i++) {
        if (light[i].x==cur_x and light[i].y==cur_y) {
            open[light[i].a][light[i].b]=1;
        }
    }
    for (int i=0; i<4; i++) {
        if (cur_x+dx[i]<=0 or cur_x+dx[i]>n or cur_y+dy[i]<=0 or cur_y+dy[i]>n) continue;
        int next_x=cur_x+dx[i], next_y=cur_y+dy[i];
        if (visit[next_x][next_y]==0 and open[next_x][next_y]==1) dfs(next_x, next_y);
    }
}

int main()
{
    //freopen("lightson.in", "r", stdin);
    //freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> light[i].x >> light[i].y >> light[i].a >> light[i].b;
    }
    sort(light, light+m, cmp);
    dfs(1, 1);
    for (int i=0; i<n*n; i++) {
        dfs(1, 1);
        fill(&visit[0][0], &visit[100][100], 0);
    }
    int ans=0;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (open[i][j]==1) ans++;
    cout << ans;
}
