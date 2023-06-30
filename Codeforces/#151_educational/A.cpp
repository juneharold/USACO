#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

ll fastpow (ll x, ll y) {
    ll exponent=y, ret=1;
    while (exponent) {
        if (exponent%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        exponent/=2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        ll n, k, x; cin >> n >> k >> x;
        if (k==1 && x==1) {
            cout << "NO\n";
            continue;
        }

        if (x==1 && k==2) {
            if (n%2) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n" << n/2 << "\n";
                for (int i=1; i<=n/2; i++) cout << "2 ";
                cout << "\n";
            }
        }
        else if (x==1 && k>2) {
            if (n%2==0) {
                cout << "YES\n" << n/2 << "\n";
                for (int i=1; i<=n/2; i++) cout << "2 ";
                cout << "\n";
            }
            else {
                cout << "YES\n" << (n-3)/2+1 << "\n";
                cout << "3 ";
                for (int i=1; i<=(n-3)/2; i++) cout << "2 ";
                cout << "\n";
            }
        }
        else {
            cout << "YES\n" << n << "\n";
            for (int i=1; i<=n; i++) cout << "1 ";
            cout << "\n";
        }
    }
}
