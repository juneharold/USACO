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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll a, b; cin >> a >> b;
        ll ans=1e18;
        for (int i=1; i*i<=2e9; i++) {
            ll temp=0;
            if (a%i) temp++;
            if (b%i) temp++;
            temp+=i-1+a/i+b/i;
            ans=min(ans, temp);
        }
        cout << ans << "\n";
    }
}
