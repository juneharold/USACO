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

int N, M, pfs[nmax]={};

struct node {
    int mxleft, mxright, mx;
};

node segtree[4*nmax]={};
node query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return {-1000000000, -1000000000, -1000000000};
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    node n1=query(2*n, a, mid, qa, qb), n2=query(2*n+1, mid+1, b, qa, qb);
    node ret;
    ret.mxleft=max(n1.mxleft, pfs[mid]-pfs[max(a-1, qa-1)]+n2.mxleft);
    ret.mxright=max(n2.mxright, pfs[min(qb, b)]-pfs[mid]+n1.mxright);
    ret.mx=max({n1.mx, n2.mx, n1.mxright+n2.mxleft});
    return ret;
}
void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]={v, v, v}; return; }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n].mxleft=max(segtree[2*n].mxleft, pfs[mid]-pfs[a-1]+segtree[2*n+1].mxleft);
    segtree[n].mxright=max(segtree[2*n+1].mxright, pfs[b]-pfs[mid]+segtree[2*n].mxright);
    segtree[n].mx=max({segtree[2*n].mx, segtree[2*n+1].mx, segtree[2*n].mxright+segtree[2*n+1].mxleft});
}

void solve() {
    cin >> N;
    vector<int> A(N+1);
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        pfs[i]=pfs[i-1]+A[i];
    }
    for (int i=1; i<=N; i++) update(1, 1, N, i, i, A[i]);
    cin >> M;
    while (M--) {
        int l, r; cin >> l >> r;
        //cout << query(1, 1, N, l, r).mxleft << "\n";
        cout << query(1, 1, N, l, r).mx << "\n";
        //cout << query(1, 1, N, l, r).mxright << "\n";
    }
}

/*
when using bounds as (a, b) in pfs in query instead of (qa, qb)

input:
10
10 -4 3 1 5 6 -35 12 21 -1
1
5 7

output:
21
11
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
