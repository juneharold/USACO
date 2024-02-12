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
    ll a, b; cin >> a >> b;
    if (a%2 && b%2) {
        cout << "NO\n";
    }
    else if (a%2==0 && b%2==0) {
        cout << "YES\n";
    }
    else {
        if (a%2==1) swap(a, b);
        ll na=a/2, nb=b*2;
        if (make_pair(na, nb)!=make_pair(a, b) && make_pair(na, nb)!=make_pair(b, a)) cout << "YES\n";
        else cout << "NO\n";
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
