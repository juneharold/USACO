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

int diff(string a, string b) {
    int ret=0;
    for (int i=0; i<a.size(); i++) {
        if (a[i]!=b[i]) ret++;
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
        string S, T; cin >> S >> T;
        string RevT=T;
        reverse(RevT.begin(), RevT.end());
        int d1=diff(S, T), d2=diff(S, RevT);
        if (d1==0) {
            out.push_back(0);
        }
        else if (d2==0) {
            out.push_back(2);
        } 
        else if (d1==d2) {
            out.push_back(d1*2-1);
        }
        else if (d2<d1) {
            if (d2%2==0) out.push_back(d2*2-1);
            else out.push_back(d2*2);
        }
        else {
            if (d1%2==0) out.push_back(d1*2);
            else out.push_back(d1*2-1);
        }
        //cout << min(diff(S, T)*2-1, diff(S, RevT)*2) << "\n";
    }
    for (int x: out) cout << x << "\n";
}

/*
1
3
bba
abc
*/
