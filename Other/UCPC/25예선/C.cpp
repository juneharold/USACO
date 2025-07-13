#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=250005, sqrmax=635, MOD=1e9+7, INF=9e18;

ll segtree1[4*1000005]={};
ll query1(ll n, ll a, ll b, ll qa, ll qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree1[n];
    ll mid=(a+b)/2;
    return query1(2*n, a, mid, qa, qb)+query1(2*n+1, mid+1, b, qa, qb);
}
void update1(ll n, ll a, ll b, ll qa, ll qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree1[n]+=v; return; }
    ll mid=(a+b)/2;
    update1(2*n, a, mid, qa, qb, v);
    update1(2*n+1, mid+1, b, qa, qb, v);
    segtree1[n]=segtree1[2*n]+segtree1[2*n+1];
}

ll segtree2[4*1000005]={};
ll query2(ll n, ll a, ll b, ll qa, ll qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree2[n];
    ll mid=(a+b)/2;
    return query2(2*n, a, mid, qa, qb)+query2(2*n+1, mid+1, b, qa, qb);
}
void update2(ll n, ll a, ll b, ll qa, ll qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree2[n]+=v; return; }
    ll mid=(a+b)/2;
    update2(2*n, a, mid, qa, qb, v);
    update2(2*n+1, mid+1, b, qa, qb, v);
    segtree2[n]=segtree2[2*n]+segtree2[2*n+1];
}

ll l[nmax], r[nmax], s[nmax], e[nmax];

struct Event{
    ll sum_pos, type, left, right, idx;
};

bool cmp(Event a, Event b) {
    return a.sum_pos<b.sum_pos;
}

ll ans[nmax]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N, Q; cin >> N >> Q;
    for (ll i=1; i<=N; i++) cin >> l[i] >> r[i];
    for (ll i=1; i<=Q; i++) cin >> s[i] >> e[i];

    vector<Event> event;
    for (ll i=1; i<=N; i++) {
        Event ev;
        ev.sum_pos=l[i]+r[i];
        ev.type=0;
        ev.left=l[i];
        ev.right=r[i];
        ev.idx=i;
        event.push_back(ev);
    }
    for (ll i=1; i<=Q; i++) {
        Event ev;
        ev.sum_pos=s[i]+e[i];
        ev.type=1;
        ev.left=s[i];
        ev.right=e[i];
        ev.idx=i;
        event.push_back(ev);
    }

    sort(event.begin(), event.end(), cmp);
    for (ll i=event.size()-1; i>=0; i--) {
        Event ev=event[i];
        if (ev.type==0) {
            update1(1, 1, 1000000, ev.left, ev.left, ev.right-ev.left);
            update2(1, 1, 1000000, ev.left, ev.left, ev.left*(ev.right-ev.left));
        }
        else {
            ll query_idx=ev.idx;
            ans[query_idx]+=ev.right*query1(1, 1, 1000000, 1, ev.right-1);
            ans[query_idx]-=query2(1, 1, 1000000, 1, ev.right-1);
        }
    }

    // initialize segtree
    for (ll i=1; i<=1000000; i++) {
        ll val1=query1(1, 1, 1000000, i, i);
        update1(1, 1, 1000000, i, i, -val1);
        ll val2=query2(1, 1, 1000000, i, i);
        update2(1, 1, 1000000, i, i, -val2);
    }

    for (ll i=0; i<event.size(); i++) {
        Event ev=event[i];
        if (ev.type==0) {
            update1(1, 1, 1000000, ev.right, ev.right, ev.right-ev.left);
            update2(1, 1, 1000000, ev.right, ev.right, ev.right*(ev.right-ev.left));
        }
        else {
            ll query_idx=ev.idx;
            ans[query_idx]-=ev.left*query1(1, 1, 1000000, ev.left+1, 1000000);
            ans[query_idx]+=query2(1, 1, 1000000, ev.left+1, 1000000);
        }
    }

    for (int i=1; i<=Q; i++) cout << ans[i]*2LL << "\n";
}