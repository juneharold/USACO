#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int cnt=0, cnt_top=0;
    for (int i=0; i<n; i+=2) {
        cnt_top++;
        if (a[i]=='0') cnt++;
        if (i+1<n && b[i+1]=='0') cnt++;
    }
    if (cnt<cnt_top) {
        cout << "NO\n";
        return;
    }
    cnt=0, cnt_top=0;
    for (int i=0; i<n; i+=2) {
        if (b[i]=='0') cnt++;
        if (i+1<n && a[i+1]=='0') cnt++;
        if (i+1<n) cnt_top++;
    }
    if (cnt<cnt_top) {
        cout << "NO\n";
        return;
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
