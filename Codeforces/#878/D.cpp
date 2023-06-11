#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        vector<ll> a(n, 0);
        for (ll i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        ll lo=0, hi=1e9;
        while (lo<hi) {
            ll mid=(lo+hi)/2;
            ll c1=a[0]+mid, idx=0;
            while (idx<n) {
                if (abs((ll)(a[idx]-c1))<=mid) idx++;
                else break;
            }
            if (idx==n) {
                hi=mid;
                continue;
            }

            ll c2=a[idx]+mid;
            while (idx<n) {
                if (abs((ll)(a[idx]-c2))<=mid) idx++;
                else break;
            }
            if (idx==n) {
                hi=mid;
                continue;
            }

            ll c3=a[idx]+mid;
            while (idx<n) {
                if (abs((ll)(a[idx]-c3))<=mid) idx++;
                else break;
            }
            if (idx==n) hi=mid;
            else lo=mid+1;
        }
        cout << lo << "\n";
    }
}
