#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define ll long long
#define f first
#define s second

ll N, Q, h[2005]={}, ncnt[2005]={}, cnt[2005]={};
stack<pair<ll, ll>> s[2005]; //i번째 index의 stack에는 (bi, h_bi)가 저장

void solve(int until) {
    ll ans=0;
    for (ll i=1; i<=until; i++) {
        pair<ll, ll> mx={1, -1e9};
        for (ll j=i+1; j<=N; j++) {
            ll dx=j-i, dy=h[j]-h[i];
            if (dy*mx.f>=mx.s*dx) {
                mx={dx, dy};
                ncnt[i]++;
            }
        }
        ans+=ncnt[i]-cnt[i];
        cnt[i]=ncnt[i];
        ncnt[i]=0;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (ll i=1; i<=N; i++) cin >> h[i];

    cin >> Q;
    for (ll q=1; q<=Q; q++) {
        ll x, y; cin >> x >> y;
        h[x]+=y;
        solve(x);
    }
}
