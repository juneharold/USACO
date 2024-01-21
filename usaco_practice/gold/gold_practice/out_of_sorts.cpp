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
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int segtree[4*nmax]={};
int query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return query(2*n, a, mid, qa, qb)+query(2*n+1, mid+1, b, qa, qb);
}
void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]=v; return; }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=segtree[2*n]+segtree[2*n+1];
}

void solve() {
    int n; cin >> n;
    vector<pii> a(n+1); 
    for (int i=1; i<=n; i++) {
        cin >> a[i].fs;
        a[i].sc=i;
    }
    sort(&a[1], &a[n+1]);
    int num=0;
    vector<int> b(n+1);
    for (int i=1; i<=n; i++) b[a[i].sc]=++num;

    int ans=1;
    for (int i=1; i<=n; i++) {
        update(1, 1, n, b[i], b[i], 1);
        ans=max(ans, query(1, 1, n, i+1, n));
    }
    cout << ans;
}

int main()
{
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
