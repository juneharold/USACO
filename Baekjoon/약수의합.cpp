#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll f[1000001]={}, g[1000001]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (ll i=1; i<=1000000; i++) {
        for (ll j=i; j<=1000000; j+=i) {
            f[j]+=i;
        }
    }
    for (ll i=1; i<=1000000; i++) g[i]=g[i-1]+f[i];
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        cout << g[n] << "\n";
    }
}