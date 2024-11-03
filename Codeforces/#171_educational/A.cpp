#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int X, Y, K; cin >> X >> Y >> K;
    int S=min(X, Y);
    cout << "0 0 " << S << ' ' << S << "\n";
    cout << "0 " << S << ' ' << S << " 0\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
