#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=998244353, INF=1e18;

ll m, a[nmax];

ll segtree[4*nmax]={};
ll query(ll n, ll a, ll b, ll qa, ll qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree[n];
    ll mid=(a+b)/2;
    return query(2*n, a, mid, qa, qb)+query(2*n+1, mid+1, b, qa, qb);
}
void update(ll n, ll a, ll b, ll qa, ll qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]=v; return; }
    ll mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=segtree[2*n]+segtree[2*n+1];
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update>

// (Set 이름).order_of_key(NUM) : ordered_set 에서 NUM 보다 작은(미만의) 원소의 개수를 반환한다. (Set 이름).find_by_order(K) : ordered_set 에서 (K+1)번째 원소가 있는 iterator 을 반환한다. (K가 0이면 1번째)
// ordered_set 을 multiset 처럼 쓰려면 less<ll> 를 less_equal<ll> 로 바꾸기만 하면 된다.
/* void m_erase(ordered_set &OS, ll val){
    ll index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}
*/

ll fastpow (ll x, ll y) {
    ll ret=1;
    while (y) {
        if (y%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        y/=2;
    }
    return ret;
}

ordered_set indexes;
ll find_score(ordered_set::iterator it) {
    ll score1=0, score2=0;
    if (it!=--indexes.end()) {
        auto temp=it;
        temp++;
        ll cnt=indexes.size()-indexes.order_of_key((*temp)+1);
        score1=query(1, 1, m, (*temp)+1, m)-cnt*query(1, 1, m, (*temp), (*temp));
    }
    if (it!=indexes.begin()) {
        auto temp=it;
        temp--;
        ll cnt=indexes.order_of_key((*temp));
        score2=cnt*query(1, 1, m, (*temp), (*temp))-query(1, 1, m, 1, (*temp)-1);
    }
    return max(score1, score2);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m;
    vector<pii> v;
    for (ll i=1; i<=m; i++) {
        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    vector<int> pos(m+5);
    for (ll i=1; i<=m; i++) pos[v[i-1].sc]=i;

    for (ll i=1; i<=m; i++) {
        update(1, 1, m, pos[i], pos[i], a[i]);
        indexes.insert(pos[i]);
        if (i<3) continue;
        ll lo=1, hi=indexes.size()-1;
        while (lo<hi) {
            ll mid=(lo+hi)/2+1;
            auto it1=indexes.find_by_order(mid-1);
            auto it2=indexes.find_by_order(mid);

            if (it1==indexes.end()) it1--;
            if (it2==indexes.end()) it2--;

            if (find_score(it1)<find_score(it2)) hi=mid-1;
            else lo=mid;
        }
        ll score=1e18;
        auto it=indexes.find_by_order(lo);
        score=min(score, find_score(it));
        cout << score%MOD*fastpow(indexes.size()-2, MOD-2)%MOD << "\n";
    }
}
