#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N=130;
int graph[N][N]={}, visit[N][N]={}, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1}, t=0;
priority_queue<pair<int, pair<int, int>>> pq;
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        int n; cin >> n;
        if (n==0) return 0;

        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> graph[i][j];
        fill(&visit[0][0], &visit[N-1][N-1], 1e9);

        pq.push({-graph[1][1], {1, 1}});
        visit[1][1]=graph[1][1];

        while (!pq.empty()) {
            int dist=-pq.top().f, x=pq.top().s.f, y=pq.top().s.s;
            pq.pop();
            if (dist>visit[x][y]) continue;

            for (int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i], nd=graph[nx][ny];
                if (nx<1 || nx>n || ny<1 || ny>n) continue;

                if (dist+nd<visit[nx][ny]) {
                    visit[nx][ny]=dist+nd;
                    pq.push({-(dist+nd), {nx, ny}});
                }
            }
        }
        t++;
        cout << "Problem " << t << ": " << visit[n][n] << "\n";
    }
}
