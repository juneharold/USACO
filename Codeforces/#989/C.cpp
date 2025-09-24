#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int n, m; 
int di[4]={1, -1, 0, 0}, dj[4]={0, 0, 1, -1};
map<char, int> dir_to_idx;

void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& vst, vector<vector<int>>& state) {
    vst[x][y]=1;
    char c=grid[x][y];
    int nx=x+di[dir_to_idx[c]], ny=y+dj[dir_to_idx[c]];
    if (nx<1 || nx>n || ny<1 || ny>m) state[x][y]=1;
    else if (grid[nx][ny]=='?') state[x][y]=0;
    else if (vst[nx][ny]) state[x][y]=state[nx][ny];
    else {
        dfs(nx, ny, grid, vst, state);
        state[x][y]=state[nx][ny];
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> grid(n+5, vector<char>(m+5));
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> grid[i][j];
    vector<vector<int>> state(n+5, vector<int>(m+5, -1));
    vector<vector<int>> vst(n+5, vector<int>(m+5, 0));

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (vst[i][j]==0 && grid[i][j]!='?') {
                
                dfs(i, j, grid, vst, state);
            }
        }
    }

    /*for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << state[i][j] << ' ';
        }
        cout << endl;
    }*/

    int cnt=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (grid[i][j]=='?') {
                int sum=0;
                for (int k=0; k<4; k++) {
                    int ni=i+di[k], nj=j+dj[k];
                    if (ni<1 || ni>n || nj<1 || nj>m) sum++;
                    else sum+=state[ni][nj];
                }
                if (sum==4) cnt++;
            }
            else if (state[i][j]==1) cnt++;
        }
    }
    cout << n*m-cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    dir_to_idx['D']=0;
    dir_to_idx['U']=1;
    dir_to_idx['R']=2;
    dir_to_idx['L']=3;
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
