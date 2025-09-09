#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=5e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int segtree[4*nmax]={};
int query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 1e9;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return min(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
}
void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]=v; return; }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=min(segtree[2*n], segtree[2*n+1]);
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<int> left(n+1, -1), right(n+1, -1);
    stack<pii> st;
    st.push({1e9, 0});
    for (int i=1; i<n; i++) {
        while (st.top().fs<a[i]) {
            st.pop();
        }
        left[i]=st.top().sc;
        st.push({a[i], i});
    }
    while (!st.empty()) st.pop();
    st.push({0, n+1});
    for (int i=n; i>=2; i--) {
        while (st.top().fs>a[i]) {
            st.pop();
        }
        right[i]=st.top().sc;
        st.push({a[i], i});
    }

    vector<pii> ranges;
    for (int i=1; i<=n; i++) {
        if (1<=left[i] && right[i]<=n) ranges.push_back({left[i], right[i]});
    }

    vector<int> smallest(n+1, 1e9);
    for (auto [x, y]: ranges) {
        //cout << "x y: " << x << ' ' << y << endl;
        smallest[x]=min(smallest[x], y);
    }
    for (int i=1; i<=n; i++) update(1, 1, n, i, i, smallest[i]);

    int l, r;
    while (q--) {
        cin >> l >> r;
        int res=query(1, 1, n, l, r);
        if (res<=r) cout << "NO\n";
        else cout << "YES\n";
    }
    for (int i=1; i<=n; i++) update(1, 1, n, i, i, 1e9);
}
/*
1
6 1
4 3 5 6 2 1
1 5
ans: NO
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(segtree, 1e9, sizeof(segtree));
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
