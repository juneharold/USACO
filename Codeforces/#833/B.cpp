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

void solve() {
    int n; cin >> n;
    string S; cin >> S;
    ll ans=0;
    for (int i=0; i<n; i++) {
        set<int> unique;
        vector<int> occur(10, 0);
        int bef=ans;
        //cout << i << " -------------\n";
        for (int j=i; j>=max(0, i-99); j--) {
            int a=S[j]-'0';
            //cout << a << endl;
            unique.insert(a);
            occur[a]++;
            bool possible=true;
            for (int k=0; k<10; k++) {
                if (occur[k]>unique.size()) possible=false;
            }
            if (possible) ans++;
        }
        //cout << "change " << i << ": " << ans-bef << endl;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
