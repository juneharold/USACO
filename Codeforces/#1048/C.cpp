#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll k, x; cin >> k >> x;
    vector<int> pos1;
    for (int i=0; i<=60; i++) {
        if ((1LL<<i)&x) pos1.push_back(i);
    }

    vector<int> ans;
    for (int i=1; i<pos1.size(); i++) {
        int d=pos1[i]-pos1[i-1];
        for (int i=1; i<=d-1; i++) ans.push_back(1);
        ans.push_back(2);
    }

    ll cur1=(1LL<<k), cur2=(1LL<<k);
    //cout << "cur1 cur2: " << cur1 << ' ' << cur2 << endl;
    for (int i=0; i<ans.size(); i++) {
        if (ans[i]==1) {
            cur2+=cur1/2;
            cur1/=2;
        }
        else {
            cur1+=cur2/2;
            cur2/=2;
        }
    }
    //cout << "cur1 cur2: " << cur1 << ' ' << cur2 << endl;
    while (cur1!=x) {
        ans.push_back(1);
        cur1/=2;
    }

    cout << ans.size() << "\n";
    for (ll a: ans) cout << a << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
