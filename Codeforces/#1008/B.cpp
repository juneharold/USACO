#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    if (k%2==0) {
        fill(&a[1], &a[n+1], n-1);
        a[n-1]=n;
    }
    else {
        fill(&a[1], &a[n+1], n);
        a[n]=n-1;
    }
    for (int i=1; i<=n; i++) cout << a[i] << ' ';
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
