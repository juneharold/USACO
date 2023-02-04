#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long

ll a[200005]={};
int main()
{
    ll T; cin >> T;
    while (T--) {
        ll n, cnt=0, sum=0, Min=1e9; cin >> n;
        for (ll i=1; i<=n; i++) {
            cin >> a[i];
            if (a[i]<0) cnt++;
            sum+=abs((ll)a[i]);
            Min=min((ll)Min, abs((ll)a[i]));
        }
        if (cnt%2==0) {
            cout << sum << "\n";
        }
        else {
            cout << sum-Min*2 << "\n";
        }

        for (ll i=1; i<=n; i++) a[i]=0;
    }
}