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
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

char grid1[8][8], grid2[8][8];
int di[4]={1, 1, -1, -1}, dj[4]={1, -1, 1, -1};

bool check(char (&grid)[8][8]) {
    for (int i=2; i<=6; i++) {
        for (int j=2; j<=6; j++) {
            if (grid[i][j]=='W') continue;
            int cnt=0;
            for (int k=0; k<4; k++) {
                int ni=i+di[k], nj=j+dj[k];
                if (grid[ni][nj]=='B') cnt++;
            }
            if (cnt==4) return false;
        }
    }
    return true;
}

vector<pii> v1, v2;
int dfs(int cur, int prev, char (&grid)[8][8], vector<pii> &v) {
    if (cur==5) return 1e9;
    if (check(grid)) return cur;
    int ret=1e9;
    for (int i=prev+1; i<v.size(); i++) {
        int x=v[i].fs, y=v[i].sc;
        if (grid[x][y]=='W') grid[x][y]='B';
        else grid[x][y]='W';
        ret=min(ret, dfs(cur+1, i, grid, v));
        if (grid[x][y]=='W') grid[x][y]='B';
        else grid[x][y]='W';
    }
    return ret;
}

void solve() {
    for (int i=1; i<=7; i++) for (int j=1; j<=7; j++) {
        char x; cin >> x;
        grid1[i][j]=grid2[i][j]='W';
        if (i%2==j%2) grid1[i][j]=x;
        else grid2[i][j]=x;
    }

    vector<pii> v1, v2;
    for (int i=1; i<=7; i++) for (int j=1; j<=7; j++) {
        if (i%2==j%2) v1.push_back({i, j});
        else v2.push_back({i, j});
    }
    int ans=dfs(0, -1, grid1, v1)+dfs(0, -1, grid2, v2);
    cout << ans << "\n";
}

int main()
{
    for (int i=1; i<=7; i++) for (int j=1; j<=7; j++) {
        if (i%2==j%2) v1.push_back({i, j});
        else v2.push_back({i, j});
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
