#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    if (n==1 || n==3) cout << "-1\n";
    else {
        if (n%2==0) {
            string ans="";
            for (int i=1; i<=n-2; i++) ans+='3';
            ans+="66";
            cout << ans << "\n";
        }
        else {
            string ans="";
            for (int i=1; i<=n-4; i++) ans+='3';
            ans+="6366";
            cout << ans << "\n";
        }
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
