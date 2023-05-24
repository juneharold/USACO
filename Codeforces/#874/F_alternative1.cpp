// This solution uses segment tree, unlike how the original solution used Fermat's Little Theorem
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
#define f first
#define s second
#define ll long long
#define MOD 1000000007

ll a[200005]={}, b[200005]={}, segtree[800005]={};

ll query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 1;
    if (qa<=a && b<=qb) return segtree[n]%MOD;
    int mid=(a+b)/2;
    return query(2*n, a, mid, qa, qb)*query(2*n+1, mid+1, b, qa, qb)%MOD;
}

void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) {segtree[n]=v; return;}
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=segtree[2*n]*segtree[2*n+1]%MOD;
}

int main() 
{
    ll T; cin >> T;
    vector<int> out;
    while (T--) {
        ll n, m; cin >> n >> m;
        map<ll, ll> level;
        for (ll i=1; i<=n; i++) {
            ll x; cin >> x;
            a[i]=x;
            level[x]++;
        }
        sort(&a[1], &a[n+1]);
        ll idx=0;
        for (ll i=1; i<=n; i++) {
            if (a[i]!=a[i-1]) {
                idx++;
                b[idx]=a[i];
            }
        }

        for (int i=1; i<=idx; i++) {
            update(1, 1, idx, i, i, level[b[i]]);
        }

        ll l=1, ans=0;
        while (l<=idx) {
            ll r=l+m-1;
            if (b[r]-b[l]==m-1) {
                ans+=query(1, 1, idx, l, r);
                ans%=MOD;
            }
            l++;
        }

        out.push_back(ans);

        fill(&a[1], &a[n+1], 0);
        fill(&b[1], &b[n+1], 0);
        fill(&segtree[1], &segtree[4*n], 0);
    }

    for (int x: out) cout << x << "\n";
}

