#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define f first
#define s second

ll a[200005]={}, pfs[200005]={}, loc[200005]={};

int main()
{
    vector<ll> ANS;
    ll T; cin >> T;
    while (T--) {
        ll n, c; cin >> n >> c;
        vector<pair<ll, ll>> cost;
        for (ll i=1; i<=n; i++) {
            cin >> a[i];
            cost.push_back(make_pair(min(a[i]+i, a[i]+n-i+1), i));
        }
        sort(cost.begin(), cost.end());

        for (ll i=1; i<=n; i++) {
            pfs[i]=pfs[i-1]+cost[i-1].f;
            loc[cost[i-1].s]=i;
        }

        ll ans=0;
        for (ll i=1; i<=n; i++) {
            // if i is first teleportal. 
            if (a[i]+i>c) continue;
            ll lo=0, hi=n;
            while (lo<hi) {
                ll mid=(lo+hi+1)/2;
                if (loc[i]<=mid) {
                    if (a[i]+i<=a[i]+n-i+1) { //왼쪽에서 옴. 
                        if (pfs[mid]<=c) lo=mid;
                        else hi=mid-1;
                    }
                    else { //오른쪽에서 옴. 
                        if (pfs[mid]+(a[i]+i)-(a[i]+n-i+1)<=c) lo=mid;
                        else hi=mid-1;
                    }
                }
                else {
                    if (pfs[mid]+a[i]+i<=c) lo=mid;
                    else hi=mid-1;
                }
            }
            if (loc[i]<=lo) ans=max(ans, lo);
            else ans=max(ans, lo+1);
        }

        cout << ans << "\n";
        for (ll i=1; i<=n; i++) {
            a[i]=0, pfs[i]=0, loc[i]=0;
        }
    }
}
