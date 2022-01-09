#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define ll long long

const ll MAX_N=2505;
ll n, pfs[MAX_N][MAX_N]={}, ans=0;
pair<ll, ll> point[MAX_N];
bool sortY (pair<ll, ll> a, pair<ll, ll> b) {
    return a.s < b.s;
}

int main()
{
    cin >> n;
    for (ll i=1; i<=n; i++) {
        ll x, y; cin >> x >> y;
        point[i]={x, y};
    }

    sort(&point[1], &point[n+1], sortY);
    for (ll i=1; i<=n; i++) point[i].s=i;
    sort(&point[1], &point[n+1]);
    for (ll i=1; i<=n; i++) point[i].f=i;

    //for (int i=1; i<=n; i++) cout << point[i].f << " " << point[i].s << "\n";

    for (ll i=1; i<=n; i++) pfs[point[i].f][point[i].s]=1;

    for (ll i=1; i<=n; i++) {
        for (ll j=1; j<=n; j++) {
            pfs[i][j]+=pfs[i-1][j]+pfs[i][j-1]-pfs[i-1][j-1];
        }
    }

    for (ll i=1; i<=n; i++) {
        for (ll j=i; j<=n; j++) {
            ll maxy=max(point[i].s, point[j].s), miny=min(point[i].s, point[j].s);

            ll above=pfs[point[j].f][n]-pfs[point[i].f-1][n]-pfs[point[j].f][maxy-1]+pfs[point[i].f-1][maxy-1];
            ll below=pfs[point[j].f][miny]-pfs[point[i].f-1][miny];
            ans+=above*below;

        }
    }
    cout << ans+1;
}
