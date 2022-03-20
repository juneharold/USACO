#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

char grid[11][100005]={};
int N, visit[11][100005]={}, dx[3]={1, 0, -1};
pair<int, int> from[11][100005]={};
vector<pair<int, int>> path, ans;

void dfs(int x, int y) {
    visit[x][y]=1;
    for (int i=0; i<3; i++) {
        int nx=x+dx[i], ny=y+1;
        if (nx<1 || nx>10 || ny>N || grid[nx][ny]=='X') continue;
        if (dx[i]==0 && !(x==10 || x==1)) continue;

        if (visit[nx][ny]==0) {
            from[nx][ny]={x, y};
            dfs(nx, ny);
        }
    }
}

int main()
{
    cin >> N;
    for (int i=1; i<=10; i++) for (int j=1; j<=N; j++) cin >> grid[i][j];

    dfs(10, 1);

    for (int i=1; i<=10; i++) if (visit[i][N]==1) {
        pair<int, int> bef={i, N};
        while (bef.s>0) {
            path.push_back(bef);
            bef=from[bef.f][bef.s];
        }
        break;
    }
    reverse(path.begin(), path.end());

    int cnt=0, start=0, up=0;
    for (int i=0; i<path.size()-1; i++) {
        if (path[i].f>path[i+1].f || (path[i].f==1 && path[i+1].f==1)) { //    증가할때,
            up++;
            if (start==0) {
                start=path[i].s;
                cnt++;
            }
        }
        else if (start!=0){
            ans.push_back({start, up});
            start=0;
            up=0;
        }
    }
    if (start!=0){
        ans.push_back({start, up});
        start=0;
        up=0;
    }

    cout << cnt << "\n";
    for (auto a: ans) cout << a.f-1 << " " << a.s << "\n";
}
