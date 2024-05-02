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

vector<int> tree[4*nmax]={};

void insert(int n, int a, int b, int i, int v) {
    if (b<i || a>i) return;
    if (a==b && b==i) {
        tree[n].push_back(v);
        return;
    }
    int mid=(a+b)/2;
    insert(2*n, a, mid, i, v);
    insert(2*n+1, mid+1, b, i, v);
    if (a<=i && i<=b) tree[n].push_back(v);
}

void sort_tree(int n, int a, int b) {
    sort(tree[n].begin(), tree[n].end());
    if (a==b) return;
    int mid=(a+b)/2;
    sort_tree(2*n, a, mid);
    sort_tree(2*n+1, mid+1, b);
}

int query(int n, int a, int b, int qa, int qb, int k) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) {
        int ret=upper_bound(tree[n].begin(), tree[n].end(), k)-tree[n].begin();
        return ret;
    }
    int mid=(a+b)/2;
    return query(2*n, a, mid, qa, qb, k)+query(2*n+1, mid+1, b, qa, qb, k);
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a; cin >> a;
        insert(1, 1, n, i, a);
    }
    sort_tree(1, 1, n);

    while (m--) {
        int i, j, k; cin >> i >> j >> k;
        int lo=-1e9-1, hi=1e9+1;
        while (lo<hi) {
            int mid=(lo+hi+1)/2;
            if (query(1, 1, n, i, j, mid)<=k-1) lo=mid;
            else hi=mid-1;
        }
        cout << lo+1 << "\n";
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
