#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n; cin >> n;
    ll k=sqrt(n*(n+1)/2LL);
    if (n*(n+1)/2LL==k*k) {
        cout << "-1\n";
        return;
    }
    vector<ll> ans;
    ans.push_back(2);
    ans.push_back(1);

    for (int i=3; i<=n; i++) {
        ans.push_back(i);
    }
    ll sum=0;
    vector<ll> cand;
    for (int i=0; i<n; i++) {
        sum+=ans[i];
        ll temp=sqrt(sum);
        if (temp*temp==sum) {
            cand.push_back(i);
        }
    }
    for (int idx: cand) {
        swap(ans[idx], ans[idx+1]);
    }
    sum=0;
    for (int i=0; i<n; i++) {
        sum+=ans[i];
        cout << ans[i] << ' ';
        ll temp=sqrt(sum);
    }
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
