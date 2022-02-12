#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

const ll MAX=1e5+5;
ll N, M;
pair<ll, ll> cow[MAX]={}, grass[MAX]={};
multiset<ll> s;

bool cmp (pair<ll, ll> a, pair<ll, ll> b) {
    if (a.s==b.s) return a.f<b.f;
    return a.s>b.s;
}

int main()
{
    cin >> N >> M;
    for (ll i=1; i<=N; i++) cin >> cow[i].f >> cow[i].s; // f가 greeness
    for (ll i=1; i<=M; i++) cin >> grass[i].f >> grass[i].s;

    sort(&cow[1], &cow[N+1], cmp);
    sort(&grass[1], &grass[M+1], cmp);

    ll idx=1, ans=0;
    for (ll i=1; i<=N; i++) {
        while (idx<=M) {
            if (grass[idx].s>=cow[i].s) {
                s.insert(grass[idx].f);
                idx++;
            }
            else break;
        }

        auto it=s.lower_bound(cow[i].f);
        if (it==s.end()) {
            cout << -1;
            exit(0);
        }
        ans+=*it;
        s.erase(it);
    }
    cout << ans;
}
