#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=3e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int A[nmax]={};

pii segtree1[4*nmax]={};
pii query1(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return {0, 0};
    if (qa<=a && b<=qb) return segtree1[n];
    int mid=(a+b)/2;
    return max(query1(2*n, a, mid, qa, qb), query1(2*n+1, mid+1, b, qa, qb));
}
void update1(int n, int a, int b, int qa, int qb, pii v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree1[n]=v; return; }
    int mid=(a+b)/2;
    update1(2*n, a, mid, qa, qb, v);
    update1(2*n+1, mid+1, b, qa, qb, v);
    segtree1[n]=max(segtree1[2*n], segtree1[2*n+1]);
}

pii segtree2[4*nmax]={};
pii query2(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return {1e9, 1e9};
    if (qa<=a && b<=qb) return segtree2[n];
    int mid=(a+b)/2;
    return min(query2(2*n, a, mid, qa, qb), query2(2*n+1, mid+1, b, qa, qb));
}
void update2(int n, int a, int b, int qa, int qb, pii v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree2[n]=v; return; }
    int mid=(a+b)/2;
    update2(2*n, a, mid, qa, qb, v);
    update2(2*n+1, mid+1, b, qa, qb, v);
    segtree2[n]=min(segtree2[2*n], segtree2[2*n+1]);
}

int segtree[4*nmax]={}, lazy[4*nmax]={};
void propagate(int n, int a, int b) {
    segtree[n]+=(b-a+1)*lazy[n];
    if (a!=b) {
        lazy[2*n]+=lazy[n];
        lazy[2*n+1]+=lazy[n];
    }
    lazy[n]=0;
}
int query(int n, int a, int b, int qa, int qb) {
    propagate(n, a, b);
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return max(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
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
    segtree[n]=max(segtree[2*n], segtree[2*n+1]);
}


void solve() {
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> A[i];

    //vector<int> cnt(n+1, 0); // count unique element from i~n
    set<int> s;
    for (int i=n; i>=1; i--) {
        s.insert(A[i]);
        update(1, 1, n, i, i, s.size());
        //cnt[i]=s.size();
    }

    vector<vector<int>> pos(n+1);
    for (int i=1; i<=n; i++) {
        update1(1, 1, n, i, i, {A[i], -i});
        update2(1, 1, n, i, i, {A[i], i});
        pos[A[i]].push_back(i);
    }

    /*for (int i=1; i<=n; i++) cout << cnt[i] << ' ';
    cout << endl;*/

    vector<int> ans;
    ans.push_back(0);
    int idx=1;
    for (int i=1; i<=s.size(); i++) {
        //cout << idx << ' ' << query(1, 1, n, idx+1, n) << endl;
        while (idx<n && query(1, 1, n, idx+1, idx+1)>=s.size()-i+1) {
            idx++;
        }
        //cout << i << ' ' << ans.back() <<' ' << idx << endl;
        if (i%2) {
            pii res=query1(1, 1, n, ans.back()+1, idx);
            for (int j: pos[res.fs]) {
                update1(1, 1, n, j, j, {-1e9, -1e9});
                update2(1, 1, n, j, j, {1e9, 1e9});
            }
            update(1, 1, n, 1, pos[res.fs].back(), -1);
            ans.push_back(-res.sc);
        }
        else {
            pii res=query2(1, 1, n, ans.back()+1, idx);
            for (int j: pos[res.fs]) {
                update1(1, 1, n, j, j, {-1e9, -1e9});
                update2(1, 1, n, j, j, {1e9, 1e9});
            }
            update(1, 1, n, 1, pos[res.fs].back(), -1);
            ans.push_back(res.sc);
        }
    }

    cout << ans.size()-1 << "\n";
    for (int i=1; i<ans.size(); i++) cout << A[ans[i]] << ' ';
    cout << "\n";

    for (int i=1; i<=n; i++) {
        update1(1, 1, n, i, i, {0, 0});
        update2(1, 1, n, i, i, {1e9, 1e9});
        int temp=query(1, 1, n, i, i);
        update(1, 1, n, i, i, -temp);
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
