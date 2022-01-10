#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second

ll N, M;
vector<pair<ll, ll>> ranges;

bool check (ll D) {
    ll least=0, cnt=0;
    for (ll i=0; i<ranges.size(); i++) {
        ll from=max(least, ranges[i].f), to=ranges[i].s;
        if (from>to) continue;

        ll num_cows=(to-from)/D+1;
        least=from+num_cows*D;
        cnt+=num_cows;
    }

    if (cnt>=N) return true;
    return false;
}

int main()
{
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> N >> M;
    for (ll i=0; i<M; i++) {
        ll a, b; cin >> a >> b;
        ranges.push_back({a, b});
    }
    sort(ranges.begin(), ranges.end());

    ll lo=0, hi=1e18;
    while (lo<hi) {
        ll mid=(lo+hi)/2+1;

        if (check(mid)) lo=mid;
        else hi=mid-1;
    }
    cout << lo;
}
