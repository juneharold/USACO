#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

ll fastpow (ll x, ll y) {
    ll exponent=y, ret=1;
    while (exponent) {
        if (exponent%2) {
            ret*=x;
        }
        x*=x;
        exponent/=2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll A, B, C, k; cin >> A >> B >> C >> k;
        ll mxa=fastpow(10, A)-1, mna=fastpow(10, A-1);
        ll mxb=fastpow(10, B)-1, mnb=fastpow(10, B-1);
        ll mxc=fastpow(10, C)-1, mnc=fastpow(10, C-1);
        ll l=max(mna+mnb, mnc), r=min(mxa+mxb, mxc);
        ll cnt=0, solve=0;
        for (ll a=mna; a<=mxa; a++) {
            ll temp=min(mxb, r-a)-max(mnb, l-a)+1;
            if (cnt+temp>=k) {
                for (ll b=max(mnb, l-a); b<=min(mxb, r-a); b++) {
                    cnt++;
                    if (cnt==k) {
                        cout << a << " + " << b << " = " << a+b << "\n";
                        solve=1;
                        break;
                    }
                }
                break;
            }
            cnt+=max((ll)0, temp);
        }
        if (!solve) cout << "-1\n";
    }
}
