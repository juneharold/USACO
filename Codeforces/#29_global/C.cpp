#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<char> a(n+5, '1');
    for (int i=1; i<=n; i++) cin >> a[i];

    // if (a[1]=='1' && a[2]=='0' && a[3]=='1') {
    //     cout << "NO\n";
    //     return;
    // }

    vector<int> pos;
    vector<int> pfs(n+5, 0);
    for (int i=0; i<=n; i++) {
        if (a[i]=='1' && a[i+1]=='1' && a[i+2]=='0') {
            int j=i+2;
            bool found=false;
            while (j+2<=n+1) {
                if (a[j]=='0' && a[j+1]=='1' && a[j+2]=='1') {
                    found=true;
                    break;
                }
                j++;
            }
            int cnt=0;
            bool possible_no=true;
            for (int k=i+2; k<=j; k++) {
                if (a[k]=='0' && a[k-1]=='0') {
                    possible_no=false;
                }
                if (a[k]=='0') cnt++;
            }
            if (found && possible_no && cnt%2) {
                cout << "NO\n";
                return;
            }
            i=j-1;
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
