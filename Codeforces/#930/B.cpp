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

char a[2][nmax];

void solve() {
    int n; cin >> n;
    for (int i=0; i<2; i++) {
        for (int j=1; j<=n; j++) cin >> a[i][j];
    }

    string s="";
    s+=a[0][1];
    bool top=true;
    for (int i=1; i<=n; i++) {
        if (top) {
            if (i<n && a[0][i+1]=='0') s+='0';
            else if (i<n && a[0][i+1]=='1' && a[1][i]=='1') s+='1';
            else {
                top=false;
                s+=a[1][i];
            }
        }
        else {
            s+=a[1][i];
        }
    }
    cout << s << "\n";

    int cnt=0;
    vector<int> b1(n+5, 1), b2(n+5, 1);
    for (int i=1; i<=n; i++) {
        if (b1[i-1]==0 || a[0][i]!=s[i-1]) b1[i]=0;
    }
    for (int i=n; i>=1; i--) {
        if (b2[i+1]==0 || a[1][i]!=s[i]) b2[i]=0;
    }
    for (int i=1; i<=n; i++) if (b1[i]==b2[i] && b1[i]==1) cnt++;
    cout << cnt << "\n";

    for (int i=0; i<2; i++) {
        for (int j=1; j<=n; j++) a[i][j]='0';
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
