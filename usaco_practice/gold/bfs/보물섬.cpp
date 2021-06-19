#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char map[55][55]={};
int visit[55][55]={};
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

int main()
{
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char a; cin >> a;
            map[i][j]=a;
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            if (map[i][j]=='W') continue;
            int max_dist=0;
            queue <pair<int, int>> q;
            q.push({i, j});
            visit[i][j]=1;
            while (!q.empty()) {
                int cur_n=q.front().first, cur_m=q.front().second;
                q.pop();
                for (int k=0; k<4; k++) {
                    int next_n=cur_n+dy[k], next_m=cur_m+dx[k];
                    if (map[next_n][next_m]=='L' && visit[next_n][next_m]==0) {
                        q.push({next_n, next_m});
                        visit[next_n][next_m]=visit[cur_n][cur_m]+1;
                        max_dist=max(max_dist, visit[cur_n][cur_m]);
                    }
                }
            }
            ans=max(ans, max_dist);
            fill(&visit[0][0], &visit[55][55], 0);
    }
    cout << ans;
    return 0;
}

/*
4 4
LLWL
LLWL
LLWL
LLWL

3 2
WW
WL
LW

2 5
LLLWL
LLLWL
*/
