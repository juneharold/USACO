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
    sort(&a[1], &a[n+1]);

    vector<vector<int>> idx(1e5+5);
    for (int i=1; i<=n; i++) {
        for (int j=1; j*j<=a[i]; j++) {
            if (a[i]%j==0) {
                idx[j].push_back(i);
                if (j*j!=a[i]) idx[a[i]/j].push_back(i);
            }
        }
    }

    ll ans=0;
    vector<ll> x(1e5+5, 0);
    for (int i=1e5; i>=1; i--) {
        for (int j=0; j<idx[i].size(); j++) x[i]+=j*(n-idx[i][j]);
        for (int j=2; j*i<=1e5; j++) x[i]-=x[j*i];
        ans+=x[i]*i;
    }
    cout << ans << "\n";
}
/*
- sort a[]
- let x[i] be the number of times f(a, b, c)=i (note that a<b<c)
    - to calculate x[i], we can just find the number of times k*i is the answer and subtract x[2*i]+x[3*i]+...
    - since n/n+n/(n-1)+...+n/1 is approximately nlogn the whole subtracting process can be done in O(nlogn)
- for every j from 1 to 1e5, store the indexes of a[i] where a[i]%j==0
- now to calculate x[i], use the vector of i (where indexs are sorted) to choose candidate for b, then c can be any index greater than the current index, while a can be any number of indexes less than b in the same vector. 
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
