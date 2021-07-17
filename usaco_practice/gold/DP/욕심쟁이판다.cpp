#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N=505;
int dp[MAX_N][MAX_N]={};
int graph[MAX_N][MAX_N];
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n;
int ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> graph[i][j];

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int visit[MAX_N][MAX_N]={};
            dp[i][j]=max(dp[i][j], 1);

            queue<pair<int, int>> q;
            q.push({i, j});
            visit[i][j]=1;
            while (!q.empty()) {
                int cur_x=q.front().first, cur_y=q.front().second;
                q.pop();
                for (int k=0; k<4; k++) {
                    int nx=cur_x+dx[k], ny=cur_y+dy[k];
                    if (nx<1 || nx>n || ny<1 || ny>n) continue;
                    if (visit[nx][ny]==0 && graph[nx][ny]>graph[cur_x][cur_y]) {
                        visit[nx][ny]=1;
                        q.push({nx, ny});
                        dp[nx][ny]=max(dp[nx][ny], dp[cur_x][cur_y]+1);
                        ans=max(ans, dp[nx][ny]);
                    }
                }
            }

        }
    }

    //for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) ans=max(ans, dp[i][j]);
    cout << ans;
}
