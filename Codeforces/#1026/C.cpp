#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<int> d(n+1), l(n+1), r(n+1);
    for (int i=1; i<=n; i++) cin >> d[i];
    for (int i=1; i<=n; i++) cin >> l[i] >> r[i];

    vector<int> mn(n+1), mx(n+1);
    mn[0]=0, mx[0]=0;
    for (int i=1; i<=n; i++) {
        if (d[i]==-1) {
            mn[i]=mn[i-1];
            mx[i]=mx[i-1]+1;
        }
        else {
            mn[i]=mn[i-1]+d[i];
            mx[i]=mx[i-1]+d[i];
        }

        if (mn[i]>r[i] || mx[i]<l[i]) {
            cout << "-1\n";
            return;
        }
        mn[i]=max(mn[i], l[i]);
        mx[i]=min(mx[i], r[i]);
    }

    for (int i=n-1; i>=1; i--) {
        if (d[i+1]==1) {
            mx[i]=min(r[i], mx[i+1]-1);
            mn[i]=max(l[i], mn[i+1]-1);
        }
        else if (d[i+1]==0) {
            mx[i]=min(r[i], mx[i+1]);
            mn[i]=max(l[i], mn[i+1]);
        }
        else {
            mx[i]=min(r[i], mx[i+1]);
            mn[i]=max(l[i], mn[i+1]-1);
        }
        if (mn[i]>mx[i]) {
            cout << "-1\n";
            return;
        }
    }
    //for (int i=1; i<=n; i++) cout << mn[i] << ' ' << mx[i] << endl;

    int cur=0;
    for (int i=1; i<=n; i++) {
        if (d[i]==-1) {
            if (cur==mx[i]) d[i]=0;
            else d[i]=1;
        }
        cur+=d[i];
        if (cur<l[i] || cur>r[i]) {
            cout << "-1\n";
            return;
        }
    }
    for (int i=1; i<=n; i++) cout << d[i] << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
