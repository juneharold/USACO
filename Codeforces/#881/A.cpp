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
        vector<int> a(n, 0);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int sum=0;
        for (int i=0; i<n; i++) {
            if (n%2 && i==n/2) continue;
            if (i<n/2) sum-=a[i];
            else sum+=a[i];
        }
        out.push_back(sum);
    }
    for (int x: out) cout << x << "\n";
}
