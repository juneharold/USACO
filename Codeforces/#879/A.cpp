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
    vector<int> out;
    while (T--) {
        int n; cin >> n;
        int x=0, y=0;
        for (int i=1; i<=n; i++) {
            int a; cin >> a;
            if (a==1) x++;
            else y++;
        }
        int ans=0;
        while (true) {
            if (x>=y && y%2==0) {
                out.push_back(ans);
                //cout << ans << "\n";
                break;
            }
            y--;
            x++;
            ans++;
        }
    }
    for (int x: out) cout << x << "\n";
}
