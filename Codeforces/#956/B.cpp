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

int n, m, a[505][505], b[505][505];
void solve() {
    cin >> n >> m;
    char x;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        cin >> x;
        a[i][j]=x-'0';
    }
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        cin >> x;
        b[i][j]=x-'0';
    }

    for (int i=1; i<=n-1; i++) for (int j=1; j<=m-1; j++) {
        if (a[i][j]!=b[i][j]) {
            int add=(b[i][j]-a[i][j]+3)%3;
            a[i][j]=(a[i][j]+add)%3;
            a[i+1][j]=(a[i+1][j]+(3-add))%3;
            a[i+1][j+1]=(a[i+1][j+1]+add)%3;
            a[i][j+1]=(a[i][j+1]+(3-add))%3;
        }
    }
    
    int cnt1=0, cnt2=0;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        if (a[i][j]!=b[i][j]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
