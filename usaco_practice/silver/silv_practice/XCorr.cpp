#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define f first
#define s second

const ll MAX=3e5+5;
ll N, M, a, b, pfs[MAX]={};
pair<ll, ll> x[MAX]={}, y[MAX]={};

ll bs1(ll i) {
    ll lo=1, hi=M;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        if (y[mid].f<i+a) lo=mid+1;
        else hi=mid;
    }
    return lo;
}

ll bs2(ll i) {
    ll lo=1, hi=M;
    while (lo<hi) {
        ll mid=(lo+hi)/2+1;
        if (i+b<y[mid].f) hi=mid-1;
        else lo=mid;
    }
    return lo;
}

int main()
{
    cin >> N;
    for (ll i=1; i<=N; i++) cin >> x[i].f >> x[i].s;
    cin >> M;
    for (ll i=1; i<=M; i++) {
        cin >> y[i].f >> y[i].s;
        pfs[i]=pfs[i-1]+y[i].s;
    }
    cin >> a >> b;

    ll ans=0;
    for (ll i=1; i<=N; i++) {
        ll l=bs1(x[i].f), r=bs2(x[i].f);
        if (x[i].f+a<=y[l].f && y[r].f<=x[i].f+b) ans+=x[i].s*(pfs[r]-pfs[l-1]);
    }
    cout << ans;
}

/*
2
0 1
100 1
3
-10 3
-2 7
102 7
2
3
*/
