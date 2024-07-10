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
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll segtree[4*nmax]={};
ll query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return query(2*n, a, mid, qa, qb)+query(2*n+1, mid+1, b, qa, qb);
}
void update(int n, int a, int b, int qa, int qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]=v; return; }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=segtree[2*n]+segtree[2*n+1];
}

void solve() {
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    map<int, int> cnt1, cnt2;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cnt1[a[i]]++;
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        cnt2[b[i]]++;
    }

    bool check=false;
    for (auto x: cnt1) {
        if (cnt2[x.fs]!=x.sc) {
            cout << "NO\n";
            return;
        }
        if (x.sc>1) check=true;
    }
    if (check) {
        cout << "YES\n";
        return;
    }

    map<int, int> pos;
    for (int i=1; i<=n; i++) pos[b[i]]=i;
    ll cnt=0;
    for (int i=n; i>=1; i--) {
        cnt+=query(1, 1, n, 1, pos[a[i]]);
        update(1, 1, n, pos[a[i]], pos[a[i]], 1);
    }
    if (cnt%2==0) cout << "YES\n";
    else cout << "NO\n";

    for (int i=n; i>=1; i--) update(1, 1, n, pos[a[i]], pos[a[i]], 0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
