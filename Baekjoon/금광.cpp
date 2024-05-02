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
const ll nmax=3e3+5, sqrmax=635, MOD=1e9+7, INF=1e9;
/*
- coordinate compression (obviously)
- fix x1, and add points to segtree as you increment x2 
- segtree contains points based on y-coordinate
- find max continuous sum for every x1, x2 pair
O(n^2log(n))
*/

ll val[nmax]={};
map<ll, ll> cx, cy;

bool cmp(pair<pii, ll> a, pair<pii, ll> b) {
    if (a.sc==b.sc) return a.fs.fs<b.fs.fs;
    return a.fs.sc<b.fs.sc;
}

struct node {
    ll mxl, mx, mxr, sum;
};

node segtree[4*nmax]={};
node query(ll n, ll a, ll b, ll qa, ll qb) {
    if (b<qa || qb<a) return {-INF, -INF, -INF, -INF};
    if (qa<=a && b<=qb) return segtree[n];
    ll mid=(a+b)/2;
    node n1=query(2*n, a, mid, qa, qb), n2=query(2*n+1, mid+1, b, qa, qb);
    node ret;
    ret.mxl=max(n1.mxl, n1.sum+n2.mxl);
    ret.mxr=max(n2.mxr, n1.mxr+n2.sum);
    ret.mx=max({n1.mx, n2.mx, n1.mxr+n2.mxl});
    ret.sum=n1.sum+n2.sum;
    return ret;
}
void update(ll n, ll a, ll b, ll qa, ll qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n].mxl+=v, segtree[n].mx+=v, segtree[n].mxr+=v, segtree[n].sum+=v; return; }
    ll mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n].mxl=max(segtree[2*n].mxl, segtree[2*n].sum+segtree[2*n+1].mxl);
    segtree[n].mxr=max(segtree[2*n+1].mxr, segtree[2*n].mxr+segtree[2*n+1].sum);
    segtree[n].mx=max({segtree[2*n].mx, segtree[2*n+1].mx, segtree[2*n].mxr+segtree[2*n+1].mxl});
    segtree[n].sum=segtree[2*n].sum+segtree[2*n+1].sum;
}

void solve() {
    ll N; cin >> N;
    vector<pair<pii, ll>> v(N+1);
    for (ll i=1; i<=N; i++) {
        cin >> v[i].fs.fs >> v[i].fs.sc >> val[i];
        v[i].sc=i;
    }

    // coordinate compression
    sort(&v[1], &v[N+1]);
    ll num=0;
    for (ll i=1; i<=N; i++) {
        if (cx.find(v[i].fs.fs)==cx.end()) cx[v[i].fs.fs]=++num;
    }
    sort(&v[1], &v[N+1], cmp);
    num=0;
    for (ll i=1; i<=N; i++) {
        if (cy.find(v[i].fs.sc)==cy.end()) cy[v[i].fs.sc]=++num;
    }

    // sweeping
    sort(&v[1], &v[N+1]);
    ll ans=0;
    for (ll i=1; i<=N; i++) {
        if (i==1 || v[i].fs.fs>v[i-1].fs.fs) {
            for (ll j=i; j<=N; j++) {
                update(1, 1, N, cy[v[j].fs.sc], cy[v[j].fs.sc], val[v[j].sc]);
                if (j==N || v[j].fs.fs<v[j+1].fs.fs) {
                    ans=max(ans, query(1, 1, N, 1, N).mx);
                }
            }
            for (ll j=i; j<=N; j++) update(1, 1, N, cy[v[j].fs.sc], cy[v[j].fs.sc], -val[v[j].sc]);
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
