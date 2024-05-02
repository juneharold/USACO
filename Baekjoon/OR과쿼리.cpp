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
const ll nmax=250005, sqrmax=635, MOD=1e9+7, INF=1e18;
/*
use 2 segtree1
- keep track of which nodes don't need more updates. a node need at most 30 upates
O(30nlogn)
*/
int segtree1[4*nmax]={};
int query1(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree1[n];
    int mid=(a+b)/2;
    return query1(2*n, a, mid, qa, qb)+query1(2*n+1, mid+1, b, qa, qb);
}
void update1(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree1[n]=v; return; }
    int mid=(a+b)/2;
    update1(2*n, a, mid, qa, qb, v);
    update1(2*n+1, mid+1, b, qa, qb, v);
    segtree1[n]=segtree1[2*n]+segtree1[2*n+1];
}

int segtree2[4*nmax]={};
int query2(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 1;
    if (qa<=a && b<=qb) return segtree2[n];
    int mid=(a+b)/2;
    return query2(2*n, a, mid, qa, qb)&query2(2*n+1, mid+1, b, qa, qb);
}
void update2(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree2[n]=v; return; }
    int mid=(a+b)/2;
    update2(2*n, a, mid, qa, qb, v);
    update2(2*n+1, mid+1, b, qa, qb, v);
    segtree2[n]=segtree2[2*n]&segtree2[2*n+1];
}



void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N+1);
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        if (A[i]==K) update1(1, 1, N, i, i, 1);
    }

    int M; cin >> M;
    while (M--) {
        int type; cin >> type;
        if (type==1) {
            int l, r, x; cin >> l >> r >> x;
            update2(1, 1, N, l, r, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << query1(1, 1, N, l, r) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
