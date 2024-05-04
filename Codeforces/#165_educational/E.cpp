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
const ll nmax=3e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int segtree[4*nmax]={}, lazy[4*nmax]={};
void propagate(int n, int a, int b) {
    segtree[n]+=lazy[n];
    if (a!=b) {
        lazy[2*n]+=lazy[n];
        lazy[2*n+1]+=lazy[n];
    }
    lazy[n]=0;
}
int query(int n, int a, int b, int qa, int qb) {
    propagate(n, a, b);
    if (b<qa || qb<a) return 1e9;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return min(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
}
void update(int n, int a, int b, int qa, int qb, int v) {
    propagate(n, a, b);
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { 
        lazy[n]+=v;
        propagate(n, a, b);
        return; 
    }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=min(segtree[2*n], segtree[2*n+1]);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    int ans=0, from=1;
    vector<int> prev1(n+1, 0), prev2(n+1, 0);
    for (int i=1; i<=n; i++) {
        update(1, 1, n, prev1[a[i]]+1, i, 1);
        if (prev1[a[i]]!=0) update(1, 1, n, prev2[a[i]]+1, prev1[a[i]], -1);
        
        int res=query(1, 1, n, from, i);
        if (res==0) {
            ans++;
            from=i+1;
        }

        prev2[a[i]]=prev1[a[i]];
        prev1[a[i]]=i;
    }
    cout << ans << "\n";

    fill(&segtree[0], &segtree[4*n], 0);
    fill(&lazy[0], &lazy[4*n], 0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
