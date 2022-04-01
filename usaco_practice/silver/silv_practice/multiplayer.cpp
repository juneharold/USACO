#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long
#define f first
#define s second

const int MAX=250*250+5;
int N, grid[255][255]={}, used_edge[255][255][4]={}, visit[255][255]={}, temp=0;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
map<int, int> m;

void solve1(int x, int y) {
    visit[x][y]=1;
    temp++;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<1 || nx>N || ny<1 || ny>N || visit[nx][ny]==1) continue;
        if (grid[nx][ny]==grid[x][y]) {
            solve1(nx, ny);
        }
    }
}

void solve2(int x, int y, int k) {
    m[grid[x][y]]++;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<1 || nx>N || ny<1 || ny>N) continue;
        if (used_edge[x][y][i]==1 || used_edge[nx][ny][(i+2)%4]==1) continue;

        if (grid[nx][ny]==k || grid[x][y]==k) {
            used_edge[x][y][i]=1;
            used_edge[nx][ny][(i+2)%4]=1;
            solve2(nx, ny, k);
        }
    }
}

int main()
{
    //freopen("multimoo.in", "r", stdin);
    //freopen("multimoo.out", "w", stdout);
    cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> grid[i][j];

    int ans1=0;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++){
        if (visit[i][j]==0) solve1(i, j);
        ans1=max(ans1, temp);
        temp=0;
    }
    cout << ans1 << "\n";

    int ans2=0;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        solve2(i, j, grid[i][j]);

        for (auto e: m) {
            if (e.f!=grid[i][j]) ans2=max(ans2, e.s);
            /*
            if (e.f!=grid[i][j] && e.s+m[grid[i][j]]>ans2) {
                ans2=max(ans2, e.s+m[grid[i][j]]);
                cout << grid[i][j] << " " << m[grid[i][j]] << " " << e.f << " " << e.s << "\n";
            }*/
        }
        m.clear();
    }

    cout << ans2 << "\n";
}

/*
4
1 3 9 7
4 7 7 7
4 7 1 7
1 9 1 3
정답:
6
9

4
1 3 1 4
4 7 3 2
4 3 1 2
1 9 1 2
정답:
3
7

*/
