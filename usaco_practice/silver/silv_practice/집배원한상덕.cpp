#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

char grid[55][55]={};
int alt[55][55]={}, visit[55][55]={}, dx[8]={-1, -1, -1, 0, 1, 1, 1, 0}, dy[8]={-1, 0, 1, 1, 1, 0, -1, -1};
pair<int, int> start;
vector<int> heights;

void dfs(int x, int y, int MAX, int MIN) {
    visit[x][y]=1;
    for (int i=0; i<8; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (visit[nx][ny]==0 && MIN<=alt[nx][ny] && alt[nx][ny]<=MAX) {
            dfs(nx, ny, MAX, MIN);
        }
    }
}

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        cin >> grid[i][j];
        if (grid[i][j]=='P') start={i, j};
    }
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        cin >> alt[i][j];
        heights.push_back(alt[i][j]);
    }

    int ans=1e9;
    for (auto maxi: heights) {
        int lo=1, hi=1e6;
        while (lo<hi) {
            int mini=(lo+hi)/2+1;
            if (maxi>=mini) {
                if (mini<=alt[start.f][start.s] && alt[start.f][start.s]<=maxi) {
                    dfs(start.f, start.s, maxi, mini);
                }
            }

            bool solved=true;
            for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
                if (grid[i][j]=='K' && visit[i][j]==0) solved=false;
            }

            if (solved) {
                lo=mini;
                ans=min(ans, maxi-mini);
            }
            else {
                hi=mini-1;
            }
            fill(&visit[0][0], &visit[N+1][N+1], 0);
        }
    }
    cout << ans;
}
