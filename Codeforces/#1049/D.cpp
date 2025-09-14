#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<ll> l(n+1), r(n+1);
    for (int i=1; i<=n; i++) cin >> l[i] >> r[i];

    ll ans=0;
    vector<pair<ll, int>> sums;
    for (int i=1; i<=n; i++) {
        ans+=r[i]-l[i];
        sums.push_back({l[i]+r[i], i});
    }
    sort(sums.begin(), sums.end());

    //cout << ans << endl;
    ll sumr=0, suml=0;
    for (int i=0; i<n/2; i++) {
        int idx1=sums[i].sc, idx2=sums[sums.size()-1-i].sc;
        sumr+=r[idx2];
        suml+=l[idx1];
    }
    if (n%2==0) {
        cout << ans+sumr-suml << "\n";
        return;
    }

    // cout << "l r: " << endl;
    // for (int i=0; i<n; i++) cout << l[sums[i].sc] << ' ' << r[sums[i].sc] << endl;

    ll mx=sumr-suml;
    for (int i=0; i<n/2; i++) {
        int idx=sums[i].sc;
        ll nsuml=suml-l[idx]+l[sums[n/2].sc];
        //cout << sumr << ' ' << nsuml << ' ' << sumr-nsuml << endl;
        mx=max(mx, sumr-nsuml);
    }
    for (int i=n/2+1; i<n; i++) {
        int idx=sums[i].sc;
        ll nsumr=sumr-r[idx]+r[sums[n/2].sc];
        //cout << nsumr << ' ' << suml << ' ' << nsumr-suml << endl;
        mx=max(mx, nsumr-suml);
    }
    ans+=mx;

    cout << ans << "\n";
}

/*
5
1 10
2 9
3 8
4 7
5 6
ans>36
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
