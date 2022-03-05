#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second

priority_queue<pair<ll, ll>> pq;
vector<pair<pair<ll, ll>, ll>> v;

bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    if (a.f.f==b.f.f) return a.f.s>b.f.s;
    return a.f.f<b.f.f;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N, k; cin >> N >> k;
    for (ll i=1; i<=k; i++) pq.push({-0, -i});
    for (ll i=1; i<=N; i++) {
        ll id, w; cin >> id >> w;
        ll nt=-pq.top().f+w, counter=-pq.top().s;
        v.push_back({{nt, counter}, id});
        pq.pop();
        pq.push({-nt, -counter});
    }

    sort(v.begin(), v.end(), cmp);

    ll ans=0;
    for (ll i=1; i<=N; i++) {
        ans+=v[i-1].s*i;
    }
    cout << ans;
}
