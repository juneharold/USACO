#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

bool check3(int n, vector<vector<char>> &a) {
    for (int j=1; j<=n; j++) {
        for (int i=1; i<=n-2; i++) {
            if (a[i][j]=='#' && a[i+1][j]=='#' && a[i+2][j]=='#') {
                return true;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n-2; j++) {
            if (a[i][j]=='#' && a[i][j+1]=='#' && a[i][j+2]=='#') {
                return true;
            }
        }
    }
    return false;
}


int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
void dfs(int n, int x, int y, vector<vector<char>> &a, vector<vector<bool>> &vst) {
    vst[x][y]=true;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<1 || nx>n || ny<1 || ny>n) continue;
        if (!vst[nx][ny] && a[nx][ny]=='#') dfs(n, nx, ny, a, vst);
    }
}

bool check_disconnect(int n, vector<vector<char>> &a) {
    int components=0;
    vector<vector<bool>> vst(n+5, vector<bool>(n+5, false));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!vst[i][j] && a[i][j]=='#') {
                dfs(n, i, j, a, vst);
                components++;
            }
        }
    }
    if (components>1) return true;
    return false;
}


void solve() {
    int n; cin >> n;
    vector<vector<char>> a(n+5, vector<char>(n+5, '.'));
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> a[i][j];

    if (!check3(n, a) && !check_disconnect(n, a)) {
        cout << "YES\n";
        return;
    }

    bool found=false;
    int x=-1, y=-1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j]=='#') {
                x=i, y=j;
                found=true;
                break;
            }
        }
        if (found) break;
    }


    if (found) {
        vector<vector<char>> b(n+5, vector<char>(n+5, '.'));
        int tx, ty;

        // left down
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) b[i][j]=a[i][j];
        tx=x, ty=y;
        for (int i=tx; i<=n; i++) {
            if (ty>=1) b[i][ty]='#';
            if (ty-1>=1) b[i][ty-1]='#';
            ty--;
        }
        if (!check3(n, b) && !check_disconnect(n, b)) {
            //cout << "here1\n";
            cout << "YES\n";
            return;
        }

        // right down
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) b[i][j]=a[i][j];
        tx=x, ty=y;
        for (int i=tx; i<=n; i++) {
            if (ty<=n) b[i][ty]='#';
            if (ty+1<=n) b[i][ty+1]='#';
            ty++;
        }
        if (!check3(n, b) && !check_disconnect(n, b)) {
            //cout << "here2\n";
            cout << "YES\n";
            return;
        }

        // down left
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) b[i][j]=a[i][j];
        tx=x, ty=y;
        for (int i=tx; i<=n; i++) {
            if (ty>=1) b[i][ty]='#';
            if (ty>=1 && i+1<=n) b[i+1][ty]='#';
            ty--;
        }
        if (!check3(n, b) && !check_disconnect(n, b)) {
            //cout << "here3\n";
            cout << "YES\n";
            return;
        }

        // down right
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) b[i][j]=a[i][j];
        tx=x, ty=y;
        for (int i=tx; i<=n; i++) {
            if (ty<=n) b[i][ty]='#';
            if (ty<=n && i+1<=n) b[i+1][ty]='#';
            ty++;
        }
        if (!check3(n, b) && !check_disconnect(n, b)) {
            //cout << "here4\n";
            cout << "YES\n";
            return;
        }
    }
    else {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
/*
1
5
.#... 
.....
.....
.....
#....
*/