#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll loc[1000005]={}, link[500005]={}, st[2000005]={};

ll query(ll n, ll a, ll b, ll qa, ll qb) {
    if (qa<=a && b<=qb) return st[n];
    if (b<qa || qb<a) return 0;
    ll mid=(a+b)/2;
    return query(2*n, a, mid, qa, qb)+query(2*n+1, mid+1, b, qa, qb);
}

void update(ll n, ll a, ll b, ll qa, ll qb, ll v) {
    if (qa<=a && b<=qb) {st[n]=v; return;}
    if (b<qa || qb<a) return;
    ll mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    st[n]=st[2*n]+st[2*n+1];
}

int main()
{
    ll n; cin >> n;
    for (ll i=1; i<=n; i++) {
        ll x; cin >> x;
        loc[x]=i;
    }
    for (ll i=1; i<=n; i++) {
        ll x; cin >> x;
        link[i]=loc[x];
    }
    long long ans=0;
    for (ll i=1; i<=n; i++) {
        ans+=query(1, 1, n, link[i]+1, n);
        update(1, 1, n, link[i], link[i], 1);
    }
    cout << ans;
}