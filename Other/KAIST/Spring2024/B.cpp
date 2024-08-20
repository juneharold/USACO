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
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    
    ll ans=0;
    for (int d=0; d<=n-1; d++) {
        ll j=n, i=n-d, prev=n+1;
        while (i>=1) {
            if (a[i]>a[j]) prev=j;
            ans+=prev-j;
            i--, j--;
        }
    }
    for (int d=1; d<=n-1; d++) {
        ll j=n-d, i=n, prev=n+1;
        while (j>=1) {
            if (a[i]>a[j]) prev=i;
            ans+=prev-i;
            i--, j--;
        }
    }
    cout << ans << "\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
