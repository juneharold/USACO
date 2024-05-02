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
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll segtree[4*nmax]={}, lazy[4*nmax][2]={};
void propagate(ll n, ll a, ll b) {
    segtree[n]=(segtree[n]*lazy[n][0]+(b-a+1)*lazy[n][1])%MOD;
    if (a!=b) {
        lazy[2*n][0]=lazy[2*n][0]*lazy[n][0]%MOD;
        lazy[2*n][1]=(lazy[2*n][1]*lazy[n][0]+lazy[n][1])%MOD;
        lazy[2*n+1][0]=lazy[2*n+1][0]*lazy[n][0]%MOD;
        lazy[2*n+1][1]=(lazy[2*n+1][1]*lazy[n][0]+lazy[n][1])%MOD;
    }
    lazy[n][0]=1,lazy[n][1]=0;
}
ll query(ll n, ll a, ll b, ll qa, ll qb) {
    propagate(n, a, b);
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) {
        //cout << a << ' ' << b << ' ' << segtree[n] << endl;
        return segtree[n]%MOD;
    }
    ll mid=(a+b)/2;
    ll ret=(query(2*n, a, mid, qa, qb)+query(2*n+1, mid+1, b, qa, qb))%MOD;
    //cout << a << ' ' << b << ' ' << ret << endl;
    return ret;
}
void update(ll n, ll a, ll b, ll qa, ll qb, ll mul, ll add) {
    propagate(n, a, b);
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { 
        lazy[n][0]=lazy[n][0]*mul%MOD;
        lazy[n][1]=lazy[n][1]*mul%MOD;
        lazy[n][1]=(lazy[n][1]+add)%MOD;
        propagate(n, a, b);
        return;
    }
    ll mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, mul, add);
    update(2*n+1, mid+1, b, qa, qb, mul, add);
    segtree[n]=(segtree[2*n]+segtree[2*n+1])%MOD;
}

void solve() {
    ll N; cin >> N;
    for (ll i=0; i<nmax*4; i++) lazy[i][0]=1;
    for (ll i=1; i<=N; i++) {
        ll a; cin >> a;
        update(1, 1, N, i, i, 1, a);
    }

    ll M; cin >> M;
    while (M--) {
        ll type; cin >> type;
        if (type!=4) {
            ll x, y, v; cin >> x >> y >> v;
            if (type==1) update(1, 1, N, x, y, 1, v);
            if (type==2) update(1, 1, N, x, y, v, 0);
            if (type==3) update(1, 1, N, x, y, 0, v);
        }
        else {
            ll x, y; cin >> x >> y;
            cout << query(1, 1, N, x, y) << "\n";
        }
        /*for (int i=1; i<=5; i++) cout << query(1, 1, N, i, i) << ' ';
        cout << endl << endl;*/
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
