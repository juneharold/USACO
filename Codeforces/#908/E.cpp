#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<ll> a[nmax], c[nmax];
ll n[nmax]={}, l[nmax]={}, r[nmax]={}, sum_c[nmax]; 
map<ll, vector<pii>> contains;

void init(int m) {
    for (ll i=1; i<=m; i++) {
        for (int j=0; j<n[i]; j++) {
            contains[a[i][j]].clear();
        }
        a[i].clear();
        c[i].clear();
        n[i]=0; l[i]=0; r[i]=0; sum_c[i]=0;
    }
}

void solve() {
    ll m; cin >> m;
    ll ans=1e18, sum_n=0, sum_l=0, sum_r=0;
    for (ll i=1; i<=m; i++) {
        cin >> n[i] >> l[i] >> r[i];
        sum_n+=n[i]; sum_l+=l[i]; sum_r+=r[i];
        if (sum_r>1e17) ans=0;
        for (ll j=0; j<n[i]; j++) {
            ll x; cin >> x;
            contains[x].push_back({i, j});
            a[i].push_back(x);
        }
        for (ll j=0; j<n[i]; j++) {
            ll x; cin >> x;
            sum_c[i]+=x;
            c[i].push_back(x);
        }
    }
    if (sum_r-sum_l>sum_n) ans=0;
    if (ans==0) {
        cout << "0\n";
        init(m);
        return;
    }

    for (ll x=sum_l; x<=sum_r; x++) {
        ll temp=sum_r, cnt_anti=0;
        for (auto pr: contains[x]) temp-=r[pr.fs];
        for (auto pr: contains[x]) {
            int idx=pr.fs, pos=pr.sc;
            ll picked=0;
            picked+=sum_c[idx]-c[idx][pos];
            if (picked<l[idx]) {
                temp+=l[idx];
                cnt_anti+=l[idx]-picked;
            }
            else temp+=min(picked, r[idx]);
        }
        ans=min(ans, max(0LL, x-temp)+cnt_anti);
    }
    cout << ans << "\n";
    init(m);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
