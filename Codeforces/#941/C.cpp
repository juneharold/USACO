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
    set<int> s;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    vector<int> a;
    for (int x: s) a.push_back(x);

    int prev=0;
    for (int i=0; i<a.size(); i++) {
        if (a[i]-prev>1) {
            if (i%2==0) cout << "Alice\n";
            else cout << "Bob\n";
            return;
        }
        prev=a[i];
    }
    if (a.size()%2==1) cout << "Alice\n";
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
