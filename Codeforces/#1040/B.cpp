#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, s; cin >> n >> s;
    vector<int> a(n+1);
    int sum=0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum+=a[i];
    }
    if (sum>s) {
        for (int i=1; i<=n; i++) cout << a[i] << ' ';
        cout << "\n";
        return;
    }
    int cnt1=0, cnt2=0;
    for (int i=1; i<=n; i++) {
        if (a[i]==2) cnt2++;
        else if (a[i]==1) cnt1++;
    }
    
    if (sum==s-1) {
        for (int i=1; i<=n; i++) {
            if (cnt1) {
                cout << "1 ";
                cnt1--;
            }
            else if (cnt2) {
                cout << "2 ";
                cnt2--;
            }
            else cout << "0 ";
        }
        cout << "\n";
    }
    else cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
