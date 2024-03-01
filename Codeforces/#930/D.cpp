#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll n; cin >> n;
    vector<char> s(n+5);
    for (ll i=1; i<=n; i++) cin >> s[i];

    vector<ll> cnt1(n+5, 0);
    for (ll i=1; i<=n; i++) {
        cnt1[i]=cnt1[i-1];
        if (s[i]=='>') cnt1[i]++;
    }
    vector<ll> pfs1(cnt1[n]+5, 0);
    ll idx=0;
    for (ll i=1; i<=n; i++) {
        if (s[i]=='>') {
            pfs1[idx+1]=pfs1[idx]+i;
            idx++;
        }
    }

    vector<ll> cnt2(n+5, 0);
    for (ll i=n; i>=1; i--) {
        cnt2[i]=cnt2[i+1];
        if (s[i]=='<') cnt2[i]++;
    }
    vector<ll> pfs2(cnt2[1]+5, 0);
    idx=0;
    for (ll i=n; i>=1; i--) {
        if (s[i]=='<') {
            pfs2[idx+1]=pfs2[idx]+i;
            idx++;
        }
    }

    vector<ll> ans(n+1, 0);
    for (ll i=1; i<=n; i++) {
        if (cnt1[i]==cnt2[i]) {
            ll need=cnt1[i];
            if (s[i]=='>') {
                ans[i]=2*(i*need-pfs1[cnt1[i]])+2*((pfs2[cnt2[i]]-pfs2[cnt2[i]-need])-i*need)+i;
            }
            else {
                ans[i]=2*(i*need-(pfs1[cnt1[i]]-pfs1[cnt1[i]-need]))+2*(pfs2[cnt2[i]]-i*need)+(n+1-i);
            }
        }
        else if (cnt1[i]>cnt2[i]) {
            ll need=cnt2[i];
            if (s[i]=='>') {
                ans[i]=2*(i*need-(pfs1[cnt1[i]-1]-pfs1[cnt1[i]-need-1]))+2*(pfs2[cnt2[i]]-i*need)+(n+1-i);
            }
            else {
                ans[i]=2*(i*need-(pfs1[cnt1[i]]-pfs1[cnt1[i]-need]))+2*(pfs2[cnt2[i]]-i*need)+(n+1-i);
            }
            //cout << "here1\n";
            //ans[i]=2*(i*need-(pfs1[cnt1[i]]-pfs1[cnt1[i]-need]))+2*(pfs2[cnt2[i]]-i*need)+(n+1-i);
        }
        else {
            ll need=cnt1[i];
            if (s[i]=='<') {
                ans[i]=2*(i*need-pfs1[cnt1[i]])+2*((pfs2[cnt2[i]-1]-pfs2[cnt2[i]-need-1])-i*need)+i;
            }
            else {
                ans[i]=2*(i*need-pfs1[cnt1[i]])+2*((pfs2[cnt2[i]]-pfs2[cnt2[i]-need])-i*need)+i;
            }
            //cout << "here2\n";
        }
    }

    for (ll i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
