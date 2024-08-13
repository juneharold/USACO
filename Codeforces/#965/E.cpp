#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll A[nmax];

int segtree[4*nmax]={};
int query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    int res1=query(2*n, a, mid, qa, qb), res2=query(2*n+1, mid+1, b, qa, qb);
    if (A[res1]>=A[res2]) return res1;
    return res2;
}
void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]=v; return; }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    int res1=segtree[2*n], res2=segtree[2*n+1];
    if (A[res1]>=A[res2]) segtree[n]=segtree[2*n];
    else segtree[n]=segtree[2*n+1];
}

int n, x, ans=0;
ll pfs[nmax]={};
void DnC(int l, int r) {
    int m=query(1, 1, n, l, r);
    ans++;
    if (l==r) return;
    if (pfs[r]-pfs[m]>=A[m]) DnC(m+1, r);
    if (pfs[m-1]-pfs[l-1]>=A[m]) DnC(l, m-1);
}

void solve() {
    cin >> n >> x;
    for (int i=1; i<=n; i++) cin >> A[i];

    for (int i=1; i<=n; i++) {
        update(1, 1, n, i, i, i);
        pfs[i]=pfs[i-1]+A[i];
    }
    DnC(1, n);
    cout << ans << "\n";
    ans=0;
    for (int i=1; i<=n; i++) {
        update(1, 1, n, i, i, 0);
        pfs[i]=0;
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
