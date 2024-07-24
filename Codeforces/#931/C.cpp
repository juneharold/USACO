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

void query(int x, int y) {
    cout << "? " << x << ' ' << y << "\n";
    cout.flush();
}

void solve() {
    int n, m; cin >> n >> m;
    query(1, 1);
    int res1; cin >> res1;
    query(1, m);
    int res2; cin >> res2;
    query(n, m);
    int res3; cin >> res3;
    pii cand1={(res1+res2+3-m)/2, (res1+2)-(res1+res2+3-m)/2};
    pii cand2={(res2+1+n-res3)/2, (n+m-res3)-(res2+1+n-res3)/2};

    if (cand1.fs<1 || cand1.fs>n || cand1.sc<1 || cand1.sc>m) {
        cout << "! " << cand2.fs << ' ' << cand2.sc << "\n";
        cout.flush();
        return;
    }
    if (cand2.fs<1 || cand2.fs>n || cand2.sc<1 || cand2.sc>m) {
        cout << "! " << cand1.fs << ' ' << cand1.sc << "\n";
        cout.flush();
        return;
    }

    query(cand1.fs, cand1.sc);
    int res4; cin >> res4;
    if (res4==0) cout << "! " << cand1.fs << ' ' << cand1.sc << "\n";
    else cout << "! " << cand2.fs << ' ' << cand2.sc << "\n";
    cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
