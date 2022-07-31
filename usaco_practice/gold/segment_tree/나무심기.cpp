#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define f first
#define s second

pair<ll, ll> tree[1000005]={};
ll MOD=1e9+7;

pair<ll, ll> query(ll n, ll a, ll b, ll qa, ll qb) {// 나무의 갯수
    if (b<qa || qb<a) return {0, 0};
    else if (qa<=a && b<=qb) return {tree[n].f, tree[n].s%MOD};

    ll mid=(a+b)/2;
    auto ans1=query(2*n, a, mid, qa, qb);
    auto ans2=query(2*n+1, mid+1, b, qa, qb);
    return {ans1.f+ans2.f, (ans1.s+ans2.s+MOD)%MOD};
}

void update(ll n, ll a, ll b, ll qa, ll qb, pair<ll, ll> v) {
    if (b<qa || qb<a) return;
    else if (qa<=a && b<=qb) {
        tree[n]={tree[n].f+v.f, tree[n].s+v.s};
        return;
    }

    ll mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    tree[n].f=tree[2*n].f+tree[2*n+1].f;
    tree[n].s=tree[2*n].s+tree[2*n+1].s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll N, ans=0; cin >> N;
    for (ll i=1; i<=N; i++) {
        ll x; cin >> x; x++;
        pair<ll, ll> a1=query(1, 1, 200001, 1, x);
        pair<ll, ll> a2=query(1, 1, 200001, x, 200001);
        ll temp=((x*a1.f-a1.s)%MOD+(a2.s-x*a2.f)%MOD)%MOD;
        if (ans==0) ans=temp;
        else if (temp!=0) ans=(ans*temp+MOD)%MOD;
        update(1, 1, 200001, x, x, {1, x});
    }
    cout << (ans+MOD)%MOD;
}
