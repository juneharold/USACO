#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long
#define db double

int main()
{
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        if (n&(1<<0)) {
            cout << -1 << "\n";
            continue;
        }

        ll a=0, b=0, c=0;
        for (ll i=1; i<30; i++) {
            if ((1<<i)&n) {
                a+=(1<<(i-1));
                b+=(1<<(i-1));
                //c+=(1<<(i-1));
            };
        }
        cout << a << ' ' << b << ' ' << c << "\n";
    }
}
