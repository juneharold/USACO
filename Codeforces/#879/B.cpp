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
        string x, y; cin >> x >> y;
        if (x.size()>y.size()) swap(x, y);
        while (x.size()!=y.size()) {
            string temp="0"+x;
            x=temp;
        }
        int ans=0;
        for (int i=0; i<x.size(); i++) {
            if (x[i]!=y[i]) {
                ans=9*(x.size()-i-1);
                ans+=abs(x[i]-y[i]);
                break;
            }
        }
        out.push_back(ans);
    }
    for (int x: out) cout << x << "\n";
}
