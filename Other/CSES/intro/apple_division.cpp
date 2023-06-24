#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, sum=0, ans=1e18; cin >> n;
    vector<ll> a(n, 0);
    for (ll i=0; i<n; i++) {
        cin >> a[i];
        sum+=a[i];
    }
 
    for (int i=0; i<(1<<n); i++) {
        ll temp=0;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) temp+=a[j];
        }
        ans=min(ans, abs(sum-2*temp));
    }
    cout << ans;
}