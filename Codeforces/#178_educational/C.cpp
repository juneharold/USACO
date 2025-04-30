#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<char> cards(n+1);
    for (int i=1; i<=n; i++) cin >> cards[i];

    if (cards[1]=='A' && cards[n]=='A') {
        cout << "Alice\n";
        return;
    }
    if (cards[1]=='B' && cards[n]=='B') {
        cout << "Bob\n";
        return;
    }

    if (cards[1]=='A') {
        int cntB=0;
        for (int i=1; i<=n; i++) {
            if (cards[i]=='B') cntB++;
        }
        if (cntB==1) {
            cout << "Alice\n";
            return;
        }
        else {
            cout << "Bob\n";
            return;
        }
    }
    if (cards[n-1]=='A') cout << "Alice\n";
    else cout << "Bob\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
