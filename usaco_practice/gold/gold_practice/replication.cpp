#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e3+5, sqrmax=635, MOD=1e9+7, INF=1e18;

char grid[nmax][nmax];
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
int dw[nmax][nmax]={}, ds[nmax][nmax]={}, vst[nmax][nmax]={};

void solve() {
    int N, D; cin >> N >> D;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> grid[i][j];

    queue<pii> q;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        if (grid[i][j]=='#') q.push({i, j});
        else dw[i][j]=1e9;
    }
    while (!q.empty()) {
        int x=q.front().fs, y=q.front().sc;
        q.pop();
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (dw[x][y]+1<dw[nx][ny]) {
                dw[nx][ny]=dw[x][y]+1;
                q.push({nx, ny});
            }
        }
    }

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        if (grid[i][j]=='S') q.push({i, j});
        else ds[i][j]=1e9;
    }
    while (!q.empty()) {
        int x=q.front().fs, y=q.front().sc;
        q.pop();
        if (ds[x][y]/D>=dw[x][y]) continue;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (grid[nx][ny]=='#') continue;
            if (ds[x][y]+1<ds[nx][ny]) {
                ds[nx][ny]=ds[x][y]+1;
                q.push({nx, ny});
            }
        }
    }

    fill(&vst[0][0], &vst[N+1][N+1], -1e9);
    priority_queue<pair<int, pii>> pq;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        if (ds[i][j]!=1e9) {
            if (ds[i][j]/D>dw[i][j]) {
                vst[i][j]=ds[i][j]/D-1;
                pq.push({ds[i][j]/D-1, {i, j}});
            }
            else {
                vst[i][j]=ds[i][j]/D;
                pq.push({ds[i][j]/D, {i, j}});
            }
            //vst[i][j]=ds[i][j]/D;
            //pq.push({ds[i][j]/D, {i, j}});
            //cout << i << ' ' << j << ' ' << ds[i][j]/D << endl;
        }
    }
    while (!pq.empty()) {
        int sz=pq.top().fs, x=pq.top().sc.fs, y=pq.top().sc.sc;
        pq.pop();
        if (sz==1) continue;
        for (int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if (grid[nx][ny]=='#') continue;
            if (vst[nx][ny]==-1e9) {
                vst[nx][ny]=sz-1;
                pq.push({vst[nx][ny], {nx, ny}});
            }
        }
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (vst[i][j]>=0 && grid[i][j]!='#') ans++;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
