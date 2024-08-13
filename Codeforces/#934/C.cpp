#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<int> cnt(n, 0);
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    bool temp=false;
    for (int i=0; i<n; i++) {
        if (cnt[i]==1) {
            if (temp) {
                cout << i << "\n";
                return;
            }
            else temp=true;
        }
        if (cnt[i]==0) {
            cout << i << "\n";
            return;
        }
    }
    cout << n << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}