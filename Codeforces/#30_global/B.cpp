#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n; 
    vector<int> even, odd;
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        if (x%2) odd.push_back(x);
        else even.push_back(x);
    }

    if (even.size()>=2) {
        cout << even[0] << ' ' << even[1] << "\n";
        return;
    }
    if (even.size()==1) {
        for (int o: odd) {
            if (o>even[0]) continue;
            if ((even[0]%o)%2==0) {
                cout << o << ' ' << even[0] << "\n";
                return;
            }
        }
    }

    for (int i=1; i<odd.size(); i++) {
        for (int j=max(0, i-50); j<i; j++) {
                if ((odd[i]%odd[j])%2==0) {
                cout << odd[j] << ' ' << odd[i] << "\n";
                return;
            }
        }
    }
    cout << "-1\n";

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
