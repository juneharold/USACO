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

ll bitsize(ll x) {
    ll ret=0;
    while (x!=0) {
        if (x%2) ret++;
        x/=2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        string a, b; cin >> a >> b;
        set<char> S;
        vector<char> unique;
        for (char x: a) {
            if (S.count(x)==0) unique.push_back(x);
            S.insert(x);
        }
        ll sz=unique.size(), mx=min(sz, k), ans=0;
        for (ll i=0; i<(1<<sz); i++) {
            // check if there are mx '1's in i
            if (bitsize(i)!=mx) continue;
            set<char> letters;
            for (ll j=0; j<sz; j++) {
                if (i&(1<<j)) letters.insert(unique[j]);
            }

            ll temp=0, cnt=0;
            for (ll j=0; j<n; j++) {
                if (a[j]==b[j] || letters.count(a[j])) cnt++;
                else {
                    temp+=cnt*(cnt+1)/2;
                    cnt=0;
                }
            }
            temp+=cnt*(cnt+1)/2;
            ans=max(ans, temp);
        }
        cout << ans << "\n";
    }
}
