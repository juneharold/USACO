#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, a; cin >> n;
    map<int, int> mp;
    for (int i=0; i<2*n; i++) {
        cin >> a;
        mp[a]++;
    }

    int ans=0, cnt=0, odd=0;
    for (auto x: mp) {
        //cout << x.fs << ' ' << x.sc << endl;
        if (x.sc%4==0) {
            cnt++;
        }
        else if (x.sc%2==1) {
            ans++;
            odd++;
        }
        else {
            ans+=2;
        }
    }
    if (cnt%2==0) {
        ans+=(cnt/2)*4;
    }
    else {
        if (odd>=2) ans+=(cnt/2)*4+2;
        else ans+=(cnt/2)*4;
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
