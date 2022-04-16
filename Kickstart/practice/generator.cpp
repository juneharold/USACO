#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll T; cin >> T;
    for (ll t=1; t<=T; t++) {
        ll G, ans=0; cin >> G;
        for (ll i=1; i*i<=2*G; i++) {
            ll temp=G*2;
            if (temp%i==0) temp/=i;
            else continue;

            temp+=(1-i);
            if (temp<=0) continue;
            if (temp%2==0) {
                ans++;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
