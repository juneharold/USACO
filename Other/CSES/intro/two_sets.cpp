#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    ll n; cin >> n;
    if ((n*(n+1)/2)%2==0) {
        set<ll> s;
        ll sum=0;
        for (ll i=n; i>=1; i--) {
            ll need=n*(n+1)/4-sum;
            if (need<=i && need>=1) {
                s.insert(need);
                break;
            }
            s.insert(i);
            sum+=i;
        }
        cout << "YES\n";
        cout << s.size() << "\n";
        for (ll x: s) cout << x << ' ';
        cout << "\n" << n-s.size() << "\n";
        for (ll i=1; i<=n; i++) if (!s.count(i)) cout << i << ' ';
    }
    else cout << "NO";
}