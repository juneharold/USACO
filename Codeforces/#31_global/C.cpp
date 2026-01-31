#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> tight, loose;
    for (int i=1; i<=k; i++) tight.push_back(0);

    for (int i=30; i>=0; i--) {
        if ((1<<i)>n) continue;

        if (n&(1<<i)) { // need odd number of 1s
            if (k%2==0) {
                if (tight.size()>0) {
                    for (int j=0; j<loose.size(); j++) loose[j]+=(1<<i);
                    for (int j=0; j<tight.size()-1; j++) tight[j]+=(1<<i);
                    loose.push_back(tight.back());
                    tight.pop_back();
                }
                else {
                    for (int j=0; j<loose.size()-1; j++) loose[j]+=(1<<i);
                }
            }
            else {
                for (int j=0; j<loose.size(); j++) loose[j]+=(1<<i);
                for (int j=0; j<tight.size(); j++) tight[j]+=(1<<i);
            }
        }
        else { // need even number of 1s
            for (int j=0; j+1<loose.size(); j+=2) {
                loose[j]+=(1<<i);
                loose[j+1]+=(1<<i);
            }
        }
    }

    for (int x: loose) cout << x << ' ';
    for (int x: tight) cout << x << ' ';
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
