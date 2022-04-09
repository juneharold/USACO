#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

bool isPrime(int n)
{
    if (n<=1) return false;
    if (n<=3) return true;
    if (n%2==0 || n%3==0) return false;

    for (int i=5; i*i<=n; i=i+6) {
        if (n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll T; cin >> T;
    for (ll t=1; t<=T; t++) {
        ll Z; cin >> Z;
        ll from=sqrt(Z)-500, prev=0, ans=0;
        for (ll i=from; i<from+1000; i++) {
            if(isPrime(i)) {
                if (prev*i<=Z && prev*i>ans) ans=prev*i;
                prev=i;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
