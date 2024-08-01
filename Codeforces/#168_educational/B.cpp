#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

char grid[4][nmax];

int n, vst[4][nmax]={}, dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};

void dfs(int x, int y) {
    vst[x][y]=1;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<1 || nx>2 || ny<1 || ny>n) continue;
        if (grid[nx][ny]=='x') continue;
        if(vst[nx][ny]==0) dfs(nx, ny);
    }
}

void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> grid[1][i];
    for (int i=1; i<=n; i++) cin >> grid[2][i];

    int cnt=0;
    for (int i=1; i<=2; i++) {
        for (int j=1; j<=n; j++) {
            if (grid[i][j]=='.' && vst[i][j]==0) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    fill(&vst[0][0], &vst[3][n+1], 0);
    if (cnt==0) {
        cout << "0\n";
        return;
    }

    int ans=0;
    for (int j=1; j<=n-2; j++) {
        if (grid[1][j]=='x' && grid[1][j+1]=='.' && grid[1][j+2]=='x') {
            if (grid[2][j]=='.' && grid[2][j+1]=='.' && grid[2][j+2]=='.') ans++;
        }
    }
    for (int j=1; j<=n-2; j++) {
        if (grid[2][j]=='x' && grid[2][j+1]=='.' && grid[2][j+2]=='x') {
            if (grid[1][j]=='.' && grid[1][j+1]=='.' && grid[1][j+2]=='.') ans++;
        }
    }
    cout << ans << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
