#include <iostream>
#include <queue>
using namespace std;
#define f first
#define s second

int a[105][105]={}, visit[105][105]={};
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};

int main()
{
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        cin >> a[i][j];
        //visit[i][j]=a[i][j];
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    fill(&visit[0][0], &visit[N+1][M+1], 1e9);
    for (int i=2; i<=N-1; i++) {
        //visit[i][1]=a[i][1], visit[i][M]=a[i][M];
        pq.push({a[i][1], {i, 1}});
        pq.push({a[i][M], {i, M}});
    }
    for (int j=1; j<=M; j++) {
        //visit[1][j]=a[1][j], visit[N][j]=a[N][j];
        pq.push({a[1][j], {1, j}});
        pq.push({a[N][j], {N, j}});
    }

    while (!pq.empty()) {
        int h=pq.top().f, x=pq.top().s.f, y=pq.top().s.s;
        pq.pop();
        if (a[x][y]<=h && h<visit[x][y]) {
            visit[x][y]=h;
            for (int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if (nx<1 || nx>N || ny<1 || ny>M) continue;
                pq.push({h, {nx, ny}});
            }
        }
        //else visit[x][y]=a[x][y];
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            //cout << visit[i][j] << ' ';
            if (visit[i][j]==1e9) continue;
            ans+=visit[i][j]-a[i][j];
        }
        //cout << endl;
    }
    cout << ans;
}

/*
3 3
3 1 1
1 1 2
3 3 1

5 5
5 5 6 7 8
5 1 6 1 4
5 1 5 6 5
5 1 1 1 5
5 5 5 5 5
ans=23
*/
