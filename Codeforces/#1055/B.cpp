#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n, rk, ck, rd, cd; cin >> n >> rk >> ck >> rd >> cd;
    ll top_k=rk, bottom_k=n-rk, left_k=ck, right_k=n-ck;
    ll top_d=rd, bottom_d=n-rd, left_d=cd, right_d=n-cd;

    ll ans=0;
    if (top_k<top_d) {
        ans=max(ans, top_d+max(0ll, abs(ck-cd)-top_d));
    }
    if (bottom_k<bottom_d) {
        ans=max(ans, bottom_d+max(0ll, abs(ck-cd)-bottom_d));
    }
    if (left_k<left_d) {
        ans=max(ans, left_d+max(0ll, abs(rk-rd)-left_d));
    }
    if (right_k<right_d) {
        ans=max(ans, right_d+max(0ll, abs(rk-rd)-right_d));
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
