#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first 
#define sc second

ll tree[4000005]={}, lazy[4000005]={};

void propagate(ll n, ll a, ll b) {
    if (lazy[n]) {
        tree[n]+=(b-a+1)*lazy[n];
        if (a!=b) {
            lazy[2*n]+=lazy[n];
            lazy[2*n+1]+=lazy[n];
        }
        lazy[n]=0;
    }
}

void update(ll n, ll a, ll b, ll qa, ll qb, ll v) {
    propagate(n, a, b);
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { 
        tree[n]+=(b-a+1)*v;
        if (a!=b) {
            lazy[2*n]+=v;
            lazy[2*n+1]+=v;
        }
        return;
    }
    ll mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    tree[n]=tree[2*n]+tree[2*n+1];
}

ll query(ll n, ll a, ll b, ll qa, ll qb) {
    propagate(n, a, b);
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return tree[n];
    ll mid=(a+b)/2;
    return query(2*n, a, mid, qa, qb)+query(2*n+1, mid+1, b, qa, qb);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N, M, K; cin >> N >> M >> K;
    for (ll i=1; i<=N; i++) {
        ll x; cin >> x;
        update(1, 1, N, i, i, x);
    }
    for (ll i=1; i<=M+K; i++) {
        ll type; cin >> type;
        if (type==1) {
            ll s, e, d; cin >> s >> e >> d;
            update(1, 1, N, s, e, d);
        }
        else {
            ll s, e; cin >> s >> e;
            cout << query(1, 1, N, s, e) << "\n";
        }
    }
}
