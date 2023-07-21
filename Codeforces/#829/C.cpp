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
    vector<int> a(n+1);
    int cnt1=0, cnt_1=0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i]==1) cnt1++;
        else if (a[i]==-1) cnt_1++;
    }
    if (cnt1==cnt_1) {
        cout << n << "\n";
        for (int i=1; i<=n; i++) cout << i << ' ' << i << "\n";
        return;
    }

    if (cnt_1>cnt1) {
        vector<int> seg;
        for (int i=1; i<n; i++) {
            if (cnt_1==cnt1) continue;
            if (a[i+1]==-1) {
                seg.push_back(i);
                cnt_1--;
                cnt1++;
                i++;
            }
        }
        if (cnt_1!=cnt1) {
            cout << "-1\n";
            return;
        }
        cout << n-seg.size() << "\n";
        int idx=0;
        for (int i=1; i<=n; i++) {
            if (idx<seg.size() && seg[idx]==i) {
                cout << i << ' ' << i+1 << "\n";
                idx++;
                i++;
            }
            else cout << i << ' ' << i << "\n";
        }

    }
    else {
        vector<int> seg;
        for (int i=1; i<n; i++) {
            if (cnt_1==cnt1) continue;
            if (a[i+1]==1) {
                seg.push_back(i);
                cnt_1++;
                cnt1--;
                i++;
            }
        }
        if (cnt_1!=cnt1) {
            cout << "-1\n";
            return;
        }
        cout << n-seg.size() << "\n";
        int idx=0;
        for (int i=1; i<=n; i++) {
            if (idx<seg.size() && seg[idx]==i) {
                cout << i << ' ' << i+1 << "\n";
                idx++;
                i++;
            }
            else cout << i << ' ' << i << "\n";
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
