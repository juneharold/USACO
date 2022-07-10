#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define ll long long

char graph[1005][1005];
int N, M, visit[1005][1005]={}, cnt[1000005]={};
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};

void dfs(int x, int y, int k) {
    visit[x][y]=k;
    cnt[k]++;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<1 || nx>N || ny<1 || ny>M || graph[nx][ny]=='1') continue;
        if (visit[nx][ny]==0) {
            dfs(nx, ny, k);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin >> graph[i][j];

    int idx=1;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        if (visit[i][j]==0 && graph[i][j]=='0') {
            dfs(i, j, idx);
            idx++;
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (graph[i][j]=='1') {
                set<int> s;
                for (int k=0; k<4; k++) {
                    int nx=i+dx[k], ny=j+dy[k];
                    if (nx<1 || nx>N || ny<1 || ny>M || graph[nx][ny]=='1') continue;
                    s.insert(visit[nx][ny]);
                }
                int ans=0;
                for (int x: s) ans+=cnt[x];
                cout << (ans+1)%10;
            }
            else cout << '0';
        }
        cout << "\n";
    }
}
