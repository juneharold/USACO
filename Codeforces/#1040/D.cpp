#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=5e3+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int n, p[nmax]={}, a[nmax]={};

void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> p[i];

    for (int i=1; i<=n; i++) {
        int same=0;
        for (int j=1; j<i; j++) if (p[j]>p[i]) same++;
        for (int j=i+1; j<=n; j++) if (p[j]<p[i]) same++;
        int switch_=n-i;
        if (switch_<same) {
            a[i]=2*n-p[i];
        }
        else {
            a[i]=p[i];
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if (a[j]>a[i]) ans++;
        }
    }
    cout << ans << "\n";

    for (int i=1; i<=n; i++) p[i]=a[i]=0;
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
9  
2 1 3 4 5 6 7 8 9

1
5
2 1 3 4 5
*/