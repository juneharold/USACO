#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
ll mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, ans=0; cin >> n;
    for (ll i=1; i*i<=n; i++) {
        ll cnt=n/i;
        ans+=cnt*i;
        ans%=mod;
    }

    cout << ans;
}
